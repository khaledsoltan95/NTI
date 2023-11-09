#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "SYSTICK_CONFIG.h"
#include "SYSTICK_PRV.h"
#include "SYSTICK_REG.h"
#include "SYSTICK_INTERFACE.h"

static volatile uint8 SYSTICK_u8Status 	= FREE ;
static void (*SYSTICK_pFunction)(void)	= NULL ;
static volatile uint8 SYSTICK_u8Type 	= SINGLE ;

void		STK_voidInit						(void)
{
								/* SET SYSTICK CLOCK SOURCE */
#if 		SYSTICK_u8CLKSource == AHB_DIVIDEDBY_8
	CLR_BIT(STK_CTRL,STK_CTRL_CLKSOURCE) ;
#elif 		SYSTICK_u8CLKSource == AHB
	SET_BIT(STK_CTRL,STK_CTRL_CLKSOURCE) ;
#else
	#error "NOT VALID SYSTICK_u8CLKSource Configuration"
#endif

								/* INTERRUP ENABLING */
#if 		SYSTICK_u8TickIntEnable == ENABLE
			SET_BIT(STK_CTRL,STK_CTRL_TICKINT) ;					// ENABLE INTERRUPT
#elif 		SYSTICK_u8TickIntEnable == DISABLE
			CLR_BIT(STK_CTRL,STK_CTRL_TICKINT) ;					// DISABLE INTERRUPT
#else
#error "NOT VALID SYSTICK_u8TickIntEnable Configuration"
#endif

								/* SYSTICK ENABLING */
#if 		SYSTICK_u8SysTickEnable == ENABLE
			SET_BIT(STK_CTRL,STK_CTRL_ENABLE) ;						// ENABLE SYSTICK
#elif 		SYSTICK_u8SysTickEnable == DISABLE
			CLR_BIT(STK_CTRL,STK_CTRL_ENABLE) ;						// DISABLE SYSTICK
#else
#error "NOT VALID SYSTICK_u8SysTickEnable Configuration"
#endif
}

uint8		STK_voidSetBusyWait					(uint32	copy_u32Ticks)
{
	uint8 Local_u8ErrorState = OK ;
	if (copy_u32Ticks < SYSTICK_TOP_VAL)
	{
		STK_LOAD = copy_u32Ticks ;

											/* Enable Timer */
		SET_BIT(STK_CTRL,STK_CTRL_ENABLE) ;

		while (GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG) != FLAG_UP) ;

		STK_LOAD = 0u ;

											/* DISABLE Timer */
		CLR_BIT(STK_CTRL,STK_CTRL_ENABLE) ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}

uint8		STK_voidSetIntervalSingle			(uint32	copy_u32Ticks, void (*copy_pFunction)(void))
{
	uint8 Local_u8ErrorState = OK ;
	if (copy_pFunction != NULL)
	{
		if (copy_u32Ticks < SYSTICK_TOP_VAL)
		{
			if (SYSTICK_u8Status != BUSY)
			{
				SYSTICK_u8Status = BUSY ;
				SYSTICK_u8Type = SINGLE ;
				 	 	 	 	 	 	 	 	 	 /* ENABLE INTERRUPT */
				SET_BIT(STK_CTRL,STK_CTRL_TICKINT) ;
				SYSTICK_pFunction = copy_pFunction ;
				STK_LOAD = copy_u32Ticks ; 							// LOAD TICKS VALUE INTO LOAD_REG
													/* Enable Timer */
				SET_BIT(STK_CTRL,STK_CTRL_ENABLE) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ; 					// IT WILL DONE AUTOMATICALLY BUT FOR MORE CHECK
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
	return Local_u8ErrorState ;
}

uint8		STK_voidSetIntervalPeriodic			(uint32	copy_u32Ticks, void (*copy_pFunction)(void))
{
	uint8 Local_u8ErrorState = OK ;
		if (copy_pFunction != NULL)
		{
			if (copy_u32Ticks < SYSTICK_TOP_VAL)
			{
				if (SYSTICK_u8Status != BUSY)
				{
					SYSTICK_u8Status = BUSY ;
					SYSTICK_u8Type = PERIODIC ;
											 /* ENABLE INTERRUPT */
					SET_BIT(STK_CTRL,STK_CTRL_TICKINT) ;

					SYSTICK_pFunction = copy_pFunction ;				// MAKE IT GLOBAL
					STK_LOAD = copy_u32Ticks ; 							// LOAD TICKS VALUE INTO LOAD_REG
											/* Enable Timer */
					SET_BIT(STK_CTRL,STK_CTRL_ENABLE) ;
				}
				else
				{
					Local_u8ErrorState = BUSY_ERR ; 					// IT WILL DONE AUTOMATICALLY BUT FOR MORE CHECK
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
		return Local_u8ErrorState ;
}

void		STK_voidStopInterval				(void)
{
												/* LOAD ZERO INTO REGISTER */
	STK_LOAD = 0u ;

												/* DISABLE INTERRUPT */
	CLR_BIT(STK_CTRL,STK_CTRL_TICKINT) ;

												/* DISABLE Timer */
	CLR_BIT(STK_CTRL,STK_CTRL_ENABLE) ;
}

uint32		STK_u32GetElapsedTime				(void)
{
	return STK_LOAD - STK_VAL ;
}

uint32		STK_u32GetRemainingTime				(void)
{
	return STK_VAL ;
}

										/* SYSTICK DOWN_FLOW ISR */
void		SysTick_Handler						(void);
void		SysTick_Handler						(void)
{
	volatile uint8 Local_u8Temp ;
	if(SYSTICK_u8Type == SINGLE)
	{
												/* LOAD ZERO INTO REGISTER */
		STK_LOAD = 0u ;

												/* DISABLE INTERRUPT */
		CLR_BIT(STK_CTRL,STK_CTRL_TICKINT) ;

												/* DISABLE Timer */
		CLR_BIT(STK_CTRL,STK_CTRL_ENABLE) ;
	}
	SYSTICK_u8Status = FREE ;

												/* SET FLAG BY READING IT */
	Local_u8Temp = GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG);

	if (SYSTICK_pFunction != NULL)
	{
		SYSTICK_pFunction () ;
	}
	else
	{
		// DO NOTHING
	}
}
