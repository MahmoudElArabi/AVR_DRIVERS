/*
 * DCM_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_DCMOTOR_DCM_INTERFACE_H_
#define HAL_DCMOTOR_DCM_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "../../MCAL/TIMER0/TMR0_Interface.h"
#include "DCM_Config.h"

/* ----------------- Section : Macro Declarations -----------------*/
#define DCM_CLOCK_WISE                   1
#define DCM_COUNTER_CLOCK_WISE           2

/* ----------------- Section : Software Interfaces Declaration -----------------*/
void DCM_voidInit(void);
void DCM_voidOn          (u8 Copy_u8Direction);
void DCM_voidControlSpeed(u8 Copy_u8Speed);
void DCM_voidOff         (void);

#endif /* HAL_DCMOTOR_DCM_INTERFACE_H_ */
