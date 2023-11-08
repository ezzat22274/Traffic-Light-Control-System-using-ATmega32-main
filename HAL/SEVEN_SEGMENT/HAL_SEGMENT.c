/*
 * Author: Ali Abdullkareem
 * HAL_SEGMENT.c
 * HAL Layer
 * Version 0.3
 *
 */
#include "HAL_SEGMENT.h"
#include <util/delay.h>


static const u8 Segment_Nums [10] =
		{
				 ~0b10111111,//0
				 ~0b10000110,//1
				 ~0b11011011,//2
				 ~0b11001111,//3
				 ~0b11100110,//4
				 ~0b11101101,//5
				 ~0b11111101,//6
				 ~0b10000111,//7
				 ~0b11111111,//8
				 ~0b11101111//9



		};


//initialize
void HSegment_VoidInit(u8 Port)
{
	if(Port <= PORTD)
	{
		mDIO_VoidSetPortDirection(Port, OUTPUT);
	}
}
void HSegment_VoidDisplayNumber(u8 Port, u8 Num)
{
	if(Port <= PORTD && (Num <= 9 && Num >=0) )
	{
//#if type == Cathode
		mDIO_VoidSetPortValue(Port,Segment_Nums[Num]);
//#elif type == anode
//		mDIO_VoidSetPortValue(Port,~Segment_Nums[Num]);
//#else
//	//#error "Define type"
//#endif
	}
}
void HSegment_VoidDisable(u8 Port)
{
	if(Port <= PORTD)
	{
	//#if type == cathode
		mDIO_VoidSetPortValue(Port,0x00);
//	#elif type == anode
//		mDIO_VoidSetPortValue(Port,0xff);
//	#else
//		//#error "Define Type"
//	#endif
	}
}
void HSegment_VoidCountUp(u8 Port, u8 Num, u8 End)
{
	if(Port <= PORTD && (Num <= 9 && Num >=0) )
	{

		for(u8 i = Num; i <= End;i++)
		{
			HSegment_VoidDisplayNumber(Port,i);
			_delay_ms(1000);
		}
	}
}
void HSegment_VoidCountDown(u8 Port, u8 Num,u8 End)
{
	if(Port <= PORTD && (Num <= 9 && Num >=0) )
		{

			for(u8 i = Num; i >= End;i--)
			{
				HSegment_VoidDisplayNumber(Port,i);
				_delay_ms(1000);
			}
		}
}

