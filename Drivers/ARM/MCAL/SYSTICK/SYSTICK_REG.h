#ifndef SYSTICK_REG_H_
#define SYSTICK_REG_H_

#define 			SYSTICK_BASEADDRESS				0xE000E010

#define 			STK_CTRL						(*(volatile uint32*)(SYSTICK_BASEADDRESS +0x00))
#define				STK_CTRL_COUNTFLAG				16u
#define				STK_CTRL_CLKSOURCE				2u
#define				STK_CTRL_TICKINT				1u
#define				STK_CTRL_ENABLE					0u

#define 			STK_LOAD						(*(volatile uint32*)(SYSTICK_BASEADDRESS +0x04))

#define 			STK_VAL							(*(volatile uint32*)(SYSTICK_BASEADDRESS +0x08))

#define 			STK_CALIB						(*(volatile uint32*)(SYSTICK_BASEADDRESS +0x0C))

#endif
