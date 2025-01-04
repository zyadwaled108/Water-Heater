/*
 * DIO_Program.c
 *
 * Created: 13/12/2024 4:33:27 PM
 *  Author: zyade
 */ 


#include "DIO_Interface.h"

// MicroController pin direction
void DIO_SetPinDirection(dioPort port, dioPin pin, dioState state)
{
	switch (state)
	{
		case DIO_INPUT:
		switch (port)
		{
			case DIO_PORTA: clr_bit(_DIO_DDRA, pin); break;
			case DIO_PORTB: clr_bit(_DIO_DDRB, pin); break;
			case DIO_PORTC: clr_bit(_DIO_DDRC, pin); break;
			case DIO_PORTD: clr_bit(_DIO_DDRD, pin); break;
		}
		break;
		case DIO_OUTPUT:
		switch (port)
		{
			case DIO_PORTA: set_bit(_DIO_DDRA, pin); break;
			case DIO_PORTB: set_bit(_DIO_DDRB, pin); break;
			case DIO_PORTC: set_bit(_DIO_DDRC, pin); break;
			case DIO_PORTD: set_bit(_DIO_DDRD, pin); break;
		}
		break;
	}
}
// Pin-Output
void DIO_SetPinValue(dioPort port, dioPin pin, dioStatus status)
{
	switch (status)
	{
		case DIO_LOW:
		switch (port)
		{
			case DIO_PORTA: clr_bit(_DIO_PORTA, pin); break;
			case DIO_PORTB: clr_bit(_DIO_PORTB, pin); break;
			case DIO_PORTC: clr_bit(_DIO_PORTC, pin); break;
			case DIO_PORTD: clr_bit(_DIO_PORTD, pin); break;
		}
		break;
		case DIO_HIGH:
		switch (port)
		{
			case DIO_PORTA: set_bit(_DIO_PORTA, pin); break;
			case DIO_PORTB: set_bit(_DIO_PORTB, pin); break;
			case DIO_PORTC: set_bit(_DIO_PORTC, pin); break;
			case DIO_PORTD: set_bit(_DIO_PORTD, pin); break;
		}
		break;
	}
}
void DIO_TogglePinDirection(dioPort port, dioPin pin)
{
	switch (port)
	{
		case DIO_PORTA: tgl_bit(_DIO_PORTA, pin); break;
		case DIO_PORTB: tgl_bit(_DIO_PORTB, pin); break;
		case DIO_PORTC: tgl_bit(_DIO_PORTC, pin); break;
		case DIO_PORTD: tgl_bit(_DIO_PORTD, pin); break;
	}
}
// Pin-Input
uint8_t DIO_ReadPinValue(dioPort port, dioPin pin)
{
	uint8_t pinValue = 0;
	switch (port)
	{
		case DIO_PORTA: pinValue = get_bit(_DIO_PINA, pin); break;
		case DIO_PORTB: pinValue = get_bit(_DIO_PINB, pin); break;
		case DIO_PORTC: pinValue = get_bit(_DIO_PINC, pin); break;
		case DIO_PORTD: pinValue = get_bit(_DIO_PIND, pin); break;
	}
	return pinValue;
}
void DIO_SetPinPullUp(dioPort port, dioPin pin)
{
	switch (port)
	{
		case DIO_PORTA: set_bit(_DIO_PORTA, pin); break;
		case DIO_PORTB: set_bit(_DIO_PORTB, pin); break;
		case DIO_PORTC: set_bit(_DIO_PORTC, pin); break;
		case DIO_PORTD: set_bit(_DIO_PORTD, pin); break;
	}
}