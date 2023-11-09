/*
 * Assignment_Private_Functions.c
 *
 *  Created on: May 28, 2023
 *      Author: KHALED
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "util/delay.h"

#include "DIO_Interface.h"
#include "ADC_Interface.h"

#include "EXTI_Interface.h"
#include "GIE_Interface.h"
#include "CLCD_Interface.h"
#include "KPD_Interface.h"
#include "LM35_Interface.h"
#include "LDR_Interface.h"

#include "Assignment_Private_Headers.h"

		uint8 u8_Flag ;

void Hamoksha_voidWelcome (void)
{
	/* Run 1  Pattern */
	uint8 Local_u8Pattern1Arr[8]={ 0b00001110 ,
			0b00001110 ,
			0b00000101 ,
			0b00001110 ,
			0b00010100 ,
			0b00001110 ,
			0b00010001 ,
			0 } ;
	/* Run 2  Pattern */
	uint8 Local_u8Pattern2Arr[8]={ 0b00001110 ,
			0b00001110 ,
			0b00010100 ,
			0b00001110 ,
			0b00000101 ,
			0b00001110 ,
			0b00010001 ,
			0 } ;
	uint8 Local_u8ZeroArr[8]={0};
	uint8 XPos = 0 ;
	CLCD_voidSendCommand(1);
	CLCD_voidGoToXY(5U,0U);
	voidSendString("WELCOME");
	while ( XPos !=16 )
	{
		//CLCD_voidSendCommand(1);
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern1Arr, XPos , 1u );
		_delay_ms(250);
		CLCD_u8WriteSpecialCharacter( 3u , Local_u8ZeroArr, XPos , 1u );
		XPos ++ ;
		//CLCD_voidSendCommand(1);
		CLCD_u8WriteSpecialCharacter( 2u , Local_u8Pattern2Arr, XPos , 1u );
		_delay_ms(250);
		CLCD_u8WriteSpecialCharacter( 3u , Local_u8ZeroArr, XPos , 1u );
		XPos ++ ;
	}
}
void CLCD_voidID (void)
{
	u8_Flag = 1 ;
	uint8 Local_u8TrialCounter = 1 ;
	uint8 Local_u8IDCounter = 0 ;
	uint8 Local_u8ID[4] ;
	uint8 Local_u8Password[4] ;
	uint8 Local_u8PasswordEntry[4] ;
	uint8 Local_u8Iterator = 0 ;
	uint8 Local_u8XPos = 0 ;
	uint8 Local_u8Flag = 0 ;
	uint8 Local_u8PasswordCheckingIterator = 0 ;
	DIO_PinVal_t Local_Pin2Reading ;
	DIO_PinVal_t Local_Pin3Reading ;
	DIO_PinVal_t Local_Pin4Reading ;
	DIO_PinVal_t Local_Pin5Reading ;
	CLCD_voidSendCommand(1);
	voidSendString("Please Enter ID:");
	CLCD_voidGoToXY(0u,1u);
	while (Local_u8IDCounter != 4)
	{
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN2 ,&Local_Pin2Reading);
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN3 ,&Local_Pin3Reading);
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN4 ,&Local_Pin4Reading);
		DIO_u8GetPinValue(DIO_PORTD , DIO_PIN5 ,&Local_Pin5Reading);
		if (Local_Pin2Reading == DIO_PIN_LOW)
		{
			voidSendNumber( 1 );
			OpenSound();
			_delay_ms(250);
			CLCD_voidGoToXY(Local_u8XPos,1);
			CLCD_voidSendData('*');
			Local_u8ID[Local_u8Iterator] = '1' ;
			Local_u8IDCounter ++ ;
			Local_u8Iterator  ++ ;
			Local_u8XPos 	  ++ ;
		}
		else if (Local_Pin3Reading == DIO_PIN_LOW)
		{
			voidSendNumber( 2 );
			OpenSound();
			_delay_ms(250);
			CLCD_voidGoToXY(Local_u8XPos,1);
			CLCD_voidSendData('*');
			Local_u8ID[Local_u8Iterator] = '2' ;
			Local_u8IDCounter ++ ;
			Local_u8Iterator  ++ ;
			Local_u8XPos 	  ++ ;
		}
		else if (Local_Pin4Reading == DIO_PIN_LOW)
		{
			voidSendNumber( 3 );
			OpenSound();
			_delay_ms(250);
			CLCD_voidGoToXY(Local_u8XPos,1);
			CLCD_voidSendData('*');
			Local_u8ID[Local_u8Iterator] = '3' ;
			Local_u8IDCounter ++ ;
			Local_u8Iterator  ++ ;
			Local_u8XPos 	  ++ ;
		}
		else if (Local_Pin5Reading == DIO_PIN_LOW)
		{
			voidSendNumber( 4 );
			OpenSound();
			_delay_ms(250);
			CLCD_voidGoToXY(Local_u8XPos,1);
			CLCD_voidSendData('*');
			Local_u8ID[Local_u8Iterator] = '4' ;
			Local_u8IDCounter ++ ;
			Local_u8Iterator  ++ ;
			Local_u8XPos 	  ++ ;
		}
		else
		{
								// DO NOTHING
		}
	}

	_delay_ms(500);
	for (Local_u8Iterator = 0 ; Local_u8Iterator < 4 ; Local_u8Iterator ++ )
	{
		Local_u8Password [ Local_u8Iterator ] = Local_u8ID [Local_u8IDCounter-1];
		Local_u8IDCounter -- ;
	}

	//////////////////////////////////////////////////////////////
	while ( Local_u8TrialCounter != 4 )
	{
		CLCD_voidSendCommand(1);
		voidSendString("Enter Password :");
		CLCD_voidGoToXY(8u,1u);
		voidSendString("Trial ");
		voidSendNumber(Local_u8TrialCounter);
		CLCD_voidGoToXY(0u,1u);
		Local_u8Iterator = 0 ;
		Local_u8XPos     = 0 ;
		Local_u8IDCounter= 0 ;
		while (Local_u8IDCounter != 4)
		{
			DIO_u8GetPinValue(DIO_PORTD , DIO_PIN2 ,&Local_Pin2Reading);
			DIO_u8GetPinValue(DIO_PORTD , DIO_PIN3 ,&Local_Pin3Reading);
			DIO_u8GetPinValue(DIO_PORTD , DIO_PIN4 ,&Local_Pin4Reading);
			DIO_u8GetPinValue(DIO_PORTD , DIO_PIN5 ,&Local_Pin5Reading);
			if (Local_Pin2Reading == DIO_PIN_LOW)
			{
				voidSendNumber(1);
				OpenSound();
				_delay_ms(250);
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendData('*');
				Local_u8PasswordEntry[Local_u8Iterator] = '1' ;
				Local_u8IDCounter ++ ;
				Local_u8Iterator  ++ ;
				Local_u8XPos 	  ++ ;
			}
			else if (Local_Pin3Reading == DIO_PIN_LOW)
			{
				voidSendNumber(2);
				OpenSound();
				_delay_ms(250);
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendData('*');
				Local_u8PasswordEntry[Local_u8Iterator] = '2' ;
				Local_u8IDCounter ++ ;
				Local_u8Iterator  ++ ;
				Local_u8XPos 	  ++ ;
			}
			else if (Local_Pin4Reading == DIO_PIN_LOW)
			{
				voidSendNumber(3);
				OpenSound();
				_delay_ms(250);
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendData('*');
				Local_u8PasswordEntry[Local_u8Iterator] = '3' ;
				Local_u8IDCounter ++ ;
				Local_u8Iterator  ++ ;
				Local_u8XPos 	  ++ ;
			}
			else if (Local_Pin5Reading == DIO_PIN_LOW)
			{
				voidSendNumber(4);
				OpenSound();
				_delay_ms(250);
				CLCD_voidGoToXY(Local_u8XPos,1);
				CLCD_voidSendData('*');
				Local_u8PasswordEntry[Local_u8Iterator] = '4' ;
				Local_u8IDCounter ++ ;
				Local_u8Iterator  ++ ;
				Local_u8XPos 	  ++ ;
			}
			else
			{
									// DO NOTHING
			}

		}
				///////////////////////////////////////////////////////////
		if (Local_u8IDCounter == 4)
		{
			Local_u8Flag = 0 ;
			for (Local_u8PasswordCheckingIterator = 0 ; Local_u8PasswordCheckingIterator<4 ; Local_u8PasswordCheckingIterator ++)
			{
				if (Local_u8PasswordEntry[Local_u8PasswordCheckingIterator] == Local_u8Password[Local_u8PasswordCheckingIterator])
				{
					Local_u8Flag ++ ;
				}
			}
			if ( Local_u8Flag == 4 )
			{
				CLCD_voidSendCommand(1);
				voidSendString("   Welcome");
				CLCD_voidGoToXY(2U,1U);
				voidSendString("ID : ");
				for (Local_u8Iterator = 0 ; Local_u8Iterator < 4 ; Local_u8Iterator ++)
				{
					CLCD_voidSendData(Local_u8ID[Local_u8Iterator]);
				}
				_delay_ms(1000);
				CLCD_voidSendCommand(1);
				voidSendString("System Activated");
				CLCD_voidGoToXY(0U,1U);
				voidSendString("TEMP=   C  ");
				voidSendString("LED=" ) ;
				_delay_ms(1000);
												/* ClEAR THE FLAG */
				EXTI_u8IntClearFlag ( INT0 ) ;
												/* INTERRUPT ENABLED */
				EXTI_u8SetSenseCtrl(INT0,FALLING_EDGE);
				EXTI_u8IntEnable(INT0);
				GIE_voidEnableGlobal();

				while (  u8_Flag == 1  )
				{
					LDRCONTROL();
					LM35CONTROL();
				}
				SystemShutDown () ;
				return ;
			}
			else
			{
				CLCD_voidSendCommand(1);
				voidSendString("Wrong Password!");
				_delay_ms (1000) ;
				Local_u8TrialCounter ++ ;
				CLCD_voidSendCommand(1);
			}
		}
	}

	if ( Local_u8TrialCounter == 4 )
	{
		CLCD_voidSendCommand(1);
		voidSendString(" No more Trials");
										/* ClEAR THE FLAG */
		EXTI_u8IntClearFlag ( INT0 ) ;
										/* INTERRUPT ENABLED */
		EXTI_u8IntEnable(INT0);
		GIE_voidEnableGlobal();
		while (  u8_Flag == 1  )
		{
			RedLED();
		}
		return ;
	}

}
void OpenSound (void)
{
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	_delay_ms(250);
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
}
void GreenLED ( void )
{
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_PIN_HIGH);
}
void RedLED (void)

