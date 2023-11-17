/*
 * WDT_Program.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "WDT_Interface.h"
#include "WDT_Registers.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void WDT_void_Enable (u8 Copy_u8_Time)
{
	switch (Copy_u8_Time)
	{
		case WDT_16_3_ms:
			CLR_BIT(_WDTCR, _WDP0);
			CLR_BIT(_WDTCR, _WDP1);
			CLR_BIT(_WDTCR, _WDP2);
			break;
		case WDT_32_5_ms:
			SET_BIT(_WDTCR, _WDP0);
			CLR_BIT(_WDTCR, _WDP1);
			CLR_BIT(_WDTCR, _WDP2);
			break;
		case WDT_65_0_ms:
			CLR_BIT(_WDTCR, _WDP0);
			SET_BIT(_WDTCR, _WDP1);
			CLR_BIT(_WDTCR, _WDP2);
			break;
		case WDT_0_13_ms:
			SET_BIT(_WDTCR, _WDP0);
			SET_BIT(_WDTCR, _WDP1);
			CLR_BIT(_WDTCR, _WDP2);
			break;
		case WDT_0_26_ms:
			CLR_BIT(_WDTCR, _WDP0);
			CLR_BIT(_WDTCR, _WDP1);
			SET_BIT(_WDTCR, _WDP2);
			break;
		case WDT_0_52_ms:
			SET_BIT(_WDTCR, _WDP0);
			CLR_BIT(_WDTCR, _WDP1);
			SET_BIT(_WDTCR, _WDP2);
			break;
		case WDT_01_0_ms:
			CLR_BIT(_WDTCR, _WDP0);
			SET_BIT(_WDTCR, _WDP1);
			SET_BIT(_WDTCR, _WDP2);
			break;
		case WDT_02_1_ms:
			SET_BIT(_WDTCR, _WDP0);
			SET_BIT(_WDTCR, _WDP1);
			SET_BIT(_WDTCR, _WDP2);
			break;
		default:
			break;
	}
	SET_BIT(_WDTCR, _WDE);
}

void WDT_void_Disable(void)
{
	_WDTCR = (1<<_WDTOE) | (1<<_WDE);
	_WDTCR = 0x00;
}
