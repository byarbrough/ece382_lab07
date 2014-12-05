/*
 * Robot9_IR_Library.c
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Brian.Yarbrough
 *      Works with
 */

#include <msp430.h>
#include "Robot9_IR_Library.h"


/**
 * converts the analong input from the right sensors -1.5
 * Returns: digital value from ADC
 */
unsigned short	getRightVal(){
	// Configure P1.5 to be the ADC input
	ADC10CTL0 = 0;										// Turn off ADC subsystem
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;					// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT5;		 							// Make P1.5 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;								// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);						// Wait for conversion to complete

	return ADC10MEM;
}

/**
 * converts the analong input from the left sensors - 1.3
 * Returns: digital value from ADC
 */
unsigned short	getLeftVal(){
	// Configure P1.3 to be the ADC input
	ADC10CTL0 = 0;										// Turn off ADC subsystem
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;					// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT3;		 							// Make P1.3 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;								// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);						// Wait for conversion to complete

	return ADC10MEM;
}

/**
 * converts the analong input from the front sensors - 1.4
 * Returns: digital value from ADC
 */
unsigned short	getFrontVal(){
	// Configure P1.4 to be the ADC input
	ADC10CTL0 = 0;										// Turn off ADC subsystem
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;					// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT4;		 							// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;								// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);						// Wait for conversion to complete

	return ADC10MEM;
}
