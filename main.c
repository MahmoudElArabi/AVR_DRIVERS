/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"


int main() {
	Port_Init(pins);
	UART_Init();
	UART_TransmitData('M');
	_delay_ms(50);
	UART_TransmitData('A');
	_delay_ms(50);
	UART_TransmitData('H');
	_delay_ms(50);
	UART_TransmitData('M');
	_delay_ms(50);
	UART_TransmitData('O');
	_delay_ms(50);
	UART_TransmitData('U');
	_delay_ms(50);
	UART_TransmitData('D');
	while (1)
	{

	}
	return 0;
}
