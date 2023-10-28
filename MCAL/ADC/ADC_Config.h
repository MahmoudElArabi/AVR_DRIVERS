/*
 * ADC_Config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

//#define ADC0		PA_0
//#define ADC1		PA_1
//#define ADC2		PA_2
//#define ADC3		PA_3
//#define ADC4		PA_4
//#define ADC5		PA_5
//#define ADC6		PA_6
//#define ADC7		PA_7

#include "ADC_Private.h"


// Voltage Reference Selections for ADC	--> (AREF, AVCC, Internal)
#define ADC_Voltage_Reference		AVCC

//ADC Left Adjust Result
#define ADC_Left_Adjust_Result		LEFT

//ADC prescaler value	64 --> (ADC_CLK = 250kHZ) , 128
#define ADC_prescaler_value			128

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
