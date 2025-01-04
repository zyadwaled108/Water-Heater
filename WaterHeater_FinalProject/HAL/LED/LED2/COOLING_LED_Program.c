/*
 * COOLING_LED_Program.c
 *
 * Created: 13/12/2024 4:49:30 PM
 *  Author: zyade
 */ 


#include "COOLING_LED_Interface.h"

void COOLING_LED_Initialize(void)
{
	DIO_SetPinDirection(COOLING_LED_PORT, COOLING_LED, COOLING_LED_OUTPUT);
}
void COOLING_LED_ON(void)
{
	DIO_SetPinValue(COOLING_LED_PORT, COOLING_LED, COOLING_LED_HIGH);
}
void COOLING_LED_OFF(void)
{
	DIO_SetPinValue(COOLING_LED_PORT, COOLING_LED, COOLING_LED_LOW);
}

void COOLING_LED_TGL(void)
{
	DIO_TogglePinDirection(COOLING_LED_PORT, COOLING_LED);
}
