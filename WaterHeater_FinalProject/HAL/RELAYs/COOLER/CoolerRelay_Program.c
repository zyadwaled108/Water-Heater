/*
 * CoolerRelay_Program.c
 *
 * Created: 14/12/2024 5:53:10 PM
 *  Author: zyade
 */ 


#include "CoolerRelay_Interface.h"

void CoolerRelay_Initialize(void){
	DIO_SetPinDirection(CoolerRelay_PORT, CoolerRelay, CoolerRelay_OUTPUT);
}
void CoolerRelay_On(void){
	DIO_SetPinValue(CoolerRelay_PORT, CoolerRelay, CoolerRelay_HIGH);
}
void CoolerRelay_Off(void){
	DIO_SetPinValue(CoolerRelay_PORT, CoolerRelay, CoolerRelay_LOW);
}
