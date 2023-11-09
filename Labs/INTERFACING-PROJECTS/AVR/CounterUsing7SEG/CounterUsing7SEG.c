#include "STD_TYPES.h"
#include "ERR_TYPE.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "PORT_Interface.h"
#include "DIO_Interface.h"

#define 	PORTA 	 *((volatile uint8*)0x3B)
#define 	DDRA 	 *((volatile uint8*)0x3A)
#define 	PORTB 	 *((volatile uint8*)0x38)
#define 	DDRB 	 *((volatile uint8*)0x37)
#define 	MASKA 	 0b11110011
#define 	MASKB 	 0b10001000
#define 	MASK_NUM 0b11101000

void Counter (uint32 copy_u16Number , uint32 copy_u32DelayValue);
char Num [10] = {0,1,2,3,4,5,6,7,0b00010000 , 0b00010001 } ;

void main ()
{
						/* Enable  */
	DDRA  &= MASKA ;
	DDRA  |= 0b00001100 ;
	PORTA &= MASKA ;
	PORTA |= 0b000000 ;

						/* SET VALUE */
	DDRB  &= MASKB ;
	DDRB  |= 0b01110111 ;
	PORTB &= MASKB ;
//	DIO_SET_PORT_VALUE(DIO_PORTB,(PORTB |= Num[9]) ) ;

	uint32 u32_Counter = 1000 ;
	while (1)
	{
		while (u32_Counter >= 0 )
		{
		Counter(u32_Counter , 100) ;
		u32_Counter -- ;
		}

	}
}
void Counter (uint32 copy_u32Number , uint32 copy_u32DelayValue)
{
	uint8 Local_u8arrNumber[4] = {0}  ;
	sint8 Local_s8Iterator = 3  ;
	while ( ( Local_s8Iterator >= 0 ) || (copy_u32Number != 0u ) )
	{
		Local_u8arrNumber[Local_s8Iterator] = (uint8)(copy_u32Number % 10) ;
		copy_u32Number /= 10 ;
		Local_s8Iterator -- ;
	}
	sint8 Counter_loop= copy_u32DelayValue / 20  ;
	while (Counter_loop >= 0)
	{
		SET_BIT(PORTA,2);
		SET_BIT(PORTA,3);
		SET_BIT(PORTB,5);
		CLR_BIT(PORTB,6);
		PORTB &= MASK_NUM ;
		PORTB |=  Num[Local_u8arrNumber[0]] ;
		_delay_ms(5) ;

		SET_BIT(PORTB,6);
		CLR_BIT(PORTB,5);
		PORTB &= MASK_NUM ;
		PORTB |=  Num[Local_u8arrNumber[1]] ;
		_delay_ms(5) ;

		SET_BIT(PORTB,5);
		CLR_BIT(PORTA,2);
		PORTB &= MASK_NUM ;
		PORTB |=  Num[Local_u8arrNumber[2]] ;
		_delay_ms(5) ;

		SET_BIT(PORTA,2);
		CLR_BIT(PORTA,3);
		PORTB &= MASK_NUM ;
		PORTB |=  Num[Local_u8arrNumber[3]] ;
		_delay_ms(5) ;
		Counter_loop -- ;
	}
}

