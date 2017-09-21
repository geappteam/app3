/*
 * This file contains the routines of the Interrupt vector table
 *    Interupt vector table : ../ASM/Vectors_intr.asm
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include "leds.h"
#include "test.h"

extern bool testNo4LaboStarted;

interrupt void handlePin4(){
    toggleLed(0);
    toggleLed(1);
    toggleLed(2);
    toggleLed(3);
}

interrupt void handlePin5(){
    if(testNo4LaboStarted)
        return;

    testNo4LaboStarted = true;
}
