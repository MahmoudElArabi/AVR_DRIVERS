/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */


#include "main_h.h"


int main() {
	Port_Init(pins);
	TMR0_voidInit();
	TMR0_voidStart();
	u8 local = 1;

	while (1) {
		local++;
		if(local == 100)
		{
			local = 0;
		}
		TMR0_voidSetDutyCycle(local);
		_delay_ms(50);
	}
	return 0;
}
