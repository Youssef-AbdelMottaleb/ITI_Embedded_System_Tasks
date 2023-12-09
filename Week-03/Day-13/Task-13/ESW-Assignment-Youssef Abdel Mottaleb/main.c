/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"
#include "MOTOR.h"


int main()
{
	//DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);
	//DIO_voidSetPinValue(DIO_PORTD, DIO_PIN0, DIO_HIGH);
	//DIO_voidSetPinValue(DIO_PORTD, DIO_PIN0, DIO_LOW);

	MOTOR_voidInit();
	MOTOR_voidClockwiseRotation(100);
	LCD_voidDisplayDirection(0); // 0 ==> CLOCKWISE, 1 ==> COUNTER CLOCKWISE

	while(1);/*{
		if(DIO_u8GetPinValue(DIO_PORTD, DIO_PIN0) == DIO_HIGH){

			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);

		}
		else{
			//DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_HIGH);
			DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);


		}
	}*/
	return 0;
}

