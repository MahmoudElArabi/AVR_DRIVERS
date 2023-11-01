/*
 * EXTI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "EXTI_Registers.h"
#include "EXTI_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Static "Private" Functions / Functions pointers -----------------*/

static void (*EXTI_prviate_PtrCallBack0) (void) = NULL;
static void (*EXTI_prviate_PtrCallBack1) (void) = NULL;
static void (*EXTI_prviate_PtrCallBack2) (void) = NULL;


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * EXTI_voidInit: This function initialize the External interrupt "EXTI0, EXTI1 or EXTI2" Mode to be:
 * 1- Rising Edge	2- Falling Edge		3- Logical Change	4- Low Level
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * 			2- copy_u8SenseControl		-> External interrupt Modes (RISING_EDGE, FALLING_EDGE, LOW_LEVEL or LOGICAL_CHANGE)
 * @return	void
 */
void EXTI_voidInit(u8 copy_u8InterruptSource, u8 copy_u8SenseControl)
{
	switch (copy_u8InterruptSource)
	{
	case EXTI_INT0:
		switch (copy_u8SenseControl)
		{
		default:
		case RISING_EDGE:
			SET_BIT(_MCUCR, ISC00);
			SET_BIT(_MCUCR, ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(_MCUCR, ISC00);
			SET_BIT(_MCUCR, ISC01);
			break;
		case LOGICAL_CHANGE:
			SET_BIT(_MCUCR, ISC00);
			CLR_BIT(_MCUCR, ISC01);
			break;
		case LOW_LEVEL:
			CLR_BIT(_MCUCR, ISC00);
			CLR_BIT(_MCUCR, ISC01);
			break;
		}
		break;

	case EXTI_INT1:
		switch (copy_u8SenseControl)
		{
		default:
		case RISING_EDGE:
			SET_BIT(_MCUCR, ISC10);
			SET_BIT(_MCUCR, ISC11);
			break;
		case FALLING_EDGE:
			CLR_BIT(_MCUCR, ISC10);
			SET_BIT(_MCUCR, ISC11);
			break;
		case LOGICAL_CHANGE:
			SET_BIT(_MCUCR, ISC10);
			CLR_BIT(_MCUCR, ISC11);
			break;
		case LOW_LEVEL:
			CLR_BIT(_MCUCR, ISC10);
			CLR_BIT(_MCUCR, ISC11);
			break;
		}
		break;

	case EXTI_INT2:
		switch (copy_u8SenseControl)
		{
		default:
		case RISING_EDGE:
			SET_BIT(_MCUCSR, ISC2);
			break;
		case FALLING_EDGE:
			CLR_BIT(_MCUCSR, ISC2);
			break;
		}
		break;
	}
}

/**
 * EXTI_voidEnable : This function enable the External interrupt "EXTI0, EXTI1 or EXTI2"
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * @return	void
 */
void EXTI_voidEnable(u8 copy_u8InterruptSource)
{
	switch (copy_u8InterruptSource)
	{
	case EXTI_INT0:
		SET_BIT(_GICR, INT0);
		break;
	case EXTI_INT1:
		SET_BIT(_GICR, INT1);
		break;
	case EXTI_INT2:
		SET_BIT(_GICR, INT2);
		break;
	}
}

/**
 * EXTI_voidDisable : This function disable the External interrupt "EXTI0, EXTI1 or EXTI2"
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * @return	void
 */
void EXTI_voidDisable(u8 copy_u8InterruptSource)
{
	switch (copy_u8InterruptSource)
	{
	case EXTI_INT0:
		CLR_BIT(_GICR, INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(_GICR, INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(_GICR, INT2);
		break;
	}
}

//CallBack Functions Implementation for EXTI0, 1, 2
void EXTI0_voidSendCallBack(void (*PtrF0)(void))
{
	if(PtrF0 !=NULL)
	{
		EXTI_prviate_PtrCallBack0 = PtrF0;
	}
}

void EXTI1_voidSendCallBack(void (*PtrF1)(void))
{
	if(PtrF1 !=NULL)
	{
		EXTI_prviate_PtrCallBack1 = PtrF1;
	}
}

void EXTI2_voidSendCallBack(void (*PtrF2)(void))
{
	if(PtrF2 !=NULL)
	{
		EXTI_prviate_PtrCallBack2 = PtrF2;
	}
}


/* ----------------- Section : ISRs -----------------*/
//EXTI0 ISR
void __vector_1(void) __attribute__((signal));
//EXTI1 ISR
void __vector_2(void) __attribute__((signal));
//EXTI2 ISR
void __vector_3(void) __attribute__((signal));


void __vector_1(void)
{
	if(EXTI_prviate_PtrCallBack0 !=NULL)
	{
		EXTI_prviate_PtrCallBack0();
	}
}

void __vector_2(void)
{
	if(EXTI_prviate_PtrCallBack1 !=NULL)
	{
		EXTI_prviate_PtrCallBack1();
	}
}

void __vector_3(void)
{
	if(EXTI_prviate_PtrCallBack2 !=NULL)
	{
		EXTI_prviate_PtrCallBack2();
	}
}
