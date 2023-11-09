#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum
{
	DIO_PORTA ,
	DIO_PORTB ,
	DIO_PORTC ,
	DIO_PORTD
}DIO_PORT;
typedef enum
{
	PIN0 ,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7 ,
	PIN8 ,
	PIN9 ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15 ,
	PIN16 ,
	PIN17 ,
	PIN18 ,
	PIN19 ,
	PIN20 ,
	PIN21 ,
	PIN22 ,
	PIN23 ,
	PIN24 ,
	PIN25 ,
	PIN26 ,
	PIN27 ,
	PIN28 ,
	PIN29 ,
	PIN30 ,
	PIN31
}DIO_PIN;

typedef enum
{
	INPUT ,
	OUTPUT
}DIO_PIN_Direction;

typedef enum
{
	LOW ,
	HIGH
}DIO_PIN_VALUE;

void  PORT_INIT 				(void);

uint8 DIO_SET_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN ,DIO_PIN_VALUE copy_Status) ;
uint8 DIO_SET_PIN_DIRECTION 	(DIO_PORT copy_Port,DIO_PIN copy_PIN ,DIO_PIN_Direction copy_Status) ;

uint8 DIO_SET_PIN_VALUE1 		(DIO_PIN copy_PIN ,DIO_PIN_VALUE copy_Status) ;
uint8 DIO_SET_PIN_DIRECTION1 	(DIO_PIN copy_PIN ,DIO_PIN_Direction copy_Status) ;

uint8 DIO_SET_PORT_DIRECTION 	(DIO_PORT copy_Port,uint8 copy_u8Direction) ;
uint8 DIO_SET_PORT_VALUE 		(DIO_PORT copy_Port,uint8 copy_u8Value) ;

uint8 DIO_GET_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN ,uint8* copy_pu8Value) ;
uint8 DIO_TOGGLE_PIN_VALUE 		(DIO_PORT copy_Port,DIO_PIN copy_PIN ) ;

#endif
