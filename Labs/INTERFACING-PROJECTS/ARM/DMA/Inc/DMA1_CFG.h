#ifndef DMA1_CFG_H__
#define	DMA1_CFG_H_H_
										/* CONFIGURATION OPTIONS : 1- SELECTED			2- NOT_SELECTED						*/
#define				DMA_u8Channel_7_Select							NOT_SELECTED
#define				DMA_u8Channel_6_Select							NOT_SELECTED
#define				DMA_u8Channel_5_Select							NOT_SELECTED
#define				DMA_u8Channel_4_Select							NOT_SELECTED
#define				DMA_u8Channel_3_Select							NOT_SELECTED
#define				DMA_u8Channel_2_Select							NOT_SELECTED
#define				DMA_u8Channel_1_Select							NOT_SELECTED

#if 				DMA_u8Channel_7_Select == SELECTED
															/* CHANNEL 7 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_7_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_7_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_7_MSize						EIGHT_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_7_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_7_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_7_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_7_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_7_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_7_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_7_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_7_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_7_Enable						ENABLE
#endif

#if 				DMA_u8Channel_6_Select == SELECTED
															/* CHANNEL 6 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_6_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_6_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_6_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_6_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_6_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_6_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_6_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_6_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_6_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_6_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_6_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_6_Enable						DISABLE
#endif

#if 				DMA_u8Channel_5_Select == SELECTED
															/* CHANNEL 5 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_5_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_5_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_5_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_5_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_5_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_5_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_5_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_5_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_5_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_5_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_5_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_5_Enable						ENABLE
#endif

#if 				DMA_u8Channel_4_Select == SELECTED
															/* CHANNEL 4 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_4_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_4_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_4_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_4_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_4_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_4_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_4_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_4_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_4_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_4_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_4_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_4_Enable						DISABLE
#endif

#if 				DMA_u8Channel_3_Select == SELECTED
															/* CHANNEL 3 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_3_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_3_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_3_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_3_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_3_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_3_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_3_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_3_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_3_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_3_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_3_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_3_Enable						ENABLE
#endif

#if 				DMA_u8Channel_2_Select == SELECTED
															/* CHANNEL 2 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_2_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_2_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_2_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_2_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_2_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_2_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_2_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_2_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_2_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_2_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_2_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_2_Enable						DISABLE
#endif

#if 				DMA_u8Channel_1_Select == SELECTED
															/* CHANNEL 1 */
										/* CONFIGURATION OPTIONS : 1- LOW 				2- MIDIUM 		3- HIGH 		4- VERY_HIGH */
					#define 			DMA_u8Channel_1_PerioritySelect				VERY_HIGH
										/* CONFIGURATION OPTIONS : 1- EIGHT_BITS 		2- SIXTEEN_BITS 3- THIRTYTWO_BITS  */
					#define 			DMA_u8Channel_1_PSize						THIRTYTWO_BITS
					#define 			DMA_u8Channel_1_MSize						THIRTYTWO_BITS
										/* CONFIGURATION OPTIONS : 1- FROM_PERIPHERAL 	2- FROM_MEMORY */
					#define 			DMA_u8Channel_1_DIR_Select					FROM_PERIPHERAL
										/* CONFIGURATION OPTIONS : 1- ENABLE 			2- DISABLE */
					#define 			DMA_u8Channel_1_CIRC_Enable					DISABLE
					#define 			DMA_u8Channel_1_MINC_Enable					DISABLE
					#define 			DMA_u8Channel_1_PINC_Enable					DISABLE
					#define 			DMA_u8Channel_1_MEM2MEM_Enable				DISABLE
					#define 			DMA_u8Channel_1_TCIE_Enable					DISABLE
					#define 			DMA_u8Channel_1_HTIE_Enable					DISABLE
					#define 			DMA_u8Channel_1_TEIE_Enable					DISABLE
					#define 			DMA_u8Channel_1_Enable						ENABLE
#endif

#endif
