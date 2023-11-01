/*
 * DCM_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_DCMOTOR_DCM_INTERFACE_H_
#define HAL_DCMOTOR_DCM_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * DCM_voidOn : used to turn on a DC motor using an H-Bridge motor driver on FARES PCB Kit
 * @param	Copy_u8Direction --> the desired direction of the motor --> [DCM_CLOCK_WISE or DCM_COUNTER_CLOCK_WISE]
 * @return	void
 */
void DCM_voidOn          (u8 Copy_u8Direction);

/**
 * DCM_voidControlSpeed : control the speed of a DC motor connected to an H-Bridge motor driver using PWM from TIMERS
 * @param	Copy_u8Speed --> [0 : 100] the desired speed of the motor. Ranges from 0  to 100
 * @return	void
 */
void DCM_voidControlSpeed(u8 Copy_u8Speed);

/**
 * DCM_voidOff : used to turn off a DC motor using an H-Bridge motor driver on FARES PCB Kit
 * @param	void
 * @return	void
 */
void DCM_voidOff         (void);

#endif /* HAL_DCMOTOR_DCM_INTERFACE_H_ */
