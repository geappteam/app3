/*
 * interrupts.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_INTERRUPTS_H_
#define INCLUDES_INTERRUPTS_H_

#include <stdbool.h>
#include "addresses.h"

#define ON true
#define OFF false

typedef enum {RISING, FALLING, CHANGE, DISABLED} interOpt;

void enableInterrupts();
void setInterrupt(unsigned int interruptSelect, bool state);

bool setExternalInterrupt(unsigned short extIntPin, interOpt setting);

bool enableTimerInterrupt(unsigned int timer);
bool disableTimerInterrupt(unsigned int timer);

#endif /* INCLUDES_INTERRUPTS_H_ */
