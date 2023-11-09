#ifndef GPIO_REG_H
#define GPIO_REG_H

#define 	GPIO_PORTA_BASE_ADD			0x40010800
#define 	GPIO_PORTB_BASE_ADD			0x40010C00
#define 	GPIO_PORTC_BASE_ADD			0x40011000


										/* GPIOA CONFIGURATIONS */
#define 	GPIOA_CRL					(*(volatile uint32*)(GPIO_PORTA_BASE_ADD+0x00))
#define 	GPIOA_CRL_CNF71				31u
#define 	GPIOA_CRL_CNF70				30u
#define 	GPIOA_CRL_MODE71			29u
#define 	GPIOA_CRL_MODE70			28u
#define 	GPIOA_CRL_CNF61				27u
#define 	GPIOA_CRL_CNF60				26u
#define 	GPIOA_CRL_MODE61			25u
#define 	GPIOA_CRL_MODE60			24u
#define 	GPIOA_CRL_CNF51				23u
#define 	GPIOA_CRL_CNF50				22u
#define 	GPIOA_CRL_MODE51			21u
#define 	GPIOA_CRL_MODE50			20u
#define 	GPIOA_CRL_CNF41				19u
#define 	GPIOA_CRL_CNF40				18u
#define 	GPIOA_CRL_MODE41			17u
#define 	GPIOA_CRL_MODE40			16u
#define 	GPIOA_CRL_CNF31				15u
#define 	GPIOA_CRL_CNF30				14u
#define 	GPIOA_CRL_MODE31			13u
#define 	GPIOA_CRL_MODE30			12u
#define 	GPIOA_CRL_CNF21				11u
#define 	GPIOA_CRL_CNF20				10u
#define 	GPIOA_CRL_MODE21			9u
#define 	GPIOA_CRL_MODE20			8u
#define 	GPIOA_CRL_CNF11				7u
#define 	GPIOA_CRL_CNF10				6u
#define 	GPIOA_CRL_MODE11			5u
#define 	GPIOA_CRL_MODE10			4u
#define 	GPIOA_CRL_CNF01				3u
#define 	GPIOA_CRL_CNF00				2u
#define 	GPIOA_CRL_MODE01			1u
#define 	GPIOA_CRL_MODE00			0u

#define 	GPIOA_CRH					(*(volatile uint32*)(GPIO_PORTA_BASE_ADD+0x04))
#define 	GPIOA_CRH_CNF151			31u
#define 	GPIOA_CRH_CNF150			30u
#define 	GPIOA_CRH_MODE151			29u
#define 	GPIOA_CRH_MODE150			28u
#define 	GPIOA_CRH_CNF141			27u
#define 	GPIOA_CRH_CNF140			26u
#define 	GPIOA_CRH_MODE141			25u
#define 	GPIOA_CRH_MODE140			24u
#define 	GPIOA_CRH_CNF131			23u
#define 	GPIOA_CRH_CNF130			22u
#define 	GPIOA_CRH_MODE131			21u
#define 	GPIOA_CRH_MODE130			20u
#define 	GPIOA_CRH_CNF121			19u
#define 	GPIOA_CRH_CNF120			18u
#define 	GPIOA_CRH_MODE121			17u
#define 	GPIOA_CRH_MODE120			16u
#define 	GPIOA_CRH_CNF111			15u
#define 	GPIOA_CRH_CNF110			14u
#define 	GPIOA_CRH_MODE111			13u
#define 	GPIOA_CRH_MODE110			12u
#define 	GPIOA_CRH_CNF101			11u
#define 	GPIOA_CRH_CNF100			10u
#define 	GPIOA_CRH_MODE101			9u
#define 	GPIOA_CRH_MODE100			8u
#define 	GPIOA_CRH_CNF91				7u
#define 	GPIOA_CRH_CNF90				6u
#define 	GPIOA_CRH_MODE91			5u
#define 	GPIOA_CRH_MODE90			4u
#define 	GPIOA_CRH_CNF81				3u
#define 	GPIOA_CRH_CNF80				2u
#define 	GPIOA_CRH_MODE81			1u
#define 	GPIOA_CRH_MODE80			0u

