/**
* @file	PORT_config.c
* @author  Alaa Hisham
* @brief   Contains function implementation for configuring
*			the initial states of all I/O pins.
* @version 1.1
* @date    2-12-2023
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT.h"
#include "PORT_config.h"
#include "PORT_register.h"

#define	INPUT		0
#define OUTPUT		1

#define HIGH		1
#define LOW			0

#define DIR_BIT		0
#define VAL_BIT		1

/* Array of addresses to each port base */
strPortReg_t* pstrPortArr[NUMBER_OF_PORTS] =
{
	#if NUMBER_OF_PORTS > ZERO
	PORTA_BASE
	#endif
	#if NUMBER_OF_PORTS > ONE_PORT
	,PORTB_BASE
	#endif
	#if NUMBER_OF_PORTS > TWO_PORTS
	,PORTC_BASE
	#endif
	#if NUMBER_OF_PORTS > THREE_PORTS
	,PORTD_BASE
	#endif
};

/* Port indices */
#if NUMBER_OF_PORTS > ZERO	
#define PORTA	0
#endif
#if NUMBER_OF_PORTS > ONE_PORT
#define PORTB	1
#endif
#if NUMBER_OF_PORTS > TWO_PORTS
#define PORTC	2
#endif
#if NUMBER_OF_PORTS > THREE_PORTS
#define PORTD	3
#endif


#define CONC(b0,b1,b2,b3,b4,b5,b6,b7)			CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)	0b##b7##b6##b5##b4##b3##b2##b1##b0


#if NUMBER_OF_PORTS > FOUR_PORTS
#error "Unsupported Port Number!"
#else
#if NUMBER_OF_PORTS > ZERO

#if PORTA_PIN0 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN0_DIR		INPUT
#define PORTA_PIN0_VAL		LOW
#elif PORTA_PIN0 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN0_DIR		INPUT
#define PORTA_PIN0_VAL		HIGH 
#elif PORTA_PIN0 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN0_DIR		INPUT
#define PORTA_PIN0_VAL		LOW
#elif PORTA_PIN0 == OUTPUT_LOW
#define PORTA_PIN0_DIR		OUTPUT
#define PORTA_PIN0_VAL		LOW
#elif PORTA_PIN0 == OUTPUT_HIGH
#define PORTA_PIN0_DIR		OUTPUT
#define PORTA_PIN0_VAL		HIGH
#else
#error "PORTA_PIN0: Invalid pin configuration."
#endif

#if PORTA_PIN1 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN1_DIR		INPUT
#define PORTA_PIN1_VAL		LOW
#elif PORTA_PIN1 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN1_DIR		INPUT
#define PORTA_PIN1_VAL		HIGH 
#elif PORTA_PIN1 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN1_DIR		INPUT
#define PORTA_PIN1_VAL		LOW
#elif PORTA_PIN1 == OUTPUT_LOW
#define PORTA_PIN1_DIR		OUTPUT
#define PORTA_PIN1_VAL		LOW
#elif PORTA_PIN1 == OUTPUT_HIGH
#define PORTA_PIN1_DIR		OUTPUT
#define PORTA_PIN1_VAL		HIGH
#else
#error "PORTA_PIN1: Invalid pin configuration."
#endif

#if PORTA_PIN2 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN2_DIR		INPUT
#define PORTA_PIN2_VAL		LOW
#elif PORTA_PIN2 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN2_DIR		INPUT
#define PORTA_PIN2_VAL		HIGH 
#elif PORTA_PIN2 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN2_DIR		INPUT
#define PORTA_PIN2_VAL		LOW
#elif PORTA_PIN2 == OUTPUT_LOW
#define PORTA_PIN2_DIR		OUTPUT
#define PORTA_PIN2_VAL		LOW
#elif PORTA_PIN2 == OUTPUT_HIGH
#define PORTA_PIN2_DIR		OUTPUT
#define PORTA_PIN2_VAL		HIGH
#else
#error "PORTA_PIN2: Invalid pin configuration."
#endif

#if PORTA_PIN3 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN3_DIR		INPUT
#define PORTA_PIN3_VAL		LOW
#elif PORTA_PIN3 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN3_DIR		INPUT
#define PORTA_PIN3_VAL		HIGH 
#elif PORTA_PIN3 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN3_DIR		INPUT
#define PORTA_PIN3_VAL		LOW
#elif PORTA_PIN3 == OUTPUT_LOW
#define PORTA_PIN3_DIR		OUTPUT
#define PORTA_PIN3_VAL		LOW
#elif PORTA_PIN3 == OUTPUT_HIGH
#define PORTA_PIN3_DIR		OUTPUT
#define PORTA_PIN3_VAL		HIGH
#else
#error "PORTA_PIN3: Invalid pin configuration."
#endif

