#include <msp430.h>
#include "head07.h"
#include "Library/Robot9_IR_Library.h"

/*
 * main.c
 */
void main(void) {

	IFG1=0; 							// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;			// disable WDT

	BCSCTL1 = CALBC1_8MHZ;				// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0 | BIT6;				// Set the red LED as output

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

	} // end infinite loop

} // end main
