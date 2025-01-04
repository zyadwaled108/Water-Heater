/*
 * Timer0_OVF_Interface.h
 *
 * Created: 18/12/2024 12:03:18 AM
 *  Author: zyade
 */ 


#ifndef TIMER0_OVF_INTERFACE_H_
#define TIMER0_OVF_INTERFACE_H_



#include "Timer0_OVF_Private.h"

void Timer0_OVF_WithInterrupt_Initialize (void);
void Timer0_OVF_WithInterrupt_Start (timer0_ovf_prescalar prescalar);
void Timer0_OVF_WithInterrupt_Stop (void);
void Timer0_OVF_WithInterrupt_SetDelay (uint32_t delay);

void Timer0_OVF_WithoutInterrupt_Initialize (void);
void Timer0_OVF_WithoutInterrupt_Start (timer0_ovf_prescalar prescalar);
void Timer0_OVF_WithoutInterrupt_Stop (void);
void Timer0_OVF_WithoutInterrupt_SetDelay (uint32_t delay);

uint8_t Timer0_OVF_CounterValue (void);



#endif /* TIMER0_OVF_INTERFACE_H_ */