/*
 * TMR0_Register.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER0_TMR0_REGISTERS_H_
#define MCAL_TIMER0_TMR0_REGISTERS_H_

// Timer/Counter 0 Control Register
#define _TCCR0 		(*((volatile unsigned char *)0x53))
// Timer/Counter 0 Register
#define _TCNT0 		(*((volatile unsigned char *)0x52))
// Output Compare Register 0
#define _OCR0 		(*((volatile unsigned char *)0x5C))
// Timer/Counter Interrupt Mask
#define _TIMSK     	(*((volatile unsigned char *)0x59))
// Timer/Counter Interrupt Flag
#define _TIFR      	(*((volatile unsigned char *)0x58))

#endif /* MCAL_TIMER0_TMR0_REGISTERS_H_ */
