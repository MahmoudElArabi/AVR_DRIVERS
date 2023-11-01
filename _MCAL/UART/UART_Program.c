/*
 * UART_Program.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Registers.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Static "Private" Functions Declaration / Functions pointers -----------------*/


/* ----------------- Section : Software Interfaces Implementation -----------------*/
void UART_Init()
{
	u16 rest = (1000000 /UART_BAUDRATE) - 1;
	_UBRRL = rest;
	switch(UART_SPEED_MODE)
	{
	case ASY_NORMAL_SPEED:
		CLR_BIT(_UCSRA,1);
		break;
	case ASY_DOUPLE_SPEED:
		SET_BIT(_UCSRA,1);
		break;
	case SYN_MASTER_MODE:
		SET_BIT(_UCSRC, 6);
		break;
	}
	// ENABLE RX TX
	SET_BIT(_UCSRB,4);
	SET_BIT(_UCSRB,3);
}

void UART_TransmitData(u8 data)
{
	while(!GET_BIT(_UCSRA,5));
	_UDR = data;
}

u8 UART_ReceiveData()
{
	while(!GET_BIT(_UCSRA,7));
	return _UDR;
}

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/

