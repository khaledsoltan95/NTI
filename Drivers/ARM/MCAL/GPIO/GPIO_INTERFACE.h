#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


	typedef enum
	{
		GPIO_PORTA ,
		GPIO_PORTB ,
		GPIO_PORTC
	}GPIO_Port_t;
	typedef enum
	{
		GPIO_PIN0 ,
		GPIO_PIN1 ,
		GPIO_PIN2 ,
		GPIO_PIN3 ,
		GPIO_PIN4 ,
		GPIO_PIN5 ,
		GPIO_PIN6 ,
		GPIO_PIN7 ,
		GPIO_PIN8 ,
		GPIO_PIN9 ,
		GPIO_PIN10 ,
		GPIO_PIN11 ,
		GPIO_PIN12 ,
		GPIO_PIN13 ,
		GPIO_PIN14 ,
		GPIO_PIN15
	}GPIO_Pin_t;
	typedef enum
	{
		GPIO_PIN_INPUT ,
		GPIO_PIN_OUTPUT_10MHZ ,
		GPIO_PIN_OUTPUT_2MHZ ,
		GPIO_PIN_OUTPUT_50MHZ ,

	}GPIO_PinDir_t;
	typedef enum
	{
		GPIO_PIN_ANALOG ,
		GPIO_PIN_FLOAT ,
		GPIO_PIN_PULLUP ,
		GPIO_PIN_PUSHPULL ,
		GPIO_PIN_OPENDRAIN ,
		GPIO_PIN_ALTERNATEFUNCTION_PUSHPULL ,
		GPIO_PIN_ALTERNATEFUNCTION_OPENDRAIN
	}GPIO_PinVal_t;
	typedef enum
	{
		GPIO_PIN_HIGH ,
		GPIO_PIN_LOW
	}GPIO_PinInitVal_t;

											/* Functions Deceleration */

	void 	GPIO_voidInit				( void ) ;

	uint8 	GPIO_U8SetPinDirection	    (GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum,		GPIO_PinDir_t copy_Dir);
	uint8 	GPIO_U8SetPortDirection		(GPIO_Port_t copy_Port,	 uint64 copy_u64PortDir);

	uint8 	GPIO_U8SetPinValue	    	(GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum,		GPIO_PinInitVal_t copy_Val);
	uint8 	GPIO_U8SetPortValue    		(GPIO_Port_t copy_Port,	 uint16 copy_u16PortVal);

	uint8 	GPIO_u8GetPinValue 			(GPIO_Port_t copy_port,  GPIO_Pin_t copy_PinNum, 		GPIO_PinVal_t* copy_pVal );
	uint8 	GPIO_u8TogglePinValue		(GPIO_Port_t copy_Port,	 GPIO_Pin_t copy_PinNum);

#endif 
