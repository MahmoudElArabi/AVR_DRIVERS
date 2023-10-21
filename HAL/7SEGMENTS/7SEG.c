/*
 * SEGMENTS.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#include "7SEG.h"

void Segments_Init(void)
{
	Pin_ConfigType pins[] =
	{
			{Dio_PORTB, pin_0, STD_OUT },
			{Dio_PORTB, pin_1, STD_OUT },
			{Dio_PORTB, pin_2, STD_OUT },
			{Dio_PORTB, pin_4, STD_OUT },
			{Dio_PORTA, pin_2, STD_OUT },
			{Dio_PORTA, pin_3, STD_OUT },
			{Dio_PORTB, pin_5, STD_OUT },
			{Dio_PORTB, pin_6, STD_OUT },
			{-1}
	};
	Port_Init(pins);
}


void Segment_Write(u8 num, u8 seg_index)
{
	switch(seg_index)
	{
	case 0:
		CLR_BIT(PORTA, 3);
		SET_BIT(PORTA, 2);
		SET_BIT(PORTB, 5);
		SET_BIT(PORTB, 6);
		break;
	case 1:
		SET_BIT(PORTA, 3);
		CLR_BIT(PORTA, 2);
		SET_BIT(PORTB, 5);
		SET_BIT(PORTB, 6);
		break;
	case 2:
		SET_BIT(PORTA, 3);
		SET_BIT(PORTA, 2);
		CLR_BIT(PORTB, 5);
		SET_BIT(PORTB, 6);
		break;
	case 3:
		SET_BIT(PORTA, 3);
		SET_BIT(PORTA, 2);
		SET_BIT(PORTB, 5);
		CLR_BIT(PORTB, 6);
		break;
	}
	if (num >9){
		return;
	}
	else{
		Dio_WriteChannel(PB_0 , (num & 0x01));
		Dio_WriteChannel(PB_1 , ((num>>1) & 0x01));
		Dio_WriteChannel(PB_2 , ((num>>2) & 0x01));
		Dio_WriteChannel(PB_4 , ((num>>3) & 0x01));
	}
}
