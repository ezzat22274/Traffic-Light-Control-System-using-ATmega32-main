/*
 * Author: Ali Abdullkareem
 * HAL_SEGMENT.h
 * HAL Layer
 * Version 0.3
 *
 */


#ifndef HAL_SEVEN_SEGMENT_HAL_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_HAL_SEGMENT_H_

#include "../../LIB/Bit_MAth.h"
#include "../../LIB/types.h"
#include "../../MCAL/DIO/DIO_MCAL_Interface.h"

#define type cathode
#define cathode 5
#define anode 6

void HSegment_VoidInit(u8 Port);
void HSegment_VoidDisplayNumber(u8 Port, u8 Num);
void HSegment_VoidDisable(u8 Port);


void HSegment_VoidCountUp(u8 Port, u8 Num, u8 End);
void HSegment_VoidCountDown(u8 Port, u8 Num,u8 End);




#endif /* HAL_SEVEN_SEGMENT_HAL_SEGMENT_H_ */
