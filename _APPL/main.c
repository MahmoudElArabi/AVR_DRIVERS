/*
 *  main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"
#include <util/delay.h>


/*-------------- GLOBALS --------------*/
u8 KEY = 'T';
u8 MODE = 0;
u8 Control = 0;
u8 LED = 0;
u8 ID = 0;
u16 PASS = 0;
u8 Received_SPI = 0;
u8 CHOOSE = 0;

/*------------ Functions PROTOTYPES -----------*/
void Slave_voidChooseMode_OnLCD(void);
void Asking_For_Info(void);
void Slave_voidDisplay_Mode(void);
void Slave_voidDisplay_Control (void);
void Slave_voidSel_SoundSys (void);
void Slave_u8Fan(void);
void Slave_voidSel_Led(void);

/*---------------- MAIN ------------*/
int main ()
{
	Port_Init(pins);
	lcd4_Init();
	Keypad_Init();
	ADC_void_Init();
	SPI_voidInit();

	// User asked to enter his ID and Pass
	Asking_For_Info();
	//now we need to send those data to the ADMIN to check if right and open the door
	lcd4_CLR();
	lcd4_disply_string((u8*)"Checking!");
	Dio_WriteChannel(PA_6, 1);
	SPI_voidTranseive(ID, &Received_SPI);
	_delay_ms(100);
	SPI_voidTranseive(((PASS / 100) % 10), &Received_SPI);
	_delay_ms(100);
	SPI_voidTranseive(((PASS / 10) % 10), &Received_SPI);
	_delay_ms(100);
	SPI_voidTranseive((PASS % 10), &Received_SPI);
	_delay_ms(100);
	SPI_voidTranseive(1, &Received_SPI);
	Dio_WriteChannel(PA_6, 0);

	lcd4_CLR();
	if(1 == Received_SPI)
	{
		while(1)
		{
			lcd4_CLR();
			Slave_voidChooseMode_OnLCD();
			switch (MODE)
			{
			case 1:
				Slave_voidDisplay_Mode();
				break;
			case 2:
				Slave_voidDisplay_Control();
				if(Control == 1)
				{
					Slave_voidSel_SoundSys();
				}
				else if(Control == 2)
				{
					Slave_u8Fan();
				}
				else if(Control == 3)
				{
					Slave_voidSel_Led();
				}
				break;
			default: break;
			}
		}

	}
	else
	{
		KEY = 'T';
		MODE = 0;
		Control = 0;
		LED = 0;
		ID = 0;
		PASS = 0;
		Received_SPI = 0;
		lcd4_disply_string((u8*)"Wrong, 2 trials");
		lcd4_disply_string_at_X_Y((u8*)"Please Try again!", 2,1);
		_delay_ms(2000);
		Asking_For_Info();
		lcd4_CLR();
		lcd4_disply_string((u8*)"Checking!");
		Dio_WriteChannel(PA_6, 1);
		SPI_voidTranseive(ID, &Received_SPI);
		_delay_ms(100);
		SPI_voidTranseive(((PASS / 100) % 10), &Received_SPI);
		_delay_ms(100);
		SPI_voidTranseive(((PASS / 10) % 10), &Received_SPI);
		_delay_ms(100);
		SPI_voidTranseive((PASS % 10), &Received_SPI);
		_delay_ms(100);
		SPI_voidTranseive(2, &Received_SPI);
		Dio_WriteChannel(PA_6, 0);

		lcd4_CLR();
		if(1 == Received_SPI)
		{
			Slave_voidChooseMode_OnLCD();
			switch (MODE)
			{
			case 1:
				Slave_voidDisplay_Mode();
				break;
			case 2:
				Slave_voidDisplay_Control();
				if(Control == 1)
				{
					Slave_voidSel_SoundSys();
				}
				else if(Control == 2)
				{
					Slave_u8Fan();
				}
				else if(Control == 3)
				{
					Slave_voidSel_Led();
				}
				break;
			default: break;
			}
		}
		else
		{
			KEY = 'T';
			MODE = 0;
			Control = 0;
			LED = 0;
			ID = 0;
			PASS = 0;
			Received_SPI = 0;
			lcd4_disply_string((u8*)"Wrong, last trial");
			lcd4_disply_string_at_X_Y((u8*)"Please Try again!", 2,1);
			_delay_ms(2000);
			Asking_For_Info();
			lcd4_CLR();
			lcd4_disply_string((u8*)"Checking!");
			Dio_WriteChannel(PA_6, 1);
			SPI_voidTranseive(ID, &Received_SPI);
			_delay_ms(100);
			SPI_voidTranseive(((PASS / 100) % 10), &Received_SPI);
			_delay_ms(100);
			SPI_voidTranseive(((PASS / 10) % 10), &Received_SPI);
			_delay_ms(100);
			SPI_voidTranseive((PASS % 10), &Received_SPI);
			_delay_ms(100);
			SPI_voidTranseive(3, &Received_SPI);
			Dio_WriteChannel(PA_6, 0);

			lcd4_CLR();
			if(1 == Received_SPI)
			{
				Slave_voidChooseMode_OnLCD();
				switch (MODE)
				{
				case 1:
					Slave_voidDisplay_Mode();
					break;
				case 2:
					Slave_voidDisplay_Control();
					if(Control == 1)
					{
						Slave_voidSel_SoundSys();
					}
					else if(Control == 2)
					{
						Slave_u8Fan();
					}
					else if(Control == 3)
					{
						Slave_voidSel_Led();
					}
					break;
				default: break;
				}
			}
			else
			{
				lcd4_disply_string((u8*)"Wrong, CHECK Admin");
			}
		}
	}
}


