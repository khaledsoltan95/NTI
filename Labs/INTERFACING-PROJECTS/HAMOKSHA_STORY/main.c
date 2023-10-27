#include "STD_TYPES.h"
#include "util/delay.h"

#include "DIO_Interface.h"
#include "PORT_Interface.h"

#include "CLCD_Interface.h"
void PlayGame ( void );
void Introduction ( void );
void Death ( void );
void Run ( void );
void Dance ( void );

/* Up Arrow Pattern */
/* Stand Pattern */
uint8 Local_u8Pattern0Arr[8]={ 0b00001110 ,
   0b00001110 ,
   0b00000100 ,
   0b00001110 ,
   0b00010101 ,
   0b00001110 ,
   0b00010001 ,
   0 } ;
/* Up Arrow Pattern */

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
/* Music  Pattern */
uint8 Local_u8Pattern5Arr[8]={ 0b00000001 ,
   0b00000111 ,
   0b00001101 ,
   0b00001001 ,
   0b00001011 ,
   0b00011011 ,
   0b00011000 ,
   0 } ;
/* Ball 1  Pattern */
uint8 Local_u8Pattern6Arr[8]={ 0 ,
   0b00001110 ,
   0b00011111 ,
   0b00011111 ,
   0b00011111 ,
   0b00001110 ,
   0 ,
   0 } ;
/* Gun  Pattern */
uint8 Local_u8Pattern7Arr[8]={ 0b00011111 ,
   0b00011111 ,
   0b00011100 ,
   0b00011100 ,
   0b00011000 ,
   0b00011000 ,
   0 ,
   0 } ;
/* Bullet  Pattern */
uint8 Local_u8Pattern8Arr[8]={ 0b00011000 ,
   0b00011000 ,
   0 ,
   0 ,
   0 ,
   0 ,
   0 ,
   0 } ;
/* Stand 2 Pattern */
uint8 Local_u8Pattern13Arr[8]={ 0b00001110 ,
   0b00001110 ,
   0b00010101 ,
   0b00001110 ,
   0b00000100 ,
   0b00001110 ,
   0b00010001 ,
   0 } ;
/* Die  Pattern */
uint8 Local_u8Pattern9Arr[8]={ 0 ,
   0 ,
   0b00001110 ,
   0b00000011 ,
   0b00001110 ,
   0 ,
   0 ,
   0 } ;
/* Die 1  Pattern */
uint8 Local_u8Pattern10Arr[8]={ 0 ,
    0b00001000 ,
    0b00010011 ,
	0b00011111 ,
	0b00010011 ,
	0b00001000 ,
	0 ,
	0 } ;
/* Die 2 Pattern */
uint8 Local_u8Pattern11Arr[8]={ 0b00001110 ,
		0b00001101 ,
		0b00011101 ,
		0b00011001 ,
		0b00011101 ,
		0b00001101 ,
		0b00001110 ,
		0 } ;
/* Die 3 Pattern */
uint8 Local_u8Pattern12Arr[8]={ 0b00010001 ,
    0b00011011 ,
    0b00001110 ,
	0b00001110 ,
	0b00011011 ,
	0b00010001 ,
	0 ,
	0 } ;
/* Playing 1 Pattern */
/* Stand Pattern */
uint8 Local_u8Pattern15Arr[8]={ 0b00001110 ,
   0b00001110 ,
   0b00001110 ,
   0b00010100 ,
   0b00010100 ,
   0b00001110 ,
   0b00001110 ,
   0 } ;
/* Up Arrow Pattern */

/* Playing 2 Pattern */
uint8 Local_u8Pattern16Arr[8]={ 0b00001110 ,
   0b00001110 ,
   0b00001110 ,
   0b00001110 ,
   0b00011011 ,
   0b00011011 ,
   0 ,
   0 } ;
/* Music Pattern */
uint8 Local_u8Pattern17Arr[8]={ 0b00000011 ,
   0b00000111 ,
   0b00011111 ,
   0b00011111 ,
   0b00011111 ,
   0b00000111 ,
   0b00000011 ,
   0 } ;



