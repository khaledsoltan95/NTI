#ifndef DMA1_INTERFACE_H__
#define	DMA1_INTERFACE_H_H_


typedef enum
{
	Channel1 ,
	Channel2 ,
	Channel3 ,
	Channel4 ,
	Channel5 ,
	Channel6 ,
	Channel7 ,
}Channel_t ;

typedef struct
{
	uint16 Enable 	: 1 ; 		// 	1 : ENABLE    		0 : DISABLE
	uint16 TCIE 	: 1 ;    	// 	1 : ENABLE    		0 : DISABLE
	uint16 HTIE 	: 1 ;    	// 	1 : ENABLE   		0 : DISABLE
	uint16 TEIE 	: 1 ;    	// 	1 : ENABLE    		0 : DISABLE
	uint16 DIR 		: 1 ;    	// 	1 : FROM MEMORY    	0 : FROM PERIPHERAL
	uint16 CIRC 	: 1 ;    	// 	1 : ENABLE   	 	0 : DISABLE
	uint16 PINC 	: 1 ;    	// 	1 : ENABLE    		0 : DISABLE
	uint16 MINC 	: 1 ;    	// 	1 : ENABLE    		0 : DISABLE
	uint16 PSIZE 	: 2 ;    	// 	2 : 32_BITS    		1 : 16_BITS			0 : 8_BITS
	uint16 MSIZE 	: 2 ;    	// 	2 : 32_BITS    		1 : 16_BITS			0 : 8_BITS
	uint16 PL 		: 2 ;    	// 	3 : VERY HIGH		2 : HIGH    		1 : MIDIUM			0 : LOW
	uint16 MEM2MEM 	: 1 ;    	// 	1 : ENABLE    		0 : DISABLE
}ChannelConfig_t ;

										 /*	DON'T FORGET ENABLING RCC_DMA1 */

void 	DMA1_voidChannelPreBuiltInit	(void) ;

uint8	DMA1_voidChannelRunTimeInit		(Channel_t copy_ChannelNum , ChannelConfig_t* copy_ChannelConfig) ;

uint8	DMA1_voidChannelStart			(uint32* copy_u32pSourceAddress ,uint32* copy_u32pDestinationAddress ,Channel_t copy_ChannelNum , uint16 copy_u16DataLength) ;


#endif
