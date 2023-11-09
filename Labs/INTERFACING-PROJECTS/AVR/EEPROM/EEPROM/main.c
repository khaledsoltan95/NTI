#include "STD_TYPES.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h"
#include "TWI_Interface.h"
#include "PORT_Interface.h"

#include "CLCD_Interface.h"
#include "EEPROM_Interface.h"

void main ()
{
	uint8 Local_u8ReceivedData = 5u ;

	PORT_voidInit() ;											// DEFINE PORT A AS OUTPUT WITH CONNECTION TO 8-LEDs

	CLCD_voidInit() ;

	TWI_u8MasterInit(0u) ;										// INITIALIZE MICROCONTROLLER AS MASTER

	EEPROM_voidWriteDataByte(0,190u) ;							// SEND DATA TO EEPROM 24C08

	/*if (EEPROM_u8ReadDataByte(0u) == 0x55)
	{
		DIO_U8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_HIGH) ;
	}*/

	Local_u8ReceivedData = EEPROM_u8ReadDataByte(0) ;			// RECEIVE DATA FROM EEPROM 24C08

	voidSendNumber(Local_u8ReceivedData) ;

	//DIO_U8SetPortValue(DIO_PORTA,Local_u8ReceivedData) ;		// SET DATA RECEIVED ON PORT A WHICH IS CONNECTED TO 8 LEDS

	while (1)
	{

	}
}


