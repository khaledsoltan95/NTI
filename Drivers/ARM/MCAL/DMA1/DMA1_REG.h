#ifndef DMA1_REG_H__
#define	DMA1_REG_H_H_

#define				DMA1_BASE_ADDRESS					0x40020000

#define				DMA1_ISR							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x000))
#define				DMA1_ISR_TEIF7						27u
#define				DMA1_ISR_HTIF7                      26u
#define				DMA1_ISR_TCIF7                      25u
#define				DMA1_ISR_GIF7                       24u
#define				DMA1_ISR_TEIF6                      23u
#define				DMA1_ISR_HTIF6                      22u
#define				DMA1_ISR_TCIF6                      21u
#define				DMA1_ISR_GIF6                       20u
#define				DMA1_ISR_TEIF5                      19u
#define				DMA1_ISR_HTIF5                      18u
#define				DMA1_ISR_TCIF5                      17u
#define				DMA1_ISR_GIF5                       16u
#define				DMA1_ISR_TEIF4                      15u
#define				DMA1_ISR_HTIF4                      14u
#define				DMA1_ISR_TCIF4                      13u
#define				DMA1_ISR_GIF4                       12u
#define				DMA1_ISR_TEIF3                      11u
#define				DMA1_ISR_HTIF3                      10u
#define				DMA1_ISR_TCIF3                      9u
#define				DMA1_ISR_GIF3                       8u
#define				DMA1_ISR_TEIF2                      7u
#define				DMA1_ISR_HTIF2                      6u
#define				DMA1_ISR_TCIF2                      5u
#define				DMA1_ISR_GIF2                       4u
#define				DMA1_ISR_TEIF1                      3u
#define				DMA1_ISR_HTIF1                      2u
#define				DMA1_ISR_TCIF1                      1u
#define				DMA1_ISR_GIF1                       0u

#define				DMA1_IFCR							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x004))
#define				DMA1_IFCR_CTEIF7					27u
#define				DMA1_IFCR_CHTIF7                    26u
#define				DMA1_IFCR_CTCIF7                    25u
#define				DMA1_IFCR_CGIF7                     24u
#define				DMA1_IFCR_CTEIF6                    23u
#define				DMA1_IFCR_CHTIF6                    22u
#define				DMA1_IFCR_CTCIF6                    21u
#define				DMA1_IFCR_CGIF6                     20u
#define				DMA1_IFCR_CTEIF5                    19u
#define				DMA1_IFCR_CHTIF5                    18u
#define				DMA1_IFCR_CTCIF5                    17u
#define				DMA1_IFCR_CGIF5                     16u
#define				DMA1_IFCR_CTEIF4                    15u
#define				DMA1_IFCR_CHTIF4                    14u
#define				DMA1_IFCR_CTCIF4                    13u
#define				DMA1_IFCR_CGIF4                     12u
#define				DMA1_IFCR_CTEIF3                    11u
#define				DMA1_IFCR_CHTIF3                    10u
#define				DMA1_IFCR_CTCIF3                    9u
#define				DMA1_IFCR_CGIF3                     8u
#define				DMA1_IFCR_CTEIF2                    7u
#define				DMA1_IFCR_CHTIF2                    6u
#define				DMA1_IFCR_CTCIF2                    5u
#define				DMA1_IFCR_CGIF2                     4u
#define				DMA1_IFCR_CTEIF1                    3u
#define				DMA1_IFCR_CHTIF1                    2u
#define				DMA1_IFCR_CTCIF1                    1u
#define				DMA1_IFCR_CGIF1                     0u
														/* CHANNELS CONTROL REGISTERS */
#define				DMA1_CCR1							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x008))
#define				DMA1_CCR2							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x01C))
#define				DMA1_CCR3							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x030))
#define				DMA1_CCR4							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x044))
#define				DMA1_CCR5							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x058))
#define				DMA1_CCR6							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x06C))
#define				DMA1_CCR7							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x080))
#define				DMA1_CCR_MEM2MEM                   	14u
#define				DMA1_CCR_PL1                      	13u
#define				DMA1_CCR_PL0                      	12u
#define				DMA1_CCR_MSIZE1                    	11u
#define				DMA1_CCR_MSIZE0                    	10u
#define				DMA1_CCR_PSIZE1                    	9u
#define				DMA1_CCR_PSIZE0                    	8u
#define				DMA1_CCR_MINC                     	7u
#define				DMA1_CCR_PINC                      	6u
#define				DMA1_CCR_CIRC                      	5u
#define				DMA1_CCR_DIR                       	4u
#define				DMA1_CCR_TEIE                      	3u
#define				DMA1_CCR_HTIE                      	2u
#define				DMA1_CCR_TCIE                      	1u
#define				DMA1_CCR_EN	                    	0u
														/* CHANEL 1 */
#define				DMA1_CNDTR1							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x00C))        /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR1							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x010))
#define				DMA1_CMAR1							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x014))
														/* CHANEL 2 */
#define				DMA1_CNDTR2							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x020)) 		/* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR2							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x024))
#define				DMA1_CMAR2							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x028))
														/* CHANEL 3 */
#define				DMA1_CNDTR3							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x034))		 /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR3							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x038))
#define				DMA1_CMAR3							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x03C))
														/* CHANEL 4 */
#define				DMA1_CNDTR4							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x048))		 /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR4							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x04C))
#define				DMA1_CMAR4							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x050))
														/* CHANEL 5 */
#define				DMA1_CNDTR5							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x05C))		 /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR5							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x060))
#define				DMA1_CMAR5							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x064))
														/* CHANEL 6 */
#define				DMA1_CNDTR6							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x070))		 /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR6							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x074))
#define				DMA1_CMAR6							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x078))
														/* CHANEL 7 */
#define				DMA1_CNDTR7							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x084))		 /* THIS REGISTER HALF OF IT IS RESERVED */
#define				DMA1_CPAR7							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x088))
#define				DMA1_CMAR7							(*(volatile uint32*)(DMA1_BASE_ADDRESS + 0x08C))

#endif
