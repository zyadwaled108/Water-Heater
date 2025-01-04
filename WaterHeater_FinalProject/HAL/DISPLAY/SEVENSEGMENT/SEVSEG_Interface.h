/*
 * SEVSEG_Interface.h
 *
 * Created: 13/12/2024 4:57:32 PM
 *  Author: zyade
 */ 


#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

#include "SEVSEG_Private.h"

void SEVSENSEGMENT_Initialize(void);

void SEVSENSEGMENT_EnableSegment1(void);
void SEVSENSEGMENT_DisableSegment1(void);

void SEVSENSEGMENT_EnableSegment2(void);
void SEVSENSEGMENT_DisableSegment2(void);

void SEVSENSEGMENT_EnableDecimalPoint(void);
void SEVSENSEGMENT_DisableDecimalPoint(void);

void SEVSENSEGMENT_DisplayNumber(uint8_t number);
void SEVSENSEGMENT_OFF(void);




#endif /* SEVSEG_INTERFACE_H_ */