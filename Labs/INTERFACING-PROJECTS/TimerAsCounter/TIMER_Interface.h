#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
	
											/* Functions Deceleration */
	void TIMER0_voidInit ( void ) ;

	uint8 TIMER0_u8SetCallBack (  void(*copy_pvNotification)(void) ) ;

	uint8 TIMER0_u8CounterFunction ( void ) ;

	uint8 TIMER0_u8ResetTCNTO (void) ;

#endif
