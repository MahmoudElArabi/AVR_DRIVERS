/*
 * STD_TYPES.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MY_LIBS_STD_TYPES_H_
#define MY_LIBS_STD_TYPES_H_

#include <avr/io.h>
#include "util/delay.h"

typedef unsigned char		u8;
typedef signed char			s8;
typedef unsigned short		u16;
typedef signed short		s16;
typedef unsigned long int	u32;
typedef signed long int		s32;
typedef float				f32;
typedef double				f64;

#define NULL				(void*)0

#endif /* MY_LIBS_STD_TYPES_H_ */
