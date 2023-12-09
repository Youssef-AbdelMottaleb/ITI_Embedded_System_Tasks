#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\youss\ITI Embedded Systems 3-Months Program\ITI Embedded Systems Program\COTS\02-MCAL\01-DIO\01-Version_1\DIO.h"
#include "C:\Users\youss\ITI Embedded Systems 3-Months Program\ITI Embedded Systems Program\COTS\01-LIB\BIT_MATH.h"
#include "C:\Users\youss\ITI Embedded Systems 3-Months Program\ITI Embedded Systems Program\COTS\01-LIB\STD_TYPES.h"

#define DIP_PORT DIO_PORTB
#define DIP_SW1 DIO_PIN0
#define DIP_SW2 DIO_PIN1
#define DIP_SW3 DIO_PIN2

#define LED_STRING_PORT DIO_PORTA

void initialize() {
    DIO_voidSetPortDirection(LED_STRING_PORT, DIO_OUTPUT);
    DIO_voidSetPortDirection(DIP_PORT, DIO_INPUT);
}

void flashAnimation() {
    while (1) {
        DIO_voidTogglePortValue(LED_STRING_PORT);
        _delay_ms(500);
    }
}

void shiftLeftAnimation() {
    u8 ledValue = 0x01;
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        ledValue <<= 1;
        if (ledValue == 0) {
            ledValue = 0x01;
        }
        _delay_ms(250);
    }
}

void shiftRightAnimation() {
    u8 ledValue = 0x80;
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        ledValue >>= 1;
        if (ledValue == 0) {
            ledValue = 0x80;
        }
        _delay_ms(250);
    }
}

void convergingAnimation() {
    u8 ledValue = 0x18;
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        ledValue >>= 1;
        if (ledValue == 0) {
            ledValue = 0x18;
        }
        _delay_ms(300);
    }
}

void divergingAnimation() {
    u8 ledValue = 0x03;
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        ledValue <<= 1;
        if (ledValue == 0) {
            ledValue = 0x03;
        }
        _delay_ms(300);
    }
}

void pingPongAnimation() {
    u8 ledValue = 0x01;
    u8 direction = 1; // 1 for right, 0 for left
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        
        if (direction) {
            ledValue <<= 1;
            if (ledValue == 0x80) {
                direction = 0;
            }
        } else {
            ledValue >>= 1;
            if (ledValue == 0x01) {
                direction = 1;
            }
        }
        
        _delay_ms(250);
    }
}

void snakeAnimation() {
    u8 ledValue = 0x01;
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        ledValue <<= 1;
        if (ledValue == 0) {
            ledValue = 0x01;
        }
        _delay_ms(300);
    }
}

void convergingDivergingAnimation() {
    u8 ledValue = 0x18;
    u8 direction = 1; // 1 for converging, 0 for diverging
    
    while (1) {
        DIO_voidSetPortValue(LED_STRING_PORT, ledValue);
        
        if (direction) {
            ledValue >>= 1;
            if (ledValue == 0x00) {
                direction = 0;
            }
        } else {
            ledValue <<= 1;
            if (ledValue == 0x18) {
                direction = 1;
            }
        }
        
        _delay_ms(300);
    }
}

int main() {
    initialize();
    
    while (1) {
        if (DIO_u8GetPinValue(DIP_PORT, DIP_SW1) == DIO_HIGH) {
            flashAnimation();
        }
        else if (DIO_u8GetPinValue(DIP_PORT, DIP_SW2) == DIO_HIGH) {
            shiftLeftAnimation();
        }
        
        // If none of the DIP switches are active, turn off all LEDs
        DIO_voidSetPortValue(LED_STRING_PORT, 0x00);
    }

    return 0;
}
