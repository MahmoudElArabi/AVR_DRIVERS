/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"

u8 key = 'T';
int main() {
	Port_Init(pins);
	Keypad_Init();
	lcd4_Init();
	while (1)
	{
		Keypad_Get_value(&key);
		if (key!='T')
		{
			lcd4_disply_char(key);
			key='T';
		}
	}
	return 0;
}
