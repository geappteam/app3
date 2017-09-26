/*
 * timer.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_TIMER_H_
#define INCLUDES_TIMER_H_

#include <stdbool.h>
#include "addresses.h"

#define CLK_SRC 225000000

#define TARGET_FRQ_8KHZ 8000

#define TIMER0 0
#define TIMER1 1

void loop_waitSeconds(unsigned int delay);

bool configAndStartTimer(unsigned short timer, double targetFrequency);

#endif /* INCLUDES_TIMER_H_ */
