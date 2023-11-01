/*
 * EXT_EEPROM_Program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "EXT_EEPROM_Private.h"
#include "EXT_EEPROM_Interface.h"
#include "../../_MCAL/TWI/TWI_Interface.h"
#include <util/delay.h>

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void EEPROM_Init(void)
{
	TWI_voidInitMaster(255);
}

void EEPROM_voidWrite_Byte(u16 copy_u16WordAdd, u8 copy_u8Data)
{
	u8 local_u8Add = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS ;
	TWI_voidSendStartCondition();
	TWI_voidSendSlaveAdd_WriteRequest(local_u8Add);

	TWI_voidWriteMasterDataByte((u8)copy_u16WordAdd);
	TWI_voidWriteMasterDataByte(copy_u8Data);
	TWI_voidSendStopCondition();
	_delay_ms(5);	// delay to eeprom to store the data
}

void EEPROM_voidRead_Byte(u16 copy_u16WordAdd, u8 *copy_u8PtrReceivedData)
{
	if(copy_u8PtrReceivedData != NULL)
	{
		u8 local_u8Add = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS ;
		TWI_voidSendStartCondition();
		TWI_voidSendSlaveAdd_WriteRequest(local_u8Add);
		TWI_voidWriteMasterDataByte((u8)copy_u16WordAdd);

		TWI_voidSendReapeatedStartCondition();

		TWI_voidSendSlaveAdd_ReadRequest(local_u8Add);

		TWI_voidReadMasterDataByte(copy_u8PtrReceivedData);

		TWI_voidSendStopCondition();

		_delay_ms(5);	// delay to eeprom to store the data
	}
}