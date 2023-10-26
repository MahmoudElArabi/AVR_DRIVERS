/*
 * DIO_Registers.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_DIO_DIO_REGISTERS_H_
#define MCAL_DIO_DIO_REGISTERS_H_

#define _PORTA 		(*((volatile unsigned char *)0x3B))
#define _PORTB 		(*((volatile unsigned char *)0x38))
#define _PORTC 		(*((volatile unsigned char *)0x35))
#define _PORTD 		(*((volatile unsigned char *)0x32))

#define _PINA 		(*((volatile unsigned char *)0x39))
#define _PINB 		(*((volatile unsigned char *)0x36))
#define _PINC 		(*((volatile unsigned char *)0x33))
#define _PIND 		(*((volatile unsigned char *)0x30))

#endif /* MCAL_DIO_DIO_REGISTERS_H_ */
