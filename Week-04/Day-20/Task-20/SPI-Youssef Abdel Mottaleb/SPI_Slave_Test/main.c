/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <util/delay.h>

#define		F_CPU		8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "SPI.h"

// Slave
int main(void){

	u8 Local_u8ReceivedData;

	// Init SPI
	SPI_voidInit();

	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	while(1){

		Local_u8ReceivedData = SPI_u8Tranceive(0xff);
		_delay_ms(500);

		switch(Local_u8ReceivedData){

		case 10:
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
			break;

		case 20:
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
			break;

		default:
			break;
		}
	}

	return 0;
}
