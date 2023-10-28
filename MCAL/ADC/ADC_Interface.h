/*
 * ADC_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "../PORT/PORT_Interface.h"
#include "ADC_Config.h"
#include "ADC_Registers.h"

/* ----------------- Section : Macro Declarations -----------------*/


/* ----------------- Section : Data types Declarations -----------------*/


/* ----------------- Section : Software Interfaces Declaration -----------------*/
void ADC_void_Init(void);
u16 ADC_void_Read_CH(u8 u8_Copychannel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
