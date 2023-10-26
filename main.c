/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */


#include "main_h.h"

void ISR_CTC(void)
{
	Dio_FlipChannel(PA_4);
}
int main() {
	Port_Init(pins);
	GI_voidEnable();
	TMR2_voidSendCallBack_OCM(ISR_CTC);
	TMR2_voidInit();
	TMR2_voidStart();
	while (1) {

	}
	return 0;
}
