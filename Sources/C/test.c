/*
 * test.c
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */
#include <interrupts.h>
#include "test.h"
#include "timer.h"
#include "codec.h"


bool testNo3Labo(){

    enableInterrupts();

    return setExternalInterrupt(4, RISING);
}

bool testNo4Labo(){

    configAndStartTimer(1, 500 * 8);
    enableInterrupts();
    setExternalInterrupt(5, RISING);

    //MUXH = 0b100000100000010110001000011;
    //if(testNo4LaboStarted)


    return true;
}

void testSDRAM(){

    unsigned int it = (unsigned int)&SDRAM_BEGIN;
    unsigned int it_max = it+0x80000;

    short digitalSoundData = 0x0;

    //TESTING WRITING
    while(it <= it_max){
        ++digitalSoundData;

        processSDRAM(digitalSoundData);

        if(digitalSoundData == 0x7FFF)
            digitalSoundData = 0x0;

        ++it;
    }

    //TESTING READING
    resetSDRAMIterator();

    it = (unsigned int)&SDRAM_BEGIN;

    while(it <= it_max){
        printf("\nValue : %d\tAddress : %x\n",getSDRAMData(), it);

        ++it;
    }
}

void testIntegrationADCSDRAMDAC(){

//    resetSDRAMIterator();
//
//    startCodec();
//
//    dacOutput(voltage, audioChannel channel);
//    getSDRAMData();
}

void testADC(){

    enableInterrupts();
    enableTimerInterrupt(1);
    configAndStartTimer(1, 1.0);

    while (true){


    }
}
