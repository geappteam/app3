/*
 * timer.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_TIMER_H_
#define INCLUDES_TIMER_H_

#include "addresses.h"

#define CLK_SRC 225000000
#define TARGET_FRQ 10000

void loop_waitSeconds(unsigned int delay);

void configAndStartTimer1(void);

#endif /* INCLUDES_TIMER_H_ */
