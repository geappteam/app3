/*
 * SDRAM.c
 *
 *  Created on: 23 sept. 2017
 *      Author: para2709
 */

#include <SDRAM.h>

void setSDRAMData(short digitalData){
    if(isEndOfSDRAM()){
        resetSDRAMIterator();
        return;
    }

    *sdramAddressIt = digitalData;
}

short getSDRAMData(){
    if(isEndOfSDRAM()){
        resetSDRAMIterator();
        return 0;
    }

    short digitalData = *sdramAddressIt;

    iterateSDRAM();

    return digitalData;
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

void processSDRAM(short digitalData){
    setSDRAMData(digitalData);
    iterateSDRAM();
}

//short processDigitalSoundPlayer(){
//    return getDigitalSoundData();
//}
