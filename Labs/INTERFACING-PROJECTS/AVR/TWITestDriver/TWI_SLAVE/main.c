#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"
#include <util/delay.h>

#include "TWI_Interface.h"
#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "GIE_Interface.h"

void TWI_ISR (void) ;

static volatile uint8 Local_u8Reading  = 5u ;
void main ()
{

	PORT_voidInit();

	TWI_u8SlaveInit(3u) ;

	GIE_voidEnableGlobal() ;

	TWI_u8SetCallBack(&TWI_ISR) ;

	while (1)
	{
//		Local_u8Reading = TWI_voidSlaveInit(3u) ;
//		 while (!GET_BIT(TWCR ,TWCR_TWINT));
//		Local_u8Reading = TWDR ;
//
//
//
//		if ( Local_u8Reading == '7' )
//		{
//			DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH) ;
//		}
//		else
//		{
//			DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH) ;
//		}
	}
}
void TWI_ISR (void)
{

							/* CLEAR TWINT FLAG */

	SET_BIT(TWCR,TWCR_TWINT) ; 								//	THIS FLAG IS CLEARING WITH SETTING IT NOT CLEARING IT AS USUAL

							/* WAIT UNTIL TWINT FLAG RAISED */

	while ( ( GET_BIT(TWCR,TWCR_TWINT ) ) != 1 ) ;

	Local_u8Reading = TWDR ;

	if ( Local_u8Reading == '7' )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH) ;
	}
	else
	{
		DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN2) ;
	}
}
