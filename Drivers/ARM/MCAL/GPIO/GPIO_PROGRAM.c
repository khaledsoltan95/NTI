#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "GPIO_CONFIG.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRV.h"
#include "GPIO_REG.h"

void GPIO_voidInit ( void )
{
	GPIOA_CRL  = PORTA_DIRL   	;
	GPIOA_CRH  = PORTA_DIRH   	;
	GPIOB_CRL  = PORTB_DIRL   	;
	GPIOB_CRH  = PORTB_DIRH		;
	GPIOC_CRL  = PORTC_DIRL     ;

	GPIOA_ODR = PORTA_VAL   	;
	GPIOB_ODR = PORTB_VAL   	;
	GPIOC_ODR = PORTC_VAL  		;
}
uint8 GPIO_U8SetPinDirection	(GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum,		GPIO_PinDir_t copy_Dir)
{
	uint8 Local_u8ErrorState = OK ;
	if ((copy_Port == GPIO_PORTC) && (copy_PinNum > GPIO_PIN2))
	{
		Local_u8ErrorState = NOK ;
	}
	else
	{
		if ( (copy_PinNum >= GPIO_PIN0) && (copy_PinNum <= GPIO_PIN7) )
		{
			if (copy_Dir == GPIO_PIN_INPUT)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : CLR_BIT(GPIOA_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOA_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTB : CLR_BIT(GPIOB_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOB_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTC : CLR_BIT(GPIOC_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOC_CRL,((copy_PinNum*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir == GPIO_PIN_OUTPUT_10MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : SET_BIT(GPIOA_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOA_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTB : SET_BIT(GPIOB_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOB_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTC : SET_BIT(GPIOC_CRL,((copy_PinNum*4u)+2u)) ;	CLR_BIT(GPIOC_CRL,((copy_PinNum*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir== GPIO_PIN_OUTPUT_2MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : CLR_BIT(GPIOA_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOA_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTB : CLR_BIT(GPIOB_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOB_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTC : CLR_BIT(GPIOC_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOC_CRL,((copy_PinNum*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir == GPIO_PIN_OUTPUT_50MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : SET_BIT(GPIOA_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOA_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTB : SET_BIT(GPIOB_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOB_CRL,((copy_PinNum*4u)+3u)) ; break ;
				case GPIO_PORTC : SET_BIT(GPIOC_CRL,((copy_PinNum*4u)+2u)) ;	SET_BIT(GPIOC_CRL,((copy_PinNum*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else if ( (copy_PinNum >= GPIO_PIN8) && (copy_PinNum <= GPIO_PIN15) )
		{
			if (copy_Dir == GPIO_PIN_INPUT)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : CLR_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	CLR_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				case GPIO_PORTB : CLR_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	CLR_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir == GPIO_PIN_OUTPUT_10MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : SET_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	CLR_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				case GPIO_PORTB : SET_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+2u))	;	CLR_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir== GPIO_PIN_OUTPUT_2MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : CLR_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	SET_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				case GPIO_PORTB : CLR_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	SET_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Dir == GPIO_PIN_OUTPUT_50MHZ)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : SET_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	SET_BIT(GPIOA_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
				case GPIO_PORTB : SET_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+2u)) ;	SET_BIT(GPIOB_CRH,(((copy_PinNum-8u)*4u)+3u)) ; break ;
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
	}
	return Local_u8ErrorState;
}
uint8 GPIO_U8SetPortDirection	(GPIO_Port_t copy_Port,	 uint64 copy_u64PortDir)
{
	uint8 Local_u8ErrorState = OK ;
		switch (copy_Port)
		{
		case GPIO_PORTA : GPIOA_CRL = (uint32)(copy_u64PortDir) ; GPIOA_CRH = (uint32)(copy_u64PortDir >> 32u) ;  break ;
		case GPIO_PORTB : GPIOB_CRL = (uint32)(copy_u64PortDir) ; GPIOB_CRH = (uint32)(copy_u64PortDir >> 32u) ;  break ;
		case GPIO_PORTC : GPIOC_CRL = (uint32)(copy_u64PortDir) ; break ;
		default : Local_u8ErrorState = NOK     ; break ;
		}
		return Local_u8ErrorState;
}

uint8 GPIO_U8SetPinValue	    (GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum,		GPIO_PinInitVal_t copy_Val)
{
	uint8 Local_u8ErrorState = OK ;
		if ( (copy_PinNum >= GPIO_PIN0) && (copy_PinNum <= GPIO_PIN15) )
		{
			if (copy_Val == GPIO_PIN_LOW)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : CLR_BIT(GPIOA_ODR,copy_PinNum); break ;
				case GPIO_PORTB : CLR_BIT(GPIOB_ODR,copy_PinNum); break ;
				case GPIO_PORTC : if ( (copy_PinNum <= GPIO_PIN2) && (copy_PinNum >= GPIO_PIN0 ) )	{CLR_BIT(GPIOC_ODR,copy_PinNum);}else {Local_u8ErrorState = NOK ; }break ;
				default : Local_u8ErrorState = NOK ; break ;
				}
			}
			else if (copy_Val == GPIO_PIN_HIGH)
			{
				switch (copy_Port)
				{
				case GPIO_PORTA : SET_BIT(GPIOA_ODR,copy_PinNum); break ;
				case GPIO_PORTB : SET_BIT(GPIOB_ODR,copy_PinNum); break ;
				case GPIO_PORTC : if ( (copy_PinNum <= GPIO_PIN2) && (copy_PinNum >= GPIO_PIN0 ) )	{SET_BIT(GPIOC_ODR,copy_PinNum);}else {Local_u8ErrorState = NOK ; }break ;
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
		return Local_u8ErrorState;
}
uint8 GPIO_U8SetPortValue    	(GPIO_Port_t copy_Port,	 uint16 copy_u16PortVal)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_Port)
	{
	case GPIO_PORTA : GPIOA_ODR = (uint32)copy_u16PortVal ; break ;
	case GPIO_PORTB : GPIOB_ODR = (uint32)copy_u16PortVal ; break ;
	case GPIO_PORTC : GPIOC_ODR = (uint32)copy_u16PortVal ; break ;
	default : Local_u8ErrorState = NOK      ; break ;
	}
	return Local_u8ErrorState;
}

uint8 GPIO_u8GetPinValue 		(GPIO_Port_t copy_port,  GPIO_Pin_t copy_PinNum, 		GPIO_PinVal_t* copy_pVal )
{
	uint8 Local_u8ErrorState = OK ;
	if (copy_pVal != NULL)
	{
		if ( (copy_PinNum >= GPIO_PIN0) && (copy_PinNum <= GPIO_PIN15) )
		{
			switch (copy_port)
			{
			case GPIO_PORTA : *copy_pVal = GET_BIT(GPIOA_IDR , copy_PinNum) ; break ;
			case GPIO_PORTB : *copy_pVal = GET_BIT(GPIOB_IDR , copy_PinNum) ; break ;
			case GPIO_PORTC : if ( (copy_PinNum <= GPIO_PIN2) && (copy_PinNum >= GPIO_PIN0 ) )	{*copy_pVal = GET_BIT(GPIOC_IDR , copy_PinNum ); }else {Local_u8ErrorState = NOK ; }break ;
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
		Local_u8ErrorState = NULL_PTR ;
	}

	return Local_u8ErrorState;
}
uint8 GPIO_u8TogglePinValue		(GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum)
{
	uint8 Local_u8ErrorState = OK ;
	if ( (copy_PinNum >= GPIO_PIN0 ) && (copy_PinNum <= GPIO_PIN15) )
	{
		switch (copy_Port)
					{
					case GPIO_PORTA : TOG_BIT(GPIOA_ODR,copy_PinNum); break ;
					case GPIO_PORTB : TOG_BIT(GPIOB_ODR,copy_PinNum); break ;
					case GPIO_PORTC : if ( (copy_PinNum <= GPIO_PIN2) && (copy_PinNum >= GPIO_PIN0 ) )	{TOG_BIT(GPIOC_ODR,copy_PinNum); }else {Local_u8ErrorState = NOK ; }break ;
					default : Local_u8ErrorState = NOK ; 		 break ;
					}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}
