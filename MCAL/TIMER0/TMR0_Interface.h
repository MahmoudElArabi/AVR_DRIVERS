/*
 * TMR0_Interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER0_TMR0_INTERFACE_H_
#define MCAL_TIMER0_TMR0_INTERFACE_H_


/* ----------------- Section : includes -----------------*/

#include "../PORT/PORT_Interface.h"
#include "TMR0_Config.h"
#include "TMR0_Registers.h"


/* ----------------- Section : Data types Declarations -----------------*/

typedef enum
{
	Normal,
	FastPWM,
	CTC,
	Phase_Correct_PWM
}TMR0_mode;


/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * TMR0_voidInit : Initializes Timer 0 (TMR0) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR0_voidInit(void);

/**
 * TMR0_voidStart : Starts ( begin the counting ) Timer 0 (TMR0) operation
 * @param	void
 * @return	void
 */
void TMR0_voidStart(void);

/**
 * TMR0_voidStop : Stops ( halt  the counting ) Timer 0 (TMR0) operation
 * @param	void
 * @return	void
 */
void TMR0_voidStop(void);

/**
 * TMR0_Preload_value_set : Sets the initial preload value for Timer 0 (TMR0)
 * @param	value: The preload value to be set
 * @return	void
 */
void TMR0_Preload_value_set(u8 value);

/**
 * TMR0_voidSetDelay_ms_using_CTC : Sets a delay in milliseconds using Timer 0 (TMR0) in Clear Timer on Compare Match (CTC) mode
 * @param	_del_ms:  The desired delay in milliseconds
 * @return	void
 */
void TMR0_voidSetDelay_ms_using_CTC(u16 _del_ms);

/**
 * TMR0_voidSetDutyCycle : Sets the duty cycle for Timer 0 (TMR0) in (Fast PWM or Phase Correct PWM)
 * 						   and inverting or non-inverting mode
 * @param	copy_u8_duty:  The desired duty cycle expressed as a percentage (0 to 100)
 * @return	void
 */
void TMR0_voidSetDutyCycle(u8 copy_u8_duty);

/*********** Call Back Functions *********/
/**
 * TMR0_voidSendCallBack_OVF : Sets an overflow callback function for Timer 0 (TMR0)
 * @param	PtrF: A pointer to the overflow callback function
 * @return	void
 */
void TMR0_voidSendCallBack_OVF(void (*PtrF)(void));

/**
 * TMR0_voidSendCallBack_OCM : Sets an output compare match callback function for Timer 0 (TMR0)
 * @param	PtrF: A pointer to the output compare match callback function
 * @return	void
 */
void TMR0_voidSendCallBack_OCM(void (*PtrF)(void));



#endif /* MCAL_TIMER0_TMR0_INTERFACE_H_ */
