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

void DCM_voidOn(u8 Copy_u8Direction)
{
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/
	Dio_WriteChannel(PB_6, 1);
	Dio_WriteChannel(PB_3, 1);
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
}

void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
//	Dio_WriteChannel(PB_6, 0);
	TMR0_voidInit();
	TMR0_voidStart();
	TMR0_voidSetDutyCycle(Copy_u8Speed);
}


void DCM_voidOff(void)
{
	/* Turn DC motor off using H-Bridge
	   By Setting Enable pin with low */
	Dio_WriteChannel(PB_6, 0);
}

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/
