#ifndef PORT_CFG_H
#define PORT_CFG_H
							/* Configure Pin Direction : Options : 1- INPUT 2- OUTPUT */ 
							
	#define 		PORTA_PIN0_DIR  		INPUT
	#define 		PORTA_PIN1_DIR  		INPUT
	#define 		PORTA_PIN2_DIR  		OUTPUT
	#define 		PORTA_PIN3_DIR  		OUTPUT
	#define 		PORTA_PIN4_DIR  		INPUT
	#define 		PORTA_PIN5_DIR  		INPUT
	#define 		PORTA_PIN6_DIR  		INPUT
	#define 		PORTA_PIN7_DIR  		INPUT
	
	#define 		PORTB_PIN0_DIR  		OUTPUT
	#define 		PORTB_PIN1_DIR  		OUTPUT
	#define 		PORTB_PIN2_DIR  		OUTPUT
	#define 		PORTB_PIN3_DIR  		INPUT
	#define 		PORTB_PIN4_DIR  		OUTPUT
	#define 		PORTB_PIN5_DIR  		INPUT
	#define 		PORTB_PIN6_DIR  		INPUT
	#define 		PORTB_PIN7_DIR  		INPUT
	
	#define 		PORTC_PIN0_DIR  		OUTPUT
	#define 		PORTC_PIN1_DIR  		OUTPUT
	#define 		PORTC_PIN2_DIR  		INPUT
	#define 		PORTC_PIN3_DIR  		INPUT
	#define 		PORTC_PIN4_DIR  		INPUT
	#define 		PORTC_PIN5_DIR  		INPUT
	#define 		PORTC_PIN6_DIR  		OUTPUT
	#define 		PORTC_PIN7_DIR  		INPUT
	
	#define 		PORTD_PIN0_DIR  		INPUT
	#define 		PORTD_PIN1_DIR  		INPUT 	
	#define 		PORTD_PIN2_DIR  		INPUT
	#define 		PORTD_PIN3_DIR  		OUTPUT
	#define 		PORTD_PIN4_DIR  		INPUT
	#define 		PORTD_PIN5_DIR  		OUTPUT
	#define 		PORTD_PIN6_DIR  		OUTPUT
	#define 		PORTD_PIN7_DIR  		OUTPUT
						
						/* Configure Pin Initial value : Options : 1- LOW 	   2- HIGH      IF PIN is OUTPUT */
																// 1- FLOATING 2-PULLED UP  IF PIN IS INPUT */
	
	#define 		PORTA_PIN0_INITVAL  	FLOATING
	#define 		PORTA_PIN1_INITVAL  	FLOATING
	#define 		PORTA_PIN2_INITVAL  	FLOATING
	#define 		PORTA_PIN3_INITVAL  	FLOATING
	#define 		PORTA_PIN4_INITVAL  	FLOATING
	#define 		PORTA_PIN5_INITVAL  	FLOATING
	#define 		PORTA_PIN6_INITVAL  	FLOATING
	#define 		PORTA_PIN7_INITVAL  	FLOATING
											
	#define 		PORTB_PIN0_INITVAL  	FLOATING
	#define 		PORTB_PIN1_INITVAL  	FLOATING 	
	#define 		PORTB_PIN2_INITVAL  	FLOATING
	#define 		PORTB_PIN3_INITVAL  	FLOATING
	#define 		PORTB_PIN4_INITVAL  	FLOATING
	#define 		PORTB_PIN5_INITVAL  	FLOATING
	#define 		PORTB_PIN6_INITVAL  	FLOATING
	#define 		PORTB_PIN7_INITVAL  	FLOATING
											
	#define 		PORTC_PIN0_INITVAL  	FLOATING
	#define 		PORTC_PIN1_INITVAL  	FLOATING 	
	#define 		PORTC_PIN2_INITVAL  	PULLEDUP
	#define 		PORTC_PIN3_INITVAL  	PULLEDUP
	#define 		PORTC_PIN4_INITVAL  	PULLEDUP
	#define 		PORTC_PIN5_INITVAL  	PULLEDUP
	#define 		PORTC_PIN6_INITVAL  	FLOATING
	#define 		PORTC_PIN7_INITVAL  	FLOATING
											
	#define 		PORTD_PIN0_INITVAL  	FLOATING
	#define 		PORTD_PIN1_INITVAL  	FLOATING 	
	#define 		PORTD_PIN2_INITVAL  	FLOATING
	#define 		PORTD_PIN3_INITVAL  	HIGH
	#define 		PORTD_PIN4_INITVAL  	FLOATING
	#define 		PORTD_PIN5_INITVAL  	HIGH
	#define 		PORTD_PIN6_INITVAL  	HIGH
	#define 		PORTD_PIN7_INITVAL  	HIGH
	
#endif 
