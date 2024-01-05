/**
* @file	PORT.h
* @author  Alaa Hisham
* @brief   Provides user interface for using the
*			I/O pin initialization capabilities
* @version 1.1
* @date    2-12-2023
*/


#ifndef PORT_H_
#define PORT_H_

#include "../../00-LIB/Common.h"

/* Configuration time options */
#define PRE_BUILD_CONFIG	1
#define POST_BUILD_CONFIG	2

/* Pre-build configuration type options */
#define CONFIG_BY_PORT		1
#define CONFIG_BY_PIN		2

/* Number of I/O ports configuration options */
#define ZERO_PORTS			0
#define ONE_PORT			1
#define TWO_PORTS			2
#define THREE_PORTS			3
#define FOUR_PORTS			4


typedef enum
{
	_2_Pins = 2,
	_4_Pins = 4,
	_8_Pins = 8,
	_16_Pins = 16,
	_32_Pins = 32
}PORT_enumPinsPerPort_t;


#define	INPUT_EXTERNAL_PULLUP		  0b000
#define	INPUT_INTERNAL_PULLUP		  0b010
#define	INPUT_EXTERNAL_PULLDOWN		  0b100
#define	OUTPUT_HIGH					  0b011
#define	OUTPUT_LOW					  0b001

/**
 * @brief Function to initialize all I/O ports on the target HW
 *		  according to user configuration
 *
 * @return void
 */
void PORT_voidInit(void);

/**
 * @brief							: Configure a DIO pin direction
 *
 * @param[in] Copy_enumPort			: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param[in] Copy_enumPin			: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param[in] Copy_enumPinConfig	: The desired configuration, Options: DIO_enumOutput
 *																  DIO_enumInputFloating
 *																  DIO_enumInputPullup
 *
 * @return CMN_enumStatusCode_t		: PORT_enumOk			   : Pin Configuration set successfully
 *									  PORT_enumInvalidPort	   : Invalid port number
 *								      PORT_enumInvalidPin	   : Invalid pin number
 *									  PORT_enumInvalidConfig   : Invalid pin configuration
 */
CMN_enumStatusCode_t PORT_enumSetPinConfiguration(u8 Copy_enumPort, u8 Copy_enumPin, u8 Copy_enumPinConfig);


#endif /* PORT_H_ */
