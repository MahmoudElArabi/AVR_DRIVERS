/*
 * PORT_Registers.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_PORT_PORT_REGISTERS_H_
#define MCAL_PORT_PORT_REGISTERS_H_

#define _DDRA 		(*((volatile unsigned char *)0x3A))
#define _DDRB 		(*((volatile unsigned char *)0x37))
#define _DDRC 		(*((volatile unsigned char *)0x34))
#define _DDRD 		(*((volatile unsigned char *)0x31))

#define _PORTA 		(*((volatile unsigned char *)0x3B))
#define _PORTB 		(*((volatile unsigned char *)0x38))
#define _PORTC 		(*((volatile unsigned char *)0x35))
#define _PORTD 		(*((volatile unsigned char *)0x32))

#endif /* MCAL_PORT_PORT_REGISTERS_H_ */
