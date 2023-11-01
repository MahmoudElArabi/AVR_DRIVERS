/*
 * ADC_Registers.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_ADC_ADC_REGISTERS_H_
#define MCAL_ADC_ADC_REGISTERS_H_

#define _ADMUX 			(*((volatile unsigned char *)0x27))
#define _ADCSRA 		(*((volatile unsigned char *)0x26))
#define _ADCL 			(*((volatile unsigned char *)0x24))
#define _ADCH 			(*((volatile unsigned char *)0x25))
#define _SFIOR  		(*((volatile unsigned char *)0X24))

#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
