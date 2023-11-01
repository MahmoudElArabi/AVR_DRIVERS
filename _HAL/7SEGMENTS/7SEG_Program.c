/*
 * SEGMENTS.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "7SEG_Interface.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"
#include "../../_MCAL/DIO/DIO_Registers.h"


/* ----------------- Section : Software Interfaces Implementation -----------------*/

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
