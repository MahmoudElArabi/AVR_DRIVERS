/*
 * I2C_Program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "TWI_Interface.h"
#include "TWI_Registers.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Software Interfaces Implementation -----------------*/

void TWI_voidInitMaster(u8 copy_u8MsterAddress)
{
	if ((copy_u8MsterAddress < 128) && (copy_u8MsterAddress > 0))
	{
		_TWAR = copy_u8MsterAddress <<1;
	}
	/* Select SCL as 400KHz */
	_TWBR = 12;
	//Prescaler 1
	CLR_BIT(_TWSR, _TWPS0);
	CLR_BIT(_TWSR, _TWPS1);

	// Enable ACK, in order to generate status code
	SET_BIT(_TWCR, _TWEA);

	// Enable TWI
	SET_BIT(_TWCR, _TWEN);
}

void TWI_voidSendStartCondition(void)
{
	// Request Start condition
	SET_BIT(_TWCR, _TWSTA);
	// Send the start condition
	SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
	while(0 == GET_BIT(_TWCR, _TWINT));
	// Check ACK is Positive
	while(STATUS_VALUE != Start_Condition_ACK);
}

void TWI_voidSendStopCondition(void)
{
	// Request STOP condition
	SET_BIT(_TWCR, _TWSTO);
	// Send the STOP condition
	SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
}

void TWI_voidSendReapeatedStartCondition(void)
{
	// Request Reapeated Start condition
	SET_BIT(_TWCR, _TWSTA);
	// Send the Reapeated start condition
	SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
	while(0 == GET_BIT(_TWCR, _TWINT));
	// Check ACK is Positive
	while(STATUS_VALUE != RepeatedStart_Condition_ACK);
}

void TWI_voidSendSlaveAdd_WriteRequest(u8 copy_u8SlaveAddress)
{
	if ((copy_u8SlaveAddress < 128) && (copy_u8SlaveAddress > 0))
	{
		_TWDR = copy_u8SlaveAddress << 1;
		CLR_BIT(_TWDR, 0);

		// Clear Start condition Flag
		CLR_BIT(_TWCR, _TWSTA);

		SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
		while(0 == GET_BIT(_TWCR, _TWINT));
		// Check ACK is Positive
		while(STATUS_VALUE != SlaveAddress_Write_ACK);
	}
}

void TWI_voidSendSlaveAdd_ReadRequest(u8 copy_u8SlaveAddress)
{
	if ((copy_u8SlaveAddress < 128) && (copy_u8SlaveAddress > 0))
	{
		_TWDR = copy_u8SlaveAddress << 1;
		SET_BIT(_TWDR, 0);

		// Clear Start condition Flag
		CLR_BIT(_TWCR, _TWSTA);

		SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
		while(0 == GET_BIT(_TWCR, _TWINT));
		// Check ACK is Positive
		while(STATUS_VALUE != SlaveAddress_Read_ACK);
	}
}

void TWI_voidWriteMasterDataByte(u8 copy_u8Data)
{
	_TWDR = copy_u8Data;
	// Clear Start condition Flag
	SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
	while(0 == GET_BIT(_TWCR, _TWINT));
	// Check ACK is Positive
	while(STATUS_VALUE != Master_Data_Transmit_ACK);
}

void TWI_voidReadMasterDataByteNACK(u8 *copy_u8PtrData)
{
	CLR_BIT(_TWCR, _TWEA);	//Disable ACK
	if (copy_u8PtrData != NULL)
	{
		// Clear Start condition Flag
		SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
		while(0 == GET_BIT(_TWCR, _TWINT));
		// Check NACK
	while(STATUS_VALUE != Master_Data_Receive_NACK);
		*copy_u8PtrData = _TWDR;
	}
	SET_BIT(_TWCR, _TWEA);	// //Enable ACK
}


void TWI_voidReadMasterDataByteACK(u8 *copy_u8PtrData)
{
	if (copy_u8PtrData != NULL)
	{
		// Clear Start condition Flag
		SET_BIT(_TWCR, _TWINT);	//Clear the TWINT Flag
		while(0 == GET_BIT(_TWCR, _TWINT));
		// Check ACK is Positive
		while(STATUS_VALUE != Master_Data_Receive_ACK);
		*copy_u8PtrData = _TWDR;
	}
}
