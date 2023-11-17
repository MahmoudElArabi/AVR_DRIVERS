/*
 *  main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"

u8 duty;
u32 freq;
u8 d ;


int main() {
	Port_Init(pins);
	GI_voidEnable();
	lcd4_Init();
	ICU_voidInit();

    while (1)
    {
    	Dio_WriteChannel(PD_0, 1);
    	_delay_us(10);
    	Dio_WriteChannel(PD_0, 0);
    	_delay_ms(60);

    	d = ICU_u32GetFallingEdgeTime() / 58;
    	lcd4_disply_num(d);
    	_delay_ms(50);
    	lcd4_CLR();
    }
}