#define 	GPIOA_IDR					(*(volatile uint32*)(GPIO_PORTA_BASE_ADD+0x08))
#define 	GPIOA_IDR_15				15u
#define 	GPIOA_IDR_14				14u
#define 	GPIOA_IDR_13				13u
#define 	GPIOA_IDR_12				12u
#define 	GPIOA_IDR_11				11u
#define 	GPIOA_IDR_10				10u
#define 	GPIOA_IDR_9					9u
#define 	GPIOA_IDR_8					8u
#define 	GPIOA_IDR_7					7u
#define 	GPIOA_IDR_6					6u
#define 	GPIOA_IDR_5					5u
#define 	GPIOA_IDR_4					4u
#define 	GPIOA_IDR_3					3u
#define 	GPIOA_IDR_2					2u
#define 	GPIOA_IDR_1					1u
#define 	GPIOA_IDR_0					0u

#define 	GPIOA_ODR					(*(volatile uint32*)(GPIO_PORTA_BASE_ADD+0x0C))
#define 	GPIOA_ODR_15				15u
#define 	GPIOA_ODR_14				14u
#define 	GPIOA_ODR_13				13u
#define 	GPIOA_ODR_12				12u
#define 	GPIOA_ODR_11				11u
#define 	GPIOA_ODR_10				10u
#define 	GPIOA_ODR_9					9u
#define 	GPIOA_ODR_8					8u
#define 	GPIOA_ODR_7					7u
#define 	GPIOA_ODR_6					6u
#define 	GPIOA_ODR_5					5u
#define 	GPIOA_ODR_4					4u
#define 	GPIOA_ODR_3					3u
#define 	GPIOA_ODR_2					2u
#define 	GPIOA_ODR_1					1u
#define 	GPIOA_ODR_0					0u

										/* GPIOB CONFIGURATIONS */
#define 	GPIOB_CRL					(*(volatile uint32*)(GPIO_PORTB_BASE_ADD+0x00))
#define 	GPIOB_CRL_CNF71				31u
#define 	GPIOB_CRL_CNF70				30u
#define 	GPIOB_CRL_MODE71			29u
#define 	GPIOB_CRL_MODE70			28u
#define 	GPIOB_CRL_CNF61				27u
#define 	GPIOB_CRL_CNF60				26u
#define 	GPIOB_CRL_MODE61			25u
#define 	GPIOB_CRL_MODE60			24u
#define 	GPIOB_CRL_CNF51				23u
#define 	GPIOB_CRL_CNF50				22u
#define 	GPIOB_CRL_MODE51			21u
#define 	GPIOB_CRL_MODE50			20u
#define 	GPIOB_CRL_CNF41				19u
#define 	GPIOB_CRL_CNF40				18u
#define 	GPIOB_CRL_MODE41			17u
#define 	GPIOB_CRL_MODE40			16u
#define 	GPIOB_CRL_CNF31				15u
#define 	GPIOB_CRL_CNF30				14u
#define 	GPIOB_CRL_MODE31			13u
#define 	GPIOB_CRL_MODE30			12u
#define 	GPIOB_CRL_CNF21				11u
#define 	GPIOB_CRL_CNF20				10u
#define 	GPIOB_CRL_MODE21			9u
#define 	GPIOB_CRL_MODE20			8u
#define 	GPIOB_CRL_CNF11				7u
#define 	GPIOB_CRL_CNF10				6u
#define 	GPIOB_CRL_MODE11			5u
#define 	GPIOB_CRL_MODE10			4u
#define 	GPIOB_CRL_CNF01				3u
#define 	GPIOB_CRL_CNF00				2u
#define 	GPIOB_CRL_MODE01			1u
#define 	GPIOB_CRL_MODE00			0u

