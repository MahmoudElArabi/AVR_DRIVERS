/*
 * I2C_Registers.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_TWI_TWI_REGISTERS_H_
#define MCAL_TWI_TWI_REGISTERS_H_

// _TWI Control Register
#define _TWCR    (*((volatile unsigned char *)0x56))
#define _TWIE    0
#define _TWEN    2
#define _TWWC    3
#define _TWSTO   4
#define _TWSTA   5
#define _TWEA    6
#define _TWINT   7

// _TWI Status Register
#define _TWSR    (*((volatile unsigned char *)0x21))
#define _TWPS0   0
#define _TWPS1   1
#define _TWS3    3
#define _TWS4    4
#define _TWS5    5
#define _TWS6    6
#define _TWS7    7

// _TWI Bit Rate Register
#define _TWBR    (*((volatile unsigned char *)0x20))

// _TWI Address Register
#define _TWAR    (*((volatile unsigned char *)0x22))
#define _TWA0    1
#define _TWA1    2
#define _TWA2    3
#define _TWA3    4
#define _TWA4    5
#define _TWA5    6
#define _TWA6    7
#define _TWGCE   0

// _TWI Data Register
#define _TWDR    (*((volatile unsigned char *)0x23))


#endif /* MCAL_TWI_TWI_REGISTERS_H_ */
