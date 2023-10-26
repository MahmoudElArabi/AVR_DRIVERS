/*
 * SEGMENTS.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/

#include "7SEG_Interface.h"


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * Segments_Init : This function initializes the 4 (7-segment) on the board of the Kit (just its pins direction)
 * @param	void
 * @return	void
 */
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

/**
 * Segment_Write : This function writes a value "num" on the chosen 7-segment
 * @param	1- num : which is the number to display
 * 			2- seg_index : which is the number of the segment 0, 1, 2 or 3
 * @return	void
 */
void Segment_Write(u8 num, u8 seg_index)
{
	switch(seg_index)
	{
	case 0:
		CLR_BIT(_PORTA, 3);
		SET_BIT(_PORTA, 2);
		SET_BIT(_PORTB, 5);
		SET_BIT(_PORTB, 6);
		break;
	case 1:
		SET_BIT(_PORTA, 3);
		CLR_BIT(_PORTA, 2);
		SET_BIT(_PORTB, 5);
		SET_BIT(_PORTB, 6);
		break;
	case 2:
		SET_BIT(_PORTA, 3);
		SET_BIT(_PORTA, 2);
		CLR_BIT(_PORTB, 5);
		SET_BIT(_PORTB, 6);
		break;
	case 3:
		SET_BIT(_PORTA, 3);
		SET_BIT(_PORTA, 2);
		SET_BIT(_PORTB, 5);
		CLR_BIT(_PORTB, 6);
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
