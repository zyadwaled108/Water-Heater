/*
 * EEPROM_24C16N_Interface.h
 *
 * Created: 16/12/2024 12:54:52 AM
 *  Author: zyade
 */ 


#ifndef EEPROM_24C16N_INTERFACE_H_
#define EEPROM_24C16N_INTERFACE_H_

#include "EEPROM_24C16N_Private.h"

void EEPROM_Initialize(void);
void EEPROM_Write_DataByte(uint16_t wordAddress, uint8_t dataTransmit);
uint8_t EEPROM_Read_DataByte(uint16_t wordAddress);


#endif /* EEPROM_24C16N_INTERFACE_H_ */