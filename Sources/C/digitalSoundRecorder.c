/*
 * SDRAM.c
 *
 *  Created on: 23 sept. 2017
 *      Author: para2709
 */

#include <digitalSoundRecorder.h>

void setDigitalSoundData(short digitalSoundData){
    if(isEndOfSDRAM()){
        resetSDRAMIterator();
        return;
    }

    *sdramAddressIt = digitalSoundData;
}

short getDigitalSoundData(){
    if(isEndOfSDRAM()){
        resetSDRAMIterator();
        return 0;
    }

    short digitalSoundData = *sdramAddressIt;

    iterateSDRAM();

    return digitalSoundData;
}

bool isEndOfSDRAM(){
    if(sdramAddressIt > &SDRAM_END)
        return true;
    else
        return false;
}

void resetSDRAMIterator(){
    sdramAddressIt = &SDRAM_BEGIN;
}

void iterateSDRAM(){
    ++sdramAddressIt;
}

void processDigitalSoundRecorder(short digitalSoundData){
    setDigitalSoundData(digitalSoundData);
    iterateSDRAM();
}

//short processDigitalSoundPlayer(){
//    return getDigitalSoundData();
//}
