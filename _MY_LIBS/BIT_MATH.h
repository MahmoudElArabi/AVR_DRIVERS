/*
 * BIT_MATH.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MY_LIBS_BIT_MATH_H_
#define MY_LIBS_BIT_MATH_H_

#define SET_BIT(REG, POS)		(REG |= (1<<POS))
#define CLR_BIT(REG, POS)		(REG &= ~(1<<POS))
#define TOG_BIT(REG, POS)		(REG ^= (1<<POS))
#define GET_BIT(REG, POS)		((REG >> POS) & 0x01)

#endif /* MY_LIBS_BIT_MATH_H_ */
