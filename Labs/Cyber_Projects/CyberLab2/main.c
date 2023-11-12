#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "util/delay.h"

#include "PORT_Interface.h"
#include "DIO_Interface.h"
#include "USART_Interface.h"
#include "TIMER_Interface.h"
#include "GIE_Interface.h"

#include "CLCD_Interface.h"

#define KEY 				5u
void 	ISR1 				(void) ;
void 	ISR2 				(void) ;
uint16 	Algorithm 			(uint16 copy_u16Num) ;
uint16 	ConcatenateNumber	(char* copy_parr) ;

static uint8 Flag = 0u ;
static uint8 Flag2 = 0u ;
static char Input[4] ;
static char Input2[5] ;
static char Required[]="2701" ;				// Request Number
static uint8 Counter = 0u ;
uint16 RandomNumber = 0u ;
uint16 NumberShould = 0u ;
static uint16 UserNumber = 0u ;
void main ()
{

	PORT_voidInit() ;

	CLCD_voidInit() ;

	USART_voidInit() ;

	TIMER0_voidInit() ;

	GIE_voidEnableGlobal() ;

	USART_u8ReceiveStringBufferAsynch(Input,&ISR1) ;

	while (1)
	{
		if (Flag == 1u)
		{
			for (uint8 i = 0 ; i<4 ;i++)
			{
				if (Input[i] == Required[i])
				{
					Counter ++ ;
				}
				else
				{
					// DO NOTHING
				}
			}
			if (Counter == 4u)
			{
				Input[0] += 4 ;
				USART_u8SendStringBufferAsynch(Input,&ISR1) ;
				_delay_ms(1000) ;
				CLCD_voidSendCommand(1) ;
				voidSendString("RandomNum=") ;
				RandomNumber = TIMER0_u16GetTimerVal() ;
				RandomNumber += 300 ;
				voidSendNumber(RandomNumber) ;
				DIO_U8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW) ;
				DIO_U8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW) ;
				DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH) ;
				NumberShould = Algorithm(RandomNumber) ;
				USART_u8ReceiveStringBufferAsynch(Input2,&ISR2) ;
				while (Flag2 != 1u ) ;
				UserNumber = ConcatenateNumber(Input2);
				voidSendNumber(UserNumber) ;
				if (UserNumber == NumberShould)
				{
					CLCD_voidSendCommand(1) ;
					DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW) ;
					DIO_U8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH) ;
					voidSendString("7101AA00");
				}
				else
				{
					CLCD_voidSendCommand(1) ;
					DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW) ;
					DIO_U8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH) ;
					voidSendString("NRC 7F 31 35");
				}
				while(1) ;
			}
			else
			{
				CLCD_voidSendCommand(1) ;
				char Answer[] = "Not Valid Request 7F 27 35" ;
				USART_u8SendStringBufferAsynch(Answer,ISR1) ;
				DIO_U8SetPinValue(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW) ;
				DIO_U8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH) ;
				while(1) ;
			}
		}

	}
}
void ISR1 (void)
{
	/*for (uint8 i = 0 ; i<4 ;i++)
	{
		CLCD_voidSendData(Input[i]) ;
	}*/
	Flag = 1u ;

}
void ISR2 (void)
{
	Flag2 = 1u ;
}
uint16 Algorithm (uint16 copy_u16Num)
{
	copy_u16Num |= KEY ;
	return copy_u16Num ;
}
uint16 	ConcatenateNumber	(char* copy_parr)
{
	uint16 Local_u16UserNumber = 0u ;
	for (uint8 i = 0u ; i<5 ; i++)
	{
		Local_u16UserNumber = (Local_u16UserNumber * 10u) + (copy_parr[i] - 48 ) ;
	}
	return Local_u16UserNumber ;
}


