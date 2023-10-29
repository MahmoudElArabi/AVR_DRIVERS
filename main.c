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

	TMR2_voidSetDelay_ms_using_CTC(2000);
	GI_voidEnable();
	TMR2_voidSendCallBack_OCM(ISR_CTC);

	TMR2_voidInit();

	TMR2_voidStart();

	u8 i =0;
	while (1)
	{
		TMR2_voidSetDutyCycle(i);
		_delay_ms(50);
		i++;
		if (i == 100)
			i = 0;
	}
	return 0;
}
