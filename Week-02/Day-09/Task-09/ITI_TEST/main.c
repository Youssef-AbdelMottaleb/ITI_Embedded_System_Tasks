/*
#include <avr/io.h>
#include <util/delay.h>
int main(){

	// PIN0 at PORTA ==> OUTPUT
	DDRA = 0b00000001;
	// PIN0 at PORTA ==> HIGH
	PORTA = 0b00000001;
	// super loop
	while(1){
		PORTA = 0b00000001;
		_delay_ms(500);
		PORTA = 0;
		_delay_ms(500);
	}
	return 0;
}
*/

#include <avr/io.h>
#include <util/delay.h>

int main() {
    // Configure PORTA pins 0-7 as OUTPUT
    DDRA = 0xFF;  // 0b11111111
    PORTA = 0x00; // Initially turn off all LEDs

    while (1) {
        // Odd LEDs sequential pattern
        for (int i = 0; i < 8; i += 2) {
            PORTA |= (1 << i); // Turn on the current LED
            _delay_ms(1000);
        }

        PORTA = 0x00;

        // Even LEDs sequential pattern
        for (int i = 1; i < 8; i += 2) {
            PORTA |= (1 << i); // Turn on the current LED
            _delay_ms(1000);
        }

        // Turn off all LEDs
        PORTA = 0x00;
    }

    return 0;
}
