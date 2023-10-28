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
	DCM_voidOn(0);
	DCM_voidControlSpeed(100);
	while (1)
	{
		if(GET_BIT(_PINA, 5)){
			DCM_voidOff();
		}
	}
	return 0;
}
