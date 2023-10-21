/*
 * PORT.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */


#include "PORT.h"



void Port_Init (Pin_ConfigType *pins_cfg)
{
	for(int i = 0 ; i < 32 ; i ++)
	{
		if((pins_cfg[i].Port) == -1){
			break;
		}
		switch(pins_cfg[i].Port)
		{
		case Dio_PORTA:
			if((pins_cfg[i].Direction) == STD_OUT)
				SET_BIT(DDRA, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRA, pins_cfg[i].Pin);
			break;
		case Dio_PORTB:
			if((pins_cfg[i].Direction) == STD_OUT)
				SET_BIT(DDRB, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRB, pins_cfg[i].Pin);
			break;
		case Dio_PORTC:
			if((pins_cfg[i].Direction) == STD_OUT)
				SET_BIT(DDRC, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRC, pins_cfg[i].Pin);
			break;
		case Dio_PORTD:
			if((pins_cfg[i].Direction) == STD_OUT)
				SET_BIT(DDRD, pins_cfg[i].Pin);
			else
				CLR_BIT(DDRD, pins_cfg[i].Pin);
			break;
		default: break;
		}
	}
}

void Port_SetPinDirection (Dio_ChannelType Pin,Dio_DirectionType Direction)
{
	switch(Pin/8)
	{
	case Dio_PORTA:
		if(Direction == STD_OUT)
			SET_BIT(DDRA, Pin);
		else
			CLR_BIT(DDRA, Pin);
		break;
	case Dio_PORTB:
		if(Direction == STD_OUT)
			SET_BIT(DDRB, Pin % 8);
		else
			CLR_BIT(DDRB, Pin % 8);
		break;
	case Dio_PORTC:
		if(Direction == STD_OUT)
			SET_BIT(DDRC, Pin % 8);
		else
			CLR_BIT(DDRC, Pin % 8);
		break;
	case Dio_PORTD:
		if(Direction == STD_OUT)
			SET_BIT(DDRD, Pin % 8);
		else
			CLR_BIT(DDRD, Pin % 8);
		break;
	default:	break;
	}
}
