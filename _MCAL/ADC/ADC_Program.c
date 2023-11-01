/*
 * ADC_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Registers.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Static "Private" Functions Declaration / Functions pointers -----------------*/
static void ADC_voidSetVoltageReference(void);
static void ADC_voidLeft_Adjust_Result(void);
static void ADC_voidSet_Prescaler(void);
static void ADC_Select_Channel(u8 u8_Copy_CH);

/* ----------------- Section : Software Interfaces Implementation -----------------*/

void ADC_void_Init(void)
{
	ADC_voidSetVoltageReference();
	ADC_voidLeft_Adjust_Result();
	ADC_voidSet_Prescaler();
	SET_BIT(_ADCSRA, 7); // Enable ADC
}

u16 ADC_void_Read_CH(u8 u8_Copychannel)
{
	u16 result = 0;
	ADC_Select_Channel(u8_Copychannel);
	SET_BIT(_ADCSRA , 6); // ADC start conversion
	while(_ADCSRA & (1 << 6));
	switch(ADC_Left_Adjust_Result)
	{
	case LEFT:
		 result = (_ADCL >> 6);
		 result |= (_ADCH << 2);
		break;
	case RIGHT:
		 result = _ADCL;
		 result |= (_ADCH << 8);
		break;
	}
	return result;
}



////CallBack Functions Implementation for EXTI0, 1, 2
//void ADC_voidSendCallBack(void (*PtrFADC)(void))
//{
//	if(PtrFADC !=NULL)
//	{
//		ADC_prviate_PtrCallBack = PtrFADC;
//	}
//}
/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/
static void ADC_voidSetVoltageReference(void)
{
	switch(ADC_Voltage_Reference)
	{
	case AREF:
		CLR_BIT(_ADMUX, 6);
		CLR_BIT(_ADMUX, 7);
		break;
	case AVCC :
		SET_BIT(_ADMUX, 6);
		CLR_BIT(_ADMUX, 7);
		break;
	case Internal:
		SET_BIT(_ADMUX, 6);
		SET_BIT(_ADMUX, 7);
		break;
	default: break;
	}
}
static void ADC_voidLeft_Adjust_Result(void)
{
	switch(ADC_Left_Adjust_Result)
	{
	case LEFT:
		SET_BIT(_ADMUX, 5);
		break;
	case RIGHT :
		CLR_BIT(_ADMUX, 5);
		break;
	default: break;
	}
}
static void ADC_voidSet_Prescaler(void)
{
	switch(ADC_prescaler_value)
	{
	case 64:
		CLR_BIT(_ADCSRA, 0);
		SET_BIT(_ADCSRA, 1);
		SET_BIT(_ADCSRA, 2);
		break;
	case 128:
		SET_BIT(_ADCSRA, 0);
		SET_BIT(_ADCSRA, 1);
		SET_BIT(_ADCSRA, 2);
		break;
	default: break;
	}
}
static void ADC_Select_Channel(u8 u8_Copy_CH)
{
	switch(u8_Copy_CH)
	{
	case(ADC0_SE):
		CLR_BIT(_ADMUX, 0);
		CLR_BIT(_ADMUX, 1);
		CLR_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC1_SE):
		SET_BIT(_ADMUX, 0);
		CLR_BIT(_ADMUX, 1);
		CLR_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC2_SE):
		CLR_BIT(_ADMUX, 0);
		SET_BIT(_ADMUX, 1);
		CLR_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC3_SE):
		SET_BIT(_ADMUX, 0);
		SET_BIT(_ADMUX, 1);
		CLR_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC4_SE):
		CLR_BIT(_ADMUX, 0);
		CLR_BIT(_ADMUX, 1);
		SET_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC5_SE):
		SET_BIT(_ADMUX, 0);
		CLR_BIT(_ADMUX, 1);
		SET_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC6_SE):
		CLR_BIT(_ADMUX, 0);
		SET_BIT(_ADMUX, 1);
		SET_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	case(ADC7_SE):
		SET_BIT(_ADMUX, 0);
		SET_BIT(_ADMUX, 1);
		SET_BIT(_ADMUX, 2);
		CLR_BIT(_ADMUX, 3);
		CLR_BIT(_ADMUX, 4);
		break;
	default: break;
	}
}

