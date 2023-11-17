/*
 * TMR1_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/BIT_MATH.h"
#include "../../_MY_LIBS/STD_TYPES.h"

#include "ICU_Interface.h"
#include "ICU_Register.h"


/* ----------------- Section : Static "Private" Functions Declaration / Functions pointers -----------------*/
volatile static u16 private_u16_On_Period ;
volatile static u16 private_u16_Off_Period ;

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void ICU_voidInit(void)
{
	// Timer 1 mode --> Normal
	CLR_BIT(_TCCR1A, _WGM10);
	CLR_BIT(_TCCR1A, _WGM11);
	CLR_BIT(_TCCR1B, _WGM12);
	CLR_BIT(_TCCR1B, _WGM13);
#if ICU_Starting_Edge == FAIILING
	// Edge select --> Falling
	CLR_BIT(_TCCR1B, _ICES1);
#elif ICU_Starting_Edge == RISING
	SET_BIT(_TCCR1B, _ICES1);
#endif
	// ICU Interrupt Enable
	SET_BIT(_TIMSK, _TICIE1);

	// Start Timer  --> for 64 prescaler
	SET_BIT(_TCCR1B, _CS10);
	SET_BIT(_TCCR1B, _CS11);
	CLR_BIT(_TCCR1B, _CS12);

}

void ICU_voidGetDutyCycle(u8 * copy_u8_duty)
{
	if(copy_u8_duty != NULL)
	{
		*copy_u8_duty = ((u32) private_u16_On_Period * 100 ) / (private_u16_On_Period + private_u16_Off_Period);
	}
}

void ICU_voidGetFrequency(u32 * copy_u32_freq_HZ)
{
	if(copy_u32_freq_HZ != NULL)
	{
		*copy_u32_freq_HZ = 1000000UL / (private_u16_On_Period + private_u16_Off_Period);		// 1 S = 1000000 us
	}
}


/* ----------------- Section : ISRs -----------------*/

//ICU ISR
void __vector_6(void) __attribute__((signal));

void __vector_6(void)
{
	static u8 local_edge_falg = ICU_Starting_Edge;
	static u16 local_u16_OldValue = 0 ;
	static u16 local_u16_CounterValue = 0 ;

	local_u16_CounterValue = _ICR1;

	if(local_edge_falg == RISING)
	{
		private_u16_Off_Period = (local_u16_CounterValue - local_u16_OldValue) * 4;   // 4 : tick time for 64 prescaler
		CLR_BIT(_TCCR1B, _ICES1);
		local_edge_falg = FALLING;
	}
	else if(local_edge_falg == FALLING)
	{
		private_u16_On_Period = (local_u16_CounterValue - local_u16_OldValue) * 4;   // 4 : tick time for 64 prescaler
		SET_BIT(_TCCR1B, _ICES1);
		local_edge_falg = RISING;
	}
	local_u16_OldValue = _ICR1;
}
