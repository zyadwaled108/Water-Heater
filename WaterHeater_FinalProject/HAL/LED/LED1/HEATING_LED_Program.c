/*
 * HEATING_LED_Program.c
 *
 * Created: 13/12/2024 4:51:56 PM
 *  Author: zyade
 */ 


#include "HEATING_LED_Interface.h"

void HEATING_LED_Initialize(void)
{
	DIO_SetPinDirection(HEATING_LED_PORT, HEATING_LED, HEATING_LED_OUTPUT);
}
void HEATING_LED_ON(void)
{
	DIO_SetPinValue(HEATING_LED_PORT, HEATING_LED, HEATING_LED_HIGH);
}
void HEATING_LED_OFF(void)
{
	DIO_SetPinValue(HEATING_LED_PORT, HEATING_LED, HEATING_LED_LOW);
}

void HEATING_LED_TGL(void)
{
	DIO_TogglePinDirection(HEATING_LED_PORT, HEATING_LED);
}