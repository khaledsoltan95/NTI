#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "ADC_Interface.h"
#include "GIE_Interface.h"

#include "LDR_Interface.h"
#include "CLCD_Interface.h"

#include "Assignment_Private_Headers.h"

ADC_Channel_t 	Sensors_arr_channels[2]={ADC0_SINGLE_ENDED,ADC1_SINGLE_ENDED} ;
uint16 			Sensors_arr_reading[2]= {0,0};
uint8 LDR_Flag = 0 ;
uint8 LM35_FLAG = 0 ;
volatile uint16 Local_u16LDRReading = 0 ;
volatile uint16 Local_u16LM35Reading = 0 ;
void ISR (void) ;
void LDR_FUNC (void);
void LM35_FUNC (void);
void main ()
{
	ADC_Chain_t Data =
	{
		. ConversionsNum = 2 ,
		. ChannelArr = Sensors_arr_channels ,
		. ResultArr = Sensors_arr_reading ,
		. NotificationFunc = ISR
	};

	PORT_voidInit() ;

	ADC_voidInit() ;

	CLCD_voidInit() ;

	GIE_voidEnable() ;

	//voidSendString("LIGHT LEVEL :") ;

	Hamoksha_voidWelcome();

	while (1)
	{
		ADC_u8StartChainConversionAsynch(&Data) ;
		_delay_ms(10) ;
		if (LDR_Flag == 1)
		{
			LDR_Flag = 0 ;
			Local_u16LDRReading =Sensors_arr_reading[0] ;
			LDR_FUNC() ;
		}
		if (LM35_FLAG == 1)
		{
			LM35_FLAG = 0 ;
			Local_u16LM35Reading = Sensors_arr_reading[1] ;
			LM35_FUNC() ;
		}
		//Local_u16LDRReading = LDR_u16GetLightLevel();
		/*CLCD_voidGoToXY(7u,1u);
		CLCD_voidSendData(' ');
		CLCD_voidGoToXY(8u,1u);
		CLCD_voidSendData(' ');
		CLCD_voidGoToXY(9u,1u);
		CLCD_voidSendData(' ');
		CLCD_voidGoToXY(7u,1u);
		voidSendNumber(Local_u16LDRReading);
		_delay_ms(1000);*/

	}

}
void ISR (void)
{
	LDR_Flag = 1 ;
	LM35_FLAG = 1 ;

}
void LDR_FUNC (void)
{
	if (Local_u16LDRReading <15)
				{
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
					Hamoksha_voidSleep() ;
				}
				else if ((Local_u16LDRReading > 15) && (Local_u16LDRReading < 45))
				{
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
					Hamoksha_voidWakeup() ;
				}
				else if ((Local_u16LDRReading > 45) && (Local_u16LDRReading < 130))
				{
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
					Hamoksha_voidPlaying() ;
				}
				else if ((Local_u16LDRReading > 130) && (Local_u16LDRReading < 220))
				{
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_LOW);
					Hamoksha_voidDancing();
				}
				else if ((Local_u16LDRReading > 220) )
				{
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN0,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN1,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
					DIO_U8SetPinValue(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
					Hamoksha_voidDeath();
					CLCD_voidSendCommand(1);
					while (1)
					{
						for (uint8 i = 0 ; i<16 ; i++)
						{
							DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN0);
							DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN1);
							DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN2);
							DIO_u8TogglePinValue(DIO_PORTC,DIO_PIN3);
							CLCD_voidGoToXY(i,0u);
							voidSendString("GOOD NIGHT");
							_delay_ms(100);
							CLCD_voidSendCommand(1);
						}
					}
				}
}
void LM35_FUNC (void)
{
	CLCD_voidGoToXY(0u,3u);
	voidSendString("The Temperature:") ;
	CLCD_voidGoToXY(17u,3u);
	Local_u16LM35Reading = (uint8)((( uint32 )Local_u16LM35Reading*500UL)/256UL);
	voidSendNumber(Local_u16LM35Reading);
	_delay_ms(3000) ;
}
