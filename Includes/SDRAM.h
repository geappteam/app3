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

#define NULL 0

void setSDRAMData(short digitalSoundData);

short getSDRAMData();

bool isEndOfSDRAM();

void resetSDRAMIterator();

void iterateSDRAM();

void processSavingInSDRAM(short digitalSoundData);

short processReadingInSDRAM();

void setEndOfLastRecordingAddress();

unsigned int* getEndOfLastRecordingAddress();

unsigned int* getSDRAMAddressIt();

#endif /* INCLUDES_SDRAM_H_ */
