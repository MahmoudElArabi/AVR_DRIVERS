/*
 * WDT_Interface.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_WDT_WDT_INTERFACE_H_
#define MCAL_WDT_WDT_INTERFACE_H_

#include "../../_MY_LIBS/STD_TYPES.h"

#define WDT_16_3_ms		1
#define WDT_32_5_ms		2
#define WDT_65_0_ms		3
#define WDT_0_13_ms		4
#define WDT_0_26_ms		5
#define WDT_0_52_ms		6
#define WDT_01_0_ms		7
#define WDT_02_1_ms		8

void WDT_void_Enable (u8 Copy_u8_Time);
void WDT_void_Disable(void);

#endif /* MCAL_WDT_WDT_INTERFACE_H_ */
