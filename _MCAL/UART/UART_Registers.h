/*
 * UART_Register.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_UART_UART_REGISTERS_H_
#define MCAL_UART_UART_REGISTERS_H_

// UART I/O DATA REG
#define _UDR 		(*((volatile unsigned char *)0x2C))
#define _UCSRA 		(*((volatile unsigned char *)0x2B))
#define _UCSRB		(*((volatile unsigned char *)0x2A))
#define _UCSRC 		(*((volatile unsigned char *)0x40))

#define _UBRRL 		(*((volatile unsigned char *)0x29))


#endif /* MCAL_UART_UART_REGISTERS_H_ */
