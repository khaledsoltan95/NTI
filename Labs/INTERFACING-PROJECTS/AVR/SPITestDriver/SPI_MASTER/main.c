#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_Interface.h"
#include "PORT_Interface.h"
#include "SPI_Interface.h"

void main ()
{
									/* THIS PROGRAM FOR TESTING SENDING DATA USING SPI PROTOCOL AND CHECKING THAT DATA RECEIVED TO SLAVE */

	PORT_voidInit() ;

	SPI_voidInitial();

	SPI_u8Transceive('9') ;

	while (1)
	{

	}
}

