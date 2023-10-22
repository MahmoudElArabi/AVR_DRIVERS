/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mahmoud El Arabi
 */

#include "LCD.h"

/*************** Helper Functions ***************/
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

static void LCD4_Command_Write(u8 command)
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

static void lcd4_set_cursor(u8 row, u8 coul){
    coul--;
    switch (row){
        case ROW1:
            LCD4_Command_Write(0x80+coul);
        break;
        case ROW2:
            LCD4_Command_Write(0xC0+coul);
        break;
        case ROW3:
            LCD4_Command_Write(0x94+coul);
        break;
        case ROW4:
            LCD4_Command_Write(0xD4+coul);
        break;
        default:;

    }
}



/************************************************/

void lcd4_Init(void)
{
	Pin_ConfigType LCD_pins[] =
	{
			{Dio_PORTB, pin_0, STD_OUT },
			{Dio_PORTB, pin_1, STD_OUT },
			{Dio_PORTB, pin_2, STD_OUT },
			{Dio_PORTB, pin_4, STD_OUT },
			{Dio_PORTA, pin_2, STD_OUT },
			{Dio_PORTA, pin_3, STD_OUT },
			{-1}
	};
	Port_Init(LCD_pins);
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

void lcd4_CLR(void)
{
	LCD4_Command_Write(0x01);
}

void lcd4_disply_char (u8 character)
{
	LCD_Data_write(character);
}

void lcd4_disply_string (const u8* str)
{
	 while (*str){
		lcd4_disply_char(*str);
		str++;
		}
}

void lcd4_disply_char_at_X_Y (u8 data, u8 row, u8 col)
{
	lcd4_set_cursor(row, col);
	LCD_Data_write(data);
}

void lcd4_disply_string_at_X_Y(u8* data, u8 row, u8 col)
{
	lcd4_set_cursor(row, col);
	lcd4_disply_string(data);
}

void lcd4_disply_num(u16 num) {
    char num_str[7];  // Assuming a 7-character buffer is sufficient
    snprintf(num_str, sizeof(num_str), "%d", num);

    // Display the string on the LCD character by character
    for (int i = 0; num_str[i] != '\0'; i++) {
        lcd4_disply_char(num_str[i]);
    }
}

void lcd4_disply_CustomCharacter(u8 row, u8 col, u8* CustomCharacter, u8 MemPos)
{
	LCD4_Command_Write(LCD_CGRAM_START + (MemPos * 8));
	for(int i = 0 ; i < 8 ; i++)
	{
		LCD_Data_write(CustomCharacter[i]);
	}
	lcd4_disply_char_at_X_Y(MemPos, row, col);
}
