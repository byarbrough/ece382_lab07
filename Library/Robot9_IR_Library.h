/*
 * Robot9_IR_Library.h
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Brian.Yarbrough
 *
 *    This library allows the MSP430 ADC to read values
 *    from IR sensors on borad ECE 382 ROBOT 09
 */

#include <msp430.h>

#ifndef ROBOT9_IR_LIBRARY_H_
#define ROBOT9_IR_LIBRARY_H_

#define 	FRONT_WALL	0x0185
#define		LEFT_WALL	0x0185
#define		RIGHT_WALL	0x0185

unsigned short	getRightVal();
unsigned short	getLeftVal();
unsigned short	getFrontVal();


#endif /* ROBOT9_IR_LIBRARY_H_ */
