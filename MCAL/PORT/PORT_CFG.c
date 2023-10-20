/*
 * PORT_CFG.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#include "PORT.h"
#include "PORT_CFG.h"

Pin_ConfigType pins_cfg[] =
{
		{Dio_PORTC, pin_7, STD_OUT },
		{Dio_PORTC, pin_2, STD_OUT },
		{Dio_PORTA, pin_3, STD_OUT },
		{Dio_PORTB, pin_3, STD_OUT },
		{Dio_PORTD, pin_3, STD_OUT },
		{Dio_PORTA, pin_1, STD_OUT }
};
