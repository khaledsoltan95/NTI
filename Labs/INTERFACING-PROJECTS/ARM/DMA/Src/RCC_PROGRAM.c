#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "RCC_CONFIG.h"
#include "RCC_INTERFACE.h"
#include "RCC_PRV.h"
#include "RCC_REG.h"

void 	RCC_voidInit 					(void)
{
	RCC_AHBENR  = RCC_AHB_ENABLE  ;
	RCC_APB2ENR = RCC_APB2_ENABLE ;
	RCC_APB1ENR = RCC_APB1_ENABLE ;
	/*SET_BIT(RCC_CR,RCC_CR_HSEON) ;

	while (RCC_CR_HSERDY != 1u) ;

	SET_BIT(RCC_CFGR,18) ;				// Multiplication * 9
	SET_BIT(RCC_CFGR,19) ;				// Multiplication * 9
	SET_BIT(RCC_CFGR,20) ;				// Multiplication * 9
	CLR_BIT(RCC_CFGR,21) ; 				// Multiplication * 9

	SET_BIT(RCC_CFGR,1) ;				// PLL AS SYSTEM CLOCK
	CLR_BIT(RCC_CFGR,0) ; 				// PLL AS SYSTEM CLOCK

	SET_BIT(RCC_CR,RCC_CR_PLLON) ;

	SET_BIT(RCC_CFGR,25) ;*/
}

uint8 	RCC_u8ClockPeripheralEnable 	(RCC_Bus_List_t copy_u32BusID , uint8 copy_u8PeripheralID)
{
	uint8 Local_u8ErrorState = OK ;
	if (copy_u8PeripheralID < 32)
	{
		switch (copy_u32BusID)
		{
			case BUS_RCC_AHB  :	SET_BIT (RCC_AHBENR 	,copy_u8PeripheralID); break;
			case BUS_RCC_APB2 :	SET_BIT (RCC_APB2ENR	,copy_u8PeripheralID); break;
			case BUS_RCC_APB1 :	SET_BIT (RCC_APB1ENR	,copy_u8PeripheralID); break;
			default : Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}

uint8 	RCC_u8ClockPeripheralDisable 	(RCC_Bus_List_t copy_u32BusID , uint8 copy_u8PeripheralID)
{
	uint8 Local_u8ErrorState = OK ;
	if (copy_u8PeripheralID < 32)
	{
		switch (copy_u32BusID)
		{
		case BUS_RCC_AHB  :	CLR_BIT (RCC_AHBENR 	,copy_u8PeripheralID); break;
		case BUS_RCC_APB2 :	CLR_BIT (RCC_APB2ENR	,copy_u8PeripheralID); break;
		case BUS_RCC_APB1 :	CLR_BIT (RCC_APB1ENR	,copy_u8PeripheralID); break;
		default : Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}
