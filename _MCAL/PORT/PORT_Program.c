/*
 * PORT.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */




/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/BIT_MATH.h"
#include "../../_MY_LIBS/STD_TYPES.h"
#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_Registers.h"
#include "PORT_Interface.h"


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * Port_Init : This function initialize the pins to be output or input
 * 			   Ex: Pin_ConfigType pins[] = 	{ {Dio_PORTA, pin_4, STD_OUT},
 * 			   								{Dio_PORTA, pin_5, STD_OUT},
 * 			   								{Dio_PORTA, pin_6, STD_IN},
 * 			   								{-1}	};
 * 			   		when I pass a pointer to this array of structures,
 * 			   		the function will make PA_4, PA_5 as Output  and PA_6 as Input
 * @param	1- Pin_ConfigType *pins_cfg 	-> which is a pointer to a structure of data type "Pin_ConfigType"
 * @return	void
 */
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
			{
				SET_BIT(_DDRA, pins_cfg[i].Pin);
			}
			else
			{
				CLR_BIT(_DDRA, pins_cfg[i].Pin);
				SET_BIT(_PORTA, pins_cfg[i].Pin);
			}
			break;
		case Dio_PORTB:
			if((pins_cfg[i].Direction) == STD_OUT)
			{
				SET_BIT(_DDRB, pins_cfg[i].Pin);
			}
			else
			{
				CLR_BIT(_DDRB, pins_cfg[i].Pin);
				SET_BIT(_PORTB, pins_cfg[i].Pin);
			}
			break;
		case Dio_PORTC:
			if((pins_cfg[i].Direction) == STD_OUT)
			{
				SET_BIT(_DDRC, pins_cfg[i].Pin);
			}
			else
			{
				CLR_BIT(_DDRC, pins_cfg[i].Pin);
				SET_BIT(_PORTC, pins_cfg[i].Pin);
			}
			break;
		case Dio_PORTD:
			if((pins_cfg[i].Direction) == STD_OUT)
			{
				SET_BIT(_DDRD, pins_cfg[i].Pin);
			}
			else
			{
				CLR_BIT(_DDRD, pins_cfg[i].Pin);
				SET_BIT(_PORTD, pins_cfg[i].Pin);
			}
			break;
		default: break;
		}
	}
}

/**
 * Port_SetPinDirection : This function Write a level on a whole PORT (8 pins)
 * @param	1- Pin 			-> to choose the PIN to set its Direction  EX: (PA_2)
 * 			2- Direction 	-> to choose the Direction to the PIN  	Ex : (1 for HIGH or 0 for LOW)
 * @return	void
 */
void Port_SetPinDirection (Dio_ChannelType Pin,Dio_DirectionType Direction)
{
	switch(Pin/8)
	{
	case Dio_PORTA:
		if(Direction == STD_OUT)
			SET_BIT(_DDRA, Pin);
		else
			CLR_BIT(_DDRA, Pin);
		break;
	case Dio_PORTB:
		if(Direction == STD_OUT)
			SET_BIT(_DDRB, Pin % 8);
		else
			CLR_BIT(_DDRB, Pin % 8);
		break;
	case Dio_PORTC:
		if(Direction == STD_OUT)
			SET_BIT(_DDRC, Pin % 8);
		else
			CLR_BIT(_DDRC, Pin % 8);
		break;
	case Dio_PORTD:
		if(Direction == STD_OUT)
			SET_BIT(_DDRD, Pin % 8);
		else
			CLR_BIT(_DDRD, Pin % 8);
		break;
	default:	break;
	}
}
