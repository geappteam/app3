/*
 * timer.c
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#include "timer.h"

const long long SECOND_TO_ITERATION = 10000000; // Close enough 5.5 sec

void loop_waitSeconds(unsigned int delay){

    unsigned long long i = delay * SECOND_TO_ITERATION;

    while (i > 0)
        --i;
}

void configAndStartTimer1(double targetFrequency){

    // Put timer on hold
    CTL1 &= ~(1 << HLD);

    // Set the desired timer frequency (10khz)
    PRD1 = (unsigned int)((CLK_SRC / 4) / (2 * targetFrequency));


    // CLT Settings:
    //    SPND = 1 : Timer stops on emulation halt
    //    Reserved 3x
    //    TSTAT = X : Timer status
    //    INVINP = X : Standard LOW/HIGH transition
    //    CLKSRC = 1 : Internal clock source
    //    CP = 1 : 50 % duty cycle
    //    HLD = X : Stay on hold
    //    GO = X : No reset
    //    Reserved 1x
    //    PWID = 1 : pulse width multiplier
    //    DATIN = X
    //    DATOUT = 1 : TOUT is driven  by TSTAT
    //    INVOUT = X
    //    FUNC = 1 : TOUT is timer output
    CTL1 |= 0x8315;

    // Start timer (setting GO and HLD bit)
    CTL1 |= 0xC0;
}
