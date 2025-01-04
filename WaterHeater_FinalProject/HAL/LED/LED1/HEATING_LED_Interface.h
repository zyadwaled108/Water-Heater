/*
 * HEATING_LED_Interface.h
 *
 * Created: 13/12/2024 4:51:11 PM
 *  Author: zyade
 */ 


#ifndef HEATING_LED_INTERFACE_H_
#define HEATING_LED_INTERFACE_H_

#include "HEATING_LED_Private.h"

void HEATING_LED_Initialize(void);
void HEATING_LED_ON(void);
void HEATING_LED_OFF(void);
void HEATING_LED_TGL(void);


#endif /* HEATING_LED_INTERFACE_H_ */