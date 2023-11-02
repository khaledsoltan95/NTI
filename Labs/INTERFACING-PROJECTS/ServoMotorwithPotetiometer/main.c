#include "STD_TYPES.h"
#include "ERR_TYPE.h"
#include "MAP.h"

#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "TIMER_Interface.h"
#include "ADC_Interface.h"

#include "CLCD_Interface.h"

void main ()
{
	uint32 Val = 2000 ;
	uint16 Local_u16ADC_Reading ;
	PORT_voidInit() ;

	ADC_voidInit() ;

	CLCD_voidInit() ;

	TIMER1_voidInit();

	while (1)
	{
		/* with Potentiometer */

		ADC_u8StartSingleConversionSynch(ADC0_SINGLE_ENDED,&Local_u16ADC_Reading) ;
		voidSendNumber(Local_u16ADC_Reading);
		Val = MAP(0u,255u,2000,4000,Local_u16ADC_Reading) ;
		TIMER1_voidSetAngle(Val) ;
		_delay_ms(500);
		CLCD_voidSendCommand(1) ;

		/*Without Potentiometer */

		/*for (uint8 i = 0 ; i<10 ; i++)
		{
			TIMER1_voidSetAngle(Val);
			_delay_ms(500);
			if (Val == 4000)
			{
				Val = 2000 ;
			}
			else
			{
				Val += 200 ;
			}
		}*/
	}
}


