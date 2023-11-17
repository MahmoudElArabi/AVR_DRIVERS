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
    	Ultra_Sonic_void_trigger(PD_0);
    	d = Ultra_Sonic_Distance_in_cm();

    	if(d < 20)
    	{
    		Dio_WriteChannel(PA_4, 1);
    	}
    	else {
    		Dio_WriteChannel(PA_4, 0);
		}
    }
}