/*------------ Functions Implementation -----------*/

void Slave_voidChooseMode_OnLCD(void) {
	KEY='T';
	lcd4_CLR();
	lcd4_disply_string_at_X_Y((u8*)"Mode: ", 1, 1);
	lcd4_disply_string_at_X_Y((u8*)"1-Display",2,1);
	lcd4_disply_string_at_X_Y((u8*)"2-Control", 3, 1);
	lcd4_set_cursor(4, 1);
	while (1)
		{
			Keypad_Get_value(&KEY);
			if (KEY!='T')
			{
				if (KEY =='#')
				{
					break;
				}
				lcd4_disply_char(KEY);
				MODE = KEY - '0';
			}
		}
}

void Asking_For_Info(void)
{
	KEY='T';
	lcd4_CLR();
	lcd4_disply_string((u8*)"WELCOME");
	lcd4_set_cursor(2, 1);
	lcd4_disply_string((u8*)"ID  : ");
	while (1)
	{
		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			if (KEY =='#')
			{
				break;
			}
			lcd4_disply_char(KEY);
			ID = KEY - '0';
		}
	}
	lcd4_set_cursor(3, 1);
	lcd4_disply_string((u8*)"PASS: ");
	while (1)
	{
		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			if (KEY =='#')
			{
				break;
			}
			lcd4_disply_char('*');
			PASS = PASS * 10 + (KEY - '0');
		}
	}
}

void Slave_voidDisplay_Mode (void)
{
	 int temperature = 0;
	 KEY = 'T';
	 lcd4_CLR();
	 if(GET_BIT(_PORTD, 5))
	 {
		 lcd4_disply_string((u8*)"R: 1ON, ");
	 }
	 else
	 {
		 lcd4_disply_string((u8*)"R: 1OFF, ");
	 }
	 if(GET_BIT(_PORTD, 6))
	 {
		 lcd4_disply_string((u8*)"2ON, ");
	 }
	 else
	 {
		 lcd4_disply_string((u8*)"2OFF, ");
	 }

	 if(GET_BIT(_PORTD, 7))
	 {
		 lcd4_disply_string((u8*)"3ON");
	 }
	 else
	 {
		 lcd4_disply_string((u8*)"3OFF");
	 }

	 lcd4_set_cursor(2, 1);
	 lcd4_disply_string((u8*)"    Temp in C");

	 lcd4_set_cursor(3, 1);
	 if(GET_BIT(_PORTA, 5))
	 {
		 lcd4_disply_string((u8*)"AC ON");
	 }
	 else
	 {
		 lcd4_disply_string((u8*)"AC OFF");
	 }
	 lcd4_set_cursor(4, 1);
	 lcd4_disply_string((u8*)"1 to go back");
	 lcd4_set_cursor(2, 12);
	 while(1){
		 temperature = ADC_void_Read_CH(7);
		 temperature = (((u32)temperature * 5000UL)/1024) / 10 ;

		 lcd4_set_cursor(2, 12);
		 lcd4_disply_num(temperature);
		 Keypad_Get_value(&KEY);
		 if(KEY == '1')
		 {
			 break;
		 }
	}
}

