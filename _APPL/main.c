/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"


int main() {
	Port_Init(pins);

	Dio_WriteChannel(PA_4, 1);

	while (1)
	{

	}
	return 0;
}
