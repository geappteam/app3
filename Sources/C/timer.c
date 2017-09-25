/*
 * timer.c
 *
 *  Created on: 20 sept. 2017
 *      Author: para2709
 */

#include "timer.h"

const long long SECOND_TO_ITERATION = 10000000; // Close enough

void loop_waitSeconds(unsigned int delay){

    unsigned long long i = delay * SECOND_TO_ITERATION;

    while (i > 0)
        --i;
}

bool configAndStartTimer(unsigned short timer, double targetFrequency){
    unsigned int* ctl;
    unsigned int* prd;

    if (timer > 1 || targetFrequency < 0.0)
        return false;

    switch (timer){
        case 0:
            ctl = &CTL0;
            prd = &PRD0;
            break;
        case 1:
            ctl = &CTL1;
            prd = &PRD1;
            break;
        default:
            return false;
    }

    // Put timer on hold
    *ctl &= ~(1 << HLD);

    // Set the desired timer frequency (10khz)
    *prd = (unsigned int)((CLK_SRC / 4) / (2 * targetFrequency));

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
    *ctl |= 0x8315;

    // Start timer (setting GO and HLD bit)
    *ctl |= 0xC0;

    return true;
}