#if PORTA_PIN4 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN4_DIR		INPUT
#define PORTA_PIN4_VAL		LOW
#elif PORTA_PIN4 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN4_DIR		INPUT
#define PORTA_PIN4_VAL		HIGH 
#elif PORTA_PIN4 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN4_DIR		INPUT
#define PORTA_PIN4_VAL		LOW
#elif PORTA_PIN4 == OUTPUT_LOW
#define PORTA_PIN4_DIR		OUTPUT
#define PORTA_PIN4_VAL		LOW
#elif PORTA_PIN4 == OUTPUT_HIGH
#define PORTA_PIN4_DIR		OUTPUT
#define PORTA_PIN4_VAL		HIGH
#else
#error "PORTA_PIN4: Invalid pin configuration."
#endif

#if PORTA_PIN5 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN5_DIR		INPUT
#define PORTA_PIN5_VAL		LOW
#elif PORTA_PIN5 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN5_DIR		INPUT
#define PORTA_PIN5_VAL		HIGH 
#elif PORTA_PIN5 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN5_DIR		INPUT
#define PORTA_PIN5_VAL		LOW
#elif PORTA_PIN5 == OUTPUT_LOW
#define PORTA_PIN5_DIR		OUTPUT
#define PORTA_PIN5_VAL		LOW
#elif PORTA_PIN5 == OUTPUT_HIGH
#define PORTA_PIN5_DIR		OUTPUT
#define PORTA_PIN5_VAL		HIGH
#else
#error "PORTA_PIN5: Invalid pin configuration."
#endif

#if PORTA_PIN6 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN6_DIR		INPUT
#define PORTA_PIN6_VAL		LOW
#elif PORTA_PIN6 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN6_DIR		INPUT
#define PORTA_PIN6_VAL		HIGH 
#elif PORTA_PIN6 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN6_DIR		INPUT
#define PORTA_PIN6_VAL		LOW
#elif PORTA_PIN6 == OUTPUT_LOW
#define PORTA_PIN6_DIR		OUTPUT
#define PORTA_PIN6_VAL		LOW
#elif PORTA_PIN6 == OUTPUT_HIGH
#define PORTA_PIN6_DIR		OUTPUT
#define PORTA_PIN6_VAL		HIGH
#else
#error "PORTA_PIN6: Invalid pin configuration."
#endif

#if PORTA_PIN7 == INPUT_EXTERNAL_PULLUP
#define PORTA_PIN7_DIR		INPUT
#define PORTA_PIN7_VAL		LOW
#elif PORTA_PIN7 == INPUT_INTERNAL_PULLUP
#define PORTA_PIN7_DIR		INPUT
#define PORTA_PIN7_VAL		HIGH 
#elif PORTA_PIN7 == INPUT_EXTERNAL_PULLDOWN
#define PORTA_PIN7_DIR		INPUT
#define PORTA_PIN7_VAL		LOW
#elif PORTA_PIN7 == OUTPUT_LOW
#define PORTA_PIN7_DIR		OUTPUT
#define PORTA_PIN7_VAL		LOW
#elif PORTA_PIN7 == OUTPUT_HIGH
#define PORTA_PIN7_DIR		OUTPUT
#define PORTA_PIN7_VAL		HIGH
#else
#error "PORTA_PIN7: Invalid pin configuration."
#endif

#endif
#if NUMBER_OF_PORTS > ONE_PORT

#if PORTB_PIN0 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN0_DIR		INPUT
#define PORTB_PIN0_VAL		LOW
#elif PORTB_PIN0 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN0_DIR		INPUT
#define PORTB_PIN0_VAL		HIGH 
#elif PORTB_PIN0 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN0_DIR		INPUT
#define PORTB_PIN0_VAL		LOW
#elif PORTB_PIN0 == OUTPUT_LOW
#define PORTB_PIN0_DIR		OUTPUT
#define PORTB_PIN0_VAL		LOW
#elif PORTB_PIN0 == OUTPUT_HIGH
#define PORTB_PIN0_DIR		OUTPUT
#define PORTB_PIN0_VAL		HIGH
#else
#error "PORTB_PIN0: Invalid pin configuration."
#endif

