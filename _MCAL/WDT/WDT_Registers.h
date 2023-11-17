/*
 * WDT_Registers.h
 *
 *  Created on: Nov 13, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_WDT_WDT_REGISTERS_H_
#define MCAL_WDT_WDT_REGISTERS_H_

#define _WDTCR 		(*((volatile unsigned char *)0x41))

#define _WDP0 	0
#define _WDP1 	1
#define _WDP2 	2
#define _WDE 	3
#define _WDTOE	4

#endif /* MCAL_WDT_WDT_REGISTERS_H_ */
