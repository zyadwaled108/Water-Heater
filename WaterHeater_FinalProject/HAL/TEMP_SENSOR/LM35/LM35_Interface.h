/*
 * LM35_Interface.h
 *
 * Created: 13/12/2024 5:59:44 PM
 *  Author: zyade
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include "LM35_Private.h"
#include "ADC_Interface.h"

/**
 * @brief Initializes the LM35 module (ADC initialization included).
 */
void LM35_Initialize(void);

/**
 * @brief Reads the temperature from the LM35 sensor.
 * @return Temperature in degrees Celsius (integer value).
 */
uint16_t LM35_ReadTemperature(void);



#endif /* LM35_INTERFACE_H_ */