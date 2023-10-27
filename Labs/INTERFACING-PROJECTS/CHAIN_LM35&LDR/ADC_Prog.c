#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_CFG.h"
#include "ADC_Prv.h"
#include "ADC_Register.h"
#include "ADC_Interface.h"

static ADC_Chain_t* ADC_pStruct = NULL ;
static uint8 ADC_ConversionCounter = 0u ;
static uint8 ADC_u8BusyFlag = IDLE ;
static void(*ADC_pFunc)(void) = NULL ;
static uint8 ADC_ConversionType = SINGLE ;
static uint16* ADC_pu16DigitalResult = NULL ;

	void   ADC_voidInit  		      ( void )
	{
		#if 	ADC_REFERENCE_SELECTION_OPTION == AREF

		CLR_BIT(ADMUX,ADMUX_REFS0);
		CLR_BIT(ADMUX,ADMUX_REFS1);

		#elif 	ADC_REFERENCE_SELECTION_OPTION == AVCC

		SET_BIT(ADMUX,ADMUX_REFS0);
		CLR_BIT(ADMUX,ADMUX_REFS1);

		#elif 	ADC_REFERENCE_SELECTION_OPTION == RESERVED

		CLR_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);

		#elif 	ADC_REFERENCE_SELECTION_OPTION == INTERNAL_256MVOLT

		SET_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);

		#else
		#error "Not Valid ADC_REFERENCE_SELECTION_OPTION"
		#endif

		#if 	ADC_ADJUSTMENT_OPTION == LEFT_ADJUST

		SET_BIT(ADMUX,ADMUX_ADLAR);

		#elif 	ADC_ADJUSTMENT_OPTION == RIGHT_ADJUST

		CLR_BIT(ADMUX,ADMUX_ADLAR);

		#else
		#error "Not Valid ADC_ADJUSTMENT_OPTION"
		#endif

		// SET PRESCALER

		ADCSRA &= PRESCALER_MASK ;
		ADCSRA |= ADC_u8PRESCALER ;

		SET_BIT(ADCSRA,ADCSRA_ADEN);		// ENABLE


	}

	uint8 ADC_u8StartSingleConversionSynch     	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult )
	{
		uint8 Local_u8ErrorState = OK ;
		ADC_ConversionType = SINGLE ;
		if (copy_Channel <= ChannelMaxValue)
		{
			if (copy_pu16DigitalResult != NULL)
			{
				if ( ADC_u8BusyFlag != BUSY)
				{
					uint32 Local_u32Counter = 0u ;
					ADC_u8BusyFlag = BUSY ;

					ADMUX &= CHANNEL_SELECTION_MASK ;
					ADMUX |= copy_Channel ;				// SET CHANNEL

					SET_BIT(ADCSRA,ADCSRA_ADSC) ; 		// START CONVERSION

					while ((GET_BIT(ADCSRA,ADCSRA_ADIF) == 0u) && (Local_u32Counter < ADC_u32TIMEOUT_COUNT))
					{
						Local_u32Counter ++ ;
					}
					if (Local_u32Counter == ADC_u32TIMEOUT_COUNT)
					{
						Local_u8ErrorState = TIMEOUT_ERR ;
					}
					else
					{
						SET_BIT(ADCSRA,ADCSRA_ADIF) ; 		// Clear Flag

						#if ADC_u8RESOLUTION == EIGHT_BITS
						*copy_pu16DigitalResult = (uint16) ADCH ;
						#elif ADC_u8RESOLUTION == TEN_BITS
						*copy_pu16DigitalResult = ADC ;
						#else
						#error "ADC_u8RESOLUTION option not valid"
						#endif
						ADC_u8BusyFlag = IDLE ;
					}
				}
				else
				{
					Local_u8ErrorState = BUSY_ERR ;
				}
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		return Local_u8ErrorState ;
	}

	uint16 ADC_u8StartSingleConversionAsynch	 	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) )
	{
		uint8 Local_u8ErrorState = OK ;
		ADC_ConversionType = SINGLE ;
		if (copy_Channel <= ChannelMaxValue)
		{
			if ( (copy_pu16DigitalResult != NULL) && (copy_pvNotification != NULL) )
			{
				if ( ADC_u8BusyFlag != BUSY)
				{
					ADC_u8BusyFlag = BUSY ;

					ADC_pFunc = copy_pvNotification ;
					ADC_pu16DigitalResult = copy_pu16DigitalResult ;

					ADMUX &= CHANNEL_SELECTION_MASK ;
					ADMUX |= copy_Channel ;				// SET CHANNEL

					SET_BIT(ADCSRA,ADCSRA_ADIE) ; 		// ENABLE INTERRUPT

					SET_BIT(ADCSRA,ADCSRA_ADSC) ; 		// START CONVERSION

				}
				else
				{
					Local_u8ErrorState = BUSY_ERR ;
				}
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		return Local_u8ErrorState ;
	}

	uint8  ADC_u8StartChainConversionAsynch 	 	 (const ADC_Chain_t *copy_ChainData)
	{
		uint8 Local_u8ErrorState = OK ;
		if (ADC_u8BusyFlag != BUSY)
		{
			if ( (copy_ChainData != NULL) && (copy_ChainData -> ChannelArr != NULL) && (copy_ChainData -> ResultArr != NULL) && (copy_ChainData -> NotificationFunc != NULL) )
			{
				ADC_u8BusyFlag = BUSY ;

				ADC_ConversionType = CHAIN ;

				ADC_pStruct = copy_ChainData ;

				ADMUX &= CHANNEL_SELECTION_MASK ;
				ADMUX |= copy_ChainData -> ChannelArr[ADC_ConversionCounter] ;				// SET CHANNEL

				SET_BIT(ADCSRA,ADCSRA_ADIE) ; 		// ENABLE INTERRUPT
				SET_BIT(ADCSRA,ADCSRA_ADSC) ; 		// START CONVERSION
			}
			else
			{
				Local_u8ErrorState = NULL_PTR ;
			}
		}
		else
		{
			Local_u8ErrorState = BUSY_ERR  ;
		}
		return Local_u8ErrorState ;
	}

	uint8  ADC_u8StartChainConversionSynch 	 	 ( const uint8 ConversionsNum , const ADC_Channel_t* ChannelArr , const uint16* ResultArr)
		{
			uint8 Local_u8ErrorState = OK ;
			if (ADC_u8BusyFlag != BUSY)
			{
				if ( (ChannelArr != NULL) && (ResultArr != NULL) )
				{
					static uint8 Local_u8Iterator = 0u ;

					ADC_ConversionType = CHAIN ;

					while ( Local_u8Iterator < ConversionsNum )
					{
						ADC_u8StartSingleConversionSynch(ChannelArr[Local_u8Iterator],&(ResultArr[Local_u8Iterator])) ;
						Local_u8Iterator ++ ;
					}
				}
				else
				{
					Local_u8ErrorState = NULL_PTR ;
				}
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR  ;
			}
			return Local_u8ErrorState ;
		}
	void __vector_16 (void) __attribute__((signal)) ;
	void __vector_16 (void)
	{
			if (ADC_ConversionType == SINGLE)
			{
				#if ADC_u8RESOLUTION == EIGHT_BITS
				*ADC_pu16DigitalResult = (uint16) ADCH ;

				#elif ADC_u8RESOLUTION == TEN_BITS
				*ADC_pu16DigitalResult = ADC ;

				#else
				#error "ADC_u8RESOLUTION option not valid"
				#endif

				SET_BIT(ADCSRA,ADCSRA_ADIF) ; 		// Clear Flag

				CLR_BIT(ADCSRA,ADCSRA_ADIE) ; 		// DISABLE INTERRUPT

				ADC_u8BusyFlag = IDLE ;
				if (ADC_pFunc != NULL)
				{
					ADC_pFunc() ;
				}
				else
				{
					// DO NOTHING
				}
			}
			else if (ADC_ConversionType == CHAIN)
			{
				#if ADC_u8RESOLUTION == EIGHT_BITS
				ADC_pStruct -> ResultArr[ADC_ConversionCounter] = (uint16) ADCH ;

				#elif ADC_u8RESOLUTION == TEN_BITS
				ADC_pStruct -> ResultArr[ADC_ConversionCounter] = (uint16) ADCH ;

				#else
				#error "ADC_u8RESOLUTION option not valid"
				#endif

				ADC_ConversionCounter ++ ;

				if (ADC_ConversionCounter < ( ADC_pStruct -> ConversionsNum ) )
				{
					ADMUX &= CHANNEL_SELECTION_MASK ;
					ADMUX |= ADC_pStruct -> ChannelArr [ADC_ConversionCounter] ;

					SET_BIT(ADCSRA,ADCSRA_ADIE) ; 	// ENABLE INTERRUPT
					SET_BIT(ADCSRA,ADCSRA_ADSC) ; 	// START CONVERSION

				}
				else
				{
					SET_BIT(ADCSRA,ADCSRA_ADIF) ; 		// Clear Flag ( HW DO IT BY DEFFAULT )

					CLR_BIT(ADCSRA,ADCSRA_ADIE) ; 		// DISABLE INTERRUPT

					ADC_ConversionCounter = 0 ;

					ADC_u8BusyFlag = IDLE ;
					if (ADC_pStruct -> NotificationFunc)
					{
						ADC_pStruct -> NotificationFunc() ;
					}
					else
					{
						// DO NOTHING
					}

				}
			}
			else
			{
				// DO NOTHING
			}

		}


