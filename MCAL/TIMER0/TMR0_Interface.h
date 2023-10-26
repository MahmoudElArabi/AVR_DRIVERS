/*
 * TMR0_Interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER0_TMR0_INTERFACE_H_
#define MCAL_TIMER0_TMR0_INTERFACE_H_

#include "../PORT/PORT_Interface.h"
#include "TMR0_Config.h"
#include "TMR0_Register.h"

typedef enum
{
	Normal,
	FastPWM,
	CTC
}TMR0_mode;

void TMR0_voidInit(void);
void TMR0_voidStart(void); // pre-scaler would be configured in TMR0_Config.h
void TMR0_voidStop(void);

void TMR0_Preload_value_set(u8 value);

void TMR0_voidSendCallBack_OVF(void (*PtrF)(void));
void TMR0_voidSendCallBack_OCM(void (*PtrF)(void));

void TMR0_voidSetDelay_ms_using_CTC(u16 _del_ms);
void TMR0_voidSetDutyCycle_using_FastPWM(u8 copy_u8_duty);

#endif /* MCAL_TIMER0_TMR0_INTERFACE_H_ */
