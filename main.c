/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"

int main() {
	Port_Init(pins);
	u8 local = 100;
	while (1)
	{
		DCM_voidOn(DCM_CLOCK_WISE);
		_delay_ms(50);
		while(local> 0){
			DCM_voidControlSpeed(local);
			_delay_ms(50);
			local--;
		}
		local = 100;
		_delay_ms(50);
		DCM_voidOn(DCM_COUNTER_CLOCK_WISE);
		_delay_ms(50);
		while(local > 0){
			DCM_voidControlSpeed(local);
			_delay_ms(50);
			local--;
		}
		local = 100;
		_delay_ms(50);
		DCM_voidOff();
		_delay_ms(2000);
	}
	return 0;
}
