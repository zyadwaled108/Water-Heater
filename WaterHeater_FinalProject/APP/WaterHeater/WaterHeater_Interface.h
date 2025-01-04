/*
 * WaterHeater_Interface.h
 *
 * Created: 25/12/2024 4:03:07 AM
 *  Author: zyade
 */ 


#ifndef WATERHEATER_INTERFACE_H_
#define WATERHEATER_INTERFACE_H_

#include "WaterHeater_Private.h"

// Function Prototypes
void System_Initialize(void);
void WaterHeater(void);
void Handle_TemperatureSetting(void);
void Handle_ON_OFF(void);
void Retrieve_Temperature_From_EEPROM(void);
void Save_Temperature_To_EEPROM(void);
void ManageHeating(void);
void Toggle_HeaterState(void);
void System_Off(void);
void cooling(void);
void heating(void);
ISR(TIMER0_OVF_vect);


#endif /* WATERHEATER_INTERFACE_H_ */