/*
 * SDRAM.h
 *
 *  Created on: 23 sept. 2017
 *      Author: para2709
 */

#ifndef INCLUDES_SDRAM_H_
#define INCLUDES_SDRAM_H_

#include <stdbool.h>
#include "addresses.h"

//SDRAM EMIF CE0 address iterator
static unsigned int* sdramAddressIt = &SDRAM_BEGIN; //TODO: Verify if it needs to be static

void setSDRAMData(short digitalSoundData);

short getSDRAMData();

//bool clearSDRAM();

bool isEndOfSDRAM();

void resetSDRAMIterator();

void iterateSDRAM();

void processSDRAM(short digitalSoundData);

//void processDigitalSoundPlayer(short digitalSoundData);

#endif /* INCLUDES_SDRAM_H_ */
