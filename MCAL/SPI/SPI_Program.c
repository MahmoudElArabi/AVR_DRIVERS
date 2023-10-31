/*
 * SPI_Program.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "SPI_interface.h"


/* ----------------- Section : STATICS -----------------*/
static void(*Private_pCallback)(u8) = NULL;

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void SPI_voidInit(void)
{
#if SPI_MODE	==	MASTER
   SET_BIT(_SPCR, 4);
   //Clock Rate Prescaler	(Only for master)
   SET_BIT(_SPCR, 0);
   CLR_BIT(_SPCR, 1);
   CLR_BIT(_SPSR, 0);
#elif SPI_MODE	==	SLAVE
   CLR_BIT(_SPCR, 4);
#endif //SPI_MODE

   // Data Order --> LSB:SET	or  MSB:CLEAR
   SET_BIT(_SPCR, 5);

   //POLARITY, PHASE	--> Falling Rising	Setup Sample
   SET_BIT(_SPCR, 3);
   SET_BIT(_SPCR, 2);

   // enable SPI
	SET_BIT(_SPCR, 6);
}

void SPI_voidTranseive(u8 copy_u8_TX_data, u8 * copy_u8_RX_data)
{
	if (copy_u8_RX_data != NULL)
	{
		while(GET_BIT(_SPSR, 6));	// To prevent collision (Writing in buffer while still have the data to be sent
		_SPDR = copy_u8_TX_data;	// write buffer >> Data register
		while(!GET_BIT(_SPSR, 7));	// blocking
		*copy_u8_RX_data =  _SPDR;	// Read data from buffer (Receive)
	}
	else
	{
		return;
	}
}

void SPI_voidTransmit_Async(u8 copy_u8_TX_data, void(*PtrFunc)(u8 copy_u8_RX_data))
{
	if (PtrFunc != NULL)
	{
		// Enable SPI Interrupt
		SET_BIT(_SPCR, 7);

		Private_pCallback = PtrFunc;
		while(GET_BIT(_SPSR, 6));	// To prevent collision (Writing in buffer while still have the data to be sent
		_SPDR = copy_u8_TX_data;	// write buffer >> Data register
	}
	else
	{

	}
}

/* ----------------- Section : ISRs -----------------*/
void __vector_12(void) __attribute__((signal));

void __vector_12(void)
{
	if(Private_pCallback)
	{
		Private_pCallback(_SPDR);
	}
}
