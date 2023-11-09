
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

void		STK_voidInit						(void);

uint8		STK_voidSetBusyWait					(uint32	copy_u32Ticks);

uint8		STK_voidSetIntervalSingle			(uint32	copy_u32Ticks, void (*copy_pFunction)(void));

uint8		STK_voidSetIntervalPeriodic			(uint32	copy_u32Ticks, void (*copy_pFunction)(void));

void		STK_voidStopInterval				(void);

uint32		STK_u32GetElapsedTime				(void);

uint32		STK_u32GetRemainingTime				(void);

#endif