#if PORTB_PIN1 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN1_DIR		INPUT
#define PORTB_PIN1_VAL		LOW
#elif PORTB_PIN1 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN1_DIR		INPUT
#define PORTB_PIN1_VAL		HIGH 
#elif PORTB_PIN1 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN1_DIR		INPUT
#define PORTB_PIN1_VAL		LOW
#elif PORTB_PIN1 == OUTPUT_LOW
#define PORTB_PIN1_DIR		OUTPUT
#define PORTB_PIN1_VAL		LOW
#elif PORTB_PIN1 == OUTPUT_HIGH
#define PORTB_PIN1_DIR		OUTPUT
#define PORTB_PIN1_VAL		HIGH
#else
#error "PORTB_PIN1: Invalid pin configuration."
#endif

#if PORTB_PIN2 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN2_DIR		INPUT
#define PORTB_PIN2_VAL		LOW
#elif PORTB_PIN2 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN2_DIR		INPUT
#define PORTB_PIN2_VAL		HIGH 
#elif PORTB_PIN2 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN2_DIR		INPUT
#define PORTB_PIN2_VAL		LOW
#elif PORTB_PIN2 == OUTPUT_LOW
#define PORTB_PIN2_DIR		OUTPUT
#define PORTB_PIN2_VAL		LOW
#elif PORTB_PIN2 == OUTPUT_HIGH
#define PORTB_PIN2_DIR		OUTPUT
#define PORTB_PIN2_VAL		HIGH
#else
#error "PORTB_PIN2: Invalid pin configuration."
#endif


#if PORTB_PIN3 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN3_DIR		INPUT
#define PORTB_PIN3_VAL		LOW
#elif PORTB_PIN3 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN3_DIR		INPUT
#define PORTB_PIN3_VAL		HIGH 
#elif PORTB_PIN3 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN3_DIR		INPUT
#define PORTB_PIN3_VAL		LOW
#elif PORTB_PIN3 == OUTPUT_LOW
#define PORTB_PIN3_DIR		OUTPUT
#define PORTB_PIN3_VAL		LOW
#elif PORTB_PIN3 == OUTPUT_HIGH
#define PORTB_PIN3_DIR		OUTPUT
#define PORTB_PIN3_VAL		HIGH
#else
#error "PORTB_PIN3: Invalid pin configuration."
#endif

#if PORTB_PIN4 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN4_DIR		INPUT
#define PORTB_PIN4_VAL		LOW
#elif PORTB_PIN4 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN4_DIR		INPUT
#define PORTB_PIN4_VAL		HIGH 
#elif PORTB_PIN4 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN4_DIR		INPUT
#define PORTB_PIN4_VAL		LOW
#elif PORTB_PIN4 == OUTPUT_LOW
#define PORTB_PIN4_DIR		OUTPUT
#define PORTB_PIN4_VAL		LOW
#elif PORTB_PIN4 == OUTPUT_HIGH
#define PORTB_PIN4_DIR		OUTPUT
#define PORTB_PIN4_VAL		HIGH
#else
#error "PORTB_PIN4: Invalid pin configuration."
#endif

#if PORTB_PIN5 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN5_DIR		INPUT
#define PORTB_PIN5_VAL		LOW
#elif PORTB_PIN5 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN5_DIR		INPUT
#define PORTB_PIN5_VAL		HIGH 
#elif PORTB_PIN5 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN5_DIR		INPUT
#define PORTB_PIN5_VAL		LOW
#elif PORTB_PIN5 == OUTPUT_LOW
#define PORTB_PIN5_DIR		OUTPUT
#define PORTB_PIN5_VAL		LOW
#elif PORTB_PIN5 == OUTPUT_HIGH
#define PORTB_PIN5_DIR		OUTPUT
#define PORTB_PIN5_VAL		HIGH
#else
#error "PORTB_PIN5: Invalid pin configuration."
#endif

#if PORTB_PIN6 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN6_DIR		INPUT
#define PORTB_PIN6_VAL		LOW
#elif PORTB_PIN6 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN6_DIR		INPUT
#define PORTB_PIN6_VAL		HIGH 
#elif PORTB_PIN6 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN6_DIR		INPUT
#define PORTB_PIN6_VAL		LOW
#elif PORTB_PIN6 == OUTPUT_LOW
#define PORTB_PIN6_DIR		OUTPUT
#define PORTB_PIN6_VAL		LOW
#elif PORTB_PIN6 == OUTPUT_HIGH
#define PORTB_PIN6_DIR		OUTPUT
#define PORTB_PIN6_VAL		HIGH
#else
#error "PORTB_PIN6: Invalid pin configuration."
#endif

