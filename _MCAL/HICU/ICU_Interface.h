/*
 * TMR1_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_HICU_INTERFACE_H_
#define MCAL_HICU_INTERFACE_H_


/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

#define RISING	1
#define FALLING	2

#define ICU_Starting_Edge	RISING

/* ----------------- Section : Data types Declarations -----------------*/
void ICU_voidInit(void);
void ICU_voidGetDutyCycle(u8 * copy_u8_duty);
void ICU_voidGetFrequency(u32 * copy_u32_freq_hz);


#endif /* MCAL_HICU_INTERFACE_H_ */
