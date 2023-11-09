#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


										/* Functions Deceleration */
		/**
		 * @brief options of channel conversion
		 */
	typedef enum
	{
		ADC0_SINGLE_ENDED = 0 ,     //!< ADC0_SINGLE_ENDED
		ADC1_SINGLE_ENDED ,         //!< ADC1_SINGLE_ENDED
		ADC2_SINGLE_ENDED ,         //!< ADC2_SINGLE_ENDED
		ADC3_SINGLE_ENDED ,         //!< ADC3_SINGLE_ENDED
		ADC4_SINGLE_ENDED ,         //!< ADC4_SINGLE_ENDED
		ADC5_SINGLE_ENDED ,         //!< ADC5_SINGLE_ENDED
		ADC6_SINGLE_ENDED ,         //!< ADC6_SINGLE_ENDED
		ADC7_SINGLE_ENDED ,         //!< ADC7_SINGLE_ENDED
		ADC0_POS_ADC0_NEG_10X_GAIN ,//!< ADC0_POS_ADC0_NEG_10X_GAIN
		ADC1_POS_ADC0_NEG_10X_GAIN , //!< ADC1_POS_ADC0_NEG_10X_GAIN
		ADC0_POS_ADC0_NEG_200X_GAIN ,
		ADC1_POS_ADC0_NEG_200X_GAIN ,
		ADC2_POS_ADC2_NEG_10X_GAIN ,
		ADC3_POS_ADC2_NEG_10X_GAIN ,
		ADC2_POS_ADC2_NEG_200X_GAIN ,
		ADC3_POS_ADC2_NEG_200X_GAIN ,
		ADC0_POS_ADC1_NEG_1X_GAIN ,
		ADC1_POS_ADC1_NEG_1X_GAIN ,
		ADC2_POS_ADC1_NEG_1X_GAIN ,
		ADC3_POS_ADC1_NEG_1X_GAIN ,
		ADC4_POS_ADC1_NEG_1X_GAIN ,
		ADC5_POS_ADC1_NEG_1X_GAIN ,
		ADC6_POS_ADC1_NEG_1X_GAIN ,
		ADC7_POS_ADC1_NEG_1X_GAIN ,
		ADC0_POS_ADC2_NEG_1X_GAIN ,
		ADC1_POS_ADC2_NEG_1X_GAIN ,
		ADC2_POS_ADC2_NEG_1X_GAIN ,
		ADC3_POS_ADC2_NEG_1X_GAIN ,
		ADC4_POS_ADC2_NEG_1X_GAIN ,
		ADC5_POS_ADC2_NEG_1X_GAIN ,
		_122MVOLT ,
		_0VOLT

	}ADC_Channel_t ;

	typedef struct
	{
		uint8   		ConversionsNum;
		ADC_Channel_t   *ChannelArr;
	    uint16  		*ResultArr;
	    void    (*NotificationFunc)(void);

	} ADC_Chain_t;
	/**
	 * @brief this file contains functions decelerations which used in program file for ADC initialization and conversion options .
	 */
	void   ADC_voidInit  		      ( void ) ;

	uint8  ADC_u8StartSingleConversionSynch     	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult ) ;

	uint16 ADC_u8StartSingleConversionAsynch	 	 ( ADC_Channel_t copy_Channel , uint16* copy_pu16DigitalResult , void(*copy_pvNotification)(void) ) ;

	uint8  ADC_u8StartChainConversionSynch 	 	 ( const uint8 ConversionsNum , const ADC_Channel_t* ChannelArr , const uint16* ResultArr) ;

	uint8  ADC_u8StartChainConversionAsynch 	 	 (const ADC_Chain_t *copy_ChainData);
#endif
