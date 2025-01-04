/*
* Interrupts_Program.c
*
* Created: 2/9/2024 4:53:56 PM
*  Author: karim
*/


#include "Interrupts_Interface.h"

void External_Interrupt_Initialization(interruptPin intrrupt, interruptSense sense)
{
	cli();//Disable global interrupt clear bit 7 in SREG (Apartment door)
	switch (intrrupt)
	{
		case EXT_INT0:
		clr_bit(DDRD, INT0);//Define direction for interrupt pin as input
		set_bit(GICR, INT0);//Enable peripheral interrupt (Room door)
		switch (sense)
		{
			case EXT_INTERRUPT_SENSE_LOW:
			clr_bit(_INTERRUPT_MCUCR, ISC01); clr_bit(_INTERRUPT_MCUCR, ISC00);// 0       0
			break;
			case EXT_INTERRUPT_SENSE_HIGH:
			clr_bit(_INTERRUPT_MCUCR, ISC01); set_bit(_INTERRUPT_MCUCR, ISC00);// 0       1
			break;
			case EXT_INTERRUPT_SENSE_FALLING:
			set_bit(_INTERRUPT_MCUCR, ISC01); clr_bit(_INTERRUPT_MCUCR, ISC00);// 1       0
			break;
			case EXT_INTERRUPT_SENSE_RISING:
			set_bit(_INTERRUPT_MCUCR, ISC01); set_bit(_INTERRUPT_MCUCR, ISC00);// 1       1
			break;
		}
		break;
		case EXT_INT1:
		clr_bit(DDRD, INT1);//Define direction for interrupt pin as input
		set_bit(GICR, INT1);//Enable peripheral interrupt (Room door)
		switch (sense)
		{
			case EXT_INTERRUPT_SENSE_LOW:
			clr_bit(_INTERRUPT_MCUCR, ISC11); clr_bit(_INTERRUPT_MCUCR, ISC10);// 0       0
			break;
			case EXT_INTERRUPT_SENSE_HIGH:
			clr_bit(_INTERRUPT_MCUCR, ISC11); set_bit(_INTERRUPT_MCUCR, ISC10);// 0       1
			break;
			case EXT_INTERRUPT_SENSE_FALLING:
			set_bit(_INTERRUPT_MCUCR, ISC11); clr_bit(_INTERRUPT_MCUCR, ISC10);// 1       0
			break;
			case EXT_INTERRUPT_SENSE_RISING:
			set_bit(_INTERRUPT_MCUCR, ISC11); set_bit(_INTERRUPT_MCUCR, ISC10);// 1       1
			break;
		}
		break;
		case EXT_INT2:
		clr_bit(DDRB, INT2);//Define direction for interrupt pin as input
		set_bit(GICR, INT2);//Enable peripheral interrupt (Room door)
		switch (sense)
		{
			case EXT_INTERRUPT_SENSE_LOW:
			clr_bit(_INTERRUPT_MCUCSR, ISC2);// 0
			break;
			case EXT_INTERRUPT_SENSE_FALLING:
			clr_bit(_INTERRUPT_MCUCSR, ISC2);// 0
			break;
			case EXT_INTERRUPT_SENSE_RISING:
			set_bit(_INTERRUPT_MCUCSR, ISC2);// 1
			break;
			case EXT_INTERRUPT_SENSE_HIGH:
			set_bit(_INTERRUPT_MCUCSR, ISC2);// 1
			break;
		}
		break;
	}
	sei();//Enable global interrupt set bit 7 in SREG (Apartment door)
}