#if PORTB_PIN7 == INPUT_EXTERNAL_PULLUP
#define PORTB_PIN7_DIR		INPUT
#define PORTB_PIN7_VAL		LOW
#elif PORTB_PIN7 == INPUT_INTERNAL_PULLUP
#define PORTB_PIN7_DIR		INPUT
#define PORTB_PIN7_VAL		HIGH 
#elif PORTB_PIN7 == INPUT_EXTERNAL_PULLDOWN
#define PORTB_PIN7_DIR		INPUT
#define PORTB_PIN7_VAL		LOW
#elif PORTB_PIN7 == OUTPUT_LOW
#define PORTB_PIN7_DIR		OUTPUT
#define PORTB_PIN7_VAL		LOW
#elif PORTB_PIN7 == OUTPUT_HIGH
#define PORTB_PIN7_DIR		OUTPUT
#define PORTB_PIN7_VAL		HIGH
#else
#error "PORTB_PIN7: Invalid pin configuration."
#endif

#endif
#if NUMBER_OF_PORTS > TWO_PORTS

#if PORTC_PIN0 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN0_DIR		INPUT
#define PORTC_PIN0_VAL		LOW
#elif PORTC_PIN0 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN0_DIR		INPUT
#define PORTC_PIN0_VAL		HIGH 
#elif PORTC_PIN0 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN0_DIR		INPUT
#define PORTC_PIN0_VAL		LOW
#elif PORTC_PIN0 == OUTPUT_LOW
#define PORTC_PIN0_DIR		OUTPUT
#define PORTC_PIN0_VAL		LOW
#elif PORTC_PIN0 == OUTPUT_HIGH
#define PORTC_PIN0_DIR		OUTPUT
#define PORTC_PIN0_VAL		HIGH
#else
#error "PORTC_PIN0: Invalid pin configuration."
#endif

#if PORTC_PIN1 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN1_DIR		INPUT
#define PORTC_PIN1_VAL		LOW
#elif PORTC_PIN1 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN1_DIR		INPUT
#define PORTC_PIN1_VAL		HIGH 
#elif PORTC_PIN1 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN1_DIR		INPUT
#define PORTC_PIN1_VAL		LOW
#elif PORTC_PIN1 == OUTPUT_LOW
#define PORTC_PIN1_DIR		OUTPUT
#define PORTC_PIN1_VAL		LOW
#elif PORTC_PIN1 == OUTPUT_HIGH
#define PORTC_PIN1_DIR		OUTPUT
#define PORTC_PIN1_VAL		HIGH
#else
#error "PORTC_PIN1: Invalid pin configuration."
#endif

#if PORTC_PIN2 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN2_DIR		INPUT
#define PORTC_PIN2_VAL		LOW
#elif PORTC_PIN2 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN2_DIR		INPUT
#define PORTC_PIN2_VAL		HIGH 
#elif PORTC_PIN2 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN2_DIR		INPUT
#define PORTC_PIN2_VAL		LOW
#elif PORTC_PIN2 == OUTPUT_LOW
#define PORTC_PIN2_DIR		OUTPUT
#define PORTC_PIN2_VAL		LOW
#elif PORTC_PIN2 == OUTPUT_HIGH
#define PORTC_PIN2_DIR		OUTPUT
#define PORTC_PIN2_VAL		HIGH
#else
#error "PORTC_PIN2: Invalid pin configuration."
#endif


#if PORTC_PIN3 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN3_DIR		INPUT
#define PORTC_PIN3_VAL		LOW
#elif PORTC_PIN3 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN3_DIR		INPUT
#define PORTC_PIN3_VAL		HIGH 
#elif PORTC_PIN3 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN3_DIR		INPUT
#define PORTC_PIN3_VAL		LOW
#elif PORTC_PIN3 == OUTPUT_LOW
#define PORTC_PIN3_DIR		OUTPUT
#define PORTC_PIN3_VAL		LOW
#elif PORTC_PIN3 == OUTPUT_HIGH
#define PORTC_PIN3_DIR		OUTPUT
#define PORTC_PIN3_VAL		HIGH
#else
#error "PORTC_PIN3: Invalid pin configuration."
#endif

