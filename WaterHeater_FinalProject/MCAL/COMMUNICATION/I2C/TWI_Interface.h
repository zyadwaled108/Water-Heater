/*
 * TWI_Interface.h
 *
 * Created: 15/12/2024 11:23:25 PM
 *  Author: zyade
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#include "TWI_Private.h"
/* ------------------------------------------------------------------------------------ */
//Master Transmit & Receive Data
void TWI_voidPeripheralInitialize                     (twiSlaveAddress slaveAddress);
void TWI_voidMasterSendStartCondition                 (void                        );
void TWI_voidMasterSendStopCondition                  (void                        );
void TWI_voidMasterSendRepeatedStartCondition         (void                        );
void TWI_voidMasterSendSlaveAddressWithWriteOperation (twiSlaveAddress slaveAddress);
void TWI_voidMasterSendSlaveAddressWithReadOperation  (twiSlaveAddress slaveAddress);
void TWI_voidMasterTransmitDataByteWithACK            (uint8_t dataTransmitted     );
void TWI_voidMasterTransmitDataByteWithNoACK          (uint8_t dataTransmitted     );
void TWI_voidMasterReceiveDataByteWithACK             (uint8_t* dataReceived       );
void TWI_voidMasterReceiveDataByteWithNoACK           (uint8_t* dataReceived       );
/* ------------------------------------------------------------------------------------ */
// Slave Transmit & Receive Data
void TWI_voidSlaveTransmitDataByteWithACK             (uint8_t dataTransmitted     );
void TWI_voidSlaveTransmitDataByteWithNoACK           (uint8_t dataTransmitted     );
void TWI_voidSlaveReceiveDataByteWithACK              (uint8_t* dataReceived       );
void TWI_voidSlaveReceiveDataByteWithNoACK            (uint8_t* dataReceived       );
/* ------------------------------------------------------------------------------------ */


#endif /* TWI_INTERFACE_H_ */