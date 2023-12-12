/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "LCD_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MCAL/DIO/DIO_Registers.h"
#include <util/delay.h>
#include "stdio.h"

/* ----------------- Section : Static "Private" Functions Declaration / Globals -----------------*/
static void LCD_Data_write(u8 data);
void LCD4_Command_Write(u8 command);

u8 current_pos = 0;

/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * lcd4_Init : This function initializes the LCD 4bit
 * @param	void
 * @return	void
 */
void lcd4_Init(void)
{
	_delay_ms(50);
	LCD4_Command_Write(LCD_CURSOR_HOME);
	LCD4_Command_Write(LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS);	//LCD 4bit mode, 2 line
	_delay_ms(1);
	LCD4_Command_Write(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON); //cursor on off,blink  0x0f,0x0c,0x0e
	_delay_ms(1);
	LCD4_Command_Write(LCD_CLEAR_COMMAND); //clear screen
	_delay_ms(2);
	LCD4_Command_Write(LCD_ENTRY_MODE_INC_SHIFT_OFF);	//increase DDRAM address
	_delay_ms(1);

	LCD4_Command_Write(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF);
	LCD4_Command_Write(LCD_DDRAM_START);
}

/**
 * lcd4_Init : This function Clears the LCD 4bit
 * @param	void
 * @return	void
 */
void lcd4_CLR(void)
{
	LCD4_Command_Write(0x01);
	current_pos = 0;
	lcd4_set_cursor(1,1);
}

/**
 * lcd4_disply_char : This function displays a character on the LCD 4bit
 * @param	data which is the character to display Ex: 'A'
 * @return	void
 */
void lcd4_disply_char (const u8 character)
{
	if(current_pos == 20 )
	{
		lcd4_set_cursor(2, 1);
	}
	else if(current_pos == 40 )
	{
		lcd4_set_cursor(3, 1);
	}
	else if(current_pos == 60 )
	{
		lcd4_set_cursor(4, 1);
	}
	else if (current_pos == 80)
	{
		lcd4_set_cursor(1, 1);
		current_pos = 0;
	}
	LCD_Data_write(character);
	current_pos ++;
}

/**
 * lcd4_disply_string : This function displays whole string on the LCD 4bit
 * @param	data which is the string to display Ex: "Mahmoud El Arabi"
 * @return	void
 */
void lcd4_disply_string (const u8* str)
{
	 while (*str){
	lcd4_disply_char(*str);
	str++;
	}
}

/**
 * lcd4_disply_char_at_X_Y : This function displays a character on the LCD 4bit at specific position
 * @param	1- data which is the character to display
 * 			2- row : the Row position of the character
 * 			3- col : the Column position of the character
 * 			Ex ('A', 2, 3) -> will display A @ [2,3]
 * @return	void
 */
void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col)
{
	lcd4_set_cursor(row, col);
	LCD_Data_write(data);
}

/**
 * lcd4_disply_string_at_X_Y : This function displays a whole string on the LCD 4bit at specific position
 * @param	1- data which is the string to display Ex: "Mahmoud El Arabi"
 * 			2- row : the Row position of the 1st character of the string which is 'M' here
 * 			3- col : the Column position of the 1st character of the string which is 'M' here
 * 			Ex ("Mahmoud El Arabi", 2, 3) -> will display "Mahmoud El Arabi" @ [2,3]
 * @return	void
 */
void lcd4_disply_string_at_X_Y(u8* data, u8 row, u8 col)
{
	lcd4_set_cursor(row, col);
	lcd4_disply_string(data);
}

/**
 * lcd4_disply_num : This function converts the nu,ber to string and displays it on the LCD 4bit
 * @param	num which is the number to display
 * @return	void
 */
void lcd4_disply_num(u16 num) {
    char num_str[7];  // Assuming a 7-character buffer is sufficient
    snprintf(num_str, sizeof(num_str), "%d", num);

    // Display the string on the LCD character by character
    for (int i = 0; num_str[i] != '\0'; i++) {
        lcd4_disply_char(num_str[i]);
    }
}

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
void lcd4_disply_CustomCharacter(u8 row, u8 col, u8* CustomCharacter, u8 MemPos)
{
	LCD4_Command_Write(LCD_CGRAM_START + (MemPos * 8));
	for(int i = 0 ; i < 8 ; i++)
	{
		LCD_Data_write(CustomCharacter[i]);
	}
	lcd4_disply_char_at_X_Y(MemPos, row, col);
}

void lcd4_set_cursor(u8 row, u8 coul){
    coul--;
    switch (row){
        case ROW1:
            LCD4_Command_Write(0x80+coul);
            current_pos = 0;
        break;
        case ROW2:
            LCD4_Command_Write(0xC0+coul);
            current_pos = 20;
        break;
        case ROW3:
            LCD4_Command_Write(0x94+coul);
            current_pos = 40;
        break;
        case ROW4:
            LCD4_Command_Write(0xD4+coul);
            current_pos = 60;
        break;
        default:
        	break;
    }
}

void displayTextAnimated(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        lcd4_disply_char(text[i]);
        _delay_ms(50); // Adjust the delay as needed
    }
}
/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/

static void LCD_Data_write(u8 data)
{
	Dio_WriteChannel(RS,STD_HIGH);

	Dio_WriteChannel(D4,GET_BIT(data,4));
	Dio_WriteChannel(D5,GET_BIT(data,5));
	Dio_WriteChannel(D6,GET_BIT(data,6));
	Dio_WriteChannel(D7,GET_BIT(data,7));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);

	Dio_WriteChannel(D4,GET_BIT(data,0));
	Dio_WriteChannel(D5,GET_BIT(data,1));
	Dio_WriteChannel(D6,GET_BIT(data,2));
	Dio_WriteChannel(D7,GET_BIT(data,3));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);
}

void LCD4_Command_Write(u8 command)
{
	Dio_WriteChannel(RS,STD_LOW);

	Dio_WriteChannel(D4,GET_BIT(command,4));
	Dio_WriteChannel(D5,GET_BIT(command,5));
	Dio_WriteChannel(D6,GET_BIT(command,6));
	Dio_WriteChannel(D7,GET_BIT(command,7));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);

	Dio_WriteChannel(D4,GET_BIT(command,0));
	Dio_WriteChannel(D5,GET_BIT(command,1));
	Dio_WriteChannel(D6,GET_BIT(command,2));
	Dio_WriteChannel(D7,GET_BIT(command,3));
	Dio_WriteChannel(EN,STD_HIGH);
	_delay_ms(1);
	Dio_WriteChannel(EN,STD_LOW);
	_delay_ms(1);
}