#if PORTC_PIN4 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN4_DIR		INPUT
#define PORTC_PIN4_VAL		LOW
#elif PORTC_PIN4 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN4_DIR		INPUT
#define PORTC_PIN4_VAL		HIGH 
#elif PORTC_PIN4 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN4_DIR		INPUT
#define PORTC_PIN4_VAL		LOW
#elif PORTC_PIN4 == OUTPUT_LOW
#define PORTC_PIN4_DIR		OUTPUT
#define PORTC_PIN4_VAL		LOW
#elif PORTC_PIN4 == OUTPUT_HIGH
#define PORTC_PIN4_DIR		OUTPUT
#define PORTC_PIN4_VAL		HIGH
#else
#error "PORTC_PIN4: Invalid pin configuration."
#endif

#if PORTC_PIN5 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN5_DIR		INPUT
#define PORTC_PIN5_VAL		LOW
#elif PORTC_PIN5 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN5_DIR		INPUT
#define PORTC_PIN5_VAL		HIGH 
#elif PORTC_PIN5 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN5_DIR		INPUT
#define PORTC_PIN5_VAL		LOW
#elif PORTC_PIN5 == OUTPUT_LOW
#define PORTC_PIN5_DIR		OUTPUT
#define PORTC_PIN5_VAL		LOW
#elif PORTC_PIN5 == OUTPUT_HIGH
#define PORTC_PIN5_DIR		OUTPUT
#define PORTC_PIN5_VAL		HIGH
#else
#error "PORTC_PIN5: Invalid pin configuration."
#endif

#if PORTC_PIN6 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN6_DIR		INPUT
#define PORTC_PIN6_VAL		LOW
#elif PORTC_PIN6 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN6_DIR		INPUT
#define PORTC_PIN6_VAL		HIGH 
#elif PORTC_PIN6 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN6_DIR		INPUT
#define PORTC_PIN6_VAL		LOW
#elif PORTC_PIN6 == OUTPUT_LOW
#define PORTC_PIN6_DIR		OUTPUT
#define PORTC_PIN6_VAL		LOW
#elif PORTC_PIN6 == OUTPUT_HIGH
#define PORTC_PIN6_DIR		OUTPUT
#define PORTC_PIN6_VAL		HIGH
#else
#error "PORTC_PIN6: Invalid pin configuration."
#endif

#if PORTC_PIN7 == INPUT_EXTERNAL_PULLUP
#define PORTC_PIN7_DIR		INPUT
#define PORTC_PIN7_VAL		LOW
#elif PORTC_PIN7 == INPUT_INTERNAL_PULLUP
#define PORTC_PIN7_DIR		INPUT
#define PORTC_PIN7_VAL		HIGH 
#elif PORTC_PIN7 == INPUT_EXTERNAL_PULLDOWN
#define PORTC_PIN7_DIR		INPUT
#define PORTC_PIN7_VAL		LOW
#elif PORTC_PIN7 == OUTPUT_LOW
#define PORTC_PIN7_DIR		OUTPUT
#define PORTC_PIN7_VAL		LOW
#elif PORTC_PIN7 == OUTPUT_HIGH
#define PORTC_PIN7_DIR		OUTPUT
#define PORTC_PIN7_VAL		HIGH
#else
#error "PORTC_PIN7: Invalid pin configuration."
#endif

#endif

#if NUMBER_OF_PORTS > THREE_PORTS

#if PORTD_PIN0 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN0_DIR		INPUT
#define PORTD_PIN0_VAL		LOW
#elif PORTD_PIN0 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN0_DIR		INPUT
#define PORTD_PIN0_VAL		HIGH 
#elif PORTD_PIN0 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN0_DIR		INPUT
#define PORTD_PIN0_VAL		LOW
#elif PORTD_PIN0 == OUTPUT_LOW
#define PORTD_PIN0_DIR		OUTPUT
#define PORTD_PIN0_VAL		LOW
#elif PORTD_PIN0 == OUTPUT_HIGH
#define PORTD_PIN0_DIR		OUTPUT
#define PORTD_PIN0_VAL		HIGH
#else
#error "PORTD_PIN0: Invalid pin configuration."
#endif

#if PORTD_PIN1 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN1_DIR		INPUT
#define PORTD_PIN1_VAL		LOW
#elif PORTD_PIN1 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN1_DIR		INPUT
#define PORTD_PIN1_VAL		HIGH 
#elif PORTD_PIN1 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN1_DIR		INPUT
#define PORTD_PIN1_VAL		LOW
#elif PORTD_PIN1 == OUTPUT_LOW
#define PORTD_PIN1_DIR		OUTPUT
#define PORTD_PIN1_VAL		LOW
#elif PORTD_PIN1 == OUTPUT_HIGH
#define PORTD_PIN1_DIR		OUTPUT
#define PORTD_PIN1_VAL		HIGH
#else
#error "PORTD_PIN1: Invalid pin configuration."
#endif

