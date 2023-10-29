/*
 * TMR2_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/

#include "TMR2_Interface.h"

/* ----------------- Section : Static "Private" Functions / Functions pointers -----------------*/
static u16 private_CTC_counter = 0;

static void (*privatePTR_OV) (void) = NULL;
static void (*privatePTR_OC) (void) = NULL;
static void select_mode(u8 mode);

#if TMR2_MODE 	== TMR2_NORMAL_MODE
static void Enable_OVI2(void);
#elif TMR2_MODE == TMR2_CTC_MODE
static void Enable_OCI2(void);
#endif	// TMR2_MODE

static void PrescalerValue_set(u16 value);


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * TMR2_voidInit : Initializes Timer 2 (TMR2) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR2_voidInit(void)
{
#if TMR2_MODE 	==  TMR2_NORMAL_MODE
	select_mode(Normal2);
	Enable_OVI2();
	TMR2_Preload_value_set(TMR2_PRELOAD);
#elif TMR2_MODE == TMR2_CTC_MODE
	select_mode(CTC2);
	Enable_OCI2();
	_OCR2 = (TMR2_OCR2_val);
#elif TMR2_MODE == TMR2_FastPWM_MODE
	select_mode(FastPWM2);
	switch(Fast_PWM_MODE2)
	{
	case non_inverting2:
		CLR_BIT(_TCCR2, 4);
		SET_BIT(_TCCR2, 5);
		break;
	case inverting2:
		SET_BIT(_TCCR2, 4);
		SET_BIT(_TCCR2, 5);
		break;
	}
#elif TMR2_MODE == TMR2_Phase_correct_PWM_MODE2
	select_mode(Phase_Correct_PWM2);
	switch(Phase_correct_PWM_MODE2)
	{
	case non_inverting2:
		CLR_BIT(_TCCR2, 4);
		SET_BIT(_TCCR2, 5);
		break;
	case inverting2:
		SET_BIT(_TCCR2, 4);
		SET_BIT(_TCCR2, 5);
		break;
	}
#endif	// TMR2_MODE
}

/**
 * TMR2_voidStart : Starts ( begin the counting ) Timer 2 (TMR2) operation
 * @param	void
 * @return	void
 */
void TMR2_voidStart(void)
{
	PrescalerValue_set((u16)TMR2_PRESCALER);
}

/**
 * TMR2_voidStop : Stops ( halt  the counting ) Timer 2 (TMR2) operation
 * @param	void
 * @return	void
 */
void TMR2_voidStop(void)
{
	CLR_BIT(_TCCR2,0);
	CLR_BIT(_TCCR2,1);
	CLR_BIT(_TCCR2,2);
}

/**
 * TMR2_Preload_value_set : Sets the initial preload value for Timer 2 (TMR2)
 * @param	value: The preload value to be set
 * @return	void
 */
void TMR2_Preload_value_set(u8 value)
{
	_TCNT2 = value;
}




/**
 * TMR2_voidSetDelay_ms_using_CTC : Sets a delay in milliseconds using Timer 2 (TMR2) in Clear Timer on Compare Match (CTC) mode
 * @param	_del_ms:  The desired delay in milliseconds
 * @return	void
 */
void TMR2_voidSetDelay_ms_using_CTC(u16 _del_ms)
{
#if   TMR2_PRESCALER == 1
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 0.0625);
#elif TMR2_PRESCALER == 8
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 0.5);
#elif TMR2_PRESCALER == 32
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 2);
#elif TMR2_PRESCALER == 64
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 4);
#elif TMR2_PRESCALER == 128
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 8);
#elif TMR2_PRESCALER == 256
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 16);
#elif TMR2_PRESCALER == 1024
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR2_OCR2_val + 1) * 64);
#endif
}

