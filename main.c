/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */


#include "main_h.h"

void ISR_NORMAL(void)
{
	Dio_FlipChannel(PA_5);
}
int main() {
	Port_Init(pins);
	GI_voidEnable();
	TMR2_voidSendCallBack_OVF(ISR_NORMAL);
	TMR2_voidInit();
	TMR2_voidStart();
	while (1) {

	}
	return 0;
}
