/*
 * PORT.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */


#include "PORT.h"
#include "PORT_CFG.h"

extern Pin_ConfigType pins_cfg[32];

void Port_Init ()
{
	for(int i = 0 ; i < pins_nums ; i ++)
	{
		switch(pins_cfg[i].Port)
		{
		case Dio_PORTA:
			if(pins_cfg[i].Direction == STD_OUT)
				SET_BIT(DDRA, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRA, pins_cfg[i].Pin);
			break;
		case Dio_PORTB:
			if(pins_cfg[i].Direction == STD_OUT)
				SET_BIT(DDRB, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRB, pins_cfg[i].Pin);
			break;
		case Dio_PORTC:
			if(pins_cfg[i].Direction == STD_OUT)
				SET_BIT(DDRC, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRC, pins_cfg[i].Pin);
			break;
		case Dio_PORTD:
			if(pins_cfg[i].Direction == STD_OUT)
				SET_BIT(DDRD, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRD, pins_cfg[i].Pin);
			break;
		default: break;
		}
	}
}
