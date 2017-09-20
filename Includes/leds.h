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

bool setLed (unsigned short led, bool state);

#endif /* INCLUDES_LEDS_H_ */
