/*
 * Timer0_CTC_Interface.h
 *
 * Created: 16/12/2024 3:43:12 AM
 *  Author: zyade
 */ 


#ifndef TIMER0_CTC_INTERFACE_H_
#define TIMER0_CTC_INTERFACE_H_



#include "Timer0_CTC_Private.h"

void Timer0_CTC_WithInterrupt_Initialize (void);
void Timer0_CTC_WithInterrupt_Start (void);
void Timer0_CTC_WithInterrupt_Stop (void);
void Timer0_CTC_WithInterrupt_SetDelay (uint32_t delay, uint8_t ocrValue);

void Timer0_CTC_WithoutInterrupt_Initialize (void);
void Timer0_CTC_WithoutInterrupt_Start (void);
void Timer0_CTC_WithoutInterrupt_Stop (void);
void Timer0_CTC_WithoutInterrupt_SetDelay (uint32_t delay, uint8_t ocrValue);

uint8_t Timer0_CTC_CounterValue (void);


#endif /* TIMER0_CTC_INTERFACE_H_ */