/*
 * TMR1_Program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "TMR1_Config.h"
#include "TMR1_Register.h"
#include "TMR1_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Static "Private" Functions Declaration / Functions pointers -----------------*/
static void PrescalerValue_set(u16 value);


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * TMR1_voidInit : Initializes Timer 1 (TMR1) with the desired MODE
 * @param	void
 * @return	void
 */
void TMR1_voidInit(void)
{
#if TMR1_MODE 	== TMR1_FastPWM_MODE_14
	CLR_BIT(_TCCR1A, _WGM10);
	SET_BIT(_TCCR1A, _WGM11);
	SET_BIT(_TCCR1B, _WGM12);
	SET_BIT(_TCCR1B, _WGM13);
	switch(TMR1_FastPWM_14_MODE)
	{
	case non_inverting1:
		CLR_BIT(_TCCR1A, _COM1A0);
		SET_BIT(_TCCR1A, _COM1A1);
		break;
	case inverting1:
		SET_BIT(_TCCR1A, _COM1A0);
		SET_BIT(_TCCR1A, _COM1A1);
		break;
	}
	TMR1_voidSetFreq_Mode14(50);
#endif // TMR1_MODE
}


void TMR1_voidStart(void)
{
	PrescalerValue_set((u16)TMR1_PRESCALER);
}

/**
 * TMR1_voidStop : Stops ( halt  the counting ) Timer 1 (TMR1) operation
 * @param	void
 * @return	void
 */
void TMR1_voidStop(void)
{
	CLR_BIT(_TCCR1B, _CS10);
	CLR_BIT(_TCCR1B, _CS11);
	CLR_BIT(_TCCR1B, _CS12);
}

void TMR1_voidSetCompareMatchValueA(u16 copy_u8CompareMatchValueA){
	_OCR1A = copy_u8CompareMatchValueA;
}


//under condition ticktime = 4 microsecond
void TMR1_voidSetFreq_Mode14(u16 copy_u16_frequency)
{
#if TMR1_PRESCALER == 64
	_ICR1 = (1000000UL / copy_u16_frequency) / 4 - 1;
#endif// TMR1_PRESCALER
}

void TMR1_voidSetDuty_Mode14(f32 copy_u8_duty)
{
	if(copy_u8_duty <= 100)
		{
		#if TMR1_FastPWM_14_MODE == non_inverting1
			if(copy_u8_duty == 0){
				_OCR1A = 0;
			}
			else{
				_OCR1A = ((copy_u8_duty * (_ICR1+1)) / 100) -1;
			}
		#elif TMR1_FastPWM_14_MODE == inverting1
			if(copy_u8_duty == 100){
				_OCR1A = 0;
			}
			else{
				copy_u8_duty = 100 - copy_u8_duty;
				_OCR1A = (((float)copy_u8_duty * (_ICR1+1)) / 100) -1;
			}
		#endif	//TMR1_FastPWM_14_MODE
		}
}
/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/
static void PrescalerValue_set(u16 value)
{
	switch(value)
	{
	case 0:
		SET_BIT(_TCCR1B, _CS10);
		CLR_BIT(_TCCR1B, _CS11);
		CLR_BIT(_TCCR1B, _CS12);
		break;
	case 8:
		CLR_BIT(_TCCR1B, _CS10);
		SET_BIT(_TCCR1B, _CS11);
		CLR_BIT(_TCCR1B, _CS12);
		break;
	case 64:
		SET_BIT(_TCCR1B, _CS10);
		SET_BIT(_TCCR1B, _CS11);
		CLR_BIT(_TCCR1B, _CS12);
		break;
	case 256:
		CLR_BIT(_TCCR1B, _CS10);
		CLR_BIT(_TCCR1B, _CS11);
		SET_BIT(_TCCR1B, _CS12);
		break;
	case 1024:
		SET_BIT(_TCCR1B, _CS10);
		CLR_BIT(_TCCR1B, _CS11);
		SET_BIT(_TCCR1B, _CS12);
		break;
	}
}

/* ----------------- Section : ISRs -----------------*/
