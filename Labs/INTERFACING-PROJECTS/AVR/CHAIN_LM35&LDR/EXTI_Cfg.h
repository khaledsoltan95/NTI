#ifndef EXTI_CFG_H
#define EXTI_CFG_H

	/* CONFIGURE INT0 TRIGGER SOURCE , OPTIONS : 1- LOW_LEVEL
	 * 											 2- ON_CHANGE
	 * 											 3- FALLING_EDGE
	 * 											 4- RISING_EDGE
	 */
	#define 		EXTI_u8INT0_TRIG_SRC 		FALLING_EDGE

	/* CONFIGURE INT1 TRIGGER SOURCE , OPTIONS : 1- LOW_LEVEL
	 * 											 2- ON_CHANGE
	 * 											 3- FALLING_EDGE
	 * 											 4- RISING_EDGE
	 */
	#define 		EXTI_u8INT1_TRIG_SRC 		FALLING_EDGE

	/* CONFIGURE INT2 TRIGGER SOURCE , OPTIONS : 1- FALLING_EDGE
	 * 											 2- RISING_EDGE
	 */
	#define 		EXTI_u8INT2_TRIG_SRC 		FALLING_EDGE
	
	/* CONFIGURE INT0 INITIAL STATE  , OPTIONS : 1- ENABLED
	 * 											 2- DISABLED
	 */
	#define 		EXTI_u8INT0_INIT_STATE 		ENABLED

	/* CONFIGURE INT1 INITIAL STATE  , OPTIONS : 1- ENABLED
	 * 											 2- DISABLED
	*/
	#define 		EXTI_u8INT1_INIT_STATE 		DISABLED

	/* CONFIGURE INT2 INITIAL STATE  , OPTIONS : 1- ENABLED
	 * 											 2- DISABLED
	*/
	#define 		EXTI_u8INT2_INIT_STATE 		DISABLED

#endif 