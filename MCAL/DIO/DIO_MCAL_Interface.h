/*
 * Author: Ali Abdullkareem
 * DIO_MCAL_Interface.h
 * MCAL Layer
 * Version 0.3
 *
 */

#ifndef MCAL_DIO_DIO_MCAL_INTERFACE_H_
#define MCAL_DIO_DIO_MCAL_INTERFACE_H_

			/*-------------------------------------------------------------
			 * ---------------------Pin Manipulation----------------------*/
//set direction of a pin
void mDIO_VoidSetPinDirection(u8 Port, u8 Pin, u8 PinDirection);

//set pin value
void mDIO_VoidSetPinValue(u8 Port, u8 Pin, u8 PinValue);

//get pin value
u8 mDIO_u8GetPinValue(u8 Port, u8 Pin);

			 /*-------------------------------------------------------------
			 * ---------------------Port Manipulation----------------------*/

/*----------------------Direction Set-------------------------*/
//set direction of a port
void mDIO_VoidSetPortDirection(u8 Port, u8 PinDirection);

//Set direction of a half a port
void mDIO_VoidSetUpperDirection(u8 Port, u8 State);
void mDIO_VoidSetLowerDirection(u8 Port, u8 State);

/*----------------------Port Set-------------------------*/
//set port value
void mDIO_VoidSetPortValue(u8 Port, u8 PortValue);


/*----------------------Public Macros----------------*/

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
//States
#define INPUT 0
#define OUTPUT 1

//Logic
#define LOW 0
#define HIGH 1
#define LOW_PORT 0x00
#define HIGH_PORT 0xFF

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7




#endif /* MCAL_DIO_DIO_MCAL_INTERFACE_H_ */
