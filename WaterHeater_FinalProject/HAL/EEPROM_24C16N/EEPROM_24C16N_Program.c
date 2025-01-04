/*
 * EEPROM_24C16N_Program.c
 *
 * Created: 16/12/2024 12:55:33 AM
 *  Author: zyade
 */ 



#include "EEPROM_24C16N_Interface.h"
#include "TWI_Interface.h"
//#include "LCD_Interface.h"	

void EEPROM_Initialize(void)
{
	TWI_voidPeripheralInitialize(_TWI_SlaveAddress0);
}
// Write byte
void EEPROM_Write_DataByte(uint16_t wordAddress, uint8_t dataTransmit)
{
	uint8_t wordAddressL = wordAddress;
	uint8_t wordAddressH = (((wordAddress>>8)&0x07) | 0x50);
	TWI_voidMasterSendStartCondition();
	
	TWI_voidMasterSendSlaveAddressWithWriteOperation(wordAddressH);
	
	TWI_voidMasterTransmitDataByteWithACK(wordAddressL);
	
	TWI_voidMasterTransmitDataByteWithACK(dataTransmit);
	
	TWI_voidMasterSendStopCondition();
	
	_delay_ms(5);
	return;
}
// Random read byte
uint8_t EEPROM_Read_DataByte(uint16_t wordAddress)
{
	
	uint8_t dataReceived = 0;
	uint8_t wordAddressL = wordAddress;
	uint8_t wordAddressH = (wordAddress >> 8) | 0x50;
	
	TWI_voidPeripheralInitialize(_TWI_SlaveAddress0);
	
	TWI_voidMasterSendStartCondition();
	
	
	TWI_voidMasterSendSlaveAddressWithWriteOperation(wordAddressH);
	
	
	TWI_voidMasterTransmitDataByteWithACK(wordAddressL);
	
	
	TWI_voidMasterSendRepeatedStartCondition();
	
	
	TWI_voidMasterSendSlaveAddressWithReadOperation(wordAddressH);
	
	
	TWI_voidMasterReceiveDataByteWithNoACK(&dataReceived);
	
	
	TWI_voidMasterSendStopCondition();
	
	
	_delay_ms(5);
	return dataReceived;
}