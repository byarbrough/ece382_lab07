#include <msp430.h>
#include "head07.h"
#include "Library/Robot9_IR_Library.h"

unsigned short sample;

/*
 * main.c
 */
void main(void) {
	IFG1=0; 							// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;			// disable WDT

	BCSCTL1 = CALBC1_8MHZ;				// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0 | BIT6;				// Set the LED as output
	P1OUT &= ~(BIT0 | BIT6);

	while(1) {

		if (getRightVal() < RIGHT_WALL_NR){
			RED_ON;
		}
		else {
			RED_OFF;
		}

		if (getLeftVal() < LEFT_WALL_NR){
			GREEN_ON;
		}
		else {
			GREEN_OFF;
		}

		_delay_cycles(1000);

		sample = getRightVal();


	} // end infinite loop

} // end main
