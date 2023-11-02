#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "TIMER_Interface.h"

#include "CLCD_Interface.h"

#define 	OCR0                *((volatile uint8*)0x5C)		/*OUTPUT COMPARE REGISTER*/

static uint16 u16ChannelReading ;

											/* THIS CODE IS FOR LED INTENSITY CONTROL , DC MOTOR SPEED CONTROL & Buzzer Sound Tone */
	void main ()
	{

		PORT_voidInit() ;

		ADC_voidInit() ;

		TIMER0_voidInit() ;

		CLCD_voidInit() ;

		voidSendString("Compare Value :");

		while (1)
		{
			ADC_u8StartSingleConversionSynch(ADC0_SINGLE_ENDED , &u16ChannelReading ) ;
			OCR0 = u16ChannelReading ;
			CLCD_voidGoToXY(7u,1u);
			voidSendNumber(u16ChannelReading);
		}

	}






