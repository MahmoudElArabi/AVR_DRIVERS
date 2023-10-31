/*
 * SPI_interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "SPI_Config.h"
#include "SPI_Registers.h"
#include "../PORT/PORT_Interface.h"

/* ----------------- Section : Software Interfaces Declaration -----------------*/
void SPI_voidInit(void);
void SPI_voidTranseive(u8 copy_u8_TX_data, u8 * copy_u8_RX_data);

void SPI_voidTransmit_Async(u8 copy_u8_TX_data, void(*PtrFunc)(u8 copy_u8_RX_data));


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
