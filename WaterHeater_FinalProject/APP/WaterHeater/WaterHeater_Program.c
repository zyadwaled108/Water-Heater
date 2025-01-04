/*
 * WaterHeater_Program.c
 *
 * Created: 25/12/2024 4:03:32 AM
 *  Author: zyade
 */ 

#include <avr/interrupt.h>
#include "WaterHeater_Interface.h"


// Global Variables
uint8_t g_SetTemperature = INITIAL_TEMPERATURE;
uint8_t g_CurrentTemperature = 0 ;
uint8_t g_HeaterState = 0; // 0: OFF, 1: ON
uint8_t g_TemperatureSettingMode = 0;
uint16_t g_lastInteractionTime = 0;
uint8_t g_heating = 0;
volatile uint32_t g_Ticks = 0;
volatile uint8_t g_BlinkFlag = 0;
static uint8_t g_TempHistory[TEMP_HISTORY_SIZE] = {0};
static uint8_t g_TempIndex = 0;



// ISR for Timer0 
extern uint32_t _T0_OVF_Count  ;
extern uint8_t  _T0_OVF_iValue ;

ISR(TIMER0_OVF_vect)
{
	g_Ticks++;
	_T0_OVF_TCNT0 = _T0_OVF_iValue;
	if (g_HeaterState)
	{
		ManageHeating();
		
		if (g_Ticks % (DISPLAY_BLINK_INTERVAL / 100) == 0 && g_TemperatureSettingMode)
		{
			g_BlinkFlag = !g_BlinkFlag;
		}
		
	}
}


// Handle ON/OFF Button
ISR(INT2_vect) {
	
	g_HeaterState = !g_HeaterState;
	LCD_Write_Location(ROW0,COL0);
	LCD_Write_IntegerNumber(g_HeaterState);

	if (g_HeaterState == 0) {
		System_Off();
		} else {
		ON_LED_ON();
		LCD_Write_Location(ROW1,COL0);
		LCD_Write_IntegerNumber(g_SetTemperature);
		
	}
}

ISR(INT0_vect) {
	// UP button pressed
	if (g_HeaterState)
	{
		if (!g_TemperatureSettingMode) {
			g_TemperatureSettingMode = 1;
			g_lastInteractionTime = g_Ticks;
			Handle_TemperatureSetting();
		}else
		{
			g_SetTemperature = (g_SetTemperature + 5 <= MAX_TEMPERATURE) ? g_SetTemperature + 5 : MAX_TEMPERATURE;
			LCD_Write_Location(ROW1,COL0);
			LCD_Write_IntegerNumber(g_SetTemperature);
			SEVSENSEGMENT_DisplayNumber(g_SetTemperature);
			g_lastInteractionTime = g_Ticks;
			Save_Temperature_To_EEPROM();
		}
	}
	
}

ISR(INT1_vect) {
	// DOWN button pressed
	if (g_HeaterState)
	{
		if (!g_TemperatureSettingMode) {
			g_TemperatureSettingMode = 1;
			g_lastInteractionTime = g_Ticks;
			Handle_TemperatureSetting();
		}else
		{
			g_SetTemperature = (g_SetTemperature - 5 >= MIN_TEMPERATURE) ? g_SetTemperature - 5 : MIN_TEMPERATURE;
			LCD_Write_Location(ROW1,COL0);
			LCD_Write_IntegerNumber(g_SetTemperature);
			SEVSENSEGMENT_DisplayNumber(g_SetTemperature);
			g_lastInteractionTime = g_Ticks;
			Save_Temperature_To_EEPROM();
		}
		
	}
	
}

void WaterHeater(void) {
	System_Initialize();
	while (1) { // Run infinitely and check the state 
		if (g_HeaterState)
		{
			
			ON_LED_ON();
			if (g_BlinkFlag) {
				
				SEVSENSEGMENT_OFF();
				
				} else if (g_TemperatureSettingMode) {
				
				SEVSENSEGMENT_DisplayNumber(g_SetTemperature);
				
			} else SEVSENSEGMENT_DisplayNumber(g_CurrentTemperature);
			
			Handle_TemperatureSetting();
			
		} else System_Off(); // Ensure system turns off properly when g_HeaterState = 0
	}
}


