/*
 * SRVM_Program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "SRVM_Interface.h"
#include "../../_HAL/DCMotor/DCM_Interface.h"
#include "../../_MCAL/TIMER1/TMR1_Interface.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/*------------------- Statics -------------------------*/
static u8 timer1Initialized = 0;		// the purpose of it is to init TMR0 only once

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void SRVM_voidOn(u8 Copy_u8Angle)
{
	if (timer1Initialized == 0)
	{
	/* TMR1 init at pwm mode 14 */
	TMR1_voidInit();

	timer1Initialized = 1;
	}

	/* Set pwm duty cycle between 5 : 10
	 depend on desired angle[0 : 180] */
	f32 duty_cycle = (f32) ( 5 + (Copy_u8Angle *(5/ 180.0) ));
	TMR1_voidSetDuty_Mode14(duty_cycle);

	/* TMR1 start */
	TMR1_voidStart();
}


void SRVM_voidOff(void)
{
	/* TMR1 stop */
	TMR1_voidStop();
}
