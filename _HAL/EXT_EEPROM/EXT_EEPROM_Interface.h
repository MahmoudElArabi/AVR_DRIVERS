/*
 * EXT_EEPROM_Interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_EXT_EEPROM_EXT_EEPROM_INTERFACE_H_
#define HAL_EXT_EEPROM_EXT_EEPROM_INTERFACE_H_


/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

/* ----------------- Section : Software Interfaces Declaration -----------------*/
void EEPROM_Init(void);

void EEPROM_voidWrite_Byte(u16 copy_u16WordAdd, u8 copy_u8Data);

void EEPROM_voidRead_Byte(u16 copy_u16WordAdd, u8 *copy_u8PtrReceivedData);


void EEPROM_voidWrite_Page(u16 startWordAddress, u8 *data, u8 dataSize);
void EEPROM_voidRead_Page(u16 startWordAddress, u8 *receivedData, u8 dataSize) ;


#endif /* HAL_EXT_EEPROM_EXT_EEPROM_INTERFACE_H_ */
