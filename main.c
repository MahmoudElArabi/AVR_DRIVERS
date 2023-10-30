/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"


int main() {
	Port_Init(pins);
	Dio_WriteChannel(PA_4, STD_LOW);

	SPI_voidInit();
	u8 data_received = 0 ;

	while (1)
	{
		Dio_WriteChannel(PB_4, STD_HIGH);
		_delay_ms(1);
		Dio_WriteChannel(PB_4, STD_LOW);
		SPI_u8Transeive(2, &data_received);
		if(data_received == 70)
		{
			Dio_FlipChannel(PA_5);
		}
		_delay_ms(100);
	}
	return 0;
}
