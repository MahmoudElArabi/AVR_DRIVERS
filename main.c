/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#include "MCAL/PORT/PORT.h"
#include "HAL/LCD/LCD.h"
#include "HAL/7SEGMENTS/7SEG.h"
#include "MCAL/GI/GI_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"

void dioflip(void)
{
	Dio_FlipChannel(PA_5);
}
int main() {

	GI_voidEnable();
	EXTI_voidInit(EXTI_INT1 ,FALLING_EDGE);
	EXTI_voidEnable(EXTI_INT1);
	EXTRI_voidSetCallBackINT1(dioflip);
	while (1) {

	}
	return 0;
}
