#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "GIE_Interface.h"

#include "KPD_Interface.h"
#include "CLCD_Interface.h"
#include "USART_Interface.h"

						/* APPLICATION TO SEBD AND RECEIVE DATA USING USART AND CHECK THE ARRIVAL OF DATA BY LED OPENNING */
void ISR_SEND (void) ;
void ISR_RECIEVE (void);

uint8 arr[5]  = {'0'} ;
void main ()
{
	uint8 Local_u8Reading = 0xff ;

	uint8 Data = 0u ;

	//char arr[6] = {'1','2','k','l','7','m'} ;


	uint8 Sending_Flag = 0u ;

	PORT_voidInit() ;

	CLCD_voidInit() ;

	USART_voidInit() ;

	GIE_voidEnableGlobal() ;

	USART_u8RecieveByteAsynch(&Data,&ISR_RECIEVE) ;
	//USART_u8ReceiveBufferAsynch(arr,5u,&ISR_RECIEVE) ;
	while (1)
	{

		do
		{
			Local_u8Reading = KPD_u8GetPressedKey();

			/*Data = USART_u8RecieveByte();
			if (Data != TIMEOUT_ERR)
			{
				CLCD_voidSendData(Data) ;
				Data = TIMEOUT_ERR ;
			}
			else
			{
				// DO NOTHING
			}*/
		}while ( Local_u8Reading == 0xff);
		CLCD_voidSendData(Data) ;

		CLCD_voidSendData(Local_u8Reading) ;
		//char x = 'a' ;
		//USART_voidSendByteAsynch(&x,&ISR_SEND) ;

		//USART_u8SendBufferAsynch(arr,6,&ISR_SEND) ;

	/*	for (uint8 i = 0u ; i<5 ; i++)
		{
			CLCD_voidSendData(arr[i]) ;
		}*/
		//

		Local_u8Reading = 0xff ;


		/*if (Data == '1')
		{
			DIO_U8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_PIN_HIGH) ;
		}
		else
		{
			// DO NOTHING
		}*/
	}
}
void ISR_SEND (void)
{
	DIO_u8TogglePinValue(DIO_PORTC , DIO_PIN0 ) ;
}
void ISR_RECIEVE (void)
{
	DIO_u8TogglePinValue(DIO_PORTC , DIO_PIN0 ) ;
}




