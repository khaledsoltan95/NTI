#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "RCC_INTERFACE.h"
#include "DMA1_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

void ISR (void) ;
int main(void)
{
																	/* TEST RCC_FUNCTIONS */
	RCC_voidInit() ;

																	/* TEST STK_FUNCTIONS */
	/*STK_voidInit() ;
	STK_voidSetBusyWait(100);
	STK_voidSetIntervalPeriodic(100u, &ISR) ;
	STK_voidSetBusyWait(200) ;
	STK_voidStopInterval() ; */
																	/* TEST GPIO_FUNCTIONS */
	/*GPIO_U8SetPortDirection(GPIO_PORTA, 0x3333333333333333);
	GPIO_U8SetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH) ;
	GPIO_U8SetPortValue(GPIO_PORTB, 0) ;
	GPIO_u8TogglePinValue(GPIO_PORTA, GPIO_PIN1) ;*/
																	/* TEST DMA1_FUNCTIONS */
	// DMA1_voidChannelPreBuiltInit() ;

	while (1)
	{

	}

}

void ISR (void)
{
	RCC_u8ClockPeripheralDisable	(BUS_RCC_AHB, 0u);
}
