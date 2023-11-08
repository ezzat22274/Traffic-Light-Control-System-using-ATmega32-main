/*
 * Author: Ali Abdullkareem
 * DIO_MCAL_Prog.h
 * MCAL Layer
 * Version 0.3
 *
 */

#include "../../LIB/Types.h"
#include "../../LIB/Bit_Math.h"
#include "DIO_MCAL_Private.h"
#include "DIO_MCAL_Interface.h"
#include <util/delay.h>

/*-------------------------------------------------------------
			 * ---------------------Pin Manipulation----------------------*/
//set direction of a pin
void mDIO_VoidSetPinDirection(u8 Port, u8 Pin, u8 State)
{
	if  (Port <= PORTD && Pin <= PIN7)
	{
		if(State == OUTPUT)
		{
			switch(Port)
			{
			case PORTA : set_bit(DIO_DDRA, Pin);break;
			case PORTB : set_bit(DIO_DDRB,Pin);break;
			case PORTC : set_bit(DIO_DDRC,Pin);break;
			case PORTD : set_bit(DIO_DDRD,Pin);break;
			}
		}
		else if(State == INPUT)
		{
			switch(Port)
			{
			case PORTA : clr_bit(DIO_DDRA,Pin);break;
			case PORTB : clr_bit(DIO_DDRB,Pin);break;
			case PORTC : clr_bit(DIO_DDRC,Pin);break;
			case PORTD : clr_bit(DIO_DDRD,Pin);break;
			}
		}

	}
}

//set pin value
	void mDIO_VoidSetPinValue(u8 Port, u8 Pin, u8 PinValue)
{
	if(Port <= PORTD && Pin <= PIN7)
	{
		if(PinValue == HIGH)
		{
			switch(Port)
			{
			case PORTA : set_bit(DIO_PORTA,Pin);break;
			case PORTB : set_bit(DIO_PORTB,Pin);break;
			case PORTC : set_bit(DIO_PORTC,Pin);break;
			case PORTD : set_bit(DIO_PORTD,Pin);break;
			}
		}
		else if(PinValue == LOW)
		{
			switch(Port)
			{
			case PORTA : clr_bit(DIO_PORTA,Pin);break;
			case PORTB : clr_bit(DIO_PORTB,Pin);break;
			case PORTC : clr_bit(DIO_PORTC,Pin);break;
			case PORTD : clr_bit(DIO_PORTD,Pin);break;
			}
		}
}
}
//get pin value
u8 mDIO_u8GetPinValue(u8 Port, u8 Pin)
{
	u8 PinValue = 0;
	if (Port <= PORTD && Pin <= PIN7)
	{
		switch(Port)
		{
		case PORTA : PinValue = get_bit(DIO_PINA, Pin);break;
		case PORTB : PinValue = get_bit(DIO_PINB, Pin);break;
		case PORTC : PinValue = get_bit(DIO_PINC, Pin);break;
		case PORTD : PinValue = get_bit(DIO_PIND, Pin);break;
		}
	}
	else
	{
		return 0xFF; //error
	}
	return PinValue;
}


/*-------------------------------------------------------------
			 * ---------------------Port Manipulation----------------------*/

/*----------------------Direction Set-------------------------*/
//set direction of a port
void mDIO_VoidSetPortDirection(u8 Port, u8 State)
{
	if(Port <= PORTD)
	{
		if(State == OUTPUT)
		{
			switch(Port)
			{
			case PORTA : DIO_DDRA = HIGH_PORT;break;
			case PORTB : DIO_DDRB = HIGH_PORT;break;
			case PORTC : DIO_DDRC = HIGH_PORT;break;
			case PORTD : DIO_DDRD = HIGH_PORT;break;
			}
		}
		else if(State == INPUT)
		{
			switch(Port)
			{
			case PORTA : DIO_DDRA = LOW_PORT;break;
			case PORTB : DIO_DDRB = LOW_PORT;break;
			case PORTC : DIO_DDRC = LOW_PORT;break;
			case PORTD : DIO_DDRD = LOW_PORT;break;
			}
		}
}

}
//Set direction of a half a port
void mDIO_VoidSetUpperDirection(u8 Port, u8 State)
{
	if(Port <= PORTD)
	{
		if(State == OUTPUT)
		{
			switch(Port)
			{
			case PORTA : set_upper(DIO_DDRA);break;
			case PORTB : set_upper(DIO_DDRB);break;
			case PORTC : set_upper(DIO_DDRC);break;
			case PORTD : set_upper(DIO_DDRD);break;
			}
		}
		else if(State == INPUT)
		{
			switch(Port)
			{
			case PORTA : clr_upper(DIO_DDRA);break;
			case PORTB : clr_upper(DIO_DDRB);break;
			case PORTC : clr_upper(DIO_DDRC);break;
			case PORTD : clr_upper(DIO_DDRD);break;
			}
		}
}
}
void mDIO_VoidSetLowerDirection(u8 Port, u8 State)
{
	if(Port <= PORTD)
	{
		if(State == OUTPUT)
		{
			switch(Port)
			{
			case PORTA : set_lower(DIO_DDRA);break;
			case PORTB : set_lower(DIO_DDRB);break;
			case PORTC : set_lower(DIO_DDRC);break;
			case PORTD : set_lower(DIO_DDRD);break;
			}
		}
		else if(State == INPUT)
		{
			switch(Port)
			{
			case PORTA : clr_lower(DIO_DDRA);break;
			case PORTB : clr_lower(DIO_DDRB);break;
			case PORTC : clr_lower(DIO_DDRC);break;
			case PORTD : clr_lower(DIO_DDRD);break;
			}
		}
}
}

/*----------------------Port Set-------------------------*/
//set port value
void mDIO_VoidSetPortValue(u8 Port, u8 PortValue)
{
	if(Port <= PORTD)
	{
		switch(Port)
		{
		case PORTA : DIO_PORTA = PortValue;break;
		case PORTB : DIO_PORTB = PortValue;break;
		case PORTC : DIO_PORTC = PortValue;break;
		case PORTD : DIO_PORTD = PortValue;break;
		}
	}
}




























