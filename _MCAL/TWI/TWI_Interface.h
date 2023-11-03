/*
 * I2C_Interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_


/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

/* ----------------- Section : Macro Declarations -----------------*/
#define STATUS_VALUE					(_TWSR & 0xF8)

#define Start_Condition_ACK				0x08
#define RepeatedStart_Condition_ACK		0x10

#define SlaveAddress_Write_ACK			0x18
#define SlaveAddress_Read_ACK			0x40

#define Master_Data_Transmit_ACK		0x28
#define Master_Data_Receive_ACK			0x50

/* ----------------- Section : Data types Declarations -----------------*/


/* ----------------- Section : Software Interfaces Declaration -----------------*/

// Master APIs
void TWI_voidInitMaster(u8 copy_u8MsterAddress);
void TWI_voidSendStartCondition(void);
void TWI_voidSendStopCondition(void);
void TWI_voidSendReapeatedStartCondition(void);
void TWI_voidSendSlaveAdd_WriteRequest(u8 copy_u8SlaveAddress);
void TWI_voidSendSlaveAdd_ReadRequest(u8 copy_u8SlaveAddress);
void TWI_voidWriteMasterDataByte(u8 copy_u8Data);
void TWI_voidReadMasterDataByte(u8 *copy_u8PtrData);

void TWI_voidSendNACK(void);
//Slave APIs

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
