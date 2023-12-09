/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: SPI						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Thursday, August 31, 2023 ******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "SPI.h"


void SPI_voidInit(void){

    // SPI MODE Master, Slave
    #if SPI_MODE == SPI_MSTR
        // MOSI OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
        // MISO INPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_INPUT);
        // SCK OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);
        // SS OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
        DIO_voidSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);

        SET_BIT(SPCR, MSTR);

    #elif SPI_MODE == SPI_SLAVE
        // MOSI OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_INPUT);
        // MISO INPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
        // SCK OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_INPUT);
        // SS OUTPUT
        DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_INPUT);

        CLR_BIT(SPCR, MSTR);

    #endif

    // Data Order, LSB --> 1, MSB --> 0
    SET_BIT(SPCR, DORD);

    // Polarity, Leading Rising
    CLR_BIT(SPCR, CPOL);

    // Clock Phase, Set Leading
    SET_BIT(SPCR, CPHA);

    // Select Clock Prescaler, 64 Scaler
    CLR_BIT(SPCR, SPR0);
    SET_BIT(SPCR, SPR1);

    // Enable SPI
    SET_BIT(SPCR, SPE);

}

/*
void SPI_voidTransmit(u8 Copy_u8Data){

    u8 Local_u8Dummy;
    SPDR = Copy_u8Data;

    // Wait Till Transmission Ends
    while(GET_BIT(SPSR, SPIF) == 0);

    Local_u8Dummy = SPDR;
}
*/

u8 SPI_u8Tranceive(u8 Copy_u8Data){

    SPDR = Copy_u8Data;

    // Wait Till Transmission Ends
    while(GET_BIT(SPSR, SPIF) == 0);
    
    return SPDR;
    
}

/*
u8 SPI_u8Receive(void){

    // Wait Till Transmission Ends
    while(GET_BIT(SPSR, SPIF) == 0);
    
    return SPDR;

}
*/
