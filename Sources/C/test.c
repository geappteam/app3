/*
 * test.c
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */
#include <interruptsConfig.h>
#include "test.h"

bool testNo4LaboStarted = false;

bool testNo3Labo(){

    enableInterrupts();

    return setExternalInterrupt(4, RISING);
}

bool testNo4Labo(){

    enableInterrupts();
    setExternalInterrupt(5, RISING);

    //if(testNo4LaboStarted)


    return true;
}
