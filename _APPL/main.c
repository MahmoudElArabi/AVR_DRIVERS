/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"
#include <util/delay.h>



int main() {
	Port_Init(pins);
	lcd4_Init();

	EEPROM_Init();

	u8 received =0;

	u8 arr[4] = {1,4,5,7};

	EEPROM_voidWrite_Page(0x50, arr, 4);
	EEPROM_voidRead_Byte((u8)3 + 0x50 , &received);
	lcd4_disply_num(received);

	while(1)
	{

	}
}
