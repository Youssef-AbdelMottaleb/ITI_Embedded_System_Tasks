/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: youss
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "INT.h"

void Func(void);

void Func(void){
	DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
}

int main(){

	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);
	DIO_voidSetPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH);

	INT_voidSetCallBack(EXT_INT0, Func);
	sei();
	INT_voidEnable(EXT_INT0, INT_FALLING_EDGE);

	while(1);

	return 0;
}
