/*
 * TMR2_Interface.h
 *
 *  Created on: Oct 26, 2223
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER2_TMR2_INTERFACE_H_
#define MCAL_TIMER2_TMR2_INTERFACE_H_

/* ----------------- Section : includes -----------------*/

#include "../PORT/PORT_Interface.h"
#include "TMR2_Config.h"
#include "TMR2_Registers.h"


/* ----------------- Section : Data types Declarations -----------------*/

typedef enum
{
	Normal2,
	FastPWM2,
	CTC2,
	Phase_Correct_PWM2
}TMR2_mode;


/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * TMR2_voidInit : Initializes Timer 2 (TMR2) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR2_voidInit(void);

/**
 * TMR2_voidStart : Starts ( begin the counting ) Timer 2 (TMR2) operation
 * @param	void
 * @return	void
 */
void TMR2_voidStart(void);

/**
 * TMR2_voidStop : Stops ( halt  the counting ) Timer 2 (TMR2) operation
 * @param	void
 * @return	void
 */
void TMR2_voidStop(void);

/**
 * TMR2_Preload_value_set : Sets the initial preload value for Timer 2 (TMR2)
 * @param	value: The preload value to be set
 * @return	void
 */
void TMR2_Preload_value_set(u8 value);

/**
 * TMR2_voidSetDelay_ms_using_CTC : Sets a delay in milliseconds using Timer 2 (TMR2) in Clear Timer on Compare Match (CTC) mode
 * @param	_del_ms:  The desired delay in milliseconds
 * @return	void
 */
void TMR2_voidSetDelay_ms_using_CTC(u16 _del_ms);

/**
 * TMR2_voidSetDutyCycle : Sets the duty cycle for Timer 2 (TMR2) in (Fast PWM or Phase Correct PWM)
 * 						   and inverting or non-inverting mode
 * @param	copy_u8_duty:  The desired duty cycle expressed as a percentage (2 to 122)
 * @return	void
 */
void TMR2_voidSetDutyCycle(u8 copy_u8_duty);

/*********** Call Back Functions *********/
/**
 * TMR2_voidSendCallBack_OVF : Sets an overflow callback function for Timer 2 (TMR2)
 * @param	PtrF: A pointer to the overflow callback function
 * @return	void
 */
void TMR2_voidSendCallBack_OVF(void (*PtrF)(void));

/**
 * TMR2_voidSendCallBack_OCM : Sets an output compare match callback function for Timer 2 (TMR2)
 * @param	PtrF: A pointer to the output compare match callback function
 * @return	void
 */
void TMR2_voidSendCallBack_OCM(void (*PtrF)(void));


#endif /* MCAL_TIMER2_TMR2_INTERFACE_H_ */
