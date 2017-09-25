/*
 * soundRecorder.h
 *
 *  Created on: 24 sept. 2017
 *      Author: para2709
 */

#include <stdio.h>
#include <interrupts.h>

#include "timer.h"
#include "dips.h"

#ifndef INCLUDES_SOUNDRECORDER_H_
#define INCLUDES_SOUNDRECORDER_H_

enum { RECORD = 0, PLAY = 1 };

void process();
void record();
void play();

#endif /* INCLUDES_SOUNDRECORDER_H_ */
