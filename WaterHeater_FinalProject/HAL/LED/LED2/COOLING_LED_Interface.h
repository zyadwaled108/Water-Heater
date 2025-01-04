/*
 * COOLING_LED_Interface.h
 *
 * Created: 13/12/2024 4:47:57 PM
 *  Author: zyade
 */ 


#ifndef COOLING_LED_INTERFACE_H_
#define COOLING_LED_INTERFACE_H_

#include "COOLING_LED_Private.h"


void COOLING_LED_Initialize(void);
void COOLING_LED_ON(void);
void COOLING_LED_OFF(void);
void COOLING_LED_TGL(void);


#endif /* COOLING_LED_INTERFACE_H_ */