/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"

int main() {
	Port_Init(pins);
	TMR1_voidInit();
	TMR1_voidStart();
	while (1)
	{
	TMR1_voidSetDuty_Mode14(5);		//-90
	_delay_ms(1000);
	TMR1_voidSetDuty_Mode14(7.5);	//0
	_delay_ms(1000);
	TMR1_voidSetDuty_Mode14(10);	//90
	_delay_ms(1000);
	}
	return 0;
}
