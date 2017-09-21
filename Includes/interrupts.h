/*
 * interrupts.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_INTERRUPTS_H_
#define INCLUDES_INTERRUPTS_H_

typedef enum {RISING, FALLING, CHANGE, DISABLED} interOpt;

void enableInterrupts();

bool setExternalInterrupt(unsigned short extIntPin, interOpt setting);

#endif /* INCLUDES_INTERRUPTS_H_ */
