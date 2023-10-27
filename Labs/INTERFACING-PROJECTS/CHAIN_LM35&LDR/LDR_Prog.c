#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "ADC_Interface.h"

#include "CLCD_Interface.h"
#include "LDR_Interface.h"
#include "LDR_Prv.h"
#include "LDR_Cfg.h"

										/* Functions Initialization */

	uint16 LDR_u16GetLightLevel ( void )
	{
		uint16 Local_u16ChannelReading ;

		ADC_u8StartSingleConversionSynch(LDR_ADC_CHANNEL,&Local_u16ChannelReading);


		return Local_u16ChannelReading ;

	}


