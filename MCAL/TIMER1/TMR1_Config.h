/*
 * TMR0_Config.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */

#include "TMR1_Private.h"

#ifndef MCAL_TIMER1_TMR1_CONFIG_H_
#define MCAL_TIMER1_TMR1_CONFIG_H_

#define TMR1_MODE							TMR1_FastPWM_MODE_14
#define TMR1_FastPWM_14_MODE				non_inverting1

#define TMR1_PRESCALER						64
#define TMR1_PRELOAD_VALUE 					65535
#endif /* MCAL_TIMER1_TMR1_CONFIG_H_ */
