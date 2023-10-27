#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "EXTI_CFG.h"
#include "EXTI_Prv.h"
#include "EXTI_Register.h"
#include "EXTI_Interface.h"

static void ( *EXTI_pfFuncPtr[3] ) ( void ) = { NULL , NULL , NULL } ;   // ARRAY OF 3 POINTERS TO FUNCTION

void  EXTI_voidInit       ( void )
{
#if INT0_STATUS == ENABLE
	SET_BIT(GICR,GICR_INT0) ;
#elif INT0_STATUS == DISABLE
	CLR_BIT(GICR,GICR_INT0) ;
#else
#error "INT0_STATUS option Not Valid "
#endif

#if INT1_STATUS == ENABLE
	SET_BIT(GICR,GICR_INT1) ;
#elif INT1_STATUS == DISABLE
	CLR_BIT(GICR,GICR_INT1) ;
#else
#error "INT1_STATUS option Not Valid "
#endif

#if INT2_STATUS == ENABLE

	SET_BIT(GICR,GICR_INT2) ;
#elif INT2_STATUS == DISABLE
	CLR_BIT(GICR,GICR_INT2) ;
#else
#error "INT2_STATUS option Not Valid "
#endif

	#if 	INT0_SENSECONTROL == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00) ;
	CLR_BIT(MCUCR,MCUCR_ISC01) ;
	#elif 	INT0_SENSECONTROL == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00) ;
	CLR_BIT(MCUCR,MCUCR_ISC01) ;
	#elif 	INT0_SENSECONTROL == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00) ;
	SET_BIT(MCUCR,MCUCR_ISC01) ;
	#elif 	INT0_SENSECONTROL == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00) ;
	SET_BIT(MCUCR,MCUCR_ISC01) ;
	#else
	#error "INT0_SENSECONTROL OPTION NOT VALID "
	#endif

	#if 	INT1_SENSECONTROL == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC10) ;
		CLR_BIT(MCUCR,MCUCR_ISC11) ;
	#elif 	INT1_SENSECONTROL == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10) ;
		CLR_BIT(MCUCR,MCUCR_ISC11) ;
	#elif 	INT1_SENSECONTROL == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC10) ;
		SET_BIT(MCUCR,MCUCR_ISC11) ;
	#elif 	INT1_SENSECONTROL == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC10) ;
		SET_BIT(MCUCR,MCUCR_ISC11) ;
	#else
	#error "INT1_SENSECONTROL OPTION NOT VALID "
	#endif

	#if 	INT2_SENSECONTROL == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2) ;
	#elif 	INT2_SENSECONTROL == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2) ;
	#else
	#error "INT2_SENSECONTROL OPTION NOT VALID "
	#endif

}
uint8 EXTI_u8SetSenseCtrl ( EXTI_IntNum_t copy_IntNum , uint8 copy_u8SenseCtrl )
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_IntNum)
	{
	case INT0 : switch (copy_u8SenseCtrl)
		{
		case LOW_LEVEL 		: 	CLR_BIT(MCUCR,MCUCR_ISC00) ; CLR_BIT(MCUCR,MCUCR_ISC01) ; break ;
		case ON_CHANGE		:	SET_BIT(MCUCR,MCUCR_ISC00) ; CLR_BIT(MCUCR,MCUCR_ISC01) ; break ;
		case FALLING_EDGE 	:	CLR_BIT(MCUCR,MCUCR_ISC00) ; SET_BIT(MCUCR,MCUCR_ISC01) ; break ;
		case RISING_EDGE 	: 	SET_BIT(MCUCR,MCUCR_ISC00) ; SET_BIT(MCUCR,MCUCR_ISC01) ; break ;
		default : Local_u8ErrorState = NOK ; break ;
		}
	break ;
	case INT1 : switch (copy_u8SenseCtrl)
		{
		case LOW_LEVEL 		: 	CLR_BIT(MCUCR,MCUCR_ISC10) ; CLR_BIT(MCUCR,MCUCR_ISC11) ; break ;
		case ON_CHANGE		:	SET_BIT(MCUCR,MCUCR_ISC10) ; CLR_BIT(MCUCR,MCUCR_ISC11) ; break ;
		case FALLING_EDGE 	:	CLR_BIT(MCUCR,MCUCR_ISC10) ; SET_BIT(MCUCR,MCUCR_ISC11) ; break ;
		case RISING_EDGE 	: 	SET_BIT(MCUCR,MCUCR_ISC10) ; SET_BIT(MCUCR,MCUCR_ISC11) ; break ;
		default : Local_u8ErrorState = NOK ; break ;
		}
	break ;
	case INT2 : switch (copy_u8SenseCtrl)
		{
		case FALLING_EDGE 	:	CLR_BIT(MCUCSR,MCUCSR_ISC2) ; break ;
		case RISING_EDGE 	: 	SET_BIT(MCUCSR,MCUCSR_ISC2) ; break ;
		default : Local_u8ErrorState = NOK ; break ;
		}
	break ;
	default : Local_u8ErrorState = NOK ; break ;
	}
	return Local_u8ErrorState ;
}
uint8 EXTI_u8IntEnable 	  ( EXTI_IntNum_t copy_IntNum)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_IntNum)
	{
	case INT0 : SET_BIT(GICR,GICR_INT0) ; break ;
	case INT1 : SET_BIT(GICR,GICR_INT1) ; break ;
	case INT2 : SET_BIT(GICR,GICR_INT2) ; break ;
	default : Local_u8ErrorState = NOK ;  break ;
	}
	return Local_u8ErrorState ;
}
uint8 EXTI_u8IntDisable   ( EXTI_IntNum_t copy_IntNum)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_IntNum)
	{
	case INT0 : CLR_BIT(GICR,GICR_INT0) ; break ;
	case INT1 : CLR_BIT(GICR,GICR_INT1) ; break ;
	case INT2 : CLR_BIT(GICR,GICR_INT2) ; break ;
	default : Local_u8ErrorState = NOK ;  break ;
	}
	return Local_u8ErrorState ;
}
uint8 EXTI_u8IntClearFlag ( EXTI_IntNum_t copy_IntNum)
{
	uint8 Local_u8ErrorState = OK ;
	switch (copy_IntNum)
	{
	case INT0 : SET_BIT(GIFR,GIFR_INTF0) ; break ;
	case INT1 : SET_BIT(GIFR,GIFR_INTF0) ; break ;
	case INT2 : SET_BIT(GIFR,GIFR_INTF0) ; break ;
	default : Local_u8ErrorState = NOK ;  break ;
	}
	return Local_u8ErrorState ;
}
uint8 EXTI_u8SetCallBack  ( EXTI_IntNum_t copy_IntNum , void(*copy_pvFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK ;
	if ( copy_pvFuncPtr != NULL )
	{
		switch (copy_IntNum)
		{
		case INT0 : EXTI_pfFuncPtr[0] = copy_pvFuncPtr ; break ;
		case INT1 : EXTI_pfFuncPtr[1] = copy_pvFuncPtr ; break ;
		case INT2 : EXTI_pfFuncPtr[2] = copy_pvFuncPtr ; break ;
		default : Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR ;
	}
	return Local_u8ErrorState ;
}											/* INT0 ISR */

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if ( EXTI_pfFuncPtr[INT0] != NULL )
		{
			EXTI_pfFuncPtr[INT0]();
		}
	else
		{
			// DO NOTHING
		}
}

											/* INT1 ISR */

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if ( EXTI_pfFuncPtr[INT1] != NULL )
		{
			EXTI_pfFuncPtr[INT1]();
		}
	else
		{
			// DO NOTHING
		}
	}
											/* INT2 ISR */

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if ( EXTI_pfFuncPtr[INT2] != NULL )
		{
			EXTI_pfFuncPtr[INT2]();
		}
	else
		{
			// DO NOTHING
		}
}
