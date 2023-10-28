/*
 * DCM_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "DCM_Interface.h"


/*------------------- Statics -------------------------*/
static u8 timerInitialized = 0;		// the purpose of it is to init TMR0 only once


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * DCM_voidOn : used to turn on a DC motor using an H-Bridge motor driver on FARES PCB Kit
 * @param	Copy_u8Direction --> the desired direction of the motor --> [DCM_CLOCK_WISE or DCM_COUNTER_CLOCK_WISE]
 * @return	void
 */
void DCM_voidOn(u8 Copy_u8Direction)
{
	Dio_WriteChannel(DC_MOTOR_EN_PIN, 1);
	DCM_voidControlSpeed(100);
	switch(Copy_u8Direction)
	{
	case DCM_CLOCK_WISE:
		Dio_WriteChannel(DC_MOTOR_DIR_PIN, 1);
		break;
	case DCM_COUNTER_CLOCK_WISE:
		Dio_WriteChannel(DC_MOTOR_DIR_PIN, 0);
		break;
	default: break;
	}
}

/**
 * DCM_voidControlSpeed : control the speed of a DC motor connected to an H-Bridge motor driver using PWM from TIMERS
 * @param	Copy_u8Speed --> [0 : 100] the desired speed of the motor. Ranges from 0  to 100
 * @return	void
 */
void DCM_voidControlSpeed(u8 Copy_u8Speed)
{
	if (timerInitialized == 0)
	{
		TMR0_voidInit();
		timerInitialized = 1;  // Set the flag to indicate initialization
	}
	TMR0_voidSetDutyCycle(Copy_u8Speed);
	TMR0_voidStart();
}

/**
 * DCM_voidOff : used to turn off a DC motor using an H-Bridge motor driver on FARES PCB Kit
 * @param	void
 * @return	void
 */
void DCM_voidOff(void)
{
	TMR0_voidStop();
	timerInitialized =0;
	Dio_WriteChannel(DC_MOTOR_EN_PIN, 0);
}
