#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"

#include "KPD_Interface.h"
#include "CLCD_Interface.h"

#include "Private_Headers.h"

uint8 Local_u8XPos = 0u;
uint8 First_Min = 0 ;
uint8 Second_Min = 0 ;
uint8 First_Second = 0 ;
uint8 Second_Second = 0 ;
uint8 Local_u8Pattern0Arr[8]={ 0b00000100 ,
		0b00001110 ,
		0b00011111 ,
		0b00001110 ,
		0b00001110 ,
		0b00001110 ,
		0b00001110 ,
		0 } ;

void AlarmInit (void)
{
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	CLCD_voidSendData(':');
	CLCD_voidSendData('0');
	CLCD_voidSendData('0');
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH) ;
}

void SetAlarm (void)
{
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH) ;
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_LOW) ;
	uint8 Local_u8PressedKey = 0xff ;

	CLCD_u8WriteSpecialCharacter(0u,Local_u8Pattern0Arr,Local_u8XPos,1u);
	do
	{
		Local_u8PressedKey = KPD_u8GetPressedKey();
	}while ( (Local_u8PressedKey == 0xff) );
	if (Local_u8PressedKey == 42)
	{
		CLCD_voidGoToXY(Local_u8XPos,1u);
		CLCD_voidSendData(' ');
		Local_u8XPos ++ ;
		if (Local_u8XPos==2)
		{
			Local_u8XPos ++ ;
		}
		else if (Local_u8XPos==5)
		{
			Local_u8XPos = 0  ;
		}
	}
	else if (Local_u8PressedKey == 45)
	{
		CLCD_voidGoToXY(Local_u8XPos,1u);
		CLCD_voidSendData(' ');
		Local_u8XPos -- ;
		if (Local_u8XPos==255)
		{
			Local_u8XPos = 4 ;
		}
		else if (Local_u8XPos==2)
		{
			Local_u8XPos -- ;
		}
	}
	else if (( Local_u8PressedKey >= '0' ) && (Local_u8PressedKey <= '9'))
	{
		CLCD_voidGoToXY(Local_u8XPos,0u);
		voidSendNumber(Local_u8PressedKey-48);
		switch (Local_u8XPos)
		{
		case 0 : First_Min = Local_u8PressedKey-48 ; break ;
		case 1 : Second_Min = Local_u8PressedKey-48 ; break ;
		case 3 : First_Second = Local_u8PressedKey-48 ; break ;
		case 4 : Second_Second = Local_u8PressedKey-48 ; break ;
		default : voidSendString("ERROR"); break ;
		}
	}
	else if (Local_u8PressedKey == '=')
	{
		CLCD_voidSendCommand(1);
		CLCD_voidSendData(First_Min + 48);
		CLCD_voidSendData(Second_Min + 48);
		CLCD_voidSendData(':');
		CLCD_voidSendData(First_Second + 48);
		CLCD_voidSendData(Second_Second + 48 );
		StartAlarm () ;
		return ;
	}

}

void StartAlarm (void)
{
	//while ( (First_Second != 0) && (Second_Second != 0) && (First_Min != 0) && ( Second_Min != 0 ) )
	DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW) ;
	while (1)
	{
		while (Second_Second != 0 )
		{
			_delay_ms(1000);
			DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN1);
			Second_Second -- ;
			CLCD_voidGoToXY(4u,0u);
			CLCD_voidSendData(Second_Second+48);
		}
		if (First_Second != 0)
		{
			_delay_ms(1000);
			DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN1);
			First_Second -- ;
			Second_Second = 9 ;
			CLCD_voidGoToXY(4u,0u);
			CLCD_voidSendData(Second_Second+48);
			CLCD_voidGoToXY(3u,0u);
			CLCD_voidSendData(First_Second+48);
		}
		else if (Second_Min != 0 )
		{
			_delay_ms(1000);
			DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN1);
			Second_Min -- ;
			First_Second = 5 ;
			Second_Second = 9 ;
			CLCD_voidGoToXY(4u,0u);
			CLCD_voidSendData(Second_Second+48);
			CLCD_voidGoToXY(3u,0u);
			CLCD_voidSendData(First_Second+48);
			CLCD_voidGoToXY(1u,0u);
			CLCD_voidSendData(Second_Min+48);
		}
		else if (First_Min != 0 )
		{
			_delay_ms(1000);
			DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN1);
			First_Min -- ;
			Second_Min = 9 ;
			First_Second = 5 ;
			Second_Second = 9 ;
			CLCD_voidGoToXY(4u,0u);
			CLCD_voidSendData(Second_Second+48);
			CLCD_voidGoToXY(3u,0u);
			CLCD_voidSendData(First_Second+48);
			CLCD_voidGoToXY(1u,0u);
			CLCD_voidSendData(Second_Min+48);
			CLCD_voidGoToXY(0u,0u);
			CLCD_voidSendData(First_Min+48);
		}
		else
		{
			uint8 Local_u8PressedKey = 0xff ;
			DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW) ;
			DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW) ;
			DIO_U8SetPinValue(DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH) ;
			do
			{
				Local_u8PressedKey = KPD_u8GetPressedKey();
			}while ( (Local_u8PressedKey == 0xff) );
			if (Local_u8PressedKey == 47)
			{
				while (Local_u8PressedKey != 61)
				{
					SetAlarm() ;
				}
			}
		}
	}
}
