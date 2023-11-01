/*
 * TMR2_Register.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TIMER2_TMR2_REGISTERS_H_
#define MCAL_TIMER2_TMR2_REGISTERS_H_

// Timer/Counter 2 Control Register
#define _TCCR2 		(*((volatile unsigned char *)0x45))
// Timer/Counter 2 Register
#define _TCNT2 		(*((volatile unsigned char *)0x44))
// Output Compare Register 2
#define _OCR2 		(*((volatile unsigned char *)0x43))
// Timer/Counter Interrupt Mask
#define _TIMSK     	(*((volatile unsigned char *)0x59))
// Timer/Counter Interrupt Flag
#define _TIFR      	(*((volatile unsigned char *)0x58))

#endif /* MCAL_TIMER2_TMR2_REGISTERS_H_ */
