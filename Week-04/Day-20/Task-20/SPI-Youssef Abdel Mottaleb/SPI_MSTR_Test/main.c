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

// Master
int main(void){

	u8 Local_u8Dummy;

	// Init SPI
	SPI_voidInit();

	while(1){

		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
		Local_u8Dummy = SPI_u8Tranceive(10);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
		_delay_ms(500);

		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
		Local_u8Dummy = SPI_u8Tranceive(20);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
		_delay_ms(500);
	}

	return 0;
}
