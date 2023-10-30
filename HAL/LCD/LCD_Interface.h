/*
 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_7SEGMENTS_LCD_H_
#define HAL_7SEGMENTS_LCD_H_

/* ----------------- Section : includes -----------------*/

#include "../../MCAL/PORT/PORT_Interface.h"


/* ----------------- Section : Macro Declarations -----------------*/

#define LCD_ROW_NUMBERS			4
#define LCD_COL_NUMBERS			20

#define ROW1    				((u8)1)
#define ROW2    				((u8)2)
#define ROW3    				((u8)3)
#define ROW4    				((u8)4)

#define COL1	                ((u8)1)
#define COL2	                ((u8)2)
#define COL3	                ((u8)3)
#define COL4	                ((u8)4)
#define COL5	                ((u8)5)
#define COL6	                ((u8)6)
#define COL7	                ((u8)7)
#define COL8	                ((u8)8)
#define COL9	                ((u8)9)
#define COL10	                ((u8)10)
#define COL11	                ((u8)11)
#define COL12	                ((u8)12)
#define COL13	                ((u8)13)
#define COL14	                ((u8)14)
#define COL15	                ((u8)15)
#define COL16	                ((u8)16)
#define COL17	                ((u8)17)
#define COL18	                ((u8)18)
#define COL19	                ((u8)19)
#define COL20	                ((u8)20)

#define D4	                    PB_0
#define D5	                    PB_1
#define D6	                    PB_2
#define D7	                    PB_4

#define RS	                    PA_3
#define EN	                    PA_2

#define LCD_CLEAR_COMMAND                                        	0x01
#define LCD_CURSOR_HOME                                          	0x02

#define LCD_ENTRY_MODE_INC_SHIFT_ON                               	0x07
#define LCD_ENTRY_MODE_INC_SHIFT_OFF                              	0x06
#define LCD_ENTRY_MODE_DEC_SHIFT_ON                               	0x05
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF                              	0x04

#define LCD_DISPLAY_OFF                                           	0x08
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF     	0x0C
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_OFF      	0x0E
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON       	0x0F
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_ON      	0x0D

#define LCD_MOVE_CURSOR_LEFT                                      	0x10
#define LCD_MOVE_CURSOR_RIGHT                                     	0x14
#define LCD_SHIFT_DISPLAY_LEFT                                    	0x18
#define LCD_SHIFT_DISPLAY_RIGHT                                   	0x1C


#define LCD_FUNCTION_SET_8_BIT_2_LINE_8_DOTS                      	0x38
#define LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS                      	0x28
#define LCD_FUNCTION_SET_8_BIT_2_LINE_11_DOTS                     	0x3C
#define LCD_FUNCTION_SET_4_BIT_2_LINE_11_DOTS                     	0x2C

#define LCD_CGRAM_START                                           	0x40
#define LCD_DDRAM_START                                           	0x80


/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * lcd4_Init : This function initializes the LCD 4bit
 * @param	void
 * @return	void
 */
void lcd4_Init(void);

/**
 * lcd4_Init : This function Clears the LCD 4bit
 * @param	void
 * @return	void
 */
void lcd4_CLR(void);

/**
 * lcd4_disply_char : This function displays a character on the LCD 4bit
 * @param	data which is the character to display Ex: 'A'
 * @return	void
 */
void lcd4_disply_char (const u8 data);

/**
 * lcd4_disply_string : This function displays whole string on the LCD 4bit
 * @param	data which is the string to display Ex: "Mahmoud El Arabi"
 * @return	void
 */
void lcd4_disply_string (const u8* data);

/**
 * lcd4_disply_char_at_X_Y : This function displays a character on the LCD 4bit at specific position
 * @param	1- data which is the character to display
 * 			2- row : the Row position of the character
 * 			3- col : the Column position of the character
 * 			Ex ('A', 2, 3) -> will display A @ [2,3]
 * @return	void
 */
void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col);

/**
 * lcd4_disply_string_at_X_Y : This function displays a whole string on the LCD 4bit at specific position
 * @param	1- data which is the string to display Ex: "Mahmoud El Arabi"
 * 			2- row : the Row position of the 1st character of the string which is 'M' here
 * 			3- col : the Column position of the 1st character of the string which is 'M' here
 * 			Ex ("Mahmoud El Arabi", 2, 3) -> will display "Mahmoud El Arabi" @ [2,3]
 * @return	void
 */
void lcd4_disply_string_at_X_Y(u8* data, u8 row, u8 col);

/**
 * lcd4_disply_num : This function converts the nu,ber to string and displays it on the LCD 4bit
 * @param	num which is the number to display
 * @return	void
 */
void lcd4_disply_num (u16 num);

/**
 * lcd4_disply_CustomCharacter : This function displays a custom on the LCD 4bit
 * @param	1- row : The row where the custom character will be displayed (0 to 3).
 * 			2- col : The column where the custom character will be displayed (0 to 19).
 * 			3- CustomCharacter:  Pointer to the custom character data in memory (an array of 8 bytes).
 * 			4- MemoryPos : The memory position where the custom character is stored in the LCD module (0 to 7).
 *
 * 			Ex: u8 customChar[] = {0x0E, 0x1B, 0x1F, 0x1F, 0x1F, 0x1F, 0x1B, 0x0E};
 * 				lcd4_disply_CustomCharacter(1, 5, customChar, 0);
 * @return	void
 */
void lcd4_disply_CustomCharacter(u8 row, u8 col, u8* CustomCharacter, u8 MemoryPos);


void lcd4_set_cursor(u8 row, u8 coul);
#endif /* HAL_7SEGMENTS_LCD_H_ */
