#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "TIMER_Interface.h"

#include "CLCD_Interface.h"



void main ()
{
	uint8 Local_u8Counter ;

	PORT_voidInit() ;

	TIMER0_voidInit() ;

	CLCD_voidInit() ;

	DIO_PinVal_t Reading ;

	voidSendString("Counter:");

	Local_u8Counter = TIMER0_u8ResetTCNTO() ;

	CLCD_voidGoToXY(7u,1u);
	voidSendNumber(Local_u8Counter);


	while (1)
	{
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN7 , &Reading ) ;
		if ( Reading == DIO_PIN_LOW )
		{
			Local_u8Counter = TIMER0_u8CounterFunction();
			CLCD_voidGoToXY(7u,1u);
			voidSendNumber(Local_u8Counter);
		}
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN6 , &Reading ) ;
		if ( Reading == DIO_PIN_LOW )
		{
			Local_u8Counter = TIMER0_u8ResetTCNTO();
			CLCD_voidGoToXY(7u,1u);
			voidSendNumber(Local_u8Counter);
		}
	}
}





