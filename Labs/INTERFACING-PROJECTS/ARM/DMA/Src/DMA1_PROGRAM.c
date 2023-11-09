#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DMA1_CFG.h"
#include "DMA1_INTERFACE.h"
#include "DMA1_PRV.h"
#include "DMA1_REG.h"

static uint8 DMA1_u8GeneralBusyFlag = ALL_FREE ;
static void (*DMA1_pvChannel1NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel2NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel3NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel4NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel5NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel6NotificationFunc)(void) = NULL ;
static void (*DMA1_pvChannel7NotificationFunc)(void) = NULL ;

void 	DMA1_voidChannelPreBuiltInit(void)
{
											/* CHANNEL 7 INITIALIZATION */
	#if 				DMA_u8Channel_7_Select == SELECTED
											/* PerioritySelect */
		#if 				DMA_u8Channel_7_PerioritySelect == VERY_HIGH
		SET_BIT(DMA1_CCR7,DMA1_CCR_PL0) ;
		SET_BIT(DMA1_CCR7,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_7_PerioritySelect == HIGH
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PL0) ;
		SET_BIT(DMA1_CCR7,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_7_PerioritySelect == MIDIUM
		SET_BIT(DMA1_CCR7,DMA1_CCR_PL0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_7_PerioritySelect == LOW
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PL0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PL1) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_PerioritySelect Configuration"
		#endif
											/* PSize SET */
		#if 				DMA_u8Channel_7_PSize == EIGHT_BITS
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PSIZE0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PSIZE1) ;
		#elif 				DMA_u8Channel_7_PSize == SIXTEEN_BITS
		SET_BIT(DMA1_CCR7,DMA1_CCR_PSIZE0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PSIZE1) ;
		#elif 				DMA_u8Channel_7_PSize == THIRTYTWO_BITS
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PSIZE0) ;
		SET_BIT(DMA1_CCR7,DMA1_CCR_PSIZE1) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_PSize Configuration"
		#endif
											/* MSize SET */
		#if 				DMA_u8Channel_7_MSize == EIGHT_BITS
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MSIZE0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MSIZE1) ;
		#elif 				DMA_u8Channel_7_MSize == SIXTEEN_BITS
		SET_BIT(DMA1_CCR7,DMA1_CCR_MSIZE0) ;
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MSIZE1) ;
		#elif 				DMA_u8Channel_7_MSize == THIRTYTWO_BITS
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MSIZE0) ;
		SET_BIT(DMA1_CCR7,DMA1_CCR_MSIZE1) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_MSize Configuration"
		#endif
											/* DIRECTION OF READING SELECTION */
		#if 				DMA_u8Channel_7_DIR_Select == FROM_PERIPHERAL
		CLR_BIT(DMA1_CCR7,DMA1_CCR_DIR) ;
		#elif 				DMA_u8Channel_7_DIR_Select == FROM_MEMORY
		SET_BIT(DMA1_CCR7,DMA1_CCR_DIR) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_DIR_Select Configuration"
		#endif
											/* CIRCULAR ENABLE */
		#if 				DMA_u8Channel_7_CIRC_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_CIRC) ;
		#elif 				DMA_u8Channel_7_CIRC_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_CIRC) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_CIRC_Enable Configuration"
		#endif
											/* MINC ENABLE */
		#if 				DMA_u8Channel_7_MINC_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MINC) ;
		#elif 				DMA_u8Channel_7_MINC_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_MINC) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_MINC_Enable Configuration"
		#endif
											/* PINC ENABLE */
		#if 				DMA_u8Channel_7_PINC_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_PINC) ;
		#elif 				DMA_u8Channel_7_PINC_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_PINC) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_PINC_Enable Configuration"
		#endif
											/* MEMORY TO MEMORY ENABLE */
		#if 				DMA_u8Channel_7_MEM2MEM_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_MEM2MEM) ;
		#elif 				DMA_u8Channel_7_MEM2MEM_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_MEM2MEM) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_MEM2MEM_Enable Configuration"
		#endif
											/* TRANSFER COMPLETE INTERRUPT ENABLE */
		#if 				DMA_u8Channel_7_TCIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_TCIE) ;
		#elif 				DMA_u8Channel_7_TCIE_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_TCIE) ;
		#else
		#error "NOT VALID DMA1_CCR7_TCIE Configuration"
		#endif
										/* HALF TRANSFER INTERRUPT ENABLE */
		#if 				DMA_u8Channel_7_HTIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_HTIE) ;
		#elif 				DMA_u8Channel_7_HTIE_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_HTIE) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_HTIE_Enable Configuration"
		#endif
										/* TRANSFER ERROR INTERRUPT ENABLE */
		#if 				DMA_u8Channel_7_TEIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_TEIE) ;
		#elif 				DMA_u8Channel_7_TEIE_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_TEIE) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_TEIE_Enable Configuration"
		#endif
										/* CHANNEL ENABLE */
		#if 				DMA_u8Channel_7_Enable == DISABLE
		CLR_BIT(DMA1_CCR7,DMA1_CCR_EN) ;
		#elif 				DMA_u8Channel_7_Enable == ENABLE
		SET_BIT(DMA1_CCR7,DMA1_CCR_EN) ;
		#else
		#error "NOT VALID DMA_u8Channel_7_Enable Configuration"
		#endif
	#elif 				DMA_u8Channel_7_Select == NOT_SELECTED
		// DO NOTHING
	#else
		#error "NOT VALID DMA_u8Channel_7_Select Configuration"
	#endif

											/* CHANNEL 6 INITIALIZATION */
	#if 				DMA_u8Channel_6_Select == SELECTED
											/* PerioritySelect */
		#if 				DMA_u8Channel_6_PerioritySelect == VERY_HIGH
		SET_BIT(DMA1_CCR6,DMA1_CCR_PL0) ;
		SET_BIT(DMA1_CCR6,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_6_PerioritySelect == HIGH
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PL0) ;
		SET_BIT(DMA1_CCR6,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_6_PerioritySelect == MIDIUM
		SET_BIT(DMA1_CCR6,DMA1_CCR_PL0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PL1) ;
		#elif 				DMA_u8Channel_6_PerioritySelect == LOW
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PL0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PL1) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_PerioritySelect Configuration"
		#endif
											/* PSize SET */
		#if 				DMA_u8Channel_6_PSize == EIGHT_BITS
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PSIZE0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PSIZE1) ;
		#elif 				DMA_u8Channel_6_PSize == SIXTEEN_BITS
		SET_BIT(DMA1_CCR6,DMA1_CCR_PSIZE0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PSIZE1) ;
		#elif 				DMA_u8Channel_6_PSize == THIRTYTWO_BITS
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PSIZE0) ;
		SET_BIT(DMA1_CCR6,DMA1_CCR_PSIZE1) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_PSize Configuration"
		#endif
											/* MSize SET */
		#if 				DMA_u8Channel_6_MSize == EIGHT_BITS
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MSIZE0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MSIZE1) ;
		#elif 				DMA_u8Channel_6_MSize == SIXTEEN_BITS
		SET_BIT(DMA1_CCR6,DMA1_CCR_MSIZE0) ;
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MSIZE1) ;
		#elif 				DMA_u8Channel_6_MSize == THIRTYTWO_BITS
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MSIZE0) ;
		SET_BIT(DMA1_CCR6,DMA1_CCR_MSIZE1) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_MSize Configuration"
		#endif
											/* DIRECTION OF READING SELECTION */
		#if 				DMA_u8Channel_6_DIR_Select == FROM_PERIPHERAL
		CLR_BIT(DMA1_CCR6,DMA1_CCR_DIR) ;
		#elif 				DMA_u8Channel_6_DIR_Select == FROM_MEMORY
		SET_BIT(DMA1_CCR6,DMA1_CCR_DIR) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_DIR_Select Configuration"
		#endif
											/* CIRCULAR ENABLE */
		#if 				DMA_u8Channel_6_CIRC_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_CIRC) ;
		#elif 				DMA_u8Channel_6_CIRC_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_CIRC) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_CIRC_Enable Configuration"
		#endif
											/* MINC ENABLE */
		#if 				DMA_u8Channel_6_MINC_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MINC) ;
		#elif 				DMA_u8Channel_6_MINC_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_MINC) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_MINC_Enable Configuration"
		#endif
											/* PINC ENABLE */
		#if 				DMA_u8Channel_6_PINC_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_PINC) ;
		#elif 				DMA_u8Channel_6_PINC_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_PINC) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_PINC_Enable Configuration"
		#endif
											/* MEMORY TO MEMORY ENABLE */
		#if 				DMA_u8Channel_6_MEM2MEM_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_MEM2MEM) ;
		#elif 				DMA_u8Channel_6_MEM2MEM_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_MEM2MEM) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_MEM2MEM_Enable Configuration"
		#endif
											/* TRANSFER COMPLETE INTERRUPT ENABLE */
		#if 				DMA_u8Channel_6_TCIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_TCIE) ;
		#elif 				DMA_u8Channel_6_TCIE_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_TCIE) ;
		#else
		#error "NOT VALID DMA1_CCR6_TCIE Configuration"
		#endif
										/* HALF TRANSFER INTERRUPT ENABLE */
		#if 				DMA_u8Channel_6_HTIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_HTIE) ;
		#elif 				DMA_u8Channel_6_HTIE_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_HTIE) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_HTIE_Enable Configuration"
		#endif
										/* TRANSFER ERROR INTERRUPT ENABLE */
		#if 				DMA_u8Channel_6_TEIE_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_TEIE) ;
		#elif 				DMA_u8Channel_6_TEIE_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_TEIE) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_TEIE_Enable Configuration"
		#endif
										/* CHANNEL ENABLE */
		#if 				DMA_u8Channel_6_Enable == DISABLE
		CLR_BIT(DMA1_CCR6,DMA1_CCR_EN) ;
		#elif 				DMA_u8Channel_7_Enable == ENABLE
		SET_BIT(DMA1_CCR6,DMA1_CCR_EN) ;
		#else
		#error "NOT VALID DMA_u8Channel_6_Enable Configuration"
		#endif
	#elif 				DMA_u8Channel_6_Select == NOT_SELECTED
		// DO NOTHING
	#else
		#error "NOT VALID DMA_u8Channel_6_Select Configuration"
	#endif
												/* CHANNEL 5 INITIALIZATION */
		#if 				DMA_u8Channel_5_Select == SELECTED
												/* PerioritySelect */
			#if 				DMA_u8Channel_5_PerioritySelect == VERY_HIGH
			SET_BIT(DMA1_CCR5,DMA1_CCR_PL0) ;
			SET_BIT(DMA1_CCR5,DMA1_CCR_PL1) ;
			#elif 				DMA_u8Channel_5_PerioritySelect == HIGH
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PL0) ;
			SET_BIT(DMA1_CCR5,DMA1_CCR_PL1) ;
			#elif 				DMA_u8Channel_5_PerioritySelect == MIDIUM
			SET_BIT(DMA1_CCR5,DMA1_CCR_PL0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PL1) ;
			#elif 				DMA_u8Channel_5_PerioritySelect == LOW
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PL0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PL1) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_PerioritySelect Configuration"
			#endif
												/* PSize SET */
			#if 				DMA_u8Channel_5_PSize == EIGHT_BITS
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PSIZE0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PSIZE1) ;
			#elif 				DMA_u8Channel_5_PSize == SIXTEEN_BITS
			SET_BIT(DMA1_CCR5,DMA1_CCR_PSIZE0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PSIZE1) ;
			#elif 				DMA_u8Channel_5_PSize == THIRTYTWO_BITS
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PSIZE0) ;
			SET_BIT(DMA1_CCR5,DMA1_CCR_PSIZE1) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_PSize Configuration"
			#endif
												/* MSize SET */
			#if 				DMA_u8Channel_5_MSize == EIGHT_BITS
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MSIZE0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MSIZE1) ;
			#elif 				DMA_u8Channel_5_MSize == SIXTEEN_BITS
			SET_BIT(DMA1_CCR5,DMA1_CCR_MSIZE0) ;
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MSIZE1) ;
			#elif 				DMA_u8Channel_5_MSize == THIRTYTWO_BITS
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MSIZE0) ;
			SET_BIT(DMA1_CCR5,DMA1_CCR_MSIZE1) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_MSize Configuration"
			#endif
												/* DIRECTION OF READING SELECTION */
			#if 				DMA_u8Channel_5_DIR_Select == FROM_PERIPHERAL
			CLR_BIT(DMA1_CCR5,DMA1_CCR_DIR) ;
			#elif 				DMA_u8Channel_5_DIR_Select == FROM_MEMORY
			SET_BIT(DMA1_CCR5,DMA1_CCR_DIR) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_DIR_Select Configuration"
			#endif
												/* CIRCULAR ENABLE */
			#if 				DMA_u8Channel_5_CIRC_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_CIRC) ;
			#elif 				DMA_u8Channel_5_CIRC_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_CIRC) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_CIRC_Enable Configuration"
			#endif
												/* MINC ENABLE */
			#if 				DMA_u8Channel_5_MINC_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MINC) ;
			#elif 				DMA_u8Channel_5_MINC_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_MINC) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_MINC_Enable Configuration"
			#endif
												/* PINC ENABLE */
			#if 				DMA_u8Channel_5_PINC_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_PINC) ;
			#elif 				DMA_u8Channel_5_PINC_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_PINC) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_PINC_Enable Configuration"
			#endif
												/* MEMORY TO MEMORY ENABLE */
			#if 				DMA_u8Channel_5_MEM2MEM_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_MEM2MEM) ;
			#elif 				DMA_u8Channel_5_MEM2MEM_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_MEM2MEM) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_MEM2MEM_Enable Configuration"
			#endif
												/* TRANSFER COMPLETE INTERRUPT ENABLE */
			#if 				DMA_u8Channel_5_TCIE_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_TCIE) ;
			#elif 				DMA_u8Channel_5_TCIE_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_TCIE) ;
			#else
			#error "NOT VALID DMA1_CCR5_TCIE Configuration"
			#endif
											/* HALF TRANSFER INTERRUPT ENABLE */
			#if 				DMA_u8Channel_5_HTIE_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_HTIE) ;
			#elif 				DMA_u8Channel_5_HTIE_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_HTIE) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_HTIE_Enable Configuration"
			#endif
											/* TRANSFER ERROR INTERRUPT ENABLE */
			#if 				DMA_u8Channel_5_TEIE_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_TEIE) ;
			#elif 				DMA_u8Channel_5_TEIE_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_TEIE) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_TEIE_Enable Configuration"
			#endif
											/* CHANNEL ENABLE */
			#if 				DMA_u8Channel_5_Enable == DISABLE
			CLR_BIT(DMA1_CCR5,DMA1_CCR_EN) ;
			#elif 				DMA_u8Channel_5_Enable == ENABLE
			SET_BIT(DMA1_CCR5,DMA1_CCR_EN) ;
			#else
			#error "NOT VALID DMA_u8Channel_5_Enable Configuration"
			#endif
		#elif 				DMA_u8Channel_5_Select == NOT_SELECTED
			// DO NOTHING
		#else
			#error "NOT VALID DMA_u8Channel_5_Select Configuration"
		#endif
													/* CHANNEL 4 INITIALIZATION */
			#if 				DMA_u8Channel_4_Select == SELECTED
													/* PerioritySelect */
				#if 				DMA_u8Channel_4_PerioritySelect == VERY_HIGH
				SET_BIT(DMA1_CCR4,DMA1_CCR_PL0) ;
				SET_BIT(DMA1_CCR4,DMA1_CCR_PL1) ;
				#elif 				DMA_u8Channel_4_PerioritySelect == HIGH
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PL0) ;
				SET_BIT(DMA1_CCR4,DMA1_CCR_PL1) ;
				#elif 				DMA_u8Channel_4_PerioritySelect == MIDIUM
				SET_BIT(DMA1_CCR4,DMA1_CCR_PL0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PL1) ;
				#elif 				DMA_u8Channel_4_PerioritySelect == LOW
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PL0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PL1) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_PerioritySelect Configuration"
				#endif
													/* PSize SET */
				#if 				DMA_u8Channel_4_PSize == EIGHT_BITS
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PSIZE0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PSIZE1) ;
				#elif 				DMA_u8Channel_4_PSize == SIXTEEN_BITS
				SET_BIT(DMA1_CCR4,DMA1_CCR_PSIZE0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PSIZE1) ;
				#elif 				DMA_u8Channel_4_PSize == THIRTYTWO_BITS
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PSIZE0) ;
				SET_BIT(DMA1_CCR4,DMA1_CCR_PSIZE1) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_PSize Configuration"
				#endif
													/* MSize SET */
				#if 				DMA_u8Channel_4_MSize == EIGHT_BITS
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MSIZE0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MSIZE1) ;
				#elif 				DMA_u8Channel_4_MSize == SIXTEEN_BITS
				SET_BIT(DMA1_CCR4,DMA1_CCR_MSIZE0) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MSIZE1) ;
				#elif 				DMA_u8Channel_4_MSize == THIRTYTWO_BITS
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MSIZE0) ;
				SET_BIT(DMA1_CCR4,DMA1_CCR_MSIZE1) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_MSize Configuration"
				#endif
													/* DIRECTION OF READING SELECTION */
				#if 				DMA_u8Channel_4_DIR_Select == FROM_PERIPHERAL
				CLR_BIT(DMA1_CCR4,DMA1_CCR_DIR) ;
				#elif 				DMA_u8Channel_4_DIR_Select == FROM_MEMORY
				SET_BIT(DMA1_CCR4,DMA1_CCR_DIR) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_DIR_Select Configuration"
				#endif
													/* CIRCULAR ENABLE */
				#if 				DMA_u8Channel_4_CIRC_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_CIRC) ;
				#elif 				DMA_u8Channel_4_CIRC_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_CIRC) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_CIRC_Enable Configuration"
				#endif
													/* MINC ENABLE */
				#if 				DMA_u8Channel_4_MINC_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MINC) ;
				#elif 				DMA_u8Channel_4_MINC_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_MINC) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_MINC_Enable Configuration"
				#endif
													/* PINC ENABLE */
				#if 				DMA_u8Channel_4_PINC_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_PINC) ;
				#elif 				DMA_u8Channel_4_PINC_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_PINC) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_PINC_Enable Configuration"
				#endif
													/* MEMORY TO MEMORY ENABLE */
				#if 				DMA_u8Channel_4_MEM2MEM_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_MEM2MEM) ;
				#elif 				DMA_u8Channel_4_MEM2MEM_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_MEM2MEM) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_MEM2MEM_Enable Configuration"
				#endif
													/* TRANSFER COMPLETE INTERRUPT ENABLE */
				#if 				DMA_u8Channel_4_TCIE_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_TCIE) ;
				#elif 				DMA_u8Channel_4_TCIE_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_TCIE) ;
				#else
				#error "NOT VALID DMA1_CCR4_TCIE Configuration"
				#endif
												/* HALF TRANSFER INTERRUPT ENABLE */
				#if 				DMA_u8Channel_4_HTIE_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_HTIE) ;
				#elif 				DMA_u8Channel_4_HTIE_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_HTIE) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_HTIE_Enable Configuration"
				#endif
												/* TRANSFER ERROR INTERRUPT ENABLE */
				#if 				DMA_u8Channel_4_TEIE_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_TEIE) ;
				#elif 				DMA_u8Channel_4_TEIE_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_TEIE) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_TEIE_Enable Configuration"
				#endif
												/* CHANNEL ENABLE */
				#if 				DMA_u8Channel_4_Enable == DISABLE
				CLR_BIT(DMA1_CCR4,DMA1_CCR_EN) ;
				#elif 				DMA_u8Channel_4_Enable == ENABLE
				SET_BIT(DMA1_CCR4,DMA1_CCR_EN) ;
				#else
				#error "NOT VALID DMA_u8Channel_4_Enable Configuration"
				#endif
			#elif 				DMA_u8Channel_4_Select == NOT_SELECTED
				// DO NOTHING
			#else
				#error "NOT VALID DMA_u8Channel_4_Select Configuration"
			#endif
														/* CHANNEL 3 INITIALIZATION */
				#if 				DMA_u8Channel_3_Select == SELECTED
														/* PerioritySelect */
					#if 				DMA_u8Channel_3_PerioritySelect == VERY_HIGH
					SET_BIT(DMA1_CCR3,DMA1_CCR_PL0) ;
					SET_BIT(DMA1_CCR3,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_3_PerioritySelect == HIGH
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PL0) ;
					SET_BIT(DMA1_CCR3,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_3_PerioritySelect == MIDIUM
					SET_BIT(DMA1_CCR3,DMA1_CCR_PL0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_3_PerioritySelect == LOW
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PL0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PL1) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_PerioritySelect Configuration"
					#endif
														/* PSize SET */
					#if 				DMA_u8Channel_3_PSize == EIGHT_BITS
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PSIZE0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PSIZE1) ;
					#elif 				DMA_u8Channel_3_PSize == SIXTEEN_BITS
					SET_BIT(DMA1_CCR3,DMA1_CCR_PSIZE0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PSIZE1) ;
					#elif 				DMA_u8Channel_3_PSize == THIRTYTWO_BITS
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PSIZE0) ;
					SET_BIT(DMA1_CCR3,DMA1_CCR_PSIZE1) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_PSize Configuration"
					#endif
														/* MSize SET */
					#if 				DMA_u8Channel_3_MSize == EIGHT_BITS
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MSIZE0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MSIZE1) ;
					#elif 				DMA_u8Channel_3_MSize == SIXTEEN_BITS
					SET_BIT(DMA1_CCR3,DMA1_CCR_MSIZE0) ;
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MSIZE1) ;
					#elif 				DMA_u8Channel_3_MSize == THIRTYTWO_BITS
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MSIZE0) ;
					SET_BIT(DMA1_CCR3,DMA1_CCR_MSIZE1) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_MSize Configuration"
					#endif
														/* DIRECTION OF READING SELECTION */
					#if 				DMA_u8Channel_3_DIR_Select == FROM_PERIPHERAL
					CLR_BIT(DMA1_CCR3,DMA1_CCR_DIR) ;
					#elif 				DMA_u8Channel_3_DIR_Select == FROM_MEMORY
					SET_BIT(DMA1_CCR3,DMA1_CCR_DIR) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_DIR_Select Configuration"
					#endif
														/* CIRCULAR ENABLE */
					#if 				DMA_u8Channel_3_CIRC_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_CIRC) ;
					#elif 				DMA_u8Channel_3_CIRC_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_CIRC) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_CIRC_Enable Configuration"
					#endif
														/* MINC ENABLE */
					#if 				DMA_u8Channel_3_MINC_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MINC) ;
					#elif 				DMA_u8Channel_3_MINC_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_MINC) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_MINC_Enable Configuration"
					#endif
														/* PINC ENABLE */
					#if 				DMA_u8Channel_3_PINC_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_PINC) ;
					#elif 				DMA_u8Channel_3_PINC_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_PINC) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_PINC_Enable Configuration"
					#endif
														/* MEMORY TO MEMORY ENABLE */
					#if 				DMA_u8Channel_3_MEM2MEM_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_MEM2MEM) ;
					#elif 				DMA_u8Channel_3_MEM2MEM_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_MEM2MEM) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_MEM2MEM_Enable Configuration"
					#endif
														/* TRANSFER COMPLETE INTERRUPT ENABLE */
					#if 				DMA_u8Channel_3_TCIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_TCIE) ;
					#elif 				DMA_u8Channel_3_TCIE_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_TCIE) ;
					#else
					#error "NOT VALID DMA1_CCR3_TCIE Configuration"
					#endif
													/* HALF TRANSFER INTERRUPT ENABLE */
					#if 				DMA_u8Channel_3_HTIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_HTIE) ;
					#elif 				DMA_u8Channel_3_HTIE_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_HTIE) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_HTIE_Enable Configuration"
					#endif
													/* TRANSFER ERROR INTERRUPT ENABLE */
					#if 				DMA_u8Channel_3_TEIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_TEIE) ;
					#elif 				DMA_u8Channel_3_TEIE_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_TEIE) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_TEIE_Enable Configuration"
					#endif
													/* CHANNEL ENABLE */
					#if 				DMA_u8Channel_3_Enable == DISABLE
					CLR_BIT(DMA1_CCR3,DMA1_CCR_EN) ;
					#elif 				DMA_u8Channel_3_Enable == ENABLE
					SET_BIT(DMA1_CCR3,DMA1_CCR_EN) ;
					#else
					#error "NOT VALID DMA_u8Channel_3_Enable Configuration"
					#endif
				#elif 				DMA_u8Channel_3_Select == NOT_SELECTED
					// DO NOTHING
				#else
					#error "NOT VALID DMA_u8Channel_3_Select Configuration"
				#endif
															/* CHANNEL 2 INITIALIZATION */
					#if 				DMA_u8Channel_2_Select == SELECTED
															/* PerioritySelect */
						#if 				DMA_u8Channel_2_PerioritySelect == VERY_HIGH
						SET_BIT(DMA1_CCR2,DMA1_CCR_PL0) ;
						SET_BIT(DMA1_CCR2,DMA1_CCR_PL1) ;
						#elif 				DMA_u8Channel_2_PerioritySelect == HIGH
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PL0) ;
						SET_BIT(DMA1_CCR2,DMA1_CCR_PL1) ;
						#elif 				DMA_u8Channel_2_PerioritySelect == MIDIUM
						SET_BIT(DMA1_CCR2,DMA1_CCR_PL0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PL1) ;
						#elif 				DMA_u8Channel_2_PerioritySelect == LOW
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PL0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PL1) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_PerioritySelect Configuration"
						#endif
															/* PSize SET */
						#if 				DMA_u8Channel_2_PSize == EIGHT_BITS
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PSIZE0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PSIZE1) ;
						#elif 				DMA_u8Channel_2_PSize == SIXTEEN_BITS
						SET_BIT(DMA1_CCR2,DMA1_CCR_PSIZE0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PSIZE1) ;
						#elif 				DMA_u8Channel_2_PSize == THIRTYTWO_BITS
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PSIZE0) ;
						SET_BIT(DMA1_CCR2,DMA1_CCR_PSIZE1) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_PSize Configuration"
						#endif
															/* MSize SET */
						#if 				DMA_u8Channel_2_MSize == EIGHT_BITS
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MSIZE0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MSIZE1) ;
						#elif 				DMA_u8Channel_2_MSize == SIXTEEN_BITS
						SET_BIT(DMA1_CCR2,DMA1_CCR_MSIZE0) ;
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MSIZE1) ;
						#elif 				DMA_u8Channel_2_MSize == THIRTYTWO_BITS
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MSIZE0) ;
						SET_BIT(DMA1_CCR2,DMA1_CCR_MSIZE1) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_MSize Configuration"
						#endif
															/* DIRECTION OF READING SELECTION */
						#if 				DMA_u8Channel_2_DIR_Select == FROM_PERIPHERAL
						CLR_BIT(DMA1_CCR2,DMA1_CCR_DIR) ;
						#elif 				DMA_u8Channel_2_DIR_Select == FROM_MEMORY
						SET_BIT(DMA1_CCR2,DMA1_CCR_DIR) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_DIR_Select Configuration"
						#endif
															/* CIRCULAR ENABLE */
						#if 				DMA_u8Channel_2_CIRC_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_CIRC) ;
						#elif 				DMA_u8Channel_2_CIRC_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_CIRC) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_CIRC_Enable Configuration"
						#endif
															/* MINC ENABLE */
						#if 				DMA_u8Channel_2_MINC_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MINC) ;
						#elif 				DMA_u8Channel_2_MINC_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_MINC) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_MINC_Enable Configuration"
						#endif
															/* PINC ENABLE */
						#if 				DMA_u8Channel_2_PINC_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_PINC) ;
						#elif 				DMA_u8Channel_2_PINC_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_PINC) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_PINC_Enable Configuration"
						#endif
															/* MEMORY TO MEMORY ENABLE */
						#if 				DMA_u8Channel_2_MEM2MEM_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_MEM2MEM) ;
						#elif 				DMA_u8Channel_2_MEM2MEM_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_MEM2MEM) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_MEM2MEM_Enable Configuration"
						#endif
															/* TRANSFER COMPLETE INTERRUPT ENABLE */
						#if 				DMA_u8Channel_2_TCIE_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_TCIE) ;
						#elif 				DMA_u8Channel_2_TCIE_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_TCIE) ;
						#else
						#error "NOT VALID DMA1_CCR2_TCIE Configuration"
						#endif
														/* HALF TRANSFER INTERRUPT ENABLE */
						#if 				DMA_u8Channel_2_HTIE_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_HTIE) ;
						#elif 				DMA_u8Channel_2_HTIE_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_HTIE) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_HTIE_Enable Configuration"
						#endif
														/* TRANSFER ERROR INTERRUPT ENABLE */
						#if 				DMA_u8Channel_2_TEIE_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_TEIE) ;
						#elif 				DMA_u8Channel_2_TEIE_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_TEIE) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_TEIE_Enable Configuration"
						#endif
														/* CHANNEL ENABLE */
						#if 				DMA_u8Channel_2_Enable == DISABLE
						CLR_BIT(DMA1_CCR2,DMA1_CCR_EN) ;
						#elif 				DMA_u8Channel_2_Enable == ENABLE
						SET_BIT(DMA1_CCR2,DMA1_CCR_EN) ;
						#else
						#error "NOT VALID DMA_u8Channel_2_Enable Configuration"
						#endif
					#elif 				DMA_u8Channel_2_Select == NOT_SELECTED
						// DO NOTHING
					#else
						#error "NOT VALID DMA_u8Channel_2_Select Configuration"
					#endif
														/* CHANNEL 1 INITIALIZATION */
				#if 				DMA_u8Channel_1_Select == SELECTED
														/* PerioritySelect */
					#if 				DMA_u8Channel_1_PerioritySelect == VERY_HIGH
					SET_BIT(DMA1_CCR1,DMA1_CCR_PL0) ;
					SET_BIT(DMA1_CCR1,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_1_PerioritySelect == HIGH
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PL0) ;
					SET_BIT(DMA1_CCR1,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_1_PerioritySelect == MIDIUM
					SET_BIT(DMA1_CCR1,DMA1_CCR_PL0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PL1) ;
					#elif 				DMA_u8Channel_1_PerioritySelect == LOW
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PL0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PL1) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_PerioritySelect Configuration"
					#endif
														/* PSize SET */
					#if 				DMA_u8Channel_1_PSize == EIGHT_BITS
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PSIZE0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PSIZE1) ;
					#elif 				DMA_u8Channel_1_PSize == SIXTEEN_BITS
					SET_BIT(DMA1_CCR1,DMA1_CCR_PSIZE0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PSIZE1) ;
					#elif 				DMA_u8Channel_1_PSize == THIRTYTWO_BITS
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PSIZE0) ;
					SET_BIT(DMA1_CCR1,DMA1_CCR_PSIZE1) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_PSize Configuration"
					#endif
														/* MSize SET */
					#if 				DMA_u8Channel_1_MSize == EIGHT_BITS
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MSIZE0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MSIZE1) ;
					#elif 				DMA_u8Channel_1_MSize == SIXTEEN_BITS
					SET_BIT(DMA1_CCR1,DMA1_CCR_MSIZE0) ;
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MSIZE1) ;
					#elif 				DMA_u8Channel_1_MSize == THIRTYTWO_BITS
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MSIZE0) ;
					SET_BIT(DMA1_CCR1,DMA1_CCR_MSIZE1) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_MSize Configuration"
					#endif
														/* DIRECTION OF READING SELECTION */
					#if 				DMA_u8Channel_1_DIR_Select == FROM_PERIPHERAL
					CLR_BIT(DMA1_CCR1,DMA1_CCR_DIR) ;
					#elif 				DMA_u8Channel_1_DIR_Select == FROM_MEMORY
					SET_BIT(DMA1_CCR1,DMA1_CCR_DIR) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_DIR_Select Configuration"
					#endif
														/* CIRCULAR ENABLE */
					#if 				DMA_u8Channel_1_CIRC_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_CIRC) ;
					#elif 				DMA_u8Channel_1_CIRC_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_CIRC) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_CIRC_Enable Configuration"
					#endif
														/* MINC ENABLE */
					#if 				DMA_u8Channel_1_MINC_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MINC) ;
					#elif 				DMA_u8Channel_1_MINC_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_MINC) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_MINC_Enable Configuration"
					#endif
														/* PINC ENABLE */
					#if 				DMA_u8Channel_1_PINC_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_PINC) ;
					#elif 				DMA_u8Channel_1_PINC_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_PINC) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_PINC_Enable Configuration"
					#endif
														/* MEMORY TO MEMORY ENABLE */
					#if 				DMA_u8Channel_1_MEM2MEM_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_MEM2MEM) ;
					#elif 				DMA_u8Channel_1_MEM2MEM_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_MEM2MEM) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_MEM2MEM_Enable Configuration"
					#endif
														/* TRANSFER COMPLETE INTERRUPT ENABLE */
					#if 				DMA_u8Channel_1_TCIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_TCIE) ;
					#elif 				DMA_u8Channel_1_TCIE_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_TCIE) ;
					#else
					#error "NOT VALID DMA1_CCR1_TCIE Configuration"
					#endif
													/* HALF TRANSFER INTERRUPT ENABLE */
					#if 				DMA_u8Channel_1_HTIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_HTIE) ;
					#elif 				DMA_u8Channel_1_HTIE_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_HTIE) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_HTIE_Enable Configuration"
					#endif
													/* TRANSFER ERROR INTERRUPT ENABLE */
					#if 				DMA_u8Channel_1_TEIE_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_TEIE) ;
					#elif 				DMA_u8Channel_1_TEIE_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_TEIE) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_TEIE_Enable Configuration"
					#endif
													/* CHANNEL ENABLE */
					#if 				DMA_u8Channel_1_Enable == DISABLE
					CLR_BIT(DMA1_CCR1,DMA1_CCR_EN) ;
					#elif 				DMA_u8Channel_1_Enable == ENABLE
					SET_BIT(DMA1_CCR1,DMA1_CCR_EN) ;
					#else
					#error "NOT VALID DMA_u8Channel_1_Enable Configuration"
					#endif
				#elif 				DMA_u8Channel_1_Select == NOT_SELECTED
					// DO NOTHING
				#else
					#error "NOT VALID DMA_u8Channel_1_Select Configuration"
				#endif

}

