/*
 * ADC_Interface.h
 *
 * Created: 13/12/2024 6:01:26 PM
 *  Author: zyade
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#include "ADC_Private.h"

void ADC_Initialize_WithoutInterrupt(adc_vref vref, adc_prescaler prescaler);

void ADC_Initialize_WithInterrupt(adc_vref vref, adc_prescaler prescaler);

uint16_t ADC_Read(adc_channel channel);


#endif /* ADC_INTERFACE_H_ */