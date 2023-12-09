/*********************************************************************************/
/**********		Author 	: Youssef Abdel Mottaleb	******************************/
/**********		SWC 	: SSD						******************************/
/**********		Version : Version 1					******************************/
/**********		Date 	: Saturday, August 19, 2023	******************************/
/*********************************************************************************/

#ifndef		SSD_H
#define		SSD_H


/*SSD Configration*/
#define		COM_CATHODE	    1
#define		COM_ANODE	    0
/*-------------------------------------*/
#define 	SSD_TYPE	COM_CATHODE

#define		SSD_PORT	DIO_PORTC

#define		MAXIMUM_VALUE		0xff
#define		MINIMUM_VALUE		0x00

#define		ZERO		0b00111111
#define		ONE			0b00000110
#define		TWO			0b01011011
#define		THREE		0b01001111
#define		FOUR		0b01100110
#define		FIVE		0b01101101
#define		SIX			0b01111101
#define		SEVEN		0b00000111
#define		EIGHT		0b01111111
#define		NINE		0b01101111


#define		CONVERGING_1		0b00011000
#define		CONVERGING_2		0b00000110

//#define		DIVERGING_1			0b00000110
//#define		DIVERGING_2			0b00011000

#define		PING_PONG_1			0b00000001
#define		PING_PONG_2			0b00000010

	

void SSD_voidDisplayNumber (u8 Copy_u8Number);
// Function to simulate the traffic light system
void SSD_voidTrafficLightSimulation();
// Function to apply different animations based on DIP switch value
void SSD_voidLEDAnimations();



#endif
