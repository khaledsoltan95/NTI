#include "STD_TYPES.h"

#include "util/delay.h"

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "ADC_Interface.h"
#include "EXTI_Interface.h"
#include "GIE_Interface.h"
#include "CLCD_Interface.h"
#include "KPD_Interface.h"

#include "Assignment_Private_Headers.h"
							/* THIS APPLICATION WORKED EFFECTIVELY */
void INT0ISR ( void ) ;
volatile uint8 u8Flag = 0 ;

void main (void)
{
	PORT_voidInit();

	ADC_voidInit() ;

	CLCD_voidInit();

	EXTI_voidInit();

	//EXTI_u8SetSenseCtrl( INT0 , FALLING_EDGE );

				//EXTI_u8IntEnable( INT0 );
	EXTI_u8SetCallBack ( INT0 , &INT0ISR);

	GIE_voidEnableGlobal();

	while (1)
	{
		if (u8Flag == 1 )
		{
			EXTI_u8IntDisable(INT0);
			//GIE_voidDisableGlobal();
			OpenSound2();
			Hamoksha_voidWelcome();
			CLCD_voidID();
		}
	}
}

void INT0ISR ( void )
{

	switch (u8Flag)
	{
	case 0 : u8Flag ++ ;EXTI_u8IntClearFlag ( INT0 ) ; break ;
	case 1 : u8Flag -- ; SystemOFF() ; EXTI_u8IntClearFlag ( INT0 ) ; break ;
	default : voidSendString("default") ; break ;
	}


}



