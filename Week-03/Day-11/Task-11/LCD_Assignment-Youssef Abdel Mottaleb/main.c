/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <util/delay.h>


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"

int main(){
	/*
	u8 customChar[] = {
		  0b10001,
		  0b01010,
		  0b00100,
		  0b00100,
		  0b00100,
		  0b00100,
		  0b00100,
		  0b00100
		};
	 */
	LCD_voidInit();
	//LCD_voidSendChar("Y");
	//LCD_voidSendChar("O");
	//LCD_voidSendChar("U");
	//LCD_voidSendChar("S");
	//LCD_voidSendChar("S");
	//LCD_voidSendChar("E");
	//LCD_voidSendChar("F");
	//LCD_voidSendString("HELLO");
	//LCD_voidSendSpecialChar(0, customChar);
	//LCD_voidSetLocation(LCD_L1_BASE_ADDRESS, 0);
	//LCD_voidSendChar(0);

	while(1){

	    // Create a custom sine wave animation
	    LCD_voidSineWave("Youssef Abdel Mottaleb");
	}

	return 0;
}
