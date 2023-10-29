/*
 * TMR1_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER1_TMR1_INTERFACE_H_
#define MCAL_TIMER1_TMR1_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "TMR1_Register.h"
#include "TMR1_Config.h"
#include "../PORT/PORT_Interface.h"

/* ----------------- Section : Macro Declarations -----------------*/

/* ----------------- Section : Data types Declarations -----------------*/
/**
 * TMR1_voidInit : Initializes Timer 1 (TMR1) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR1_voidInit(void);

/**
 * TMR1_voidStart : Starts ( begin the counting ) Timer 1 (TMR1) operation
 * @param	void
 * @return	void
 */
void TMR1_voidStart(void);

/**
 * TMR1_voidStop : Stops ( halt  the counting ) Timer 1 (TMR1) operation
 * @param	void
 * @return	void
 */
void TMR1_voidStop(void);

void TMR1_voidSetFreq_Mode14(u16 copy_u16_frequency);

void TMR1_voidSetDuty_Mode14(f32 copy_u8_duty);
/* ----------------- Section : Software Interfaces Declaration -----------------*/

void TMR1_voidSetCompareMatchValueA(u16 copy_u8CompareMatchValueA);
#endif /* MCAL_TIMER1_TMR1_INTERFACE_H_ */
