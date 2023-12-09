/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "TIMER.h"

//void TOGG(void);
//void Traffic(void);

int main(){
	u8 Local_u8Value = 0;
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	//DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
	//DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);

	//TIMER0_voidSetCallBack(Traffic);
	TIMER0_voidInit();
	//sei();

	while(1){

		TIMER0_voidSetOCR0Value(Local_u8Value);
		Local_u8Value++;
		_delay_ms(50);
	}

	return 0;
}

/*
void TOGG(void){

	DIO_voidTogglePin(DIO_PORTA, DIO_PIN0);
}
*/
/*
void Traffic(void){
	static u8 counter = 0;
	counter++;
	if(counter <= 10){
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);

	}
	else if(counter <= 13){
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
	}

	else if(counter <= 23){
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
		if(counter == 23){
			counter = 0;
		}
	}
}
*/
