/*
 * main.c
 *
 *  Created on: Aug 25, 2023
 *      Author: youss
 */

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"
#include "KPD.h"

int main(void){

	u8 x;
	LCD_voidInit();
	KPD_voidInit();

	while(1){
		x = KPD_u8GetPressedKey();
		if(x != KPD_CHECK_KEY){
			LCD_voidSendChar(x);
		}
	}

	return 0;
}
