/*
 * ON_LED_Program.c
 *
 * Created: 13/12/2024 4:55:35 PM
 *  Author: zyade
 */ 


#include "ON_LED_Interface.h"

void ON_LED_Initialize(void)
{
	DIO_SetPinDirection(ON_LED_PORT, ON_LED, ON_LED_OUTPUT);
}
void ON_LED_ON(void)
{
	DIO_SetPinValue(ON_LED_PORT, ON_LED, ON_LED_HIGH);
}
void ON_LED_OFF(void)
{
	DIO_SetPinValue(ON_LED_PORT, ON_LED, ON_LED_LOW);
}
void ON_LED_TGL(void)
{
	DIO_TogglePinDirection(ON_LED_PORT, ON_LED);
}