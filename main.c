/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#include "MCAL/PORT/PORT.h"
#include "HAL/LCD/LCD.h"
#include "HAL/7SEGMENTS/7SEG.h"


int main()
{
	lcd4_Init();
	lcd4_disply_char('M');
	_delay_ms(200);
	lcd4_disply_char('A');
	_delay_ms(200);
	lcd4_disply_char('H');
	_delay_ms(200);
	lcd4_disply_char('M');
	_delay_ms(200);
	lcd4_disply_char('O');
	_delay_ms(200);
	lcd4_disply_char('U');
	_delay_ms(200);
	lcd4_disply_char('D');
	_delay_ms(200);
	lcd4_disply_char('_');
	_delay_ms(200);
	lcd4_disply_char('A');
	_delay_ms(200);
	lcd4_disply_char('R');
	_delay_ms(200);
	lcd4_disply_char('A');
	_delay_ms(200);
	lcd4_disply_char('B');
	_delay_ms(200);
	lcd4_disply_char('Y');
	_delay_ms(200);
	lcd4_disply_char('!');
	_delay_ms(350);
	lcd4_CLR();
	_delay_ms(350);
	lcd4_disply_char('.');
	_delay_ms(350);
	lcd4_disply_char('.');
	_delay_ms(350);
	lcd4_disply_char('.');
	_delay_ms(350);
	lcd4_disply_char('.');
	_delay_ms(100);
	lcd4_disply_char('.');
	_delay_ms(110);
	lcd4_disply_char('.');
	_delay_ms(100);
	lcd4_disply_char('.');
	_delay_ms(100);
	lcd4_disply_char('.');
	_delay_ms(100);
	lcd4_disply_char('.');
	_delay_ms(300);
	lcd4_disply_char('.');
	lcd4_CLR();
	lcd4_disply_char_at_X_Y('>', 2,3);
	lcd4_disply_char('>');
	lcd4_disply_char('>');
	lcd4_disply_char_at_X_Y('<', 2,16);
	lcd4_disply_char('<');
	lcd4_disply_char('<');
	_delay_ms(350);
	lcd4_disply_char_at_X_Y('N', 2,6);
	lcd4_disply_string("TI_GROUP2");
	lcd4_disply_char_at_X_Y('M', 3,3);
	lcd4_disply_string("ahmoud El Arabi");
	while(1)
	{

	}
}
