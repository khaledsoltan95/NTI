#ifndef EXTI_CFG_H
#define EXTI_CFG_H

							/* Select Options : 1- ENABLE 2- DISABLE */

#define INT0_STATUS		ENABLE
#define INT1_STATUS		ENABLE
#define INT2_STATUS		ENABLE

							/* Select Options : 1- LOW_LEVEL 2- ON_CHANGE 3- FALLING_EDGE 4- RISING_EDGE */
#define INT0_SENSECONTROL		FALLING_EDGE
#define INT1_SENSECONTROL		FALLING_EDGE

							/* Select Options : 1- FALLING EDGE 2- RISING EDGE */
#define INT2_SENSECONTROL		FALLING_EDGE

#endif
