#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "GIE_CFG.h"
#include "GIE_Prv.h"
#include "GIE_Register.h"
#include "GIE_Interface.h"


void GIE_voidEnable  	(void)
{
	__asm volatile ("SEI"); 						// ASSEMBLY INSTRUCTION
}

void GIE_voidDisable 	(void)
{
	__asm volatile ("CLI");
}
