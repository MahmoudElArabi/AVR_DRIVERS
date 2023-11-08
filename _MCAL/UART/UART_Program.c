/*
 * UART_Program.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Mahmoud El Arabi
 */


/* ----------------- Section : includes -----------------*/
#include "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Registers.h"
#include "../../_MCAL/DIO/DIO_Interface.h"
#include "../../_MY_LIBS/BIT_MATH.h"
#include <stdlib.h>

/* ----------------- Section : Static "Private" Functions Declaration / Functions pointers -----------------*/


/* ----------------- Section : Software Interfaces Implementation -----------------*/
void UART_Init()
{
	u16 rest = (1000000 /UART_BAUDRATE) - 1;
	_UBRRL = rest;
	switch(UART_SPEED_MODE)
	{
	case ASY_NORMAL_SPEED:
		CLR_BIT(_UCSRA,1);
		break;
	case ASY_DOUPLE_SPEED:
		SET_BIT(_UCSRA,1);
		break;
	case SYN_MASTER_MODE:
		SET_BIT(_UCSRC, 6);
		break;
	}
	// ENABLE RX TX
	SET_BIT(_UCSRB,4);
	SET_BIT(_UCSRB,3);
}

void UART_TransmitData(u8 data)
{
	while(!GET_BIT(_UCSRA,5));
	_UDR = data;
}

u8 UART_ReceiveData()
{
	while(!GET_BIT(_UCSRA,7));
	return _UDR;
}

#include <stdbool.h>

// Function to receive a number over UART, terminated by '\r' (Enter key)
int UART_ReceiveNumber() {
    char rxBuffer[20];  // A buffer to store received characters
    int rxIndex = 0;    // Index for the buffer
    char receivedChar;
    u8 endOfNumber = 0;

    // Read characters until Enter ('\r') is received
    while (!endOfNumber) {
        while (!GET_BIT(_UCSRA, 7));  // Wait for a character to be received
        receivedChar = _UDR;          // Read the received character

        if (receivedChar == '\r' || receivedChar == '\n') {
            // If Enter key is received, mark the end of the number
            endOfNumber = 1;
        } else {
            // Store the character in the buffer
            rxBuffer[rxIndex] = receivedChar;
            rxIndex++;

            // Check if the buffer is full (adjust the buffer size as needed)
            if (rxIndex >= sizeof(rxBuffer)) {
                rxIndex = sizeof(rxBuffer) - 1;
            }
        }
    }

    // Null-terminate the string in the buffer
    rxBuffer[rxIndex] = '\0';

    // Convert the received string to an integer
    int receivedNumber = atoi(rxBuffer);

    return receivedNumber;
}

void UART_TransmitString(const char* str) {
    // Iterate over each character in the string until the null terminator is reached
    for (int i = 0; str[i] != '\0'; i++) {
        UART_TransmitData(str[i]); // Transmit each character
    }
}

/* ----------------- Section : Static "Private" Functions Declaration Implementation -----------------*/

