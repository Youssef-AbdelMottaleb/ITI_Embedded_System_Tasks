/*#include <avr/io.h>
#include <util/delay.h>


#define GREEN_LED DIO_PIN0
#define YELLOW_LED DIO_PIN1
#define RED_LED DIO_PIN2

// 7-Segment Display Configuration
#define SEGMENT_PORT PORTB
#define DIGIT_PORT PORTC
#define SEG_A DIO_PIN0
#define SEG_B DIO_PIN1
#define SEG_C DIO_PIN2
#define SEG_D DIO_PIN3
#define SEG_E DIO_PIN4
#define SEG_F DIO_PIN5
#define SEG_G DIO_PIN6
#define SEG_DP DIO_PIN7
#define DIGIT_1 DIO_PIN0
#define DIGIT_2 DIO_PIN1

void initialize() {
    DIO_voidSetPinDirection(DIO_PORTA, GREEN_LED, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, YELLOW_LED, DIO_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, RED_LED, DIO_OUTPUT);
    
    DIO_voidSetPortDirection(SEGMENT_PORT, 0xFF); // Set all segments as outputs
    DIO_voidSetPortDirection(DIGIT_PORT, 0xFF);   // Set all digits as outputs

}

void turnOnLED(u8 pin) {
    DIO_voidSetPinValue(DIO_PORTA, pin, DIO_HIGH);
}

void turnOffLED(u8 pin) {
    DIO_voidSetPinValue(DIO_PORTA, pin, DIO_LOW);
}

void trafficLightSequence() {
    // Turn on Green LED for 10 seconds
    turnOnLED(GREEN_LED);
    _delay_ms(10000);
    turnOffLED(GREEN_LED);
    
    // Turn on Yellow LED for 3 seconds
    turnOnLED(YELLOW_LED);
    _delay_ms(3000);
    turnOffLED(YELLOW_LED);
    
    // Turn on Red LED for 10 seconds
    turnOnLED(RED_LED);
    _delay_ms(10000);
    turnOffLED(RED_LED);
}

void displayDigit(u8 digit) {
    // 7-segment display segment configurations for digits 0-9
    const u8 segmentConfig[] = {
        0b00111111, // 0
        0b00000110, // 1
        0b01011011, // 2
        0b01001111, // 3
        0b01100110, // 4
        0b01101101, // 5
        0b01111101, // 6
        0b00000111, // 7
        0b01111111, // 8
        0b01101111  // 9
    };

    DIO_voidSetPortValue(SEGMENT_PORT, segmentConfig[digit]);
}

void displayCountdown(u8 seconds) {
    u8 tens = seconds / 10;
    u8 ones = seconds % 10;

    // Display tens digit
    DIO_voidSetPinValue(DIGIT_PORT, DIGIT_1, DIO_HIGH);
    DIO_voidSetPinValue(DIGIT_PORT, DIGIT_2, DIO_LOW);
    displayDigit(tens);
    _delay_ms(5); // Delay for stable display
    
    // Display ones digit
    DIO_voidSetPinValue(DIGIT_PORT, DIGIT_1, DIO_LOW);
    DIO_voidSetPinValue(DIGIT_PORT, DIGIT_2, DIO_HIGH);
    displayDigit(ones);
    _delay_ms(5); // Delay for stable display
}

int main() {
    initialize();
    
    while (1) {
        trafficLightSequence();
        for (u8 i = 23; i > 0; i--) { // 23 seconds in total
            displayCountdown(i);
            _delay_ms(1000);
        }
    }

    return 0;
}
*/
