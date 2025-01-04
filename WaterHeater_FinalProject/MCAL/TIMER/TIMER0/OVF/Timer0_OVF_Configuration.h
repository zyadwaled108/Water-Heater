/*
 * Timer0_OVF_Configuration.h
 *
 * Created: 18/12/2024 12:03:02 AM
 *  Author: zyade
 */ 


#ifndef TIMER0_OVF_CONFIGURATION_H_
#define TIMER0_OVF_CONFIGURATION_H_

#include "Timer0_OVF_Address.h"

#define _T0_OVF_BITS         256
#define _T0_OVF_PRESCALER    1024
#define _T0_OVF_FREQUENCY    16
#define _T0_OVF_MICROSECOND  1000

// Creating new dataType for Pre-scalar
typedef enum
{
	_T0_OVF_PRE_0    = 0,
	_T0_OVF_PRE_1    = 1,
	_T0_OVF_PRE_8    = 2,
	_T0_OVF_PRE_64   = 3,
	_T0_OVF_PRE_256  = 4,
	_T0_OVF_PRE_1024 = 5
}timer0_ovf_prescalar;



#endif /* TIMER0_OVF_CONFIGURATION_H_ */