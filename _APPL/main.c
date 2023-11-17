/*
 *  main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"

u8 duty = 0;
u32 freq = 0;

int main ()
{
	Port_Init(pins);
	lcd4_Init();

	GI_voidEnable();
	ICU_voidInit();

	ICU_voidGetDutyCycle(&duty);
	ICU_voidGetFrequency(&freq);

	while(1)
	{
		lcd4_disply_num(duty);
		lcd4_disply_char('_');
		lcd4_disply_num(freq);
		_delay_ms(100);
	}
}

