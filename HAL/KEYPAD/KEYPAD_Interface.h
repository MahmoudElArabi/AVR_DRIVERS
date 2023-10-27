/*
 * KEYPAD_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/* ----------------- Section : includes -----------------*/

#include "../../MCAL/PORT/PORT_Interface.h"

/* ----------------- Section : Macro Declarations -----------------*/
#define keypad_rows 4
#define keypad_coul 4

/* ----------------- Section : Data types Declarations -----------------*/


/* ----------------- Section : Software Interfaces Declaration -----------------*/

void Keypad_Init(void);
void Keypad_Get_value(u8 *value);
#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