/**
 * TMR2_voidSetDutyCycle : Sets the duty cycle for Timer 2 (TMR2) in (Fast PWM or Phase Correct PWM)
 * 						   and inverting or non-inverting mode
 * @param	copy_u8_duty:  The desired duty cycle expressed as a percentage (0 to 100)
 * @return	void
 */void TMR2_voidSetDutyCycle(u8 copy_u8_duty)
{
#if TMR2_MODE == TMR2_FastPWM_MODE
	if(copy_u8_duty <= 100)
	{
	#if Fast_PWM_MODE2 == non_inverting2
		if(copy_u8_duty == 0){
			_OCR2 = 0;
		}
		else{
			_OCR2 = (((u16)copy_u8_duty * 256) / 100) -1;
		}
	#elif Fast_PWM_MODE2 == inverting2
		if(copy_u8_duty == 100){
			_OCR2 = 0;
		}
		else{
			copy_u8_duty = 100 - copy_u8_duty;
			_OCR2 = (((u16)copy_u8_duty * 256) / 100) -1;
		}
	#endif	//Fast_PWM_MODE2
	}
#elif TMR2_MODE == TMR2_Phase_correct_PWM_MODE2
	if(copy_u8_duty <= 100)
	{
	#if Phase_correct_PWM_MODE2 == non_inverting2
	_OCR2 = (copy_u8_duty * 256) / 100;
	#elif Phase_correct_PWM_MODE2 == inverting2
	copy_u8_duty = 100 - copy_u8_duty;
	_OCR2 = (((u16)copy_u8_duty * 256) / 100) - 510;
	#endif	//Phase_correct_PWM_MODE2
	}
#endif // TMR2_MODE
}


/*********** Call Back Functions *********/

#if TMR2_MODE 	== TMR2_NORMAL_MODE
/**
 * TMR2_voidSendCallBack_OVF : Sets an overflow callback function for Timer 2 (TMR2)
 * @param	PtrF: A pointer to the overflow callback function
 * @return	void
 */
void TMR2_voidSendCallBack_OVF(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OV = PtrF;
	}
}

#elif TMR2_MODE == TMR2_CTC_MODE
/**
 * TMR2_voidSendCallBack_OCM : Sets an output compare match callback function for Timer 2 (TMR2)
 * @param	PtrF: A pointer to the output compare match callback function
 * @return	void
 */

void TMR2_voidSendCallBack_OCM(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OC = PtrF;
	}
}

#endif	//TMR2_MODE

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/

static void select_mode(u8 mode)
{
	switch(mode)
	{
	case Normal2:
		CLR_BIT(_TCCR2, 3);
		CLR_BIT(_TCCR2, 6);
		break;
	case FastPWM2:
		SET_BIT(_TCCR2, 3);
		SET_BIT(_TCCR2, 6);
		break;
	case CTC2:
		SET_BIT(_TCCR2, 3);
		CLR_BIT(_TCCR2, 6);
		break;
	case Phase_Correct_PWM2:
		CLR_BIT(_TCCR2, 3);
		SET_BIT(_TCCR2, 6);
		break;
	}
}

#if TMR2_MODE 	== TMR2_NORMAL_MODE
static void Enable_OVI2(void)
{
	SET_BIT(_TIMSK, 6);
}
#elif TMR2_MODE == TMR2_CTC_MODE
static void Enable_OCI2(void)
{
	SET_BIT(_TIMSK, 7);
}
#endif	//TMR2_MODE

static void PrescalerValue_set(u16 value)
{
	switch(value)
	{
	case 0:
		SET_BIT(_TCCR2,0);
		CLR_BIT(_TCCR2,1);
		CLR_BIT(_TCCR2,2);
		break;
	case 8:
		CLR_BIT(_TCCR2,0);
		SET_BIT(_TCCR2,1);
		CLR_BIT(_TCCR2,2);
		break;
	case 32:
		SET_BIT(_TCCR2,0);
		SET_BIT(_TCCR2,1);
		CLR_BIT(_TCCR2,2);
		break;
	case 64:
		CLR_BIT(_TCCR2,0);
		CLR_BIT(_TCCR2,1);
		SET_BIT(_TCCR2,2);
		break;
	case 128:
		SET_BIT(_TCCR2,0);
		CLR_BIT(_TCCR2,1);
		SET_BIT(_TCCR2,2);
		break;
	case 256:
		CLR_BIT(_TCCR2,0);
		SET_BIT(_TCCR2,1);
		SET_BIT(_TCCR2,2);
		break;
	case 1024:
		SET_BIT(_TCCR2,0);
		SET_BIT(_TCCR2,1);
		SET_BIT(_TCCR2,2);
		break;
	}
}





/* ----------------- Section : ISRs -----------------*/

//TIMER2 OVF - NORMAL Mode ISR
void __vector_5(void) __attribute__((signal));
// TIMER2 COMP - CTC Mode ISR
void __vector_4(void) __attribute__((signal));


void __vector_5(void)
{
	static u16 count = 0;
	count ++;
	if(count == TMR2_OVERFLOW)
	{
		TMR2_Preload_value_set(113);
		count = 0;
		if(privatePTR_OV !=NULL)
			{
				privatePTR_OV();
			}
	}

}


void __vector_4(void)
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