#if PORTD_PIN2 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN2_DIR		INPUT
#define PORTD_PIN2_VAL		LOW
#elif PORTD_PIN2 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN2_DIR		INPUT
#define PORTD_PIN2_VAL		HIGH 
#elif PORTD_PIN2 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN2_DIR		INPUT
#define PORTD_PIN2_VAL		LOW
#elif PORTD_PIN2 == OUTPUT_LOW
#define PORTD_PIN2_DIR		OUTPUT
#define PORTD_PIN2_VAL		LOW
#elif PORTD_PIN2 == OUTPUT_HIGH
#define PORTD_PIN2_DIR		OUTPUT
#define PORTD_PIN2_VAL		HIGH
#else
#error "PORTD_PIN2: Invalid pin configuration."
#endif


#if PORTD_PIN3 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN3_DIR		INPUT
#define PORTD_PIN3_VAL		LOW
#elif PORTD_PIN3 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN3_DIR		INPUT
#define PORTD_PIN3_VAL		HIGH 
#elif PORTD_PIN3 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN3_DIR		INPUT
#define PORTD_PIN3_VAL		LOW
#elif PORTD_PIN3 == OUTPUT_LOW
#define PORTD_PIN3_DIR		OUTPUT
#define PORTD_PIN3_VAL		LOW
#elif PORTD_PIN3 == OUTPUT_HIGH
#define PORTD_PIN3_DIR		OUTPUT
#define PORTD_PIN3_VAL		HIGH
#else
#error "PORTD_PIN3: Invalid pin configuration."
#endif

#if PORTD_PIN4 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN4_DIR		INPUT
#define PORTD_PIN4_VAL		LOW
#elif PORTD_PIN4 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN4_DIR		INPUT
#define PORTD_PIN4_VAL		HIGH 
#elif PORTD_PIN4 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN4_DIR		INPUT
#define PORTD_PIN4_VAL		LOW
#elif PORTD_PIN4 == OUTPUT_LOW
#define PORTD_PIN4_DIR		OUTPUT
#define PORTD_PIN4_VAL		LOW
#elif PORTD_PIN4 == OUTPUT_HIGH
#define PORTD_PIN4_DIR		OUTPUT
#define PORTD_PIN4_VAL		HIGH
#else
#error "PORTD_PIN4: Invalid pin configuration."
#endif

#if PORTD_PIN5 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN5_DIR		INPUT
#define PORTD_PIN5_VAL		LOW
#elif PORTD_PIN5 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN5_DIR		INPUT
#define PORTD_PIN5_VAL		HIGH 
#elif PORTD_PIN5 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN5_DIR		INPUT
#define PORTD_PIN5_VAL		LOW
#elif PORTD_PIN5 == OUTPUT_LOW
#define PORTD_PIN5_DIR		OUTPUT
#define PORTD_PIN5_VAL		LOW
#elif PORTD_PIN5 == OUTPUT_HIGH
#define PORTD_PIN5_DIR		OUTPUT
#define PORTD_PIN5_VAL		HIGH
#else
#error "PORTD_PIN5: Invalid pin configuration."
#endif

#if PORTD_PIN6 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN6_DIR		INPUT
#define PORTD_PIN6_VAL		LOW
#elif PORTD_PIN6 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN6_DIR		INPUT
#define PORTD_PIN6_VAL		HIGH 
#elif PORTD_PIN6 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN6_DIR		INPUT
#define PORTD_PIN6_VAL		LOW
#elif PORTD_PIN6 == OUTPUT_LOW
#define PORTD_PIN6_DIR		OUTPUT
#define PORTD_PIN6_VAL		LOW
#elif PORTD_PIN6 == OUTPUT_HIGH
#define PORTD_PIN6_DIR		OUTPUT
#define PORTD_PIN6_VAL		HIGH
#else
#error "PORTD_PIN6: Invalid pin configuration."
#endif

