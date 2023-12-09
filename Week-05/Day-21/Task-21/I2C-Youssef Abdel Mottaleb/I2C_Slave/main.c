/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: youss
 */

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "I2C.h"

int main(void){

	u8 Local_u8Data;
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	I2C_voidSlaveInit(1);
	while(1){
		Local_u8Data = I2C_u8SlaveReceiveData();

		if(Local_u8Data == '1'){
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
		}
		else if(Local_u8Data == '2')
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);

	}



	return 0;
}
