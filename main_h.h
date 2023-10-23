/*
 * main_h.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MAIN_H_H_
#define MAIN_H_H_

#include "MCAL/PORT/PORT.h"
#include "HAL/LCD/LCD.h"
#include "HAL/7SEGMENTS/7SEG.h"
#include "MCAL/GI/GI_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

Pin_ConfigType pins[] =
	{
			{Dio_PORTA, pin_4, STD_OUT },
			{Dio_PORTA, pin_5, STD_OUT },
			{Dio_PORTA, pin_6, STD_OUT },
			{-1}
	};

#endif /* MAIN_H_H_ */
