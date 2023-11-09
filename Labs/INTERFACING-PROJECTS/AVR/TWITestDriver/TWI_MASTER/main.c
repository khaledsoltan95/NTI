#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"
#include <util/delay.h>


#include "PORT_Interface.h"
#include "TWI_Interface.h"

#include "CLCD_Interface.h"

void main ()
{
	uint8 Local_u8Data = 0u ;

	PORT_voidInit();

	TWI_u8MasterInit(0u) ;

	Local_u8Data =TWI_voidSendStartCondition();

	Local_u8Data = TWI_voidSendSlaveAddressWithWrite(3u);

	Local_u8Data = TWI_voidMasterWriteDataByte('7') ;

	TWI_voidSendStopCondition() ;


	while (1)
	{

	}
}
