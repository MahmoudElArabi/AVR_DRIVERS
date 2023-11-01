/*
 * 7SEG.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_7SEGMENTS_7SEG_INTERFACE_H_
#define HAL_7SEGMENTS_7SEG_INTERFACE_H_

/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * Segment_Write : This function writes a value "num" on the chosen 7-segment
 * @param	1- num : which is the number to display
 * 			2- seg_index : which is the number of the segment 0, 1, 2 or 3
 * @return	void
 */
void Segment_Write(u8 num, u8 seg_index);


#endif /* HAL_7SEGMENTS_7SEG_INTERFACE_H_ */
