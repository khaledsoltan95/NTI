#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_


/* CONFIGURATION OPTIONS : 	1- AHB_DIVIDEDBY_8
 * 							2- AHB
 */
#define				SYSTICK_u8CLKSource				AHB_DIVIDEDBY_8

/* CONFIGURATION OPTIONS : 	1- ENABLE					" INTERRUPT ENABLING "
 * 							2- DISABLE
 */
#define				SYSTICK_u8TickIntEnable			ENABLE

/* CONFIGURATION OPTIONS : 	1- ENABLE
 * 							2- DISABLE
 */
#define				SYSTICK_u8SysTickEnable			ENABLE


#endif
