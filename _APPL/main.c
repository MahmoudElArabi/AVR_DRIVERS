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
	SRVM_voidOn(45);
	_delay_ms(500);
	SRVM_voidOn(0);
	_delay_ms(500);
	SRVM_voidOn(25);
	_delay_ms(500);
	SRVM_voidOn(45);
	_delay_ms(500);
	SRVM_voidOn(50);
	_delay_ms(500);
	SRVM_voidOn(90);
	_delay_ms(500);
	SRVM_voidOn(120);
	_delay_ms(500);
	SRVM_voidOn(150);
	_delay_ms(500);
	SRVM_voidOn(160);
	_delay_ms(500);
	SRVM_voidOn(180);
//	TMR1_voidInit();
//	TMR1_voidStart();
//	TMR1_voidSetDuty_Mode14(7.5);	//0

	while(1)
	{
//		TMR1_voidSetDuty_Mode14(5);		//-90
//		_delay_ms(500);
//		TMR1_voidSetDuty_Mode14(7.5);	//0
//		_delay_ms(500);
//		TMR1_voidSetDuty_Mode14(10);	//90
//		_delay_ms(500);
	}
}
