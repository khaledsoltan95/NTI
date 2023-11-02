#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "SPI_Interface.h"
#include "GIE_Interface.h"

void ISR ( void ) ;
uint8 local_u8Data ;
							/* THIS PROGRAM FOR TESTING THAT DATA SENT FROM MASTER USING SPI PROTOCOL HAS BEEN RECEIVED TO SLAVE SUCCESSFULLY */
void main ()
{
	PORT_voidInit() ;

	SPI_voidInitial() ;

	SPI_u8SetCallBack( &ISR ) ;

	GIE_voidEnableGlobal();

	while (1)
	{

	}
}

void ISR ( void )
{

	local_u8Data = SPI_u8Transceive('6') ;

	if (local_u8Data == '9')
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
	}
	else
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
	}
}