uint8	DMA1_voidChannelRunTimeInit		(Channel_t copy_ChannelNum , ChannelConfig_t* copy_ChannelConfig)
{
	uint8 Local_u8ErrorState = OK ;

	if (copy_ChannelConfig != NULL)
	{
	    union
	    {
	        ChannelConfig_t Local_TempStruct;
	        uint16 			Local_u32TempRegister ;
	    }Union_t;
	    Union_t.Local_TempStruct = *copy_ChannelConfig;
												/*1- SET CHANNEL CONFIGURATION */
		switch (copy_ChannelNum)
		{
		case Channel1 :	DMA1_CCR1 = DMA1_CCRMASK ;	DMA1_CCR1 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel2 : DMA1_CCR2 = DMA1_CCRMASK ;	DMA1_CCR2 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel3 : DMA1_CCR3 = DMA1_CCRMASK ;	DMA1_CCR3 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel4 : DMA1_CCR4 = DMA1_CCRMASK ;	DMA1_CCR4 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel5 : DMA1_CCR5 = DMA1_CCRMASK ;	DMA1_CCR5 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel6 : DMA1_CCR6 = DMA1_CCRMASK ;	DMA1_CCR6 |= (uint16)Union_t.Local_u32TempRegister ; break;
		case Channel7 : DMA1_CCR7 = DMA1_CCRMASK ;	DMA1_CCR7 |= (uint16)Union_t.Local_u32TempRegister ; break;
		default : Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR ;
	}
	return Local_u8ErrorState ;
}

uint8	DMA1_voidChannelStart			(uint32* copy_u32pSourceAddress ,uint32* copy_u32pDestinationAddress ,Channel_t copy_ChannelNum , uint16 copy_u16DataLength)
{
	uint8 Local_u8ErrorState = OK ;
	if ((copy_u32pSourceAddress != NULL) && (copy_u32pDestinationAddress != NULL))
	{
		/*	STEPS : 1- CHECK CHANNEL_FLAG IS NOT BUSY
		 * 			1- SET CHANNEL_FLAG BUSY
		 * 			2- DISABLE CHANNEL
		 * 			3- SET SOURCE ADDRESS INTO CHANNEL PERIPHERAL ADDRESS REGISTER
		 * 			4- SET DISTNATION ADDRESS INTO CHANNEL MEMORY ADDRESS REGISTER
		 * 			5- SET DATA INTO CHANNEL NUMBER OF DATA REGISTER
		 * 			6- ENABLE CHANNEL
		 */
		switch (copy_ChannelNum)
		{
		case Channel1 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL1_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL1_FLAG) ;
				CLR_BIT(DMA1_CCR1,DMA1_CCR_EN) ;
				DMA1_CPAR1 = *copy_u32pDestinationAddress ;
				DMA1_CMAR1 = *copy_u32pDestinationAddress ;
				DMA1_CNDTR1 = copy_u16DataLength ;
				SET_BIT(DMA1_CCR1,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel2 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL2_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL2_FLAG) ;
				CLR_BIT(DMA1_CCR2,DMA1_CCR_EN) ;
				DMA1_CPAR2 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR2 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR2 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR2,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel3 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL3_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL3_FLAG) ;
				CLR_BIT(DMA1_CCR3,DMA1_CCR_EN) ;
				DMA1_CPAR3 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR3 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR3 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR3,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel4 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL4_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL4_FLAG) ;
				CLR_BIT(DMA1_CCR4,DMA1_CCR_EN) ;
				DMA1_CPAR4 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR4 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR4 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR4,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel5 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL5_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL5_FLAG) ;
				CLR_BIT(DMA1_CCR5,DMA1_CCR_EN) ;
				DMA1_CPAR5 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR5 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR5 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR5,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel6 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL6_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL6_FLAG) ;
				CLR_BIT(DMA1_CCR6,DMA1_CCR_EN) ;
				DMA1_CPAR6 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR6 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR6 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR6,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		case Channel7 :
			if (GET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL7_FLAG) != 1u )
			{
				SET_BIT(DMA1_u8GeneralBusyFlag,CHANNEL7_FLAG) ;
				CLR_BIT(DMA1_CCR7,DMA1_CCR_EN) ;
				DMA1_CPAR7 	= *copy_u32pDestinationAddress ;
				DMA1_CMAR7 	= *copy_u32pDestinationAddress ;
				DMA1_CNDTR7 =  copy_u16DataLength ;
				SET_BIT(DMA1_CCR7,DMA1_CCR_EN) ;
			}
			else
			{
				Local_u8ErrorState = BUSY_ERR ;
			}
			break ;
		default : Local_u8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR ;
	}
	return Local_u8ErrorState ;
}

									/*	CHANNEL 1 ISR */
