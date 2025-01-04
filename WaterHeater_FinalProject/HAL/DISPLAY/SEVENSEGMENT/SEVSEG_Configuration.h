/*
 * SEVSEG_Configuration.h
 *
 * Created: 13/12/2024 4:57:01 PM
 *  Author: zyade
 */ 


#ifndef SEVSEG_CONFIGURATION_H_
#define SEVSEG_CONFIGURATION_H_


#include "CPU_Configuration.h"

// Renaming Port
#define SEVSEG_PORT           _DIO_PORTA
#define SEVESEG_DATA_PORT     DIO_PORTA
#define SEVESEG_CONTROL_PORT  DIO_PORTA
// Renaming Pin
#define SEVSEG_DATA_A         DIO_PIN4
#define SEVSEG_DATA_B         DIO_PIN5
#define SEVSEG_DATA_C         DIO_PIN6
#define SEVSEG_DATA_D         DIO_PIN7

#define SEVSEG_CONTROL_EN1   DIO_PIN1
#define SEVSEG_CONTROL_EN2   DIO_PIN2
#define SEVSEG_CONTROL_DIP   DIO_PIN3
// Renaming State
#define SEVSEG_OUTPUT         DIO_OUTPUT
// Renaming Status
#define SEVSEG_LOW            DIO_LOW
#define SEVSEG_HIGH           DIO_HIGH


#endif /* SEVSEG_CONFIGURATION_H_ */