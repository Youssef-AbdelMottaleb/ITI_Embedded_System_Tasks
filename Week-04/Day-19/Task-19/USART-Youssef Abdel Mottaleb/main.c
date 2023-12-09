/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "USART.h"

#define F_CPU		8000000UL


int main(void){

	u8 Local_u8ReceivedData;

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, DIO_OUTPUT);

	// RX PD0, INPUT
	DIO_voidSetPinDirection(DIO_PORTD, PIN0, DIO_INPUT);

	// TX PD1 OUTPUT
	DIO_voidSetPinDirection(DIO_PORTD, PIN1, DIO_OUTPUT);

	USART_voidInit();

	while(1){

		USART_voidReceiveData(&Local_u8ReceivedData);

		USART_voidTransmitData(Local_u8ReceivedData);

		switch(Local_u8ReceivedData){

			case 'A':
				DIO_voidSetPinValue(DIO_PORTA, PIN0, DIO_HIGH);
				break;

			case 'B':
				DIO_voidSetPinValue(DIO_PORTA, PIN0, DIO_LOW);
				break;

			default:
				break;

		}
	}
	return 0;
}
