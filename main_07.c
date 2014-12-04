#include <msp430.h> 

/*
 * main.c
 */
void main(void) {

    unsigned short sample[16];									// Just to analyze the values
    	unsigned char i = 0;										// index into sample array

    	IFG1=0; 													// clear interrupt flag1
    	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

    	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
    	DCOCTL = CALDCO_8MHZ;

    	P1DIR = BIT0;												// Set the red LED as output

    	while(1) {

    		  // Configure P1.4 to be the ADC input
    		ADC10CTL0 = 0;											// Turn off ADC subsystem
    		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
    		ADC10AE0 = BIT4;		 								// Make P1.4 analog input
    		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

    		ADC10CTL0 |= ADC10SC;									// Start a conversion
    		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
    		sample[i] = ADC10MEM;									// collect that 10-bit value
    		if (sample[i] > 0x0200)	P1OUT |= BIT0;
    		else					P1OUT &= ~BIT0;

    		i = (i+1) & 0xF;							// This is a mod 16 increment
    	} // end infinite loop

    } // end main
