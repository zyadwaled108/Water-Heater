/*
 * CPU_Configuration.h
 *
 * Created: 13/12/2024 4:34:28 PM
 *  Author: zyade
 */ 


#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

/* ------------------------->CPU Configurations    */
#undef F_CPU            // Disable internal clock
#define F_CPU 16000000  // Enable external clock
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "BIT_Math.h"
#include "STD_Types.h"

#include "DIO_Interface.h"




#endif /* CPU_CONFIGURATION_H_ */