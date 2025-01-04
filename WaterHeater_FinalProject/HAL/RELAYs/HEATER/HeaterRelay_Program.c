/*
 * HeaterRelay_Program.c
 *
 * Created: 14/12/2024 5:35:49 PM
 *  Author: zyade
 */ 


#include "HeaterRelay_Interface.h"

void HeaterRelay_Initialize(void){
	DIO_SetPinDirection(HeaterRelay_PORT, HeaterRelay, HeaterRelay_OUTPUT);

}
void HeaterRelay_On(void){
	DIO_SetPinValue(HeaterRelay_PORT, HeaterRelay, HeaterRelay_HIGH);
}
void HeaterRelay_Off(void){
	DIO_SetPinValue(HeaterRelay_PORT, HeaterRelay, HeaterRelay_LOW);
}
