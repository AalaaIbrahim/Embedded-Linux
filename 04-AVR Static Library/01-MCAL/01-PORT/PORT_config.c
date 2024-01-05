/**
 * @file	PORT_config.c
 * @author  Alaa Hisham
 * @brief   Post build configurations for all pins on the target
 * @version 0.1
 * @date    2-12-2023
 */ 

#include "STD_TYPES.h"

#include "PORT.h"
#include "PORT_config.h"


#if CONFIG_TIME == POST_BUILD_CONFIG	

u8 PORT_u8PinConfigArr[NUMBER_OF_PORTS][PINS_PER_PORT] =
{
	#if NUMBER_OF_PORTS > FOUR_PORTS
		#error "Unsupported Port Number!"
	#else
		#if NUMBER_OF_PORTS > ZERO
		{
			/* Port A, Pin 0 */ OUTPUT_LOW				,
			/* Port A, Pin 1 */ OUTPUT_LOW				,
			/* Port A, Pin 2 */ OUTPUT_LOW				,
			/* Port A, Pin 3 */ OUTPUT_LOW				,
			/* Port A, Pin 4 */ OUTPUT_LOW				,
			/* Port A, Pin 5 */ OUTPUT_LOW				,
			/* Port A, Pin 6 */ OUTPUT_LOW				,
			/* Port A, Pin 7 */ OUTPUT_LOW
		}
		#endif
		#if NUMBER_OF_PORTS > ONE_PORT
		,{
			/* Port B, Pin 0 */ OUTPUT_LOW				,
			/* Port B, Pin 1 */ OUTPUT_LOW				,
			/* Port B, Pin 2 */ OUTPUT_LOW				,
			/* Port B, Pin 3 */ OUTPUT_LOW				,
			/* Port B, Pin 4 */ OUTPUT_LOW				,
			/* Port B, Pin 5 */ OUTPUT_LOW				,
			/* Port B, Pin 6 */ OUTPUT_LOW				,
			/* Port B, Pin 7 */ OUTPUT_LOW
		}
		#endif
		#if NUMBER_OF_PORTS > TWO_PORTS
		,{
			/* Port C, Pin 0 */ OUTPUT_LOW				,
			/* Port C, Pin 1 */ INPUT_INTERNAL_PULLUP	,
			/* Port C, Pin 2 */ OUTPUT_LOW				,
			/* Port C, Pin 3 */ OUTPUT_LOW				,
			/* Port C, Pin 4 */ OUTPUT_LOW				,
			/* Port C, Pin 5 */ OUTPUT_LOW				,
			/* Port C, Pin 6 */ OUTPUT_LOW				,
			/* Port C, Pin 7 */ OUTPUT_LOW
		}
		#endif
		#if NUMBER_OF_PORTS > THREE_PORTS
		,{
			/* Port D, Pin 0 */ OUTPUT_LOW				,
			/* Port D, Pin 1 */ OUTPUT_LOW				,
			/* Port D, Pin 2 */ OUTPUT_LOW				,
			/* Port D, Pin 3 */ OUTPUT_LOW				,
			/* Port D, Pin 4 */ OUTPUT_LOW				,
			/* Port D, Pin 5 */ OUTPUT_LOW				,
			/* Port D, Pin 6 */ OUTPUT_LOW				,
			/* Port D, Pin 7 */ OUTPUT_LOW
		}
		#endif
	#endif
};

#endif
