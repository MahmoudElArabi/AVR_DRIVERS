/*
 * EXTI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

#include "EXTI_interface.h"
#include "EXTI_register.h"

static void (*EXTI_prviate_PtrCallBack0) (void)=NULL;
static void (*EXTI_prviate_PtrCallBack1) (void)=NULL;
static void (*EXTI_prviate_PtrCallBack2) (void)=NULL;

void EXTI_voidInit(u8 copy_u8InterruptSource, u8 copy_u8SenseControl)
{
	switch (copy_u8InterruptSource) {

	case EXTI_INT0:
		switch (copy_u8SenseControl) {
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

		switch (copy_u8SenseControl) {
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
		switch (copy_u8SenseControl) {
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

void EXTI_voidEnable(u8 copy_u8InterruptSource) {
	switch (copy_u8InterruptSource) {
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

void EXTI_voidDisable(u8 copy_u8InterruptSource) {

	switch (copy_u8InterruptSource) {
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

/*************** CallBacks ***************/
void EXTI_voidSendCallBack0(void (*PtrF)(void)){
	if(PtrF !=NULL)
	{
		EXTI_prviate_PtrCallBack0 = PtrF;
	}
}

void EXTI_voidSendCallBack1(void (*PtrF)(void)){
	if(PtrF !=NULL)
	{
		EXTI_prviate_PtrCallBack1 = PtrF;
	}
}

void EXTI_voidSendCallBack2(void (*PtrF)(void)){
	if(PtrF !=NULL)
	{
		EXTI_prviate_PtrCallBack2 = PtrF;
	}
}



/*************** ISRs ***************/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_prviate_PtrCallBack0 !=NULL)
	{
		EXTI_prviate_PtrCallBack0();
	}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_prviate_PtrCallBack1 !=NULL)
	{
		EXTI_prviate_PtrCallBack1();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_prviate_PtrCallBack2 !=NULL)
	{
		EXTI_prviate_PtrCallBack2();
	}
}