void  DMA1_Channel1__IRQHandler(void);
void  DMA1_Channel1__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF1) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL1_FLAG) ; 				// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 1 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF1) ;

	if (DMA1_pvChannel1NotificationFunc != NULL)
	{
		DMA1_pvChannel1NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 2 ISR */
void  DMA1_Channel2__IRQHandler(void);
void  DMA1_Channel2__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF2) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL2_FLAG) ; 				// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 2 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF2) ;

	if (DMA1_pvChannel2NotificationFunc != NULL)
	{
		DMA1_pvChannel2NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 3 ISR */
void  DMA1_Channel3__IRQHandler(void);
void  DMA1_Channel3__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF3) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL3_FLAG) ; 				// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 3 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF3) ;
	if (DMA1_pvChannel3NotificationFunc != NULL)
	{
		DMA1_pvChannel3NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 4 ISR */
void  DMA1_Channel4__IRQHandler(void);
void  DMA1_Channel4__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF4) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL4_FLAG) ;				// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 4 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF4) ;
	if (DMA1_pvChannel4NotificationFunc != NULL)
	{
		DMA1_pvChannel4NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 5 ISR */
void  DMA1_Channel5__IRQHandler(void);
void  DMA1_Channel5__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF5) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL5_FLAG) ;					// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 5 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF5) ;

	if (DMA1_pvChannel5NotificationFunc != NULL)
	{
		DMA1_pvChannel5NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 6 ISR */
void  DMA1_Channel6__IRQHandler(void);
void  DMA1_Channel6__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF6) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL6_FLAG) ;					// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 6 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF6) ;
	if (DMA1_pvChannel6NotificationFunc != NULL)
	{
		DMA1_pvChannel6NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}

									/*	CHANNEL 7 ISR */
void  DMA1_Channel7__IRQHandler(void);
void  DMA1_Channel7__IRQHandler(void)
{
	if (GET_BIT(DMA1_ISR,DMA1_ISR_TCIF7) == 1u)
	{
		CLR_BIT(DMA1_u8GeneralBusyFlag,CHANNEL7_FLAG) ;						// MAKE CHANNEL BUSY_FLAG FREE
	}
	else
	{
		// DO NOTHING
	}
									/* CLEAR CHANNEL 7 GENERAL INTERRUPT FLAG */
	SET_BIT(DMA1_IFCR , DMA1_IFCR_CGIF7) ;

	if (DMA1_pvChannel7NotificationFunc != NULL)
	{
		DMA1_pvChannel7NotificationFunc() ;
	}
	else
	{
		// DO NOTHING
	}
}
