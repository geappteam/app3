/*
 * SDRAM.c
 *
 *  Functions to naviate through the SDRAM available on the DSK
 *
 *  Created on: 23 sept. 2017
 *      Author: para2709
 */

#include <SDRAM.h>

//SDRAM EMIF CE0 address iterators
unsigned short* sdramAddressIt = &SDRAM_BEGIN;
unsigned short* lastSDRAMAddressIt = NULL;

void setSDRAMData(short digitalData){
    *sdramAddressIt = digitalData;
}

short getSDRAMData(){
    return *sdramAddressIt;
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

void processSavingInSDRAM(short digitalData){
    setSDRAMData(digitalData);
    iterateSDRAM();
}

short processReadingInSDRAM(){
    short digitalData = getSDRAMData();
    iterateSDRAM();

    return digitalData;
}

void setEndOfLastRecordingAddress(){
    lastSDRAMAddressIt = sdramAddressIt;
}

unsigned short* getEndOfLastRecordingAddress(){
    return lastSDRAMAddressIt;
}

unsigned short* getSDRAMAddressIt(){
    return sdramAddressIt;
}
