/*
 * TMR0_Register.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_HICU_REGISTER_H_
#define MCAL_HICU_REGISTER_H_

#define _TCCR1A 	(*((volatile unsigned char *)0x4F))
#define _TCCR1B 	(*((volatile unsigned char *)0x4E))
#define _TCNT1 		(*((volatile unsigned short *)0x4C))
#define _OCR1A 		(*((volatile unsigned short *)0x4A))
#define _OCR1B 		(*((volatile unsigned short *)0x48))
#define _ICR1 		(*((volatile unsigned short *)0x46))
#define _TIMSK 		(*((volatile unsigned char *)0x59))
#define _TIFR 		(*((volatile unsigned char *)0x58))

// TCCR1A pins
#define _WGM10       0
#define _WGM11       1
#define _FOC1B       2
#define _FOC1A       3
#define _COM1B1      5
#define _COM1B0      4
#define _COM1A1      7
#define _COM1A0      6

// TCCR1B pins
#define _CS10        0
#define _CS11        1
#define _CS12        2
#define _WGM12       3
#define _WGM13       4
#define _ICES1       6
#define _ICNC1       7

// TIMSK pins
#define _TOIE1       2
#define _OCIE1B      3
#define _OCIE1A      4
#define _TICIE1      5

// _TIFR pins
#define _TOV1        2
#define _OCF1B       3
#define _OCF1A       4
#define _ICF1		 5

#endif /* MCAL_HICU_REGISTER_H_*/
