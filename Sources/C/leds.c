/*
 * leds.c
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */
#include "leds.h"

bool setLed (unsigned short led, bool state){
    if (led > 3)
        return false;

    if (state)
        USER_REG |= 1<<led;
    else
        USER_REG &= ~ (1<<led);

    return true;
}
