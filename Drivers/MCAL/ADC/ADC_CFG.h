#ifndef ADC_CFG_H
#define ADC_CFG_H

	/* SELECT BETWEEN THESE OPTIONS : 1- AREF 2- AVCC 3- RESERVED 4- INTERNAL_256MVOLT */

#define 	ADC_REFERENCE_SELECTION_OPTION		AVCC

	/* SELECT BETWEEN THESE OPTIONS : 1- LEFT_ADJUST 2- RIGHT_ADJUST  */

#define 	ADC_ADJUSTMENT_OPTION				LEFT_ADJUST    	//	IF EIGHT_BIT  ------> LEFT ADJUST
																//  IF TEN_BIT 	  ------> RIGHT ADJUST

									/* CONFIGURE ADC PRESCALER DIVISION FACTOR : 1- DIVISION_BY_2
									 * 											 2- DIVISION_BY_4
									 *											 3- DIVISION_BY_8
									 * 											 4- DIVISION_BY_16
									 * 											 5- DIVISION_BY_32
									 *											 6- DIVISION_BY_64
									 * 											 7- DIVISION_BY_128
									 */
#define 	ADC_u8PRESCALER						DIVISION_BY_128


									/* CONFIGURE ADC RESOLUTION , OPTIONS : 1- EIGHT_BITS
									 * 										2- TEN_BITS
									 * 										*/
#define 	ADC_u8RESOLUTION					EIGHT_BITS

#define 	ADC_u32TIMEOUT_COUNT				5000UL

#endif
