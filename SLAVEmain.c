/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"	//SLAVE

void ACT_SPI(u8 Copy_u8Recrived)
{
	if(Copy_u8Recrived == 2)
	{
		Dio_FlipChannel(PA_4);
	}
}

int main() {
	Port_Init(pins);
	GI_voidEnable();

	SPI_voidInit();

	while (1)
	{
		SPI_voidTransmit_Async(70, ACT_SPI);
		_delay_ms(200);
	}
	return 0;
}
