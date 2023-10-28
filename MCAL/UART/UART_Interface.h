/*
 * UART_Interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "UART_Config.h"
#include "UART_Registers.h"
#include "../PORT/PORT_Interface.h"

/* ----------------- Section : Macro Declarations -----------------*/


/* ----------------- Section : Data types Declarations -----------------*/


/* ----------------- Section : Software Interfaces Declaration -----------------*/
void UART_Init();
void UART_TransmitData(u8 data);
u8 UART_ReceiveData();


#endif /* MCAL_UART_UART_INTERFACE_H_ */
