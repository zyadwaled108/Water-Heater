/*
 * LM35_Configuration.h
 *
 * Created: 13/12/2024 5:59:25 PM
 *  Author: zyade
 */ 


#ifndef LM35_CONFIGURATION_H_
#define LM35_CONFIGURATION_H_

#include "CPU_Configuration.h"

// ADC channel to which LM35 is connected (ADC0 - ADC7)
#define LM35_ADC_CHANNEL   ADC_channel_0

// Reference voltage for ADC (ADC_Avcc, ADC_Aref, or ADC_Internal)
#define LM35_ADC_VREF      ADC_Avcc

// ADC prescaler (ADC_PRE1, ADC_PRE2, ..., ADC_PRE128)
#define LM35_ADC_PRESCALER ADC_PRE64


#endif /* LM35_CONFIGURATION_H_ */