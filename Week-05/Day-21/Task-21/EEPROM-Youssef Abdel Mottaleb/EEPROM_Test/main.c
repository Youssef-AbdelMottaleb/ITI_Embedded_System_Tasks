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
#include "EEPROM.h"

int main(void){

	u8 Local_u8Data = 0;
	DIO_voidSetPortDirection(DIO_PORTA, 0xff);
	I2C_voidMasterInit();
	while(1){

		for(u8 i = 0; i < 8; i++){

			EEPROM_voidWriteDataByte(0, Local_u8Data);
			_delay_ms(50);
			DIO_voidSetPortValue(DIO_PORTA, EEPROM_u8ReadDataByte(0));
			Local_u8Data++;
			_delay_ms(500);
		}
		Local_u8Data = 0;

	}



	return 0;
}
