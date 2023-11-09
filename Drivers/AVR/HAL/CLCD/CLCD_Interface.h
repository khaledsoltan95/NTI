
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_voidSendData (uint8 Local_u8Data) ;
void CLCD_voidSendCommand (uint8 Local_u8Command);
void CLCD_voidInit (void);
uint8 CLCD_u8SendString (char*Copy_u8String ) ;


#endif 
