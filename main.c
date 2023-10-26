/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */


#include "main_h.h"


void ISR0(void)
{
	Dio_FlipChannel(PA_4);
}

void ISR1(void)
{
	Dio_FlipChannel(PA_5);
}

void ISR2(void)
{
	Dio_FlipChannel(PA_6);
}
int main() {
	GI_voidEnable();
	EXTI_voidInit(EXTI_INT0 ,RISING_EDGE);
	EXTI_voidInit(EXTI_INT1 ,RISING_EDGE);
	EXTI_voidInit(EXTI_INT2 ,RISING_EDGE);

	EXTI_voidEnable(EXTI_INT0);
	EXTI_voidEnable(EXTI_INT1);
	EXTI_voidEnable(EXTI_INT2);

	EXTI0_voidSendCallBack(ISR0);
	EXTI1_voidSendCallBack(ISR1);
	EXTI2_voidSendCallBack(ISR2);

	Port_Init(pins);
	Dio_WriteChannel(PA_4, 1);
	Dio_WriteChannel(PA_5, 1);
	Dio_WriteChannel(PA_6, 1);

	while (1) {

	}
	return 0;
}
