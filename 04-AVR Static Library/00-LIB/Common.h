/*
 * Common.h
 *
 * Created: 12/16/2023 12:08:50 AM
 *  Author: ME
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#define POW(base, exponent) \
({ \
	int result = 1; \
	for (int i = 0; i < exponent; i++) { \
		result *= base; \
	} \
	result; \
})						

#define MODULE_STATUS_CODE_OFFSET				(100)
#define CALC_STATUS_CODE(BASE,OFFSET)			(BASE + OFFSET)
#define GET_STATUS_CODE_BASE(INDEX)				(INDEX * MODULE_STATUS_CODE_OFFSET)
#define GET_STATUS_CODE_OFFSET(CODE,INDEX)	    (CODE - (MODULE_STATUS_CODE_OFFSET*INDEX))

typedef enum
{
	SYS_INDEX	,
	DIO_INDEX	,
	PORT_INDEX	,
	LED_INDEX	,
	BTN_INDEX	,
	SSD_INDEX
}SYS_enumModuleIndex_t;

typedef enum
{
	SYS_enumStatusBase			= GET_STATUS_CODE_BASE(SYS_INDEX)				  ,				
	SYS_enumStatusOk			= SYS_enumStatusBase						  ,				
	SYS_enumNullPtr												  ,				
	SYS_enumInvalidPort											  ,				
	SYS_enumInvalidPin											  ,				
	SYS_enumInvalidConfig											  ,				
	SYS_enumInvalidValue											  ,				
	SYS_enumIndexOutOfBounds										  ,				
	
	PORT_enumStatusBase			= GET_STATUS_CODE_BASE(PORT_INDEX)				  ,
	PORT_enumStatusOk			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumStatusOk	) ,	  /* If the operation is done successfully */
	PORT_enumNullPtr			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumNullPtr		) ,	  /* If any address passed as an argument is a null pointer */
	PORT_enumInvalidPort			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumInvalidPort	) ,	  /* If the port number passed as an argument is invalid */
	PORT_enumInvalidPin			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumInvalidPin	) ,	  /* If the pin number passed as an argument is invalid */
	PORT_enumInvalidConfig			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumInvalidConfig	) ,	  /* If the pin/port configuration passed as an argument is invalid */
	PORT_enumInvalidValue			= CALC_STATUS_CODE(PORT_enumStatusBase, SYS_enumInvalidValue	) ,	  /* If the pin value passed as an argument is invalid */
														
	DIO_enumStatusBase			= GET_STATUS_CODE_BASE(DIO_INDEX)	      			  ,
	DIO_enumStatusOk			= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumStatusOk		) ,	  /* If the operation is done successfully */
	DIO_enumNullPtr				= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumNullPtr		) ,	  /* If any address passed as an argument is a null pointer */
	DIO_enumInvalidPort			= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumInvalidPort	) ,	  /* If the port number passed as an argument is invalid */
	DIO_enumInvalidPin			= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumInvalidPin	) ,	  /* If the pin number passed as an argument is invalid */
	DIO_enumInvalidConfig			= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumInvalidConfig	) ,	  /* If the pin/port configuration passed as an argument is invalid */
	DIO_enumInvalidValue			= CALC_STATUS_CODE(DIO_enumStatusBase, SYS_enumInvalidValue	) ,	  /* If the pin value passed as an argument is invalid */
														
	LED_enumStatusBase			= GET_STATUS_CODE_BASE(LED_INDEX)				  ,
	LED_enumStatusOk			= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumStatusOk		) ,	  /* If the operation is done successfully */
	LED_enumNullPtr				= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumNullPtr		) ,	  /* If any address passed as an argument is a null pointer */
	LED_enumInvalidPort			= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumInvalidPort	) ,	  /* If the port number passed as an argument is invalid */
	LED_enumInvalidPin			= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumInvalidPin	) ,	  /* If the pin number passed as an argument is invalid */
	LED_enumInvalidConfig			= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumInvalidConfig	) ,	  /* If the LED configuration is invalid (neither output high or low) */
	LED_enumInvalidValue			= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumInvalidValue	) ,	  /* If the pin value passed as an argument is invalid */
	LED_enumIndexOutOfBounds		= CALC_STATUS_CODE(LED_enumStatusBase, SYS_enumIndexOutOfBounds	) ,
	
	BTN_enumStatusBase			= GET_STATUS_CODE_BASE(BTN_INDEX)				  ,
	BTN_enumStatusOk			= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumStatusOk		) ,	   /* If the operation is done successfully */
	BTN_enumNullPtr				= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumNullPtr		) ,	   /* If any address passed as an argument is a null pointer */
	BTN_enumInvalidPort			= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumInvalidPort	) ,	   /* If the port number passed as an argument is invalid */
	BTN_enumInvalidPin			= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumInvalidPin	) ,	   /* If the pin number passed as an argument is invalid */
	BTN_enumInvalidConfig			= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumInvalidConfig	) ,	   /* If the pin/port configuration passed as an argument is invalid */
	BTN_enumIndexOutOfBounds		= CALC_STATUS_CODE(BTN_enumStatusBase, SYS_enumIndexOutOfBounds	) ,
	
	SSD_enumStatusBase			= GET_STATUS_CODE_BASE(SSD_INDEX)				  ,
	SSD_enumStatusOk			= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumStatusOk		) ,	   /* If the operation is done successfully */
	SSD_enumInvalidPort			= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumInvalidPort	) ,	   /* If the port number passed as an argument is invalid */
	SSD_enumInvalidPin			= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumInvalidPin	) ,	   /* If the pin number passed as an argument is invalid */
	SSD_enumInvalidConfig			= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumInvalidConfig	) ,	   /* If the pin/port configuration passed as an argument is invalid */
	SSD_enumInvalidValue			= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumInvalidValue	) ,	   /* If the value passed as an argument for the SSD is out of bounds */
	SSD_enumIndexOutOfBounds		= CALC_STATUS_CODE(SSD_enumStatusBase, SYS_enumIndexOutOfBounds	) 
}CMN_enumStatusCode_t;




#endif /* COMMON_H_ */