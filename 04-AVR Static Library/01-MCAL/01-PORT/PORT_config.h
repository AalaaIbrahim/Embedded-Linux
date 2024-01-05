 /**
 * @file	PORT_config.h
 * @author  Alaa Hisham
 * @brief   Pre-build configuration file for the initial
 *			state of all I/O pins.
 * @version 0.1
 * @date    2-12-2023
 *
 */ 


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

 /**
 * The number of ports on the target hardware
 * Options:		OnePort
 *				TwoPorts
 *				ThreePorts
 *				FourPorts
 *				FivePorts
 *				SixPorts
 */ 			
#define	NUMBER_OF_PORTS		FOUR_PORTS

 /**
 * The number of pins on each port on the target hardware
 * Options:		2_Pins
 *				4_Pins
 *				8_Pins
 *				16_Pins
 *				32_Pins
 */ 			
#define	PINS_PER_PORT		_8_Pins

 /**
 * The configuration time of the I/O ports
 * Options:		PRE_BUILD_CONFIG
 *				POST_BUILD_CONFIG
 */ 	
#define CONFIG_TIME			POST_BUILD_CONFIG	

/*--------------------------------------------------------------------------*/

#if CONFIG_TIME == PRE_BUILD_CONFIG	

 /**
 * The configuration time of the I/O ports
 * Options:		CONFIG_BY_PORT	
 *				CONFIG_BY_PIN
 */ 	
#define CONFIG_TYPE			CONFIG_BY_PIN	

	#if CONFIG_TYPE == CONFIG_BY_PIN

/** 
 * Pin Initial States Configuration
 * Options:		INPUT_EXTERNAL_PULLUP
 *				INPUT_INTERNAL_PULLUP
 *				INPUT_EXTERNAL_PULLDOWN
 *				OUTPUT_HIGH
 *				OUTPUT_LOW
 */
		#if NUMBER_OF_PORTS > FOUR_PORTS
		#error "Unsupported Port Number!"
		#else
			#if NUMBER_OF_PORTS > ZERO
			
				#define PORTA_PIN0		OUTPUT_LOW
				#define PORTA_PIN1		OUTPUT_LOW
				#define PORTA_PIN2		OUTPUT_LOW
				#define PORTA_PIN3		OUTPUT_LOW
				#define PORTA_PIN4		OUTPUT_LOW
				#define PORTA_PIN5		OUTPUT_LOW
				#define PORTA_PIN6		OUTPUT_LOW
				#define PORTA_PIN7		OUTPUT_LOW
			
			#endif
			#if NUMBER_OF_PORTS > ONE_PORT
			
				#define PORTB_PIN0		OUTPUT_LOW
				#define PORTB_PIN1		OUTPUT_LOW
				#define PORTB_PIN2		OUTPUT_LOW
				#define PORTB_PIN3		OUTPUT_LOW
				#define PORTB_PIN4		OUTPUT_LOW
				#define PORTB_PIN5		OUTPUT_LOW
				#define PORTB_PIN6		OUTPUT_LOW
				#define PORTB_PIN7		OUTPUT_LOW
			
			#endif
			#if NUMBER_OF_PORTS > TWO_PORTS
			
				#define PORTC_PIN0		OUTPUT_LOW
				#define PORTC_PIN1		INPUT_INTERNAL_PULLUP
				#define PORTC_PIN2		OUTPUT_LOW
				#define PORTC_PIN3		OUTPUT_LOW
				#define PORTC_PIN4		OUTPUT_LOW
				#define PORTC_PIN5		OUTPUT_LOW
				#define PORTC_PIN6		OUTPUT_LOW
				#define PORTC_PIN7		OUTPUT_LOW
			
			#endif
			#if NUMBER_OF_PORTS > THREE_PORTS
			
				#define PORTD_PIN0		OUTPUT_LOW
				#define PORTD_PIN1		OUTPUT_LOW
				#define PORTD_PIN2		OUTPUT_LOW
				#define PORTD_PIN3		OUTPUT_LOW
				#define PORTD_PIN4		OUTPUT_LOW
				#define PORTD_PIN5		OUTPUT_LOW
				#define PORTD_PIN6		OUTPUT_LOW
				#define PORTD_PIN7		OUTPUT_LOW
			
			#endif
		#endif
		
	#elif CONFIG_TYPE == CONFIG_BY_PORT

/**
 * Port Initial State Configurations
 * Options:		
 *		PORTx_DIR : 0 bit -> input pin		
 *					1 bit -> output pin
 *				
 *		PORTx_INIT_VALUE:
 *				 0 bit -> (if output) low 
 *				          (if input ) internal pull-up disabled 	
 *				 1 bit -> (if output) high 
 *				          (if input ) internal pull-up enabled	
 */	
			
		#if NUMBER_OF_PORTS > FOUR_PORTS
			#error "Unsupported Port Number!"
		#else
			#if NUMBER_OF_PORTS > ZERO
				
				#define PORTA_DIR			0b11111111
				#define PORTA_INIT_VALUE	0b00000000
				
			#endif
			#if NUMBER_OF_PORTS > ONE_PORT
			
				#define PORTB_DIR			0b11111111
				#define PORTB_INIT_VALUE	0b00000000
				
			#endif
			#if NUMBER_OF_PORTS > TWO_PORTS
			
				#define PORTC_DIR			0b11111111
				#define PORTC_INIT_VALUE	0b00000000
				
			#endif
			#if NUMBER_OF_PORTS > THREE_PORTS
			
				#define PORTD_DIR			0b11111111
				#define PORTD_INIT_VALUE	0b00000000
			
			#endif
		#endif
	
	#endif
	
#endif

#endif /* PORT_CONFIG_H_ */