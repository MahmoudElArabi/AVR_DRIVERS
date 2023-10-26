/*
 * main_h.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MAIN_H_H_
#define MAIN_H_H_

#include "HAL/7SEGMENTS/7SEG_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/GI/GI_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/PORT/PORT_Interface.h"
#include "MCAL/TIMER0/TMR0_Interface.h"
#include "MCAL/TIMER2/TMR2_Interface.h"

Pin_ConfigType pins[] =
	{
		{Dio_PORTB, pin_3, STD_OUT},
		{Dio_PORTA, pin_5, STD_OUT},
		{-1}
	};

#endif /* MAIN_H_H_ */
