/*
 * TMR0_Program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "TMR0_Config.h"
#include "TMR0_Registers.h"
#include "TMR0_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Static "Private" Functions / Functions pointers -----------------*/
static volatile u16 private_CTC_counter = 0;

static void (*privatePTR_OV) (void) = NULL;
static void (*privatePTR_OC) (void) = NULL;
static void select_mode(u8 mode);
#if TMR0_MODE 	== TMR0_NORMAL_MODE
static void Enable_OVI0(void);
#elif TMR0_MODE == TMR0_CTC_MODE
static void Enable_OCI0(void);
#endif
static void PrescalerValue_set(u16 value);



/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * TMR0_voidInit : Initializes Timer 0 (TMR0) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR0_voidInit(void)
{
#if TMR0_MODE 	== TMR0_NORMAL_MODE
	select_mode(Normal);
	Enable_OVI0();
	TMR0_Preload_value_set(TMR0_PRELOAD);
#elif TMR0_MODE == TMR0_CTC_MODE
	select_mode(CTC);
	Enable_OCI0();
	_OCR0 = (TMR0_OCR0_val);
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
#elif TMR0_MODE == TMR0_Phase_Correct_PWM_MODE
	select_mode(Phase_Correct_PWM);
	switch(Phase_correct_PWM_MODE)
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

/**
 * TMR0_voidStart : Starts ( begin the counting ) Timer 0 (TMR0) operation
 * @param	void
 * @return	void
 */
void TMR0_voidStart(void)
{
	PrescalerValue_set((u16)TMR0_PRESCALER);
}

/**
 * TMR0_voidStop : Stops ( halt  the counting ) Timer 0 (TMR0) operation
 * @param	void
 * @return	void
 */
void TMR0_voidStop(void)
{
	CLR_BIT(_TCCR0,0);
	CLR_BIT(_TCCR0,1);
	CLR_BIT(_TCCR0,2);
}

/**
 * TMR0_Preload_value_set : Sets the initial preload value for Timer 0 (TMR0)
 * @param	value: The preload value to be set
 * @return	void
 */
void TMR0_Preload_value_set(u8 value)
{
	_TCNT0 = value;
}




/**
 * TMR0_voidSetDelay_ms_using_CTC : Sets a delay in milliseconds using Timer 0 (TMR0) in Clear Timer on Compare Match (CTC) mode
 * @param	_del_ms:  The desired delay in milliseconds
 * @return	void
 */
void TMR0_voidSetDelay_ms_using_CTC(u16 _del_ms)
{
#if TMR0_PRESCALER == 1
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR0_OCR0_val + 1) * 0.0625);
#elif TMR0_PRESCALER == 8
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR0_OCR0_val + 1) * 0.5);
#elif TMR0_PRESCALER == 64
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR0_OCR0_val + 1) * 4);
#elif TMR0_PRESCALER == 256
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR0_OCR0_val + 1) * 16);

#elif TMR0_PRESCALER == 1024
	private_CTC_counter = ((u32)_del_ms*1000) / ((TMR0_OCR0_val + 1) * 64);
#endif
}

/**
 * TMR0_voidSetDutyCycle : Sets the duty cycle for Timer 0 (TMR0) in (Fast PWM or Phase Correct PWM)
 * 						   and inverting or non-inverting mode
 * @param	copy_u8_duty:  The desired duty cycle expressed as a percentage (0 to 100)
 * @return	void
 */
void TMR0_voidSetDutyCycle(u8 copy_u8_duty)
{
#if TMR0_MODE == TMR0_FastPWM_MODE
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
	#endif	//Fast_PWM_MODE
	}
#elif TMR0_MODE == TMR0_Phase_Correct_PWM_MODE
	if(copy_u8_duty <= 100)
	{
	#if Phase_correct_PWM_MODE == non_inverting
	_OCR0 = (copy_u8_duty * 256) / 100;
	#elif Phase_correct_PWM_MODE == inverting
	copy_u8_duty = 100 - copy_u8_duty;
	_OCR0 = (((u16)copy_u8_duty * 256) / 100) - 510;;
	#endif	//Phase_Correct_PWM_MODE
	}
#endif // TMR0_MODE
}



/*********** Call Back Functions *********/
/**
 * TMR0_voidSendCallBack_OVF : Sets an overflow callback function for Timer 0 (TMR0)
 * @param	PtrF: A pointer to the overflow callback function
 * @return	void
 */
void TMR0_voidSendCallBack_OVF(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OV = PtrF;
	}
}

/**
 * TMR0_voidSendCallBack_OCM : Sets an output compare match callback function for Timer 0 (TMR0)
 * @param	PtrF: A pointer to the output compare match callback function
 * @return	void
 */

void TMR0_voidSendCallBack_OCM(void (*PtrF)(void))
{
	if(PtrF != NULL)
	{
		privatePTR_OC = PtrF;
	}
}

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/

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
	case Phase_Correct_PWM:
		CLR_BIT(_TCCR0, 3);
		SET_BIT(_TCCR0, 6);
		break;
	}
}

#if TMR0_MODE 	== TMR0_NORMAL_MODE
static void Enable_OVI0(void)
{
	SET_BIT(_TIMSK, 0);
}
#elif TMR0_MODE == TMR0_CTC_MODE
static void Enable_OCI0(void)
{
	SET_BIT(_TIMSK, 1);
}
#endif

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





/* ----------------- Section : ISRs -----------------*/

//NORMAL Mode ISR
void __vector_11(void) __attribute__((signal));
//CTC Mode ISR
void __vector_10(void) __attribute__((signal));


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
