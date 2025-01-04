/*
 * TWI_Configuration.h
 *
 * Created: 15/12/2024 11:22:51 PM
 *  Author: zyade
 */ 


#ifndef TWI_CONFIGURATION_H_
#define TWI_CONFIGURATION_H_

#include "TWI_Address.h"

#define TWI_SDA PC1
#define TWI_SCL PC0

// Another option, Create new data type
typedef enum
{
	TWI_SLave  = 0,
	TWI_Master = 1
}twi_mode;
// Master Status
typedef enum
{
	Master_Start_Ack              = 0x08,
	Master_Repeated_Start_Ack     = 0x10,
	Master_SLA_WR_Ack             = 0x18,
	Master_SLA_WR_NAck            = 0x20,
	Master_Data_Trasmit_Ack       = 0x28,
	Master_Data_Trasmit_NAck      = 0x30,
	Master_ArbitrationLost_SLA_WR = 0x38,
	Master_SLA_RD_ACK             = 0x40,
	Master_SLA_RD_NACK            = 0x48,
	Master_Data_receive_Ack       = 0x50,
	Master_Data_receive_NAck      = 0x58
}twi_master_status;
// Slave Status
typedef enum
{
	Slave_Start_Ack              = 0x08,
	Slave_Repeated_Start_Ack     = 0x10,
	Slave_SLA_WR_Ack             = 0x18,
	Slave_SLA_WR_NAck            = 0x20,
	Slave_Data_Trasmit_Ack       = 0x28,
	Slave_Data_Trasmit_NAck      = 0x30,
	Slave_ArbitrationLost_SLA_WR = 0x38,
	Slave_SLA_RD_ACK             = 0x40,
	Slave_SLA_RD_NACK            = 0x48,
	Slave_Data_receive_Ack       = 0x50,
	Slave_Data_receive_NAck      = 0x58
}twi_slave_status;
// Slave Address
typedef enum
{
	_TWI_GeneralCallAddress = 0x00,//0
	_TWI_SlaveAddress0      = 0x01,//1
	_TWI_SlaveAddress1      = 0x02,//2
	_TWI_SlaveAddress2      = 0x03,//3
	_TWI_SlaveAddress3      = 0x04,//4
	_TWI_SlaveAddress4      = 0x05,//5
	_TWI_SlaveAddress5      = 0x06,//6
	_TWI_SlaveAddress6      = 0x07,//7
	_TWI_SlaveAddress7      = 0x08,//8
	_TWI_SlaveAddress8      = 0x09,//9
	_TWI_SlaveAddress9      = 0x0A,//10
	_TWI_SlaveAddress10     = 0x0B,//11
	_TWI_SlaveAddress11     = 0x0C,//12
	_TWI_SlaveAddress12     = 0x0D,//13
	_TWI_SlaveAddress13     = 0x0E,//14
	_TWI_SlaveAddress14     = 0x0F,//15
	_TWI_ReservedAddress0   = 0x78,//120
	_TWI_ReservedAddress1   = 0x79,//121
	_TWI_ReservedAddress2   = 0x7A,//122
	_TWI_ReservedAddress3   = 0x7B,//123
	_TWI_ReservedAddress4   = 0x7C,//124
	_TWI_ReservedAddress5   = 0x7D,//125
	_TWI_ReservedAddress6   = 0x7E,//126
	_TWI_ReservedAddress7   = 0x7F //127
}twiSlaveAddress;
// Optional
#define TWI_ACTIVATOR (_TWI_TWCR|=((1<<TWEN)|(1<<TWINT)))
/* ----------------------------------------------Need---------------------------------------------------------------------------- */
#define START_ACK               0x08 // Start has been transmitted
#define REP_START_ACK           0x10 // Repeated start has been transmitted
#define STOP_ACK                0xA0 // Stop has been transmitted

#define MASTER_WR_BYTE_ACK      0x28 // Data byte + Write transmitted acknowledgment has been received
#define MASTER_WR_BYTE_NOACK    0x30 // Data byte + Write transmitted acknowledgment has not been received
#define MASTER_RD_BYTE_ACK      0x50 // Data byte + Read transmitted acknowledgment has been received
#define MASTER_RD_BYTE_NOACK    0x58 // Data byte + Read transmitted acknowledgment has not been received

#define SLAVE_WR_BYTE_ACK       0xB8 // Data byte + Write transmitted acknowledgment has been received
#define SLAVE_WR_BYTE_NOACK     0xC0 // Data byte + Write transmitted acknowledgment has not been received
#define SLAVE_RD_BYTE_ACK       0x80 // Data byte + Read transmitted acknowledgment has been received
#define SLAVE_RD_BYTE_NOACK     0x88 // Data byte + Read transmitted acknowledgment has not been received
/* ----------------------------------------------No Need------------------------------------------------------------------------- */
#define SLAVE_ADD_WR_ACK        0x18 // Slave address + Write transmitted acknowledgment has been received
#define SLAVE_ADD_WR_NOACK      0x20 // Slave address + Write transmitted acknowledgment has not been received
#define SLAVE_ADD_RD_ACK        0x40 // Slave address + Read transmitted acknowledgment has been received
#define SLAVE_ADD_RD_NOACK      0x48 // Slave address + Read transmitted acknowledgment has not been received

#define SLAVE_ADD_RCVD_WR_REQ   0x60 // Slave received + Write own address acknowledgment has been received
#define SLAVE_ADD_RCVD_RD_REQ   0xA8 // Slave received + Read own address acknowledgment has been received
/* ----------------------------------------------End----------------------------------------------------------------------------- */



#endif /* TWI_CONFIGURATION_H_ */