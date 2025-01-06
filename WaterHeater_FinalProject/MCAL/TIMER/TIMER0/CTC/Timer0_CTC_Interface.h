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


#endif /* TIMER0_CTC_INTERFACE_H_ */