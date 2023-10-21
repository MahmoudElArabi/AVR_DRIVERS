/*
 * 7SEG.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_7SEGMENTS_7SEG_H_
#define HAL_7SEGMENTS_7SEG_H_


#include "../../MCAL/PORT/PORT.h"


void Segments_Init(void);
void Segment_Write(u8 num, u8 seg_index);


#endif /* HAL_7SEGMENTS_7SEG_H_ */
