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
#include "CLCD_Interface.h"

#include "Assignment_Private_Headers.h"



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
	CLCD_voidGoToXY(2U,0U);
	voidSendString("WELCOME AGAIN");
	while ( XPos !=16 )
	{
		//CLCD_voidSendCommand(1);
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern1Arr, XPos , 1u );
		_delay_ms(250);
		CLCD_u8WriteSpecialCharacter( 3u , Local_u8ZeroArr, XPos , 1u );
		XPos ++ ;

		CLCD_u8WriteSpecialCharacter( 2u , Local_u8Pattern2Arr, XPos , 1u );
		_delay_ms(250);
		CLCD_u8WriteSpecialCharacter( 3u , Local_u8ZeroArr, XPos , 1u );
		XPos ++ ;
	}
	CLCD_voidSendCommand(1);
}
void Hamoksha_voidSleep (void)
{
	uint8 Local_u8Pattern9Arr[8]={ 0 ,
	   0 ,
	   0b00001110 ,
	   0b00000011 ,
	   0b00001110 ,
	   0 ,
	   0 ,
	   0 } ;
	uint8 Local_u8Pattern10Arr[8]={ 0 ,
	    0b00001000 ,
	    0b00010011 ,
		0b00011111 ,
		0b00010011 ,
		0b00001000 ,
		0 ,
		0 } ;

	voidSendString("  Sleeping Time");
	CLCD_u8WriteSpecialCharacter( 9u , Local_u8Pattern9Arr, 14u , 1u );
	CLCD_u8WriteSpecialCharacter( 10u , Local_u8Pattern10Arr,15u , 1u );

}
void Hamoksha_voidWakeup (void)
{
	uint8 Local_u8Pattern0Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00000100 ,
	   0b00001110 ,
	   0b00010101 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	CLCD_voidSendCommand(1);
	voidSendString("  GOOD MORNING");
	CLCD_u8WriteSpecialCharacter( 10u , Local_u8Pattern0Arr,15u , 1u );
	_delay_ms(3000);
}
void Hamoksha_voidPlaying (void)
{
	uint8 Local_u8Pattern0Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00000100 ,
	   0b00001110 ,
	   0b00010101 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	uint8 Local_u8Pattern1Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00000101 ,
	   0b00001110 ,
	   0b00010100 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	uint8 Local_u8Pattern2Arr[8]={ 0b00001110 ,
			   0b00001110 ,
			   0b00010100 ,
			   0b00001110 ,
			   0b00000101 ,
			   0b00001110 ,
			   0b00010001 ,
			   0 } ;

	CLCD_voidSendCommand(1);
	uint8 XPos = 1 ;
	CLCD_voidSendCommand(1);
	voidSendString("   RUNNING TIME");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 0u , 1u );
	while ( XPos !=15 )
	{
		CLCD_voidSendCommand(1);
		voidSendString("   RUNNING TIME");
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern1Arr, XPos , 1u );
		_delay_ms(250);
		XPos ++ ;
		CLCD_voidSendCommand(1);
		voidSendString("   RUNNING TIME");
		CLCD_u8WriteSpecialCharacter( 2u , Local_u8Pattern2Arr, XPos , 1u );
		_delay_ms(250);
		XPos ++ ;
	}

}
void Hamoksha_voidDancing (void)
{
	uint8 Local_u8Pattern0Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00000100 ,
	   0b00001110 ,
	   0b00010101 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	uint8 Local_u8Pattern5Arr[8]={ 0b00000001 ,
	   0b00000111 ,
	   0b00001101 ,
	   0b00001001 ,
	   0b00001011 ,
	   0b00011011 ,
	   0b00011000 ,
	   0 } ;
	uint8 Local_u8Pattern13Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00010101 ,
	   0b00001110 ,
	   0b00000100 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	uint8 Local_u8Pattern17Arr[8]={ 0b00000011 ,
	   0b00000111 ,
	   0b00011111 ,
	   0b00011111 ,
	   0b00011111 ,
	   0b00000111 ,
	   0b00000011 ,
	   0 } ;
	CLCD_voidSendCommand(1);
	for (uint8 i = 0 ; i<2 ; i++)
	{
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 5u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,6u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 7u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,8u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 7u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("Dancing Time");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,6u , 1u );
	_delay_ms(250);
	}
}
void Hamoksha_voidDeath (void)
{
	uint8 Local_u8Pattern0Arr[8]={ 0b00001110 ,
	   0b00001110 ,
	   0b00000100 ,
	   0b00001110 ,
	   0b00010101 ,
	   0b00001110 ,
	   0b00010001 ,
	   0 } ;
	uint8 Local_u8Pattern7Arr[8]={ 0b00011111 ,
	   0b00011111 ,
	   0b00011100 ,
	   0b00011100 ,
	   0b00011000 ,
	   0b00011000 ,
	   0 ,
	   0 } ;
	uint8 Local_u8Pattern8Arr[8]={ 0b00011000 ,
	   0b00011000 ,
	   0 ,
	   0 ,
	   0 ,
	   0 ,
	   0 ,
	   0 } ;
	uint8 Local_u8Pattern9Arr[8]={ 0 ,
	   0 ,
	   0b00001110 ,
	   0b00000011 ,
	   0b00001110 ,
	   0 ,
	   0 ,
	   0 } ;
	uint8 Local_u8Pattern10Arr[8]={ 0 ,
	    0b00001000 ,
	    0b00010011 ,
		0b00011111 ,
		0b00010011 ,
		0b00001000 ,
		0 ,
		0 } ;
	uint8 Local_u8Pattern11Arr[8]={ 0b00001110 ,
			0b00001101 ,
			0b00011101 ,
			0b00011001 ,
			0b00011101 ,
			0b00001101 ,
			0b00001110 ,
			0 } ;
	uint8 Local_u8Pattern12Arr[8]={ 0b00010001 ,
	    0b00011011 ,
	    0b00001110 ,
		0b00001110 ,
		0b00011011 ,
		0b00010001 ,
		0 ,
		0 } ;
	uint8 XPos = 1u ;
	CLCD_voidSendCommand( 1 ) ;
	while (XPos != 15)
	{
		voidSendString("Stop Talking !! ");
		CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 15u , 1u );
		CLCD_u8WriteSpecialCharacter( 7u , Local_u8Pattern7Arr, 0u , 1u );

		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern8Arr, XPos , 1u );
		_delay_ms(100);
		CLCD_voidSendCommand( 1 );
		XPos++ ;
	}
	CLCD_voidSendCommand( 1 ) ;
	voidSendString("   SWEET DEATH");
	CLCD_u8WriteSpecialCharacter( 7u , Local_u8Pattern7Arr, 0u , 1u );
	CLCD_u8WriteSpecialCharacter( 9u , Local_u8Pattern9Arr, 14u , 1u );
	CLCD_u8WriteSpecialCharacter( 10u , Local_u8Pattern10Arr,15u , 1u );
	CLCD_u8WriteSpecialCharacter( 11u , Local_u8Pattern11Arr, 8u , 1u );
	CLCD_u8WriteSpecialCharacter( 12u , Local_u8Pattern12Arr, 7u , 1u );
	_delay_ms(3000);
	CLCD_voidSendCommand( 1 ) ;
	return ;
}
