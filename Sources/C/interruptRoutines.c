/*
 * This file contains the routines of the Interrupt vector table
 *    Interupt vector table : ../ASM/Vectors_intr.asm
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include "interrupts.h"
#include "leds.h"
#include "test.h"
#include "codec.h"
#include <stdbool.h>

bool testNo4LaboStarted = false;

extern volatile bool timerFlag1;
extern volatile bool codecFlag;
extern volatile bool eocFlag;


interrupt void codec_int(){
    codecFlag = true;
}

interrupt void endOfConv(){
    eocFlag = true;
}

interrupt void timerIsr1(){
    timerFlag1 = true;
}

