#define F_CPU 8000000UL
#include <util/delay.h>
/***************************************************************************************************************************
 *********************************************************LIB**************************************************************
 **************************************************************************************************************************/
#include "../LIB/types.h"
#include "../LIB/BIT_MATH.h"
/***************************************************************************************************************************
 *********************************************************HAL**************************************************************
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *********************************************************MCAL**************************************************************
 **************************************************************************************************************************/
#include "../MCAL/DIO/DIO_MCAL_Interface.h"
#include "../HAL/SEVEN_SEGMENT/HAL_SEGMENT.h"

int main()
{
    mDIO_VoidSetPortDirection(PORTA, OUTPUT); // as a traffic light
    HSegment_VoidInit(PORTC);
    HSegment_VoidInit(PORTD);

    while (1)
    {
        // green
        mDIO_VoidSetPinValue(PORTA, PIN0, HIGH); // to light a red light
        HSegment_VoidDisplayNumber(PORTD, 1);
        for (int i = 5; i >= 0; i--)
        {
            HSegment_VoidDisplayNumber(PORTC, i);
            _delay_ms(1000);
        }

        HSegment_VoidDisplayNumber(PORTD, 0);
        for (int j = 9; j >= 0; j--)
        {
            HSegment_VoidDisplayNumber(PORTC, j);
            _delay_ms(1000);
        }
        // yellow
        mDIO_VoidSetPinValue(PORTA, PIN0, LOW);
        mDIO_VoidSetPinValue(PORTA, PIN1, HIGH);
        HSegment_VoidDisplayNumber(PORTD, 0);
        for (int i = 3; i >= 0; i--)
        {
            HSegment_VoidDisplayNumber(PORTC, i);
            _delay_ms(1000);
        }
        mDIO_VoidSetPinValue(PORTA, PIN1, LOW);

        // red
        mDIO_VoidSetPinValue(PORTA, PIN2, HIGH); // to light a red light
        HSegment_VoidDisplayNumber(PORTD, 1);
        for (int i = 5; i >= 0; i--)
        {
            HSegment_VoidDisplayNumber(PORTC, i);
            _delay_ms(1000);
        }

        HSegment_VoidDisplayNumber(PORTD, 0);
        for (int j = 9; j >= 0; j--)
        {
            HSegment_VoidDisplayNumber(PORTC, j);
            _delay_ms(1000);
        }
        mDIO_VoidSetPinValue(PORTA, PIN2, LOW);
    }

    return 0;
}
