#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_Interface.h"
#include "PORT_Interface.h"

#include "KPD_Interface.h"
#include "CLCD_Interface.h"

#include "Private_Headers.h"

void main ()
{
	uint8 Local_u8PressedKey = 0xff ;
	PORT_voidInit();
	CLCD_voidInit();

	while (1)
	{
		do
		{
			Local_u8PressedKey = KPD_u8GetPressedKey();
		}while ( (Local_u8PressedKey == 0xff) );
		if (Local_u8PressedKey == 127)
		{
			CLCD_voidSendCommand(1);
			AlarmInit() ;
		}
		else if (Local_u8PressedKey == 47)
		{
			while (Local_u8PressedKey != 61)
			{
				SetAlarm() ;
			}
		}
	}
}

