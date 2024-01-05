/**
 * @file    :   BTN.c
 * @author  :   Alaa Hisham
 * @brief   :   Contains Delay API Definitions
 * @version :   0.0
 * @date    :   15-12-2023
 */

#include "STD_TYPES.h"

#define F_CPU 8000000UL

/**
 * @brief				 : Function to apply a delay for a given period
 * 
 * @param Copy_u32TimeMs : The period to delay in milliseconds
 * 
 * @return void
 */
void DELAY_ms(u32 Copy_u32TimeMs)
{
	u32 Loc_u32DelayValue;
	u32 Loc_u32Iterator;
	
	Loc_u32DelayValue = (float)Copy_u32TimeMs*(F_CPU/(float)11300);
	
	for(Loc_u32Iterator=0; Loc_u32Iterator<Loc_u32DelayValue; Loc_u32Iterator++)
	{
		asm("NOP");
	}
}

