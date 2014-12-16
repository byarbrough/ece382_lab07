/*
 * head07.h
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Brian.Yarbrough
 * Header file, contains LED control statements
 */

#ifndef HEAD07_H_
#define HEAD07_H_

#define		RED_ON		P1OUT |= BIT0
#define		RED_OFF		P1OUT &= ~BIT0
#define		GREEN_ON	P1OUT |= BIT6
#define		GREEN_OFF	P1OUT &= ~BIT6



#endif /* HEAD07_H_ */