void main ()
{
	PORT_voidInit() ;

	DIO_U8SetPortDirection(DIO_PORTA,0xff);  					// PORTA IS OUTPUT
	CLCD_voidInit();

	while (1)
	{

		Introduction();

		Run();

		PlayGame();

		Dance() ;

		Death();

	}
}
void PlayGame ( void )
{
	for (uint8 i = 0 ; i < 8 ; i++)
	{
		CLCD_voidSendCommand( 1 ) ;
		voidSendString("I Can Play ");
		CLCD_voidGoToXY(0u,1u);
		voidSendString( "Football");
		CLCD_u8WriteSpecialCharacter( 6u , Local_u8Pattern6Arr, 18u , 1u );
		CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern15Arr, 19u , 0u );
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern16Arr, 19u , 1u );
		_delay_ms(250);
		CLCD_voidSendCommand( 1 ) ;
		voidSendString( "I Can Play");
		CLCD_voidGoToXY(0u,1u);
		voidSendString( "Football");
		CLCD_u8WriteSpecialCharacter( 6u , Local_u8Pattern6Arr, 18u , 0u );
		CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern15Arr, 19u , 0u );
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern16Arr, 19u , 1u );
		_delay_ms(250);
	}
	_delay_ms(13);
	CLCD_voidSendCommand( 1 ) ;
}
void Introduction ( void )
{
	voidSendString("Hi I am Hamoksha");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 7u , 1u );
	_delay_ms(3000);
	CLCD_voidSendCommand( 1 ) ;
}
void Death ( void )
{
	uint8 XPos = 1u ;
	CLCD_voidSendCommand( 1 ) ;
	while (XPos != 19)
	{
		voidSendString("Do Not Kill Me !!");
		CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 19u , 1u );
		CLCD_u8WriteSpecialCharacter( 7u , Local_u8Pattern7Arr, 0u , 1u );

		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern8Arr, XPos , 1u );
		_delay_ms(100);
		CLCD_voidSendCommand( 1 );
		XPos++ ;
	}
	CLCD_voidSendCommand( 1 ) ;
	voidSendString("   SWEET DEATH");
	CLCD_u8WriteSpecialCharacter( 7u , Local_u8Pattern7Arr, 0u , 1u );
	CLCD_u8WriteSpecialCharacter( 9u , Local_u8Pattern9Arr, 18u , 1u );
	CLCD_u8WriteSpecialCharacter( 10u , Local_u8Pattern10Arr,19u , 1u );
	CLCD_u8WriteSpecialCharacter( 11u , Local_u8Pattern11Arr, 8u , 1u );
	CLCD_u8WriteSpecialCharacter( 12u , Local_u8Pattern12Arr, 7u , 1u );
	_delay_ms(3000);
	CLCD_voidSendCommand( 1 ) ;
}
void Run ( void )
{
	uint8 XPos = 1 ;
	CLCD_voidSendCommand(1);
	voidSendString("   I Can Run");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 0u , 1u );
	_delay_ms(1500);
	while ( XPos !=19 )
	{
		CLCD_voidSendCommand(1);
		voidSendString("   I Can Run");
		CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern1Arr, XPos , 1u );
		_delay_ms(250);
		XPos ++ ;
		CLCD_voidSendCommand(1);
		voidSendString("   I Can Run");
		CLCD_u8WriteSpecialCharacter( 2u , Local_u8Pattern2Arr, XPos , 1u );
		_delay_ms(250);
		XPos ++ ;
	}
	for (uint8 i = 0 ; i<5 ; i++)
	{
	CLCD_voidSendCommand(1);
	voidSendString("    winner");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 19u , 1u );
	_delay_ms(200);
	CLCD_voidSendCommand(1);
	voidSendString("    winner");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr, 19u , 1u );
	_delay_ms(200);
	}
	CLCD_voidSendCommand(1);
}
void Dance ( void )
{
	CLCD_voidSendCommand(1);
	voidSendString("  I Can Dance");
	CLCD_u8WriteSpecialCharacter( 5u , Local_u8Pattern5Arr, 7u , 1u );
	CLCD_u8WriteSpecialCharacter( 5u , Local_u8Pattern5Arr, 8u , 1u );
	_delay_ms(2000);
	for (uint8 i = 0 ; i<2 ; i++)
	{
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 5u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,6u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 7u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,8u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 0u , Local_u8Pattern0Arr, 7u , 1u );
	_delay_ms(250);
	CLCD_voidSendCommand(1);
	voidSendString("I Can Dance");
	CLCD_u8WriteSpecialCharacter( 1u , Local_u8Pattern17Arr, 12u , 0u );
	voidSendString("On");
	CLCD_u8WriteSpecialCharacter( 13u , Local_u8Pattern13Arr,6u , 1u );
	_delay_ms(250);
	}
	CLCD_voidSendCommand(1);
}