{
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_PIN_HIGH);
}
void DC_Motor (void)
{
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	_delay_ms(1000);
}
void OpenSound2 (void)
{
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
}
void SystemOFF ( void )
{
	CLCD_voidSendCommand(1);
	voidSendString(" System Closed");
	OpenSound2();
	_delay_ms(2000);
	u8_Flag ++ ;

}
void LDRCONTROL ( void )
{
	uint16 local_u16LDRReading = 0 ;
	local_u16LDRReading = LDR_u16PreconfigGetLightLevel();
	_delay_ms(100);
	if (local_u16LDRReading < 5)
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(8);
	}
	else if ((local_u16LDRReading < 15) && (local_u16LDRReading >5 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(7);
	}
	else if ((local_u16LDRReading < 25) && (local_u16LDRReading >15 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(6);
	}
	else if ((local_u16LDRReading < 45) && (local_u16LDRReading >25 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(5);
	}
	else if ((local_u16LDRReading < 90) && (local_u16LDRReading >45 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(4);
	}
	else if ((local_u16LDRReading < 130) && (local_u16LDRReading >90 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(3);
	}
	else if ((local_u16LDRReading < 175) && (local_u16LDRReading >130 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(2);
	}
	else if ((local_u16LDRReading > 175) && (local_u16LDRReading <215 ) )
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(1);
	}
	else if (local_u16LDRReading > 215)
	{
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN4,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN5,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW);
		DIO_U8SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
		CLCD_voidGoToXY(15u , 1u);
		voidSendNumber(0);
	}
	else
	{
		// do nothing
	}
}

void LM35CONTROL ( void )
{
	uint8 Local_u8LM35Reading = 0 ;
	Local_u8LM35Reading = LM35_u8GetTemperature() ;
	CLCD_voidGoToXY(5u,1u);
	voidSendNumber((uint32)(Local_u8LM35Reading));
	_delay_ms(100) ;
	if ( Local_u8LM35Reading >= 35)
	{
		DIO_U8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		CLCD_voidGoToXY(9u,1u);
		CLCD_voidSendData('M');
	}
	else if (Local_u8LM35Reading <= 30)
	{
		DIO_U8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		CLCD_voidGoToXY(9u,1u);
		CLCD_voidSendData(' ');
	}
	else
	{
		// DO NOTHING
	}
}
void SystemShutDown ( void )
{
	CLCD_voidSendCommand(1);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN0 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN1 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN3 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN5 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN6 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_LOW);
	DIO_U8SetPinValue(DIO_PORTB , DIO_PIN0 , DIO_PIN_LOW);
}
