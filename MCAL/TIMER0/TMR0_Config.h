/*
 * TMR0_Config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER0_TMR0_CONFIG_H_
#define MCAL_TIMER0_TMR0_CONFIG_H_

#include "TMR0_Private.h"

// Configure TMR0 Mode    --> TMR0_NORMAL_MODE	TMR0_CTC_MODE	TMR0_FastPWM_MODE	TMR0_Phase_Correct_PWM_MODE
#define TMR0_MODE					TMR0_FastPWM_MODE
// Fast_PWM_MODE 		  --> inverting		or	non_inverting
#define Fast_PWM_MODE				non_inverting
// Phase_correct_PWM_MODE --> inverting		or	non_inverting
#define Phase_correct_PWM_MODE		non_inverting

#define TMR0_PRESCALER				64
#define TMR0_PRELOAD				113
#define TMR0_OVERFLOW				977
#define TMR0_OCR0_val				63


#endif /* MCAL_TIMER0_TMR0_CONFIG_H_ */