#if PORTD_PIN7 == INPUT_EXTERNAL_PULLUP
#define PORTD_PIN7_DIR		INPUT
#define PORTD_PIN7_VAL		LOW
#elif PORTD_PIN7 == INPUT_INTERNAL_PULLUP
#define PORTD_PIN7_DIR		INPUT
#define PORTD_PIN7_VAL		HIGH 
#elif PORTD_PIN7 == INPUT_EXTERNAL_PULLDOWN
#define PORTD_PIN7_DIR		INPUT
#define PORTD_PIN7_VAL		LOW
#elif PORTD_PIN7 == OUTPUT_LOW
#define PORTD_PIN7_DIR		OUTPUT
#define PORTD_PIN7_VAL		LOW
#elif PORTD_PIN7 == OUTPUT_HIGH
#define PORTD_PIN7_DIR		OUTPUT
#define PORTD_PIN7_VAL		HIGH
#else
#error "PORTD_PIN7: Invalid pin configuration."
#endif /* PORTD_PIN7 Configuration */

#endif /* NUMBER_OF_PORTS > THREE_PORTS */
#endif 


#define DDRA_CONFIGURATION		CONC(PORTA_PIN0_DIR,PORTA_PIN1_DIR,PORTA_PIN2_DIR,PORTA_PIN3_DIR,PORTA_PIN4_DIR,PORTA_PIN5_DIR,PORTA_PIN6_DIR,PORTA_PIN7_DIR)
#define DDRB_CONFIGURATION		CONC(PORTB_PIN0_DIR,PORTB_PIN1_DIR,PORTB_PIN2_DIR,PORTB_PIN3_DIR,PORTB_PIN4_DIR,PORTB_PIN5_DIR,PORTB_PIN6_DIR,PORTB_PIN7_DIR)
#define DDRC_CONFIGURATION		CONC(PORTC_PIN0_DIR,PORTC_PIN1_DIR,PORTC_PIN2_DIR,PORTC_PIN3_DIR,PORTC_PIN4_DIR,PORTC_PIN5_DIR,PORTC_PIN6_DIR,PORTC_PIN7_DIR)
#define DDRD_CONFIGURATION		CONC(PORTD_PIN0_DIR,PORTD_PIN1_DIR,PORTD_PIN2_DIR,PORTD_PIN3_DIR,PORTD_PIN4_DIR,PORTD_PIN5_DIR,PORTD_PIN6_DIR,PORTD_PIN7_DIR)

#define PORTA_CONFIGURATION		CONC(PORTA_PIN0_VAL,PORTA_PIN1_VAL,PORTA_PIN2_VAL,PORTA_PIN3_VAL,PORTA_PIN4_VAL,PORTA_PIN5_VAL,PORTA_PIN6_VAL,PORTA_PIN7_VAL)
#define PORTB_CONFIGURATION		CONC(PORTB_PIN0_VAL,PORTB_PIN1_VAL,PORTB_PIN2_VAL,PORTB_PIN3_VAL,PORTB_PIN4_VAL,PORTB_PIN5_VAL,PORTB_PIN6_VAL,PORTB_PIN7_VAL)
#define PORTC_CONFIGURATION		CONC(PORTC_PIN0_VAL,PORTC_PIN1_VAL,PORTC_PIN2_VAL,PORTC_PIN3_VAL,PORTC_PIN4_VAL,PORTC_PIN5_VAL,PORTC_PIN6_VAL,PORTC_PIN7_VAL)
#define PORTD_CONFIGURATION		CONC(PORTD_PIN0_VAL,PORTD_PIN1_VAL,PORTD_PIN2_VAL,PORTD_PIN3_VAL,PORTD_PIN4_VAL,PORTD_PIN5_VAL,PORTD_PIN6_VAL,PORTD_PIN7_VAL)


#if CONFIG_TIME == POST_BUILD_CONFIG
extern u8 PORT_u8PinConfigArr[NUMBER_OF_PORTS][PINS_PER_PORT];
#endif

/**
 * @brief Function to initialize all I/O ports on the target HW
 *		  according to user configuration
 *
 * @return void
 */
