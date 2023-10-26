/*
 * PORT.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_PORT_PORT_INTERFACE_H_
#define MCAL_PORT_PORT_INTERFACE_H_

/* ----------------- Section : includes -----------------*/

#include "../DIO/DIO_Interfance.h"
#include "PORT_Registers.h"


/* ----------------- Section : Macro Declarations -----------------*/



/* ----------------- Section : Data types Declarations -----------------*/

typedef struct {
		Dio_PortType Port;
		Dio_PinType Pin;
		Dio_DirectionType Direction;
}Pin_ConfigType;


/* ----------------- Section : Software Interfaces Declaration -----------------*/

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
void Port_Init (Pin_ConfigType *pins_cfg);

/**
 * Port_SetPinDirection : This function Write a level on a whole PORT (8 pins)
 * @param	1- Pin 			-> to choose the PIN to set its Direction  EX: (PA_2)
 * 			2- Direction 	-> to choose the Direction to the PIN  	Ex : (1 for HIGH or 0 for LOW)
 * @return	void
 */
void Port_SetPinDirection (Dio_ChannelType Pin,Dio_DirectionType Direction);

#endif /* MCAL_PORT_PORT_INTERFACE_H_ */
