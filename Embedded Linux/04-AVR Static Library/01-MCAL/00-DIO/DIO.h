/**
 * @file    DIO.h
 * @author  Alaa Hisham
 * @brief   User interface for the DIO module
 * @version 1.1
 * @date    11/25/2023
 */

#ifndef DIO_H_
#define DIO_H_

#include "../../00-LIB/Common.h"

typedef enum
{
	DIO_enumPortA,
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
}DIO_enumPort_t;

typedef enum
{
	DIO_enumPin0,
	DIO_enumPin1,
	DIO_enumPin2,
	DIO_enumPin3,
	DIO_enumPin4,
	DIO_enumPin5,
	DIO_enumPin6,
	DIO_enumPin7
}DIO_enumPin_t;

typedef enum
{
	DIO_enumOutput,
	DIO_enumInputFloating,
	DIO_enumInputPullup
}DIO_enumConfig_t;

typedef enum
{
	DIO_enumLow,
	DIO_enumHigh
}DIO_enumValue_t;


/*=============================================================================================*/
/*									 Function Prototypes						    		   */
/*=============================================================================================*/

/**
 * @brief						 : Set direction Configuration for an entire port
 *
 * @param Copy_enumPort			 : The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param Copy_u8PortConfig		 : The desired configuration, Options: Any 8-bit number
 *
 * @return CMN_enumStatusCode_t :  DIO_enumStatusOk			: Port Configuration set successfully
 *								   DIO_enumInvalidPort		: Invalid port number
 */
CMN_enumStatusCode_t DIO_enumSetPortConfiguration(DIO_enumPort_t Copy_enumPort, u8 Copy_u8PortConfig);

/**
 * @brief					: Set the value of an output pin
 *
 * @param Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param Copy_enumPin		: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param Copy_enumPinValue	: The desired pin value    , Options: DIO_enumLow, DIO_enumHigh
 *
 * @return CMN_enumStatusCode_t : DIO_enumStatusOk	   : Pin Value set successfully
 *								  DIO_enumInvalidPort  : Invalid port number
 *								  DIO_enumInvalidPin   : Invalid pin number
 *								  DIO_enumInvalidValue : Invalid pin value (neither DIO_enumLow nor DIO_enumHigh)
 *								  DIO_enumInvalidConfig: If the pin is not an output pin
 */
CMN_enumStatusCode_t DIO_enumSetPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin, DIO_enumValue_t Copy_enumPinValue);

/**
 * @brief					: Set the value of an entire output port
 *
 * @param Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param Copy_u8PortValue	: The desired port value   , Options: Any 8-bit number
 *
 * @return CMN_enumStatusCode_t : DIO_enumStatusOk	   : Port Value set successfully
 *								  DIO_enumInvalidPort  : Invalid port number
 *								  DIO_enumInvalidConfig: If the port is not an output port
 */
CMN_enumStatusCode_t DIO_enumSetPort(DIO_enumPort_t Copy_enumPort, u8 Copy_u8PortValue);

/**
 * @brief					: Get the value of a DIO pin
 *
 * @param Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param Copy_enumPin		: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param Add_enumPinValue	: The address of a variable to store the pin value
 *
 * @return CMN_enumStatusCode_t : DIO_enumStatusOk	   : Pin Value set successfully
 *								  DIO_enumInvalidPort  : Invalid port number
 *								  DIO_enumInvalidPin   : Invalid pin number
 *								  DIO_enumNullPtr	   : If the passed address is a null pointer
 */
CMN_enumStatusCode_t DIO_enumGetPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin, DIO_enumValue_t* Add_penuPinValue);


#endif /* DIO_H_ */
