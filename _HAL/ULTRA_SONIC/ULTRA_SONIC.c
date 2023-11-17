/*
 * ULTRA_SONIC.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */


#include "ULTRA_SONIC.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"
#include "../../_MCAL/HICU/ICU_Interface.h"
#include "util/delay.h"

void Ultra_Sonic_void_trigger(u8 channel)
{
	Dio_WriteChannel(channel, 1);
	_delay_us(10);
	Dio_WriteChannel(channel, 0);
	_delay_ms(60);
}

u16 Ultra_Sonic_Distance_in_cm(void)
{
	return (ICU_u32GetFallingEdgeTime() / 58);
}
