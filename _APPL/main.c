/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"
#include <util/delay.h>



int main() {
	Port_Init(pins);
	Dio_WriteChannel(PD_1, 1);
	Dio_WriteChannel(PC_7, 1);
	lcd4_Init();
	Keypad_Init();
	ADC_void_Init();

	TMR0_voidInit();
	TMR0_voidStart();

	uint16_t number = 0;
	u8 key;
	u16 adcval = 0;

	lcd4_disply_string((u8*)"Threshold: ");
	while (1)
	{
		Keypad_Get_value(&key);
		if (key != 'T' && key != '#') {
				number = number * 10 + (key - '0');
				lcd4_set_cursor(1,11);
				lcd4_disply_num(number);
		}
		if (key == '#') {
			lcd4_CLR();
			lcd4_disply_string((u8*)"   Threshold : ");
			lcd4_disply_num(number);
			_delay_ms(100);
			lcd4_CLR();
			lcd4_set_cursor(2,1);
			lcd4_disply_string((u8*)" ADC CH0 STARTS... ");
			_delay_ms(100);
			lcd4_CLR();
			while(1)
			{
				_delay_ms(100);
				lcd4_CLR();
				adcval = ADC_void_Read_CH(0);
				_delay_ms(50);
				if(number < adcval)
				{
					if (adcval <= 101)
					{
						lcd4_disply_string((u8*)"00.0000 %");
						TMR0_voidSetDutyCycle(0);
					}
					else if (adcval <= 134)
					{
						lcd4_disply_string((u8*)"13.7435 %");
						TMR0_voidSetDutyCycle(10);
					}
					else if (adcval <= 171)
					{
						lcd4_disply_string((u8*)"17.5385 %");
						TMR0_voidSetDutyCycle(20);
					}
					else if (adcval <= 236)
					{
						lcd4_disply_string((u8*)"24.2051 %");
						TMR0_voidSetDutyCycle(25);
					}
					else if (adcval <= 384)
					{
						lcd4_disply_string((u8*)"39.3846 %");
						TMR0_voidSetDutyCycle(40);
					}
					else if (adcval <= 536)
					{
						lcd4_disply_string((u8*)"54.9744 %");
						TMR0_voidSetDutyCycle(50);
					}
					else if (adcval <= 694)
					{
						lcd4_disply_string((u8*)"71.1795 %");
						TMR0_voidSetDutyCycle(71);
					}
					else if (adcval <= 856)
					{
						lcd4_disply_string((u8*)"87.7949 %");
						TMR0_voidSetDutyCycle(80);
					}
					else if (adcval <= 932)
					{
						lcd4_disply_string((u8*)"95.5897 %");
						TMR0_voidSetDutyCycle(90);
					}
					else if (adcval <= 975)
					{
						lcd4_disply_string((u8*)"99.9999 %");

						TMR0_voidSetDutyCycle(100);
					}
				}
				else
				{
					lcd4_disply_string((u8*)"UNDER THRESHOLD");
					TMR0_voidSetDutyCycle(0);
				}

			}
		}
	}
}
