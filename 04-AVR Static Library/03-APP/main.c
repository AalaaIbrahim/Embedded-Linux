 /**
 * @file    TASK2.h
 * @author  Alaa Hisham
 * @brief   application to display the binary value of the number of 
 *			push button presses on 4 LEDs
 * @version 1.1
 * @date    27-11-2023
 *
 */ 

#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO.h"
#include "PORT.h"


/* State Options */
#define  ACTIVATED	1
#define  DEACTIVATED	0

/* Configurations */
#define  SWITCH_PULL_UP ACTIVATED


#if   SWITCH_PULL_UP == ACTIVATED
	#define PRESSED 0
	#define NOT_PRESSED 1
#else
	#define PRESSED 1
	#define NOT_PRESSED 0
#endif

/* LED pins (all on port B) */
#define LED_PORT	DIO_enumPortB
#define LED1_PIN	DIO_enumPin0
#define LED2_PIN	DIO_enumPin1
#define LED3_PIN	DIO_enumPin2
#define LED4_PIN	DIO_enumPin3

/* Switch pin (on port C) */
#define  SWITCH_PORT	DIO_enumPortC
#define  SWITCH_PIN	DIO_enumPin1


void TASK2(void)
{
	u8 Loc_u8SwitchValue, Loc_u8Counter=0;

	/* Initialize all target ports */
	PORT_voidInit();
	
    while (1) 
    {
		/* Get the switch state */
		DIO_enumGetPin(SWITCH_PORT, SWITCH_PIN, (DIO_enumValue_t*)&Loc_u8SwitchValue);
		
		if(PRESSED == Loc_u8SwitchValue)
		{
			/* increment the number of presses */
			Loc_u8Counter++;
			
			DIO_enumSetPort(LED_PORT, Loc_u8Counter);
			
			/* Delay for debouncing */
			DELAY_ms(300);
		}

    }
}

