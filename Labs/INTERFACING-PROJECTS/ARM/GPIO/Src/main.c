#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"


int main(void)
{
											/* ENABLE PERIPHERALS WILL BE USED */

	//RCC_u8ClockPeripheralEnable(BUS_RCC_APB2, 2u) ;
	//RCC_u8ClockPeripheralEnable(BUS_RCC_APB2, 3u) ;
	//RCC_u8ClockPeripheralEnable(BUS_RCC_APB2, 4u) ;
	RCC_voidInit() ;

											/* USE GPIO PREBUILT CONFIGURATIONS */

	GPIO_voidInit() ;

	while (1)
	{

	}

}

