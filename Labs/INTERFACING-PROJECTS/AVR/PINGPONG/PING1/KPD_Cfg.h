#ifndef KPD_CFG_H
#define KPD_CFG_H

					/* KPD CONFIGURATIONS */

		#define		KPD

		#define 	KPD_u8ROW_PORT 				DIO_PORTC

		#define 	KPD_u8RO_PIN				DIO_PIN5
		#define 	KPD_u8R1_PIN				DIO_PIN4
		#define 	KPD_u8R2_PIN				DIO_PIN3
		#define 	KPD_u8R3_PIN				DIO_PIN2

		#define 	KPD_u8COL_PORT 				DIO_PORTD

		#define 	KPD_u8CO_PIN				DIO_PIN7
		#define 	KPD_u8C1_PIN				DIO_PIN6
		#define 	KPD_u8C2_PIN				DIO_PIN5
		#define 	KPD_u8C3_PIN				DIO_PIN3

		#define 	KPD_u8BUTTON_ARR			{ {'7','8','9','/'} , {'4','5','6','*'} , {'1','2','3','-'} , {127,'0','=','+'} }
		#define   	KPD_u8NO_PRESSED_KEY_VAL 	0xff



#endif
