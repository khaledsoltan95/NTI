#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <util/delay.h>

#include "DIO_Interface.h"

#include "CLCD_Prv.h"
#include "CLCD_Cfg.h"
#include "CLCD_Interface.h"



							/* Assumed that CLCD_8BitMode in one PORT */

void CLCD_voidSendEnablePulse (void)
{
									// Send Enable Pulse

	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
		//
}
void CLCD_voidSendHalf (uint8 Local_u8Command)
{
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(Local_u8Command,3)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(Local_u8Command,2)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(Local_u8Command,1)) ;
	DIO_U8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(Local_u8Command,0)) ;
}
void CLCD_voidSendCommand (uint8 Local_u8Command)
{
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW) ;         // Command Selection

#if CLCD_u8READ_OPERATION_ENABLE == ENABLED

	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
#else
	// Do Nothing
#endif
#if CLCD_U8CONNECTION_MODE == EIGHT_BIT

		DIO_U8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Command);

#elif CLCD_U8CONNECTION_MODE == FOUR_BIT

		CLCD_voidSendHalf( Local_u8Command >> 4u ) ;
		CLCD_voidSendEnablePulse() ;
		CLCD_voidSendHalf( Local_u8Command ) ;

#else
#error "Not Valid CLCD_U8CONNECTION_MODE Option"

#endif
CLCD_voidSendEnablePulse();

}
void CLCD_voidInit (void)
{

						/* Wait More Than 30 mSec After Power ON */
	_delay_ms(40) ;
#if CLCD_U8CONNECTION_MODE == EIGHT_BIT
						/*SET FUNCTION SET */
	CLCD_voidSendCommand(0b00111000) ;

#elif CLCD_U8CONNECTION_MODE == FOUR_BIT

	CLCD_voidSendHalf( 0b0010 ) ;
	CLCD_voidSendEnablePulse ();
	CLCD_voidSendHalf( 0b0010 ) ;
	CLCD_voidSendEnablePulse ();
	CLCD_voidSendHalf( 0b1000 ) ;
	CLCD_voidSendEnablePulse ();

#else
#error "Selection CLCD_U8CONNECTION_MODE Not Valid"
#endif

						/* Wait More Than 39 uSec After Power ON */
	//_delay_us(50) ;
						/*SET FUNCTION SET */
	CLCD_voidSendCommand(0b00001100) ;
						/* Wait More Than 39 uSec After Power ON */
	//_delay_us(50) ;
						/*SET FUNCTION SET */
	CLCD_voidSendCommand(1) ;
						/* Wait More Than 39 uSec After Power ON */
	//_delay_ms(2) ;






}
void CLCD_voidSendData (uint8 Local_u8Data)
{
	DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH) ;         // Command Selection

	#if 		CLCD_u8READ_OPERATION_ENABLE == ENABLED

		DIO_U8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_LOW);
	#else
		// Do Nothing
	#endif
	#if CLCD_U8CONNECTION_MODE == EIGHT_BIT

			DIO_U8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);

	#elif CLCD_U8CONNECTION_MODE == FOUR_BIT

			CLCD_voidSendHalf( Local_u8Data >> 4u ) ;
			CLCD_voidSendEnablePulse() ;
			CLCD_voidSendHalf( Local_u8Data ) ;

	#else
	#error "Not Valid CLCD_U8CONNECTION_MODE Option"

	#endif

			CLCD_voidSendEnablePulse() ;

}
uint8 CLCD_u8SendString (char*Copy_u8String )
{
	uint8 Local_u8ErrorState = OK ;
	if (Copy_u8String != NULL)
	{
		uint8 Local_u8Iterator = 0 ;
		while (Copy_u8String[Local_u8Iterator] != '\0' )
		{
			CLCD_voidSendData(Copy_u8String[Local_u8Iterator]) ;
			Local_u8Iterator ++ ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}
