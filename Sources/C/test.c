/*
 * test.c
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */
#include <interrupts.h>
#include "test.h"
#include "timer.h"


bool testNo3Labo(){

    enableInterrupts();

    return setExternalInterrupt(4, RISING);
}

bool testNo4Labo(){

    configAndStartTimer1(500 * 8);
    enableInterrupts();
    setExternalInterrupt(5, RISING);

    //MUXH = 0b100000100000010110001000011;
    //if(testNo4LaboStarted)


    return true;
}
