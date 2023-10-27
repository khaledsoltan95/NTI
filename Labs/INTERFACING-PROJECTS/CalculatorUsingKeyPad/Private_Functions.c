#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"

#include "KPD_Interface.h"
#include "CLCD_Interface.h"

#include "Private_Headers.h"

#define 	SIZE 	20u

static uint8  	InputArr[SIZE] ;
static sint32 	NumArr[SIZE] ;

static uint8 	Local_u8Index = 0 ;
static uint8 	Local_u8Counter = 0u ;
static uint8 	Counter1 = 0u ;
static uint8 	Counter2 = 0u ;
static sint32 	Result = 0u ;

void CalculatorInit (void)
{
	CLCD_voidSendCommand(1) ;
	CLCD_voidGoToXY(4,0) ;
	voidSendString("WELCOME TO") ;
	CLCD_voidGoToXY(4,1) ;
	voidSendString("Calculator") ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH) ;
}

void SetCalculators (void)
{
	uint8 Local_u8PressedKey = 0xff ;
	Local_u8Index = 0 ;
	CLCD_voidSendCommand(1) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW) ;

	while (Local_u8PressedKey != '=')
	{
		do
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
		}while ( (Local_u8PressedKey == 0xff) );

		if ( (Local_u8PressedKey == '+') || (Local_u8PressedKey == '-') || (Local_u8PressedKey == '/') || (Local_u8PressedKey == '*') )
		{
			CheckLogic(Local_u8Index) ;
			Counter2 = Local_u8Index - 1u   ;
			CLCD_voidSendData(Local_u8PressedKey) ;    			// Display on LCD
			InputArr[Local_u8Index] = Local_u8PressedKey ;
			ConcatenateNumber(Counter1,Counter2) ;
			NumArr[Local_u8Counter] = Local_u8PressedKey ;
			Local_u8Index ++ ;
			Local_u8Counter ++ ;
			Counter1 = Local_u8Index ;
		}
		else if (( Local_u8PressedKey >= '0' ) && (Local_u8PressedKey <= '9'))
		{
			CLCD_voidSendData(Local_u8PressedKey) ;    			// Display on LCD
			switch (Local_u8PressedKey)
			{
			case '0' : InputArr[Local_u8Index] = 0u; break ;
			case '1' : InputArr[Local_u8Index] = 1u; break ;
			case '2' : InputArr[Local_u8Index] = 2u; break ;
			case '3' : InputArr[Local_u8Index] = 3u; break ;
			case '4' : InputArr[Local_u8Index] = 4u; break ;
			case '5' : InputArr[Local_u8Index] = 5u; break ;
			case '6' : InputArr[Local_u8Index] = 6u; break ;
			case '7' : InputArr[Local_u8Index] = 7u; break ;
			case '8' : InputArr[Local_u8Index] = 8u; break ;
			case '9' : InputArr[Local_u8Index] = 9u; break ;
			default : break ;
			}
			Local_u8Index ++ ;
		}
		else if ( Local_u8PressedKey == 127 )
		{
			CalculatorInit() ;
		}
		else
		{
			// DO NOTHING
		}
	}

	if (Local_u8PressedKey == '=')
	{
		Counter2 = Local_u8Index - 1u   ;
		ConcatenateNumber(Counter1  ,Counter2 ) ;
		CLCD_voidGoToXY(0u,1u) ;
		//PrintNumArr() ;
		_delay_ms(1000) ;
		StartCalculating () ;
	}

}

