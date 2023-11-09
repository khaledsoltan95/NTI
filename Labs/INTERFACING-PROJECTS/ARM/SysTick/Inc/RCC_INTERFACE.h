#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

typedef enum
{
	BUS_RCC_AHB ,
	BUS_RCC_APB2 ,
	BUS_RCC_APB1
}RCC_Bus_List_t ;
void 	RCC_voidInit 					(void) ;


/* copy_u32BusID Configuration Options : 	1- RCC_AHB
 * 											2- RCC_APB2
 * 											3- RCC_APB1
 */
uint8 	RCC_u8ClockPeripheralEnable 	(RCC_Bus_List_t copy_u32BusID , uint8 copy_u8PeripheralID) ;

/* copy_u32BusID Configuration Options : 	1- RCC_AHB
 * 											2- RCC_APB2
 * 											3- RCC_APB1
 */
uint8 	RCC_u8ClockPeripheralDisable 	(RCC_Bus_List_t copy_u32BusID , uint8 copy_u8PeripheralID) ;

#endif 
