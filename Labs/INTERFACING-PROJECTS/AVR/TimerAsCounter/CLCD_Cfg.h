#ifndef CLCD_CFG_H
#define CLCD_CFG_H

					/* CLCD CONFIGURATIONS */
/* CLCD connection type configuration macro , select between :  1- FOUR_BIT  2- EIGHT_BIT */
#define		CLCD_U8CONNECTION_MODE			FOUR_BIT
								//
/* CLCD Read Operation Enable Configuration , select between :  1- ENABLED	 2- DISABLED */
#define		CLCD_u8READ_OPERATION_ENABLE 	DISABLED
								//
#define 	CLCD_u8DATA_PORT 				DIO_PORTB


#if			CLCD_U8CONNECTION_MODE == FOUR_BIT
#define 	CLCD_u8D4_PIN 					DIO_PIN1
#define 	CLCD_u8D5_PIN 					DIO_PIN2
#define 	CLCD_u8D6_PIN 					DIO_PIN3
#define 	CLCD_u8D7_PIN 					DIO_PIN4
#endif

#define 	CLCD_u8CTRL_PORT 				DIO_PORTA

#define 	CLCD_u8RS_PIN 					DIO_PIN3

#if 		CLCD_u8READ_OPERATION_ENABLE == ENABLED
#define 	CLCD_u8RW_PIN 					DIO_PIN1
#endif

#define 	CLCD_u8E_PIN 					DIO_PIN2

#endif