// System Initialization
void System_Initialize(void) {
	
	ON_LED_Initialize();
	HEATING_LED_Initialize();
	COOLING_LED_Initialize();
	
	LM35_Initialize();
	SEVSENSEGMENT_Initialize();
	
	HeaterRelay_Initialize();
	CoolerRelay_Initialize();
	
	LCD_Initialize();
	
	Timer0_OVF_WithInterrupt_Initialize();
	Timer0_OVF_WithInterrupt_Start(_T0_OVF_PRE_1024);
	Timer0_OVF_WithInterrupt_SetDelay(10);
	
	External_Interrupt_Initialization(EXT_INT0,EXT_INTERRUPT_SENSE_RISING);
	External_Interrupt_Initialization(EXT_INT1,EXT_INTERRUPT_SENSE_RISING);
	External_Interrupt_Initialization(EXT_INT2,EXT_INTERRUPT_SENSE_FALLING);
	
	EEPROM_Initialize();
	
	// Retrieve last saved temperature
	Retrieve_Temperature_From_EEPROM();
	
	sei();
}



// Handle Temperature Setting Mode
void Handle_TemperatureSetting(void) {

	if (g_TemperatureSettingMode)
	{
		// Exit setting mode after inactivity
		if ((g_Ticks - g_lastInteractionTime) > (INACTIVITY_TIMEOUT / 100))
		{
			g_TemperatureSettingMode = 0;
			g_BlinkFlag = 0 ;
		}
	}
}

// Retrieve Temperature from EEPROM
void Retrieve_Temperature_From_EEPROM(void) {
	
	uint8_t savedTemperature;
	savedTemperature = EEPROM_Read_DataByte(0x01);

	if (savedTemperature >= MIN_TEMPERATURE && savedTemperature <= MAX_TEMPERATURE) {
		g_SetTemperature = savedTemperature;
		} else {
		g_SetTemperature = INITIAL_TEMPERATURE;
	}
}

// Save Temperature to EEPROM
void Save_Temperature_To_EEPROM(void) {
	EEPROM_Write_DataByte(0x01, g_SetTemperature);
}

// Timer Task for periodic operations
void ManageHeating(void) {

	// Temperature sensing every TEMP_SENSING_INTERVAL ms (100ms)
	
	// Read current temperature
	g_CurrentTemperature = LM35_ReadTemperature();
	LCD_Write_Location(ROW0,COL6);
	LCD_Write_IntegerNumber(g_CurrentTemperature);

	// Update temperature history
	g_TempHistory[g_TempIndex] = g_CurrentTemperature;
	g_TempIndex = (g_TempIndex + 1) % TEMP_HISTORY_SIZE;

	// Calculate average temperature
	uint16_t tempSum = 0;
	for (uint8_t i = 0; i < TEMP_HISTORY_SIZE; i++) {
		tempSum += g_TempHistory[i];
	}
	uint8_t g_AvergeTemperature = tempSum / TEMP_HISTORY_SIZE;

	// Control logic
	if (g_AvergeTemperature > (g_SetTemperature - 5) && !g_heating) {
		cooling();
		g_heating = 0;
		} else if (g_AvergeTemperature < (g_SetTemperature + 5)) {
		heating();
		g_heating = 1;
		} else {
		HeaterRelay_Off();
		HEATING_LED_OFF();
		CoolerRelay_Off();
		COOLING_LED_OFF();
		g_heating = 0;
	}
}

void System_Off(void)
{
	ON_LED_OFF();
	COOLING_LED_OFF();
	HEATING_LED_OFF();
	
	CoolerRelay_Off();
	HeaterRelay_Off();
	
	SEVSENSEGMENT_OFF();
}

void heating(void){
	static uint8_t count = 0;
	HeaterRelay_On();
	COOLING_LED_OFF();
	CoolerRelay_Off();
	if (count >= 10)
	{
		HEATING_LED_TGL();
		count = 0 ;
	}
	count++;
}

void cooling(void){
	COOLING_LED_ON();
	CoolerRelay_On();
	HEATING_LED_OFF();
	HeaterRelay_Off();
}
