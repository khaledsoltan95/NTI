#ifndef ERR_TYPE_H 
#define ERR_TYPE_H

						/* Error Statues */
						
	#define 	OK 			 						0U
	#define 	NOK     	 						1U
	#define 	NULL_PTR 	 						2U
	#define 	NULL		 						(void*)0
	#define		TIMEOUT_ERR	 						3U
	#define		BUSY_ERR	 						4u

	#define		RESERVED_ADDRESS_WARNING			5U
	#define		RESERVED_ADDRESS_ERR				6U
	#define 	ADDRESS_N_ACK_ERR					7U
	#define 	DATA_N_ACK_ERR						8U

#endif  
