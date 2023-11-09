#include "STD_TYPES.h"
#include "ERR_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_Reg.h"
#include "DIO_Interface.h"
#include "DIO_Cfg.h"
#include "DIO_Prv.h"

void  PORT_INIT 				(void)
{
	DDRA = PORTA_DIRECTION ;
	DDRB = PORTB_DIRECTION ;
	DDRC = PORTC_DIRECTION ;
	DDRD = PORTD_DIRECTION ;

	PORTA = PORTA_VALUE ;
	PORTB = PORTB_VALUE ;
	PORTC = PORTC_VALUE ;
	PORTD = PORTD_VALUE ;

}
uint8 DIO_SET_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN ,DIO_PIN_VALUE copy_Status)
{
	uint8 Local_u8ErrorState = OK ;

	if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN7 ) )
	{
		if ( copy_Status == HIGH )
		{
			switch (copy_Port)
			{
			case DIO_PORTA : SET_BIT(PORTA,copy_PIN) ; break ;
			case DIO_PORTB : SET_BIT(PORTB,copy_PIN) ; break ;
			case DIO_PORTC : SET_BIT(PORTC,copy_PIN) ; break ;
			case DIO_PORTD : SET_BIT(PORTD,copy_PIN) ; break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else if ( copy_Status == LOW )
		{
			switch (copy_Port)
			{
			case DIO_PORTA : CLR_BIT(PORTA,copy_PIN) ; break ;
			case DIO_PORTB : CLR_BIT(PORTB,copy_PIN) ; break ;
			case DIO_PORTC : CLR_BIT(PORTC,copy_PIN) ; break ;
			case DIO_PORTD : CLR_BIT(PORTD,copy_PIN) ; break ;
			default : Local_u8ErrorState = NOK ; break ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
return Local_u8ErrorState ;
}
uint8 DIO_SET_PIN_DIRECTION 	(DIO_PORT copy_Port,DIO_PIN copy_PIN ,DIO_PIN_Direction copy_Status)
{
	uint8 Local_u8ErrorState = OK ;

		if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN7 ) )
		{
			if ( copy_Status == INPUT )
			{
				switch (copy_Port)
				{
				case DIO_PORTA : CLR_BIT(DDRA,copy_PIN) ; break ;
				case DIO_PORTB : CLR_BIT(DDRA,copy_PIN) ; break ;
				case DIO_PORTC : CLR_BIT(DDRA,copy_PIN) ; break ;
				case DIO_PORTD : CLR_BIT(DDRA,copy_PIN) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if ( copy_Status == OUTPUT )
			{
				switch (copy_Port)
				{
				case DIO_PORTA : SET_BIT(DDRA,copy_PIN) ; break ;
				case DIO_PORTB : SET_BIT(DDRB,copy_PIN) ; break ;
				case DIO_PORTC : SET_BIT(DDRC,copy_PIN) ; break ;
				case DIO_PORTD : SET_BIT(DDRD,copy_PIN) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	return Local_u8ErrorState ;
}
uint8 DIO_SET_PORT_DIRECTION 	(DIO_PORT copy_Port,uint8 copy_u8Direction)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_Port)
	{
	case DIO_PORTA : DDRA = copy_u8Direction ; break ;
	case DIO_PORTB : DDRB = copy_u8Direction ; break ;
	case DIO_PORTC : DDRC = copy_u8Direction ; break ;
	case DIO_PORTD : DDRD = copy_u8Direction ; break ;
	default : Local_u8ErrorState = NOK ; break ;
	}
	return Local_u8ErrorState ;
}
uint8 DIO_SET_PORT_VALUE 		(DIO_PORT copy_Port,uint8 copy_u8Value)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_Port)
	{
	case DIO_PORTA : PORTA = copy_u8Value ; break ;
	case DIO_PORTB : PORTB = copy_u8Value ; break ;
	case DIO_PORTC : PORTC = copy_u8Value ; break ;
	case DIO_PORTD : PORTD = copy_u8Value ; break ;
	default : Local_u8ErrorState = NOK      ; break ;
	}
	return Local_u8ErrorState;
}
uint8 DIO_GET_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN ,uint8* copy_pu8Value)
{
	uint8 Local_u8ErrorState = OK ;

		if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN7 ) )
		{
				switch (copy_Port)
				{
				case DIO_PORTA : *copy_pu8Value = GET_BIT(PORTA,copy_PIN) ; break ;
				case DIO_PORTB : *copy_pu8Value = GET_BIT(PORTB,copy_PIN) ; break ;
				case DIO_PORTC : *copy_pu8Value = GET_BIT(PORTC,copy_PIN) ; break ;
				case DIO_PORTD : *copy_pu8Value = GET_BIT(PORTD,copy_PIN) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	return Local_u8ErrorState ;
}
uint8 DIO_TOGGLE_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN )
{
	uint8 Local_u8ErrorState = OK ;

			if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN7 ) )
			{
					switch (copy_Port)
					{
					case DIO_PORTA : TOG_BIT(PORTA,copy_PIN) ; break ;
					case DIO_PORTB : TOG_BIT(PORTB,copy_PIN) ; break ;
					case DIO_PORTC : TOG_BIT(PORTC,copy_PIN) ; break ;
					case DIO_PORTD : TOG_BIT(PORTD,copy_PIN) ; break ;
					default : Local_u8ErrorState = NOK ; break ;
					}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		return Local_u8ErrorState ;
}
uint8 DIO_SET_PIN_VALUE1 		(DIO_PIN copy_PIN ,DIO_PIN_VALUE copy_Status)
{
	uint8 Local_u8ErrorState = OK ;

		if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN31 ) )
		{
			uint8 Local_u8PortSelect = copy_PIN / 8 ;
			uint8 Local_u8PinSelect  = copy_PIN % 8 ;
			if ( copy_Status == HIGH )
			{
				switch (Local_u8PortSelect)
				{
				case DIO_PORTA : SET_BIT(PORTA,Local_u8PinSelect) ; break ;
				case DIO_PORTB : SET_BIT(PORTB,Local_u8PinSelect) ; break ;
				case DIO_PORTC : SET_BIT(PORTC,Local_u8PinSelect) ; break ;
				case DIO_PORTD : SET_BIT(PORTD,Local_u8PinSelect) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if ( copy_Status == LOW )
			{
				switch (Local_u8PortSelect)
				{
				case DIO_PORTA : CLR_BIT(PORTA,Local_u8PinSelect) ; break ;
				case DIO_PORTB : CLR_BIT(PORTB,Local_u8PinSelect) ; break ;
				case DIO_PORTC : CLR_BIT(PORTC,Local_u8PinSelect) ; break ;
				case DIO_PORTD : CLR_BIT(PORTD,Local_u8PinSelect) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	return Local_u8ErrorState ;
}
uint8 DIO_SET_PIN_DIRECTION1 	(DIO_PIN copy_PIN ,DIO_PIN_Direction copy_Status)
{
	uint8 Local_u8ErrorState = OK ;

		if ( ( copy_PIN >= PIN0 ) && ( copy_PIN <= PIN31 ) )
		{
			uint8 Local_u8PortSelect = copy_PIN / 8 ;
			uint8 Local_u8PinSelect  = copy_PIN % 8 ;
			if ( copy_Status == HIGH )
			{
				switch (Local_u8PortSelect)
				{
				case DIO_PORTA : SET_BIT(DDRA,Local_u8PinSelect) ; break ;
				case DIO_PORTB : SET_BIT(DDRB,Local_u8PinSelect) ; break ;
				case DIO_PORTC : SET_BIT(DDRC,Local_u8PinSelect) ; break ;
				case DIO_PORTD : SET_BIT(DDRD,Local_u8PinSelect) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if ( copy_Status == LOW )
			{
				switch (Local_u8PortSelect)
				{
				case DIO_PORTA : CLR_BIT(DDRA,Local_u8PinSelect) ; break ;
				case DIO_PORTB : CLR_BIT(DDRB,Local_u8PinSelect) ; break ;
				case DIO_PORTC : CLR_BIT(DDRC,Local_u8PinSelect) ; break ;
				case DIO_PORTD : CLR_BIT(DDRD,Local_u8PinSelect) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	return Local_u8ErrorState ;
}
