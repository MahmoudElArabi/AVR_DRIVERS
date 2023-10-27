/*
 * DCM_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "DCM_Interface.h"

/* ----------------- Section : Static "Private" Functions Declaration / Globals -----------------*/



/* ----------------- Section : Software Interfaces Implementation -----------------*/

void DCM_voidInit(void)
{
	Pin_ConfigType H_bridge_pins[] =
	{
		{Dio_PORTB, pin_3, STD_OUT},
		{Dio_PORTB, pin_5, STD_OUT},
		{Dio_PORTB, pin_6, STD_OUT},
		{-1}
	};
	Port_Init(H_bridge_pins);
#if 	DCM_timer	==	TMR0
//	TMR0_voidInit();
#elif	DCM_timer	==	TMR1

#elif	DCM_timer	==	TMR2

#endif //DCM_timer
}

void DCM_voidOn(u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	case DCM_CLOCK_WISE:
		Dio_WriteChannel(PB_5, 1);
		break;
	case DCM_COUNTER_CLOCK_WISE:
		Dio_WriteChannel(PB_5, 0);
		break;
	default: break;
	}
	Dio_WriteChannel(PB_6, 1);
	Dio_WriteChannel(PB_3, 1);
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/
}

void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
	/* Controlling DC motor speed using PWM
	mode from TMR0 by setting Duty Cycle*/
}


void DCM_voidOff(void)
{
	/* Turn DC motor off using H-Bridge
	   By Setting Enable pin with low */
}

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/
