/*
 * TMR0_Program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "TMR0_Interface.h"

/***********************/
static volatile u16 private_CTC_counter = 0;
/***********************/
static void (*privatePTR_OV) (void) = NULL;
static void (*privatePTR_OC) (void) = NULL;
static void select_mode(u8 mode);
static void Enable_OVI(void);
static void Enable_OCI(void);
static void PrescalerValue_set(u16 value);
static void TMR0_Compare_match_value_set(u8 value);

/***********************/

void TMR0_voidInit(void)
{
#if TMR0_MODE 	== TMR0_NORMAL_MODE
	select_mode(Normal);
	Enable_OVI();
	TMR0_Preload_value_set(TMR0_PRELOAD);
#elif TMR0_MODE == TMR0_CTC_MODE
	select_mode(CTC);
	Enable_OCI();
	TMR0_Compare_match_value_set(TMR0_OCR0_val);
#elif TMR0_MODE == TMR0_FastPWM_MODE
	select_mode(FastPWM);
	switch(Fast_PWM_MODE)
	{
	case non_inverting:
		CLR_BIT(_TCCR0, 4);
		SET_BIT(_TCCR0, 5);
		break;
	case inverting:
		SET_BIT(_TCCR0, 4);
		SET_BIT(_TCCR0, 5);
		break;
	}
#endif
}

void TMR0_voidStart(void)
{
	PrescalerValue_set((u16)TMR0_PRESCALER);
}

void TMR0_voidStop(void)
{
	CLR_BIT(_TCCR0,0);
	CLR_BIT(_TCCR0,1);
	CLR_BIT(_TCCR0,2);
}

void TMR0_Preload_value_set(u8 value)
{
	_TCNT0 = value;
}

void TMR0_voidSendCallBack_OVF(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OV = PtrF;
	}
}

void TMR0_voidSendCallBack_OCM(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OC = PtrF;
	}
}

void TMR0_voidSetDelay_ms_using_CTC(u16 _del_ms)
{
#if TMR0_PRESCALER == 1
	private_CTC_counter = (_del_ms*1000) / ((TMR0_OCR0_val + 1) * 0.0625);
#elif TMR0_PRESCALER == 8
	private_CTC_counter = (_del_ms*1000) / ((TMR0_OCR0_val + 1) * 0.5);
#elif TMR0_PRESCALER == 64
	private_CTC_counter = (_del_ms*1000) / ((TMR0_OCR0_val + 1) * 4);
#elif TMR0_PRESCALER == 256
	private_CTC_counter = (_del_ms*1000) / ((TMR0_OCR0_val + 1) * 16);

#elif TMR0_PRESCALER == 1024
	private_CTC_counter = (_del_ms*1000) / ((TMR0_OCR0_val + 1) * 64);
#endif
}

void TMR0_voidSetDutyCycle_using_FastPWM(u8 copy_u8_duty)
{
	if(copy_u8_duty <= 100)
	{
#if Fast_PWM_MODE == non_inverting
		if(copy_u8_duty == 0){
			_OCR0 = 0;
		}
		else{
			_OCR0 = (((u16)copy_u8_duty * 256) / 100) -1;
		}
#elif Fast_PWM_MODE == inverting
		if(copy_u8_duty == 100){
			_OCR0 = 0;
		}
		else{
			copy_u8_duty = 100 - copy_u8_duty;
			_OCR0 = (((u16)copy_u8_duty * 256) / 100) -1;
		}
#endif
	}
}
/************** private implementation **************/
static void select_mode(u8 mode)
{
	switch(mode)
	{
	case Normal:
		CLR_BIT(_TCCR0, 3);
		CLR_BIT(_TCCR0, 6);
		break;
	case FastPWM:
		SET_BIT(_TCCR0, 3);
		SET_BIT(_TCCR0, 6);
		break;
	case CTC:
		SET_BIT(_TCCR0, 3);
		CLR_BIT(_TCCR0, 6);
		break;
	}
}

static void Enable_OVI(void)
{
	SET_BIT(_TIMSK, 0);
}

static void Enable_OCI(void)
{
	SET_BIT(_TIMSK, 1);
}

static void PrescalerValue_set(u16 value)
{
	switch(value)
	{
	case 0:
		SET_BIT(_TCCR0,0);
		CLR_BIT(_TCCR0,1);
		CLR_BIT(_TCCR0,2);
		break;
	case 8:
		CLR_BIT(_TCCR0,0);
		SET_BIT(_TCCR0,1);
		CLR_BIT(_TCCR0,2);
		break;
	case 64:
		SET_BIT(_TCCR0,0);
		SET_BIT(_TCCR0,1);
		CLR_BIT(_TCCR0,2);
		break;
	case 256:
		CLR_BIT(_TCCR0,0);
		CLR_BIT(_TCCR0,1);
		SET_BIT(_TCCR0,2);
		break;
	case 1024:
		SET_BIT(_TCCR0,0);
		CLR_BIT(_TCCR0,1);
		SET_BIT(_TCCR0,2);
		break;
	}
}

static void TMR0_Compare_match_value_set(u8 value)
{
	_OCR0 = value;
}

/************* TMR0_ISR ***********/

//NORMAL
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 count = 0;
	count ++;
	if(count == TMR0_OVERFLOW)
	{
		TMR0_Preload_value_set(113);
		count = 0;
		if(privatePTR_OV !=NULL)
			{
				privatePTR_OV();
			}
	}

}

//CTC
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 count = 0;
	count ++;
	if(count == private_CTC_counter)
	{
		count = 0;
		if(privatePTR_OC !=NULL)
			{
			privatePTR_OC();
			}
	}
}
