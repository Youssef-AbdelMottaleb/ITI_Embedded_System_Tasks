/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: youss
 */


#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"

int main(){

	ADC_voidInit();
	LCD_voidInit();
	u16 Local_u16DigitalValue, Local_u16AnalogeValue, Localu16Temp;

	while(1){
		Local_u16DigitalValue = ADC_u16GetDigitalValue(ADC_CHANNEL0);
		Local_u16AnalogeValue = (Local_u16DigitalValue * 5000UL) / 1024; //5000 mVolt
		Localu16Temp =  Local_u16AnalogeValue / 10;
		LCD_voidSendNumber(Localu16Temp);
		_delay_ms(500);
		LCD_voidSendCommand(CLEAR_DISPLAY);
	}
	return 0;
}
