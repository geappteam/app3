/*
 * interrupts.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_INTERRUPTSCONFIG_H_
#define INCLUDES_INTERRUPTSCONFIG_H_

#include <stdbool.h>
#include "addresses.h"

typedef enum {RISING, FALLING, CHANGE, DISABLED} interOpt;

void enableInterrupts();

bool setExternalInterrupt(unsigned short extIntPin, interOpt setting);

#endif /* INCLUDES_INTERRUPTSCONFIG_H_ */
