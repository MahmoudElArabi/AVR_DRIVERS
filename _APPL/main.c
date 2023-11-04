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
	Keypad_Init();
	EEPROM_Init();

	u8 receiveddata = 0;
	u8 arrsend[4] = {0};
	u8 received[4] ={0};
	u8 key;
	u16 number = 0;


	EEPROM_voidRead_Byte(0x50, &receiveddata);
	if (receiveddata == 0xFF) {
		lcd4_disply_string(
				(u8*) "It's your 1st time! Please Enter 4digits to setup your new  password:");
		while (1) {
			Keypad_Get_value(&key);
			if (key != 'T' && key != '#') {
				number = number * 10 + (key - '0');
				lcd4_set_cursor(4, 11);
				lcd4_disply_num(number);
			}
			if (key == '#') {
				for (int i = 0; i < 4; i++) {
					arrsend[3 - i] = number % 10;
					number /= 10;
				}
				lcd4_CLR();
				EEPROM_voidWrite_Page(0x50, arrsend, 4);
				lcd4_disply_string(
						(u8*) " PASSWORD CONFIRMED!  TAP BTN0 to RESTART!");
			}
		}
	}

	else {

		lcd4_disply_string((u8*) "Welcome back! Please Enter your password:");
		u8 trial = 3;
		label:
		while (1) {
			Keypad_Get_value(&key);
			if (key != 'T' && key != '#') {
				number = number * 10 + (key - '0');
				lcd4_set_cursor(4, 11);
				lcd4_disply_num(number);
			}
			if (key == '#') {
				for (int i = 0; i < 4; i++) {
					arrsend[3 - i] = number % 10;
					number /= 10;
				}
				lcd4_CLR();
				EEPROM_voidRead_Page(0x50 , received, 4);


				if ((received[0] == arrsend[0]) && (received[1] == arrsend[1])
						&& (received[2] == arrsend[2])
						&& (received[3] == arrsend[3])) {
					lcd4_disply_string((u8*) "DOOR OPEN , Closed in 4 Sec");
					SET_BIT(_DDRD, 5);
					SRVM_voidOn(0);
					_delay_ms(4000);
					SRVM_voidOn(90);
					lcd4_CLR();
					lcd4_disply_string((u8*) "DOOR  DOOR CLOSED ");
				}
				else {
					lcd4_CLR();
					lcd4_disply_string((u8*) "WRONG!! remain");
					trial--;
					lcd4_disply_num(trial);
					if (trial == 0)
					{
						Dio_WriteChannel(PC_7, 1);
						Dio_WriteChannel(PB_7, 1);
						_delay_ms(500000);
					}
					goto label;
				}
			}
		}
	}
}
