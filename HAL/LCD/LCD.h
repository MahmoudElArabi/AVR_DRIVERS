/*
 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_7SEGMENTS_LCD_H_
#define HAL_7SEGMENTS_LCD_H_

#include "../../MCAL/PORT/PORT.h"

#define LCD_ROW_NUMBERS			4
#define LCD_COL_NUMBERS			20

#define ROW1    ((u8)1)
#define ROW2    ((u8)2)
#define ROW3    ((u8)3)
#define ROW4    ((u8)4)

#define COL1	((u8)1)
#define COL2	((u8)2)
#define COL3	((u8)3)
#define COL4	((u8)4)
#define COL5	((u8)5)
#define COL6	((u8)6)
#define COL7	((u8)7)
#define COL8	((u8)8)
#define COL9	((u8)9)
#define COL10	((u8)10)
#define COL11	((u8)11)
#define COL12	((u8)12)
#define COL13	((u8)13)
#define COL14	((u8)14)
#define COL15	((u8)15)
#define COL16	((u8)16)
#define COL17	((u8)17)
#define COL18	((u8)18)
#define COL19	((u8)19)
#define COL20	((u8)20)

#define D4	PB_0
#define D5	PB_1
#define D6	PB_2
#define D7	PB_4

#define RS	PA_3
#define EN	PA_2

#define LCD_CLEAR_COMMAND                                                               0x01
#define LCD_CURSOR_HOME                                                                 0x02

#define LCD_ENTRY_MODE_INC_SHIFT_ON                                                     0x07
#define LCD_ENTRY_MODE_INC_SHIFT_OFF                                                    0x06
#define LCD_ENTRY_MODE_DEC_SHIFT_ON                                                     0x05
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF                                                    0x04

#define LCD_DISPLAY_OFF                                                                 0x08
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF                           0x0C
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_OFF                            0x0E
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON                             0x0F
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_ON                            0x0D

#define LCD_MOVE_CURSOR_LEFT                                                            0x10
#define LCD_MOVE_CURSOR_RIGHT                                                           0x14
#define LCD_SHIFT_DISPLAY_LEFT                                                          0x18
#define LCD_SHIFT_DISPLAY_RIGHT                                                         0x1C


#define LCD_FUNCTION_SET_8_BIT_2_LINE_8_DOTS                                            0x38
#define LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS                                            0x28
#define LCD_FUNCTION_SET_8_BIT_2_LINE_11_DOTS                                           0x3C
#define LCD_FUNCTION_SET_4_BIT_2_LINE_11_DOTS                                           0x2C

#define LCD_CGRAM_START                                                                 0x40
#define LCD_DDRAM_START                                                                 0x80

void lcd4_Init(void);
void lcd4_CLR(void);
void LCD_Command_Write (u8 command);
void lcd4_disply_char (u8 data);
void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col);
void lcd4_disply_string_at_X_Y(u8* data, u8 row, u8 col);
void lcd4_disply_string (u8* data);
void lcd4_disply_num (u8 num);
//void lcd4_CreateCustomCharacter(u8* Address_pu8CustomCharacter, u8 Copy_u8MemoryIndex);)

#endif /* HAL_7SEGMENTS_LCD_H_ */