void Slave_voidDisplay_Control (void)
{
	KEY='T';
	lcd4_CLR();
	lcd4_disply_string((u8*)"Control Mode");
	_delay_ms(1000);
	lcd4_CLR();
	lcd4_disply_string((u8*)"1->Sound System");
	lcd4_set_cursor(2,1);
	lcd4_disply_string((u8*)"2->AC");
	lcd4_set_cursor(3,1);
	lcd4_disply_string((u8*)"3->Light");
	lcd4_set_cursor(4,1);

	while (1)
	{
		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			if (KEY =='#')
			{
				break;
			}
			lcd4_disply_char(KEY);
			Control = KEY - '0';
		}
	}
	_delay_ms(30);
	lcd4_CLR();
}

void Slave_voidSel_SoundSys (void)
{
	lcd4_disply_string((u8*)"Music ON");
	Dio_WriteChannel(PD_0, 1);
	_delay_ms(1000);
	Dio_WriteChannel(PD_0, 0);
	_delay_ms(1000);
	Dio_WriteChannel(PD_0 , 1);
	_delay_ms(2000);
	Dio_WriteChannel(PD_0 , 0);
	lcd4_CLR();
}

void Slave_u8Fan(void) {
	KEY = 'T';
	int temperature = 0;
	lcd4_disply_string((u8*)"Temp in C: ");
	lcd4_set_cursor(2,1);
	lcd4_disply_string((u8*)"Press any K to exit");
	while (1) {
		temperature = ADC_void_Read_CH(7);
		temperature = (((u32)temperature * 5000UL)/1024) / 10 ;

		 lcd4_set_cursor(1, 12);
		 lcd4_disply_num(temperature);

		if (temperature < 20) {
			Dio_WriteChannel(PA_5, STD_LOW);
		}
		else if (temperature > 25) {
			Dio_WriteChannel(PA_5, STD_HIGH);
		}

		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			break;
		}
	}
}

void Slave_voidSel_Led(void) {
	KEY='T';
	lcd4_CLR();
	lcd4_disply_string((u8*)"Choose Room: ");
	lcd4_set_cursor(2, 1);
	lcd4_disply_string((u8*)"1 -> Room 1 ");
	lcd4_set_cursor(3, 1);
	lcd4_disply_string((u8*)"2 -> Room 2 ");
	lcd4_set_cursor(4, 1);
	lcd4_disply_string((u8*)"3 -> Room 3  : ");
	while (1)
	{
		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			if (KEY =='#')
			{
				break;
			}
			lcd4_disply_char(KEY);
			LED = KEY - '0';
		}
	}
	_delay_ms(50);
	lcd4_CLR();
	lcd4_disply_string((u8*)"Turning On The Led>>");
	lcd4_disply_num(LED);
	switch (LED) {
	case 1:
		Dio_WriteChannel(PD_5, STD_HIGH);
		break;
	case 2:
		Dio_WriteChannel(PD_6, STD_HIGH);
		break;
	case 3:
		Dio_WriteChannel(PD_7, STD_HIGH);
		break;
	}

	lcd4_set_cursor(2,1);
	lcd4_disply_string((u8*)"1->Go Back");
	lcd4_set_cursor(3, 1);
	lcd4_disply_string((u8*)"2->Turning Off Leds");
	lcd4_set_cursor(4, 1);
	lcd4_disply_string((u8*)"3->Main   ");

	KEY = 'T';
	CHOOSE = 0;
	while (1)
	{
		Keypad_Get_value(&KEY);
		if (KEY!='T')
		{
			if (KEY =='#')
			{
				break;
			}
			lcd4_disply_char(KEY);
			CHOOSE = KEY - '0';
		}
	}

	if (CHOOSE == 1) {
		Slave_voidSel_Led();
	}
	else if (CHOOSE == 2) {
			Dio_WriteChannel(PD_5, STD_LOW);
			Dio_WriteChannel(PD_6, STD_LOW);
			Dio_WriteChannel(PD_7, STD_LOW);
			Slave_voidSel_Led();
	}
}
