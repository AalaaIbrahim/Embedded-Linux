/**
 * @file    DIO.c
 * @author  Alaa Hisham
 * @brief   Contains API definitions for DIO peripheral
 * @version 1.1
 * @date    11/25/2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_register.h"
#include "PORT.h"
#include "PORT_config.h"
#include "DIO.h"

 /*=============================================================================================*/
 /*								 Private Function Prototypes					               */
 /*=============================================================================================*/
 /**
  * @brief 					: Validate that the port and pin numbers are not out of range
  *
  * @param[in] Copy_enumPort: The port to check
  * @param[in] Copy_enumPin : The pin to check
  *
  * @return CMN_enumStatusCode_t
  */
static CMN_enumStatusCode_t enuValidatePortPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin);

/**
 * @brief 					: A function to check validate the pin's configuration
 *
 * @param[in] Copy_enumPort: The port of the pin
 * @param[in] Copy_enumPin : The pin to check
 *
 * @return CMN_enumStatusCode_t
 */
static CMN_enumStatusCode_t enuCheckPinConfig(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin);

/*=============================================================================================*/
/*								Pubic Function Implementation					    		   */
/*=============================================================================================*/

/**
 * @brief						: Set the value of an output pin
 *
 * @param[in] Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param[in] Copy_enumPin		: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param[in] Copy_enumPinValue	: The desired pin value    , Options: DIO_enumLow, DIO_enumHigh
 *
 * @return CMN_enumStatusCode_t: DIO_enumStatusOk			   : Pin Value set successfully
 *								  DIO_enumInvalidPort	   : Invalid port number
 *								  DIO_enumInvalidPin	   : Invalid pin number
 *								  DIO_enumInvalidValue	   : Invalid pin value (neither DIO_enumLow nor DIO_enumHigh)
 *								  DIO_enumInvalidConfig	   : If the pin is not an output pin
 */
CMN_enumStatusCode_t DIO_enumSetPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin, DIO_enumValue_t Copy_enumPinValue)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = enuCheckPinConfig(Copy_enumPort, Copy_enumPin);

	if (DIO_enumStatusOk == Loc_enumErrorStatus)
	{
		if (DIO_enumHigh == Copy_enumPinValue)
		{
			/* Set the pin value to HIGH */
			SET_BIT(pstrPortArr[Copy_enumPort]->PORT, Copy_enumPin);
		}
		else if (DIO_enumLow == Copy_enumPinValue)
		{
			/* Set the pin value to LOW */
			CLR_BIT(pstrPortArr[Copy_enumPort]->PORT, Copy_enumPin);
		}
		else
		{
			Loc_enumErrorStatus = DIO_enumInvalidValue;
		}
	}
	else
	{
		/* Do Nothing */
	}

	return Loc_enumErrorStatus;
}

/**
 * @brief						: Set the value of an entire output port
 *
 * @param[in] Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param[in] Copy_u8PortValue	: The desired port value   , Options: Any 8-bit number
 *
 * @return CMN_enumStatusCode_t: DIO_enumStatusOk			   : Port Value set successfully
 *								  DIO_enumInvalidPort	   : Invalid port number
 */
CMN_enumStatusCode_t DIO_enumSetPort(DIO_enumPort_t Copy_enumPort, u8 Copy_u8PortValue)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = LED_enumStatusOk;

	if (Copy_enumPort >= 0 && Copy_enumPort <= NUMBER_OF_PORTS)
	{
		/* Set the Port register of the port to the given value */
		ASSIGN_REG(pstrPortArr[Copy_enumPort]->PORT, Copy_u8PortValue);
	}
	else
	{
		/* Do Nothing */
	}

	return Loc_enumErrorStatus;
}
/**
 * @brief							: Get the value of a DIO pin
 *
 * @param[in]  Copy_enumPort		: The port of the pin      , Options: DIO_enumPortA ... DIO_enumPortD
 * @param[in]  Copy_enumPin			: The pin to configure	   , Options: DIO_enumPin0 ... DIO_enumPin7
 * @param[out] Add_penumPinValue	: The address of a variable to store the pin value
 *
 * @return CMN_enumStatusCode_t	: DIO_enumStatusOk			   : Pin Value set successfully
 *									  DIO_enumInvalidPort	   : Invalid port number
 *									  DIO_enumInvalidPin	   : Invalid pin number
 *									  DIO_enumNullPtr		   : If the passed address is a null pointer
 */
CMN_enumStatusCode_t DIO_enumGetPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin, DIO_enumValue_t* Add_penumPinValue)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = DIO_enumStatusOk;

	/* Validate port and pin values */
	Loc_enumErrorStatus = enuValidatePortPin(Copy_enumPort, Copy_enumPin);

	if (DIO_enumStatusOk == Loc_enumErrorStatus)
	{
		if (NULL != Add_penumPinValue)
		{
			/* Store the pin value in the given address */
			*Add_penumPinValue = GET_BIT(pstrPortArr[Copy_enumPort]->PIN, Copy_enumPin);
		}
		else
		{
			Loc_enumErrorStatus = DIO_enumNullPtr;
		}
	}
	else
	{
		/* Do Nothing */
	}

	return Loc_enumErrorStatus;
}


/*=============================================================================================*/
/*								Private Function Implementations				    		   */
/*=============================================================================================*/
/**
 * @brief 			  : Validate that the port and pin numbers are not out of range
 *
 * @param Copy_enumPort: The port to check
 * @param Copy_enumPin : The pin to check
 *
 * @return CMN_enumStatusCode_t
 */
static CMN_enumStatusCode_t enuValidatePortPin(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = DIO_enumStatusOk;

	if (Copy_enumPort >= ZERO && Copy_enumPort <= NUMBER_OF_PORTS)
	{
		if (Copy_enumPin >= ZERO && Copy_enumPin <= PINS_PER_PORT)
		{
			/* Valid, Do Nothing */
		}
		else
		{
			Loc_enumErrorStatus = DIO_enumInvalidPin;
		}
	}
	else
	{
		Loc_enumErrorStatus = DIO_enumInvalidPort;
	}

	return Loc_enumErrorStatus;
}

/**
 * @brief 			  : Check if the pin is an output pin
 *
 * @param Copy_enumPort: The port of the pin
 * @param Copy_enumPin : The pin to check
 *
 * @return CMN_enumStatusCode_t
 */
static CMN_enumStatusCode_t enuCheckPinConfig(DIO_enumPort_t Copy_enumPort, DIO_enumPin_t Copy_enumPin)
{
	CMN_enumStatusCode_t Loc_enumErrorStatus = enuValidatePortPin(Copy_enumPort, Copy_enumPin);

	if (DIO_enumStatusOk == Loc_enumErrorStatus)
	{
		if (GET_BIT(pstrPortArr[Copy_enumPort]->DDR, Copy_enumPin))
		{
			/* Valid, Do Nothing */
		}
		else
		{
			Loc_enumErrorStatus = DIO_enumInvalidConfig;
		}
	}
	else
	{
		/* Do Nothing */
	}

	return Loc_enumErrorStatus;
}
