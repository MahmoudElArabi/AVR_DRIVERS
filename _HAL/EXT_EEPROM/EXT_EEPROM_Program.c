/*
 * EXT_EEPROM_Program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "EXT_EEPROM_Private.h"
#include "../../_MCAL/TWI/TWI_Registers.h"
#include "../../_MY_LIBS/BIT_MATH.h"
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
		CLR_BIT(_TWCR, _TWEA);
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


void EEPROM_voidWrite_Page(u16 copy_u16WordAdd, u8 *copy_u8Data, u8 copy_u8Size)
{

	u8 local_u8Add = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS ;
	TWI_voidSendStartCondition();
	TWI_voidSendSlaveAdd_WriteRequest(local_u8Add);

	TWI_voidWriteMasterDataByte((u8)copy_u16WordAdd);
	for (int i = 0; i <copy_u8Size ; i++ )
		{
			TWI_voidWriteMasterDataByte(copy_u8Data[i]);
		}

	TWI_voidSendStopCondition();
	_delay_ms(5);	// delay to eeprom to store the data
}

void EEPROM_voidRead_Page(u16 copy_u16WordAdd, u8 *copy_u8PtrReceivedData, u8 copy_u8Size)
{
	SET_BIT(_TWCR, _TWEA);
    u8 local_u8Add = (copy_u16WordAdd >> 8) | EEPROM_FIXED_ADDRESS;
    TWI_voidSendStartCondition();
    TWI_voidSendSlaveAdd_WriteRequest(local_u8Add);
    TWI_voidWriteMasterDataByte((u8)copy_u16WordAdd);

    TWI_voidSendReapeatedStartCondition();

    TWI_voidSendSlaveAdd_ReadRequest(local_u8Add);

    for (int i = 0; i < copy_u8Size; i++)
    {
    	TWI_voidReadMasterDataByteACK(&copy_u8PtrReceivedData[i]);
    	if(i == copy_u8Size -1)
    	{
    		CLR_BIT(_TWCR, _TWEA);
    	}
    }
    TWI_voidSendStopCondition();

    _delay_ms(5);  // Delay for EEPROM to store the data
}