#define 	GPIOB_CRH					(*(volatile uint32*)(GPIO_PORTB_BASE_ADD+0x04))
#define 	GPIOB_CRH_CNF151			31u
#define 	GPIOB_CRH_CNF150			30u
#define 	GPIOB_CRH_MODE151			29u
#define 	GPIOB_CRH_MODE150			28u
#define 	GPIOB_CRH_CNF141			27u
#define 	GPIOB_CRH_CNF140			26u
#define 	GPIOB_CRH_MODE141			25u
#define 	GPIOB_CRH_MODE140			24u
#define 	GPIOB_CRH_CNF131			23u
#define 	GPIOB_CRH_CNF130			22u
#define 	GPIOB_CRH_MODE131			21u
#define 	GPIOB_CRH_MODE130			20u
#define 	GPIOB_CRH_CNF121			19u
#define 	GPIOB_CRH_CNF120			18u
#define 	GPIOB_CRH_MODE121			17u
#define 	GPIOB_CRH_MODE120			16u
#define 	GPIOB_CRH_CNF111			15u
#define 	GPIOB_CRH_CNF110			14u
#define 	GPIOB_CRH_MODE111			13u
#define 	GPIOB_CRH_MODE110			12u
#define 	GPIOB_CRH_CNF101			11u
#define 	GPIOB_CRH_CNF100			10u
#define 	GPIOB_CRH_MODE101			9u
#define 	GPIOB_CRH_MODE100			8u
#define 	GPIOB_CRH_CNF91				7u
#define 	GPIOB_CRH_CNF90				6u
#define 	GPIOB_CRH_MODE91			5u
#define 	GPIOB_CRH_MODE90			4u
#define 	GPIOB_CRH_CNF81				3u
#define 	GPIOB_CRH_CNF80				2u
#define 	GPIOB_CRH_MODE81			1u
#define 	GPIOB_CRH_MODE80			0u

#define 	GPIOB_IDR					(*(volatile uint32*)(GPIO_PORTB_BASE_ADD+0x08))
#define 	GPIOB_IDR_15				15u
#define 	GPIOB_IDR_14				14u
#define 	GPIOB_IDR_13				13u
#define 	GPIOB_IDR_12				12u
#define 	GPIOB_IDR_11				11u
#define 	GPIOB_IDR_10				10u
#define 	GPIOB_IDR_9					9u
#define 	GPIOB_IDR_8					8u
#define 	GPIOB_IDR_7					7u
#define 	GPIOB_IDR_6					6u
#define 	GPIOB_IDR_5					5u
#define 	GPIOB_IDR_4					4u
#define 	GPIOB_IDR_3					3u
#define 	GPIOB_IDR_2					2u
#define 	GPIOB_IDR_1					1u
#define 	GPIOB_IDR_0					0u

#define 	GPIOB_ODR					(*(volatile uint32*)(GPIO_PORTB_BASE_ADD+0x0C))
#define 	GPIOB_ODR_15				15u
#define 	GPIOB_ODR_14				14u
#define 	GPIOB_ODR_13				13u
#define 	GPIOB_ODR_12				12u
#define 	GPIOB_ODR_11				11u
#define 	GPIOB_ODR_10				10u
#define 	GPIOB_ODR_9					9u
#define 	GPIOB_ODR_8					8u
#define 	GPIOB_ODR_7					7u
#define 	GPIOB_ODR_6					6u
#define 	GPIOB_ODR_5					5u
#define 	GPIOB_ODR_4					4u
#define 	GPIOB_ODR_3					3u
#define 	GPIOB_ODR_2					2u
#define 	GPIOB_ODR_1					1u
#define 	GPIOB_ODR_0					0u

										/* GPIOC CONFIGURATIONS */
#define 	GPIOC_CRL					(*(volatile uint32*)(GPIO_PORTC_BASE_ADD+0x00))
#define 	GPIOC_CRL_CNF21				11u
#define 	GPIOC_CRL_CNF20				10u
#define 	GPIOC_CRL_MODE21			9u
#define 	GPIOC_CRL_MODE20			8u
#define 	GPIOC_CRL_CNF11				7u
#define 	GPIOC_CRL_CNF10				6u
#define 	GPIOC_CRL_MODE11			5u
#define 	GPIOC_CRL_MODE10			4u
#define 	GPIOC_CRL_CNF01				3u
#define 	GPIOC_CRL_CNF00				2u
#define 	GPIOC_CRL_MODE01			1u
#define 	GPIOC_CRL_MODE00			0u

#define 	GPIOC_IDR					(*(volatile uint32*)(GPIO_PORTC_BASE_ADD+0x08))
#define 	GPIOC_IDR_2					2u
#define 	GPIOC_IDR_1					1u
#define 	GPIOC_IDR_0					0u

#define 	GPIOC_ODR					(*(volatile uint32*)(GPIO_PORTC_BASE_ADD+0x0C))
#define 	GPIOC_ODR_2					2u
#define 	GPIOC_ODR_1					1u
#define 	GPIOC_ODR_0					0u
#endif 
