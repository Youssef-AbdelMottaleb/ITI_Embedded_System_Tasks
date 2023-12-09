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
#include "SSD.h"

int main(){

	/*
	DIO_voidSetPortDirection(DIO_PORTC, MAXIMUM_VALUE);
	//DIO_voidSetPortValue(DIO_PORTC, MAXIMUM_VALUE);

	while(1){
		/*
		if(DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0) == 0){
			_delay_ms(20);
			if(DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0) == 0){
				DIO_voidTogglePin(DIO_PORTA, DIO_PIN1);
			}
		}


		for(u8 Local_u8Count = 0; Local_u8Count <= 9; Local_u8Count++){
			SSD_voidDisplayNumber(Local_u8Count);
			_delay_ms(1000);
		}
	}

	*/

    // Initialize DIO Ports
    DIO_voidSetPortDirection(DIO_PORTA, DIO_INPUT);
    DIO_voidSetPortDirection(DIO_PORTB, MAXIMUM_VALUE);
    DIO_voidSetPortDirection(DIO_PORTC, MAXIMUM_VALUE);

    // Call the functions
    SSD_voidTrafficLightSimulation();
    //SSD_voidLEDAnimations();


	return 0;
}
