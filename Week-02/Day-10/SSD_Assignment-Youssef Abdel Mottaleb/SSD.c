/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: SSD						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Saturday, August 19, 2023	******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "SSD.h"

u8 Numbers [10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void SSD_voidDisplayNumber (u8 Copy_u8Number)
{
	#if SSD_TYPE == COM_CATHODE
	
	DIO_voidSetPortValue (SSD_PORT , Numbers[Copy_u8Number]);
	
	#elif SSD_TYPE == COM_ANODE
	
	DIO_voidSetPortValue (SSD_PORT , ~ Numbers[Copy_u8Number]);
	
	#endif
}


void SSD_voidTrafficLightSimulation(){
	// Turn on Green LED for 10 seconds
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
	_delay_ms(10000);

	// Turn on Yellow LED for 3 seconds
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_HIGH);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_LOW);
	_delay_ms(3000);

	// Turn on Red LED for 10 seconds
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_LOW);
	DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_HIGH);
	_delay_ms(10000);
}

void SSD_voidLEDAnimations() {
    // Read the value of the DIP switch
    u8 Local_u8DipValue = DIO_u8GetPortValue(DIO_PORTA);

    // Apply animations based on DIP switch value
    switch(Local_u8DipValue) {
        case 1:
            // Flashing every 500 ms
            DIO_voidTogglePin(DIO_PORTB, DIO_PIN0);
            _delay_ms(500);
            break;

        case 2:
            // Shifting Left every 250 ms
            DIO_voidSetPortValue(DIO_PORTB, DIO_u8GetPortValue(DIO_PORTB) << 1);
            _delay_ms(250);
            break;

        case 3:
            // Shifting Right every 250 ms
            DIO_voidSetPortValue(DIO_PORTB, DIO_u8GetPortValue(DIO_PORTB) >> 1);
            _delay_ms(250);
            break;

        case 4:
            // 2-LEDs Converging every 300 ms
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_1);
            _delay_ms(300);
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_2);
            _delay_ms(300);
            break;

        case 5:
            // 2-LEDs Diverging every 300 ms
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_2);
            _delay_ms(300);
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_1);
            _delay_ms(300);
            break;

        case 6:
            // Ping Pong effect every 250 ms
            DIO_voidSetPortValue(DIO_PORTB, PING_PONG_1);
            _delay_ms(250);
            DIO_voidSetPortValue(DIO_PORTB, PING_PONG_2);
            _delay_ms(250);
            break;

        case 7:
            // Incrementing (Snake effect) every 300 ms
            for (u8 Local_u8SnakeCounter = 0; Local_u8SnakeCounter < 8; Local_u8SnakeCounter++) {
                DIO_voidSetPortValue(DIO_PORTB, 1 << Local_u8SnakeCounter);
                _delay_ms(300);
            }
            break;

        case 8:
            // 2-LEDs Converging/Diverging every 300 ms
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_1);
            _delay_ms(300);
            DIO_voidSetPortValue(DIO_PORTB, CONVERGING_2);
            _delay_ms(300);
            break;

        default:
            DIO_voidSetPortValue(DIO_PORTB, MINIMUM_VALUE);
            break;
    }
}


