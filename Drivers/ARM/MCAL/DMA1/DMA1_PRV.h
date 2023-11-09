#ifndef DMA1_PRV_H__
#define	DMA1_PRV_H_H_

#define				DMA1_CCRMASK 		0u

#define				ALL_FREE			0u
#define				ALL_BUSY			254u
#define				CHANNEL1_FLAG		1u								/* CHANNEL 1 BUSY FLAG */
#define				CHANNEL2_FLAG		2u								/* CHANNEL 2 BUSY FLAG */
#define				CHANNEL3_FLAG		3u								/* CHANNEL 3 BUSY FLAG */
#define				CHANNEL4_FLAG		4u                              /* CHANNEL 4 BUSY FLAG */
#define				CHANNEL5_FLAG		5u                              /* CHANNEL 5 BUSY FLAG */
#define				CHANNEL6_FLAG		6u                              /* CHANNEL 6 BUSY FLAG */
#define				CHANNEL7_FLAG		7u								/* CHANNEL 7 BUSY FLAG */

#define 			SELECTED			1u
#define 			NOT_SELECTED		2u

#define 			ENABLE				1u
#define 			DISABLE				2u

#define 			FROM_PERIPHERAL		1u
#define 			FROM_MEMORY			2u

#define 			EIGHT_BITS			0u
#define 			SIXTEEN_BITS		1u
#define 			THIRTYTWO_BITS		2u

#define 			LOW					0u
#define 			MIDIUM				1u
#define 			HIGH				2u
#define 			VERY_HIGH			3u

#endif
