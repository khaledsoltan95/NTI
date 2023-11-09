#ifndef RCC_REG_H
#define RCC_REG_H

#define 	RCC_BASE_ADD 				0x40021000

#define 	RCC_CR						(*(volatile uint32*)(RCC_BASE_ADD+0x00))
#define 	RCC_CR_R1				31u
#define 	RCC_CR_R2				30u
#define 	RCC_CR_R3				29u
#define 	RCC_CR_R4				28u
#define 	RCC_CR_R5				27u
#define 	RCC_CR_R6				26u
#define 	RCC_CR_PLLRDY			25u
#define 	RCC_CR_PLLON			24u
#define 	RCC_CR_R7				23u
#define 	RCC_CR_R8				22u
#define 	RCC_CR_R9				21u
#define 	RCC_CR_R10				20u
#define 	RCC_CR_CSSON			19u
#define 	RCC_CR_HSEBYP			18u
#define 	RCC_CR_HSERDY			17u
#define 	RCC_CR_HSEON			16u
#define 	RCC_CR_HSICAL7			15u
#define 	RCC_CR_HSICAL6			14u
#define 	RCC_CR_HSICAL5			13u
#define 	RCC_CR_HSICAL4			12u
#define 	RCC_CR_HSICAL3			11u
#define 	RCC_CR_HSICAL2			10u
#define 	RCC_CR_HSICAL1			9u
#define 	RCC_CR_HSICAL0			8u
#define 	RCC_CR_HSITRIM4			7u
#define 	RCC_CR_HSITRIM3			6u
#define 	RCC_CR_HSITRIM2			5u
#define 	RCC_CR_HSITRIM1			4u
#define 	RCC_CR_HSITRIM0			3u
#define 	RCC_CR_R11				2u
#define 	RCC_CR_HSIRDY			1u
#define 	RCC_CR_HSION			0u

#define 	RCC_CFGR					(*(volatile uint32*)(RCC_BASE_ADD+0x04))

#define 	RCC_AHBENR					(*(volatile uint32*)(RCC_BASE_ADD+0x14))
#define 	RCC_AHBENR_R1				31u
#define 	RCC_AHBENR_R2				30u
#define 	RCC_AHBENR_R3				29u
#define 	RCC_AHBENR_R4				28u
#define 	RCC_AHBENR_R5				27u
#define 	RCC_AHBENR_R6				26u
#define 	RCC_AHBENR_R7				25u
#define 	RCC_AHBENR_R8				24u
#define 	RCC_AHBENR_R9				23u
#define 	RCC_AHBENR_R10				22u
#define 	RCC_AHBENR_R11				21u
#define 	RCC_AHBENR_R12				20u
#define 	RCC_AHBENR_R13				19u
#define 	RCC_AHBENR_R14				18u
#define 	RCC_AHBENR_R15				17u
#define 	RCC_AHBENR_R16				16u
#define 	RCC_AHBENR_R17				15u
#define 	RCC_AHBENR_R18				14u
#define 	RCC_AHBENR_R19				13u
#define 	RCC_AHBENR_R20				12u
#define 	RCC_AHBENR_R21				11u
#define 	RCC_AHBENR_SDIOEN			10u
#define 	RCC_AHBENR_R22				9u
#define 	RCC_AHBENR_FSMCEN			8u
#define 	RCC_AHBENR_R23				7u
#define 	RCC_AHBENR_CRCEN			6u
#define 	RCC_AHBENR_R24				5u
#define 	RCC_AHBENR_FLITFEN			4u
#define 	RCC_AHBENR_R25				3u
#define 	RCC_AHBENR_SRAMEN			2u
#define 	RCC_AHBENR_DMA2EN			1u
#define 	RCC_AHBENR_DMA1EN			0u

#define 	RCC_APB2ENR					(*(volatile uint32*)(RCC_BASE_ADD+0x18))
#define 	RCC_APB2_R1					31u
#define 	RCC_APB2_R2					30u
#define 	RCC_APB2_R3					29u
#define 	RCC_APB2_R4					28u
#define 	RCC_APB2_R5					27u
#define 	RCC_APB2_R6					26u
#define 	RCC_APB2_R7					25u
#define 	RCC_APB2_R8					24u
#define 	RCC_APB2_R9					23u
#define 	RCC_APB2_R10				22u
#define 	RCC_APB2_R11				21u
#define 	RCC_APB2_R12				20u
#define 	RCC_APB2_R13				19u
#define 	RCC_APB2_R14				18u
#define 	RCC_APB2_R15				17u
#define 	RCC_APB2_R16				16u
#define 	RCC_APB2_R17				15u
#define 	RCC_APB2_R18				14u
#define 	RCC_APB2_R19				13u
#define 	RCC_APB2_R20				12u
#define 	RCC_APB2_R21				11u
#define 	RCC_APB2_SDIOEN				10u
#define 	RCC_APB2_R22				9u
#define 	RCC_APB2_FSMCEN				8u
#define 	RCC_APB2_R23				7u
#define 	RCC_APB2_CRCEN				6u
#define 	RCC_APB2_R24				5u
#define 	RCC_APB2_FLITFEN			4u
#define 	RCC_APB2_R25				3u
#define 	RCC_APB2_SRAMEN				2u
#define 	RCC_APB2_DMA2EN				1u
#define 	RCC_APB2_DMA1EN				0u

#define 	RCC_APB1ENR					(*(volatile uint32*)(RCC_BASE_ADD+0x1C))
#define 	RCC_APB1_R1					31u
#define 	RCC_APB1_R2					30u
#define 	RCC_APB1_R3					29u
#define 	RCC_APB1_R4					28u
#define 	RCC_APB1_R5					27u
#define 	RCC_APB1_R6					26u
#define 	RCC_APB1_R7					25u
#define 	RCC_APB1_R8					24u
#define 	RCC_APB1_R9					23u
#define 	RCC_APB1_R10				22u
#define 	RCC_APB1_R11				21u
#define 	RCC_APB1_R12				20u
#define 	RCC_APB1_R13				19u
#define 	RCC_APB1_R14				18u
#define 	RCC_APB1_R15				17u
#define 	RCC_APB1_R16				16u
#define 	RCC_APB1_R17				15u
#define 	RCC_APB1_R18				14u
#define 	RCC_APB1_R19				13u
#define 	RCC_APB1_R20				12u
#define 	RCC_APB1_R21				11u
#define 	RCC_APB1_SDIOEN				10u
#define 	RCC_APB1_R22				9u
#define 	RCC_APB1_FSMCEN				8u
#define 	RCC_APB1_R23				7u
#define 	RCC_APB1_CRCEN				6u
#define 	RCC_APB1_R24				5u
#define 	RCC_APB1_FLITFEN			4u
#define 	RCC_APB1_R25				3u
#define 	RCC_APB1_SRAMEN				2u
#define 	RCC_APB1_DMA2EN				1u
#define 	RCC_APB1_DMA1EN				0u

#endif 