void StartCalculating (void)
{
	uint8 Local_u8Iterator1 = 0u ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH) ;

	while (Local_u8Iterator1 < SIZE)
	{
		switch (NumArr[Local_u8Iterator1])
		{
		case '+' : NumArr[Local_u8Iterator1 ] = 0u ; break ;
		case '-' : NumArr[Local_u8Iterator1 ] = 0u ; break ;
		default : break ;
		}
		Local_u8Iterator1 ++ ;
	}
	Local_u8Iterator1 = 0u ;
	while (Local_u8Iterator1 < SIZE)
	{
		switch (NumArr[Local_u8Iterator1])
		{
		case '*' :
			if ((NumArr[Local_u8Iterator1 - 2u] == '*') || (NumArr[Local_u8Iterator1 - 2u] == '/'))
			{
				Result *= NumArr [Local_u8Iterator1 + 1u] ;NumArr[Local_u8Iterator1 - 1u] = 0u ;  NumArr[Local_u8Iterator1 + 1u] = 0u ;
			}
			else
			{
				Result += (NumArr[Local_u8Iterator1 - 1u] * NumArr [Local_u8Iterator1 + 1u]) ;NumArr[Local_u8Iterator1 - 1u] = 0u ;  NumArr[Local_u8Iterator1 + 1u] = 0u ;
			}
			break ;
		case '/' :
			if ((NumArr[Local_u8Iterator1 - 2u] == '*') || (NumArr[Local_u8Iterator1 - 2u] == '/'))
			{
				Result /= NumArr [Local_u8Iterator1 + 1u] ;NumArr[Local_u8Iterator1 - 1u] = 0u ;  NumArr[Local_u8Iterator1 + 1u] = 0u ;
			}
			else
			{
				Result += (NumArr[Local_u8Iterator1 - 1u] / NumArr [Local_u8Iterator1 + 1u]) ;NumArr[Local_u8Iterator1 - 1u] = 0u ;  NumArr[Local_u8Iterator1 + 1u] = 0u ;
			}
			break ;
		default : break ;
		}

		Local_u8Iterator1 ++ ;
	}
	Local_u8Iterator1 = 0u ;
	while (Local_u8Iterator1 < SIZE)
	{
		if ( (NumArr[Local_u8Iterator1] == '*') || (NumArr[Local_u8Iterator1] == '/') )
		{
			NumArr[Local_u8Iterator1] = 0u ;
		}
		Local_u8Iterator1 ++ ;
	}
	Local_u8Iterator1 = 0u ;
	while (Local_u8Iterator1 < SIZE)
	{
		Result += NumArr[Local_u8Iterator1] ;
		Local_u8Iterator1 ++ ;
	}
	CLCD_voidGoToXY(0u,1u);
	voidSendString("RESULT= ") ;
	voidSendNumber(Result) ;
	_delay_ms(5000) ;
}

void CheckLogic (uint8 copy_u8Index)
{
	if ( copy_u8Index != 0u)
	{
		if ((InputArr[copy_u8Index - 2u] != '/') && (InputArr[copy_u8Index - 1u] != 0u))
		{
			if ( (InputArr[copy_u8Index - 1] == '-') || (InputArr[copy_u8Index - 1] == '*') || (InputArr[copy_u8Index - 1] == '+') || (InputArr[copy_u8Index - 1] == '/'))
			{
				Counter1 = 0 ;
				Counter2 = 0 ;
				CLCD_voidSendCommand(1) ;
				voidSendString("Error") ;
				_delay_ms(2000) ;
				SetCalculators() ;
			}
			else
			{
				// DO NOTHING
			}
		}
		else
		{
			Counter1 = 0 ;
			Counter2 = 0 ;
			CLCD_voidSendCommand(1) ;
			voidSendString("Error") ;
			_delay_ms(2000) ;
			SetCalculators() ;
		}
	}
	else
	{
		Counter1 = 0 ;
		Counter2 = 0 ;
		CLCD_voidSendCommand(1) ;
		voidSendString("Error") ;
		_delay_ms(2000) ;
		SetCalculators() ;
	}
}

void ConcatenateNumber (uint8 Flag1 , uint8 Flag2)
{
	uint8 Local_u8Iterator = 0u  ;
	if ( Flag1 == Flag2)
	{
		NumArr[Local_u8Counter] = InputArr[Flag1] ;
	}
	else
	{
		NumArr[Local_u8Counter] = InputArr[Flag1] ;
		for (Local_u8Iterator = Flag1 ; Local_u8Iterator < Flag2 ; Local_u8Iterator ++)
		{
			NumArr[Local_u8Counter] = ( NumArr[Local_u8Counter] * 10 ) + InputArr[Local_u8Iterator + 1] ;
		}
	}
	if ((NumArr[Local_u8Counter - 1u]) == '-')
	{
		NumArr[Local_u8Counter] *= -1 ;
		NumArr[Local_u8Counter - 1u] = '+' ;
	}
	else
	{
		// DO NOTHING
	}
	Local_u8Counter ++ ;
}

void PrintNumArr (void)
{
	uint8 Localu8Iterator = 0 ;
	while (Localu8Iterator < 10u)
	{
		if ( (Localu8Iterator % 2 ) != 0u)
		{
			CLCD_voidSendData(NumArr[Localu8Iterator]) ;
		}
		else
		{
			voidSendNumber(NumArr[Localu8Iterator]) ;
		}
		Localu8Iterator ++ ;
	}
}