void PORT_voidInit(void)
{
#if CONFIG_TIME == PRE_BUILD_CONFIG

#if NUMBER_OF_PORTS > ZERO
	pstrPortArr[PORTA]->DDR = DDRA_CONFIGURATION;		/* Set PortA DDR register as configured */
	pstrPortArr[PORTA]->PORT = PORTA_CONFIGURATION;		/* Set PortA PORT register as configured */
#endif

#if NUMBER_OF_PORTS > ONE_PORT
	pstrPortArr[PORTB]->DDR = DDRB_CONFIGURATION;		 /* Set PortB DDR register as configured */
	pstrPortArr[PORTB]->PORT = PORTB_CONFIGURATION;		 /* Set PortB PORT register as configured */
#endif

#if NUMBER_OF_PORTS > TWO_PORTS
	pstrPortArr[PORTC]->DDR = DDRC_CONFIGURATION;		/* Set PortC DDR register as configured */
	pstrPortArr[PORTC]->PORT = PORTC_CONFIGURATION;		/* Set PortC PORT register as configured */
#endif

#if NUMBER_OF_PORTS > THREE_PORTS
	pstrPortArr[PORTD]->DDR = DDRD_CONFIGURATION;		/* Set PortD DDR register as configured */
	pstrPortArr[PORTD]->PORT = PORTD_CONFIGURATION;		/* Set PortD PORT register as configured */
#endif

#elif CONFIG_TIME == POST_BUILD_CONFIG 
	u8 Loc_u8PortIterator = ZERO;
	u8 Loc_u8PinIterator = ZERO;

	for (Loc_u8PortIterator; Loc_u8PortIterator < NUMBER_OF_PORTS; Loc_u8PortIterator++)
	{
		for (Loc_u8PinIterator = ZERO; Loc_u8PinIterator < PINS_PER_PORT; Loc_u8PinIterator++)
		{
			/* Get the direction bit from the pin configuration */
			if (GET_BIT(PORT_u8PinConfigArr[Loc_u8PortIterator][Loc_u8PinIterator], DIR_BIT))
			{
				/* Configure the pin as an output pin */
				SET_BIT(pstrPortArr[Loc_u8PortIterator]->DDR, Loc_u8PinIterator);
			}
			else
			{
				/* Configure the pin as an input pin */
				CLR_BIT(pstrPortArr[Loc_u8PortIterator]->DDR, Loc_u8PinIterator);
			}

			/* Get the value bit from the pin configuration */
			if (GET_BIT(PORT_u8PinConfigArr[Loc_u8PortIterator][Loc_u8PinIterator], VAL_BIT))
			{
				SET_BIT(pstrPortArr[Loc_u8PortIterator]->PORT, Loc_u8PinIterator);
			}
			else
			{
				CLR_BIT(pstrPortArr[Loc_u8PortIterator]->PORT, Loc_u8PinIterator);
			}

		}
	}
#endif
}

/**
 * @brief							: Configure a DIO pin direction
 *
 * @param[in] Copy_enumPort			: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param[in] Copy_enumPin			: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param[in] Copy_enumPinConfig	: The desired configuration, Options: DIO_enumOutput
 *																		  DIO_enumInputFloating
 *																		  DIO_enumInputPullup
 *
 * @return CMN_enumStatusCode_t	: PORT_enumOk			   : Pin Configuration set successfully
 *									  PORT_enumInvalidPort	   : Invalid port number
 *								      PORT_enumInvalidPin	   : Invalid pin number
 *									  PORT_enumInvalidConfig   : Invalid pin configuration
 */
CMN_enumStatusCode_t PORT_enumSetPinConfiguration(u8 Copy_enumPort, u8 Copy_enumPin, u8 Copy_enumPinConfig)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = PORT_enumStatusOk;

	if (Copy_enumPort >= NUMBER_OF_PORTS)
	{
		Loc_enumErrorStatus = PORT_enumInvalidPort;
	}
	else if (Copy_enumPin >= PINS_PER_PORT)
	{
		Loc_enumErrorStatus = PORT_enumInvalidPin;
	}
	else
	{
		switch (Copy_enumPinConfig)
		{
		case INPUT_EXTERNAL_PULLDOWN:
		case INPUT_EXTERNAL_PULLUP:
			CLR_BIT(pstrPortArr[Copy_enumPort]->DDR, Copy_enumPin);
			break;

		case INPUT_INTERNAL_PULLUP:
			CLR_BIT(pstrPortArr[Copy_enumPort]->DDR, Copy_enumPin);	/* Configure the pin as input */
			SET_BIT(pstrPortArr[Copy_enumPort]->PORT, Copy_enumPin);  /* Enable pull up resistor */
			break;

		case OUTPUT_HIGH:
			SET_BIT(pstrPortArr[Copy_enumPort]->DDR, Copy_enumPin);
			SET_BIT(pstrPortArr[Copy_enumPort]->PORT, Copy_enumPin);  /* Set initial state */
			break;

		case OUTPUT_LOW:
			SET_BIT(pstrPortArr[Copy_enumPort]->DDR, Copy_enumPin);
			CLR_BIT(pstrPortArr[Copy_enumPort]->PORT, Copy_enumPin);  /* Set initial state */
			break;

		default: Loc_enumErrorStatus = PORT_enumInvalidConfig;	break;
		}
	}

	return Loc_enumErrorStatus;
}
