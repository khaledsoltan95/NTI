#ifndef CLCD_PRV_H
#define CLCD_PRV_H

	#define 	EIGHT_BIT		1u
	#define 	FOUR_BIT		2u

	#define 	PRE_CONNECTED	3u
	#define 	POST_CONNECTED	4u

static void CLCD_voidSendHalf (uint8 Local_u8Command);
static void CLCD_voidSendEnablePulse (void) ;

#endif
