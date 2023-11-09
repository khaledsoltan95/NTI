#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


void 	RCC_voidInit 					(void) ;


/* copy_u32BusID Configuration Options : 	1- RCC_AHB
 * 											2- RCC_APB2
 * 											3- RCC_APB1
 */
uint8 	RCC_u8ClockPeripheralEnable 	(uint8 copy_u32BusID , uint8 copy_u8PeripheralID) ;

/* copy_u32BusID Configuration Options : 	1- RCC_AHB
 * 											2- RCC_APB2
 * 											3- RCC_APB1
 */
uint8 	RCC_u8ClockPeripheralDisable 	(uint8 copy_u32BusID , uint8 copy_u8PeripheralID) ;

#endif 
