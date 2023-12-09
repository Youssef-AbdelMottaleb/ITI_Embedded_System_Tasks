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

	I2C_voidMasterInit();
	while(1){

		I2C_voidStartCondition();
		I2C_voidSlaveAddressWrite(1);
		I2C_voidMasterSendData('1');
		I2C_voidStopCondition();
		_delay_ms(500);

		I2C_voidStartCondition();
		I2C_voidSlaveAddressWrite(1);
		I2C_voidMasterSendData('2');
		I2C_voidStopCondition();
		_delay_ms(500);
	}



	return 0;
}
