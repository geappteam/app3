/*
 * leds.h
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_LEDS_H_
#define INCLUDES_LEDS_H_

#include <stdbool.h>
#include "addresses.h"

#define HIGH true
#define LOW false

#define DEL0 0
#define DEL1 1
#define DEL2 2
#define DEL3 3

bool setLed (unsigned short led, bool state);
bool toggleLed(unsigned short led);

#endif /* INCLUDES_LEDS_H_ */
