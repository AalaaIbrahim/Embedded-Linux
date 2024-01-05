/**
 * @file	PORT_register.h
 * @author  Alaa Hisham
 * @brief   Register addresses for all target ports
 * @version 0.0
 * @date    2-12-2023
 */ 


#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_


/* Register Addresses */
typedef struct
{
	volatile u8 PIN ;
	volatile u8 DDR ;
	volatile u8 PORT;
}strPortReg_t;

#define PORTA_BASE		((strPortReg_t* volatile) 0x39)
#define PORTB_BASE		((strPortReg_t* volatile) 0x36)
#define PORTC_BASE		((strPortReg_t* volatile) 0x33)
#define PORTD_BASE		((strPortReg_t* volatile) 0x30)

extern strPortReg_t* pstrPortArr[4];


#endif /* PORT_REGISTER_H_ */