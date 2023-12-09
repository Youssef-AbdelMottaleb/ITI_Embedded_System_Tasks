/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: USART						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Thursday, August 31, 2023 ******************************/
/*********************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART.h"


void USART_voidInit(void){


    u8 Local_u8UCSRC = 0x80;

    // Data Size, 8 Bit Data
    SET_BIT(Local_u8UCSRC, UCSZ0);
    SET_BIT(Local_u8UCSRC, UCSZ1);
    CLR_BIT(UCSRB, UCSZ2);
    
    // Config Parity, Disable
    CLR_BIT(Local_u8UCSRC, UPM0);
    CLR_BIT(Local_u8UCSRC, UPM1);

    // Config Stop Bit, 1 Bit
    CLR_BIT(Local_u8UCSRC, USBS);

    // Config USART Asynchronous
    CLR_BIT(Local_u8UCSRC, UMSEL);

    // Assign UCSRC Value as a Byte Access
    //UCSRC = Local_u8UCSRC;
    UCSRC = 0x86;

    // Config BaudRate, 9600, 51
    UBRRH = 0;
    UBRRL = 51;

    // Enable RX, TX
    SET_BIT(UCSRB, RXEN);
    SET_BIT(UCSRB, TXEN);
}

void USART_voidTransmitData(u8 Copy_u8Data){

    // Wait Untill UDR be Empty
    while(GET_BIT(UCSRA, UDRE) == 0);
    UDR = Copy_u8Data;
    // Wait Untill TXC be Empty
    while(GET_BIT(UCSRA, TXC) == 0);
    SET_BIT(UCSRA, TXC);
}

void USART_voidReceiveData(u8 * Copy_pu8Data){

    while(GET_BIT(UCSRA, RXC) == 0);
    
    if (Copy_pu8Data != NULL)
    {
        *Copy_pu8Data = UDR;
    } else{}
    
}
