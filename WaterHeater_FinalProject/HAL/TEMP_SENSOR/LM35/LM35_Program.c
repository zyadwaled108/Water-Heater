/*
 * LM35_Program.c
 *
 * Created: 13/12/2024 5:59:55 PM
 *  Author: zyade
 */ 

#include "LM35_Interface.h"
void LM35_Initialize(void) {
	// Initialize the ADC module with configured reference voltage and prescaler
	ADC_Initialize_WithoutInterrupt(LM35_ADC_VREF, LM35_ADC_PRESCALER);
}

uint16_t LM35_ReadTemperature(void) {
	// Read the ADC value from the configured channel
	uint16_t adcValue = ADC_Read(LM35_ADC_CHANNEL);

	// Convert ADC value to temperature in millivolts
	uint32_t millivolts = ((uint32_t)adcValue * 5000) / 1024;

	// Convert millivolts to temperature (10mV per degree Celsius for LM35)
	uint16_t temperature = millivolts / 10;

	return temperature;
}