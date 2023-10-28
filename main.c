/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"


int main() {
	Port_Init(pins);
	lcd4_Init();

	ADC_void_Init();

	u16 retval = 0;
	while (1)
	{
		retval = ADC_void_Read_CH(ADC1_SE);
		lcd4_disply_num(retval);
		_delay_ms(100);
		lcd4_CLR();
	}
	return 0;
}

