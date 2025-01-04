/*
 * TWI_Program.c
 *
 * Created: 15/12/2024 11:24:48 PM
 *  Author: zyade
 */ 


#include "TWI_Interface.h"
//#include "LCD_Interface.h"

/* -------------------------------------------------------------------------------------------------------------------------------------- */
//Master Receive byte from slave
void TWI_voidPeripheralInitialize (twiSlaveAddress slaveAddress)
{
	_TWI_TWSR &=~((1<<TWPS1) |(1<<TWPS0))            ; // Pre-scalar bits in TWSR will be initialize to value = 0
	_TWI_TWBR |= (0x0C)                              ; // ((((MC_FREQ / I2C_SCL) / Prescaler) - 16 ) / 2); Dcimal = 12
	_TWI_TWAR = (slaveAddress << 1) | (0x01)         ; // Set Slave Address + Enable General Call
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEA) | (1<<TWEN)); // Reinitialize flag + Enable TWI + Enable Acknowledgment
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
void TWI_voidMasterSendStartCondition (void)
{
	//TWI_ACTIVATOR;
	_TWI_TWCR = ((1<<TWSTA) | (1<<TWINT) | (1<<TWEN)); // Start Condition + Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1);            // Waiting Flag
	while((_TWI_TWSR & 0xF8) != START_ACK);            // Wait until receive start acknowledgment, 0x08
	_delay_ms(5);
}

void TWI_voidMasterSendStopCondition (void)
{
	//TWI_ACTIVATOR;
	_TWI_TWCR = ((1<<TWSTO) | (1<<TWINT) | (1<<TWEN)); // Issue stop condition
}

void TWI_voidMasterSendRepeatedStartCondition (void)
{
	//TWI_ACTIVATOR;
	_TWI_TWCR = ((1<<TWSTA) | (1<<TWINT) | (1<<TWEN)); // Start Condition + Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1);            // Waiting Flag
	while((_TWI_TWSR & 0xF8) != REP_START_ACK);        // Wait until receive repeated start acknowledgment, 0x10
	//_TWI_TWCR &=~(1<<TWSTA);
}

void TWI_voidMasterSendSlaveAddressWithWriteOperation (twiSlaveAddress slaveAddress)
{
	if(slaveAddress < 128)
	{
		_TWI_TWDR = (slaveAddress<<1) | (0x00);        // Write Slave address with write operation
		_TWI_TWCR &=~(1<<TWSTA);                       // Clear start condition is constrain according to data-sheet
		_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));         // Reinitialize flag + Enable TWI
		while (get_bit(_TWI_TWCR, TWINT) != 1);        // Waiting Flag
		while((_TWI_TWSR & 0xF8) != SLAVE_ADD_WR_ACK); // Wait until receive write acknowledgment
	}
	else
	{
		return;
	}
}

void TWI_voidMasterSendSlaveAddressWithReadOperation(twiSlaveAddress slaveAddress)
{
	// Ensure slave address is within valid range
	if (slaveAddress < 128)
	{
		// Set the slave address with read operation (LSB = 1)
		_TWI_TWDR = (slaveAddress << 1) | 0x01;

		// Initiate a start condition if needed (This function assumes start condition is already handled)
        _TWI_TWCR |= (1 << TWSTA) | (1 << TWINT) | (1 << TWEN); // Send start condition
		while (get_bit(_TWI_TWCR, TWINT) != 1);   // Wait for flag to clear

		// Check if the slave acknowledged the address with a read operation
		while ((_TWI_TWSR & 0xF8) != 0x40)  // 0x40 is the acknowledgment for a slave address with read operation
		{
			// Optionally handle timeout or error
		}
	}
	else
	{
		// Error: invalid slave address
		return;  // You might want to signal an error, return status, etc.
	}
}

void TWI_voidMasterTransmitDataByteWithACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1); // Waiting Flag
	while((_TWI_TWSR & 0xF8) != MASTER_WR_BYTE_ACK); // Wait until receive write acknowledgment
}

void TWI_voidMasterTransmitDataByteWithNoACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));      // Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1);     // Waiting Flag
	while((_TWI_TWSR & 0xF8) != MASTER_WR_BYTE_NOACK); // Wait until receive write acknowledgment
}

void TWI_voidMasterReceiveDataByteWithACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (get_bit(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != MASTER_RD_BYTE_ACK);     // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}

void TWI_voidMasterReceiveDataByteWithNoACK(uint8_t* dataReceived)
{
	  // Enable TWI and clear interrupt flag
	  _TWI_TWCR = (1 << TWEN) | (1 << TWINT);

	  // Wait until TWI finishes the operation
	  while (get_bit(_TWI_TWCR, TWINT) != 1);

	   //Check for successful data reception without acknowledgment
	  while ((_TWI_TWSR & 0xF8) != 0x58) {  // 0x58 is the expected status for no ACK after byte read
		  // Optionally handle timeout or error
	  }

	  // Store received data
	  *dataReceived = _TWI_TWDR;
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
void TWI_voidSlaveTransmitDataByteWithACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWEA)|(1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1); // Waiting Flag
	while((_TWI_TWSR & 0xF8) != SLAVE_WR_BYTE_ACK); // Wait until receive write acknowledgment
}

void TWI_voidSlaveTransmitDataByteWithNoACK(uint8_t dataTransmitted)
{
	_TWI_TWDR = dataTransmitted;
	_TWI_TWCR |= ((1<<TWINT) | (1<<TWEN));  // Reinitialize flag + Enable TWI
	while (get_bit(_TWI_TWCR, TWINT) != 1); // Waiting Flag
	while((_TWI_TWSR & 0xF8) != SLAVE_WR_BYTE_ACK); // Wait until receive write acknowledgment
}

void TWI_voidSlaveReceiveDataByteWithACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (get_bit(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != SLAVE_RD_BYTE_ACK);      // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}

void TWI_voidSlaveReceiveDataByteWithNoACK(uint8_t* dataReceived)
{
	_TWI_TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT); // Reinitialize flag + Enable TWI + Enable Acknowledgment
	while (get_bit(_TWI_TWCR, TWINT) != 1);         // Wait until job finish
	while((TWSR & 0xF8) != SLAVE_RD_BYTE_ACK);            // Wait until receive write acknowledgment
	_TWI_TWCR &=~(1<<TWEA);                         // Disable acknowledgment
	*dataReceived = _TWI_TWDR;                      // Read received data
}
/* -------------------------------------------------------------------------------------------------------------------------------------- */
