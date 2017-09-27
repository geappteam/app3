/*
 * codec.h
 *
 *  Created on: 23 sept. 2017
 *      Author: dene2303
 */

#ifndef INCLUDES_CODEC_H_
#define INCLUDES_CODEC_H_

#include "C6713Helper_UdeS.h"

#define FREQ_8KHZ   8
#define FREQ_16KHZ 16
#define FREQ_24KHZ 24
#define FREQ_32KHZ 32
#define FREQ_44KHZ 44
#define FREQ_48KHZ 48
#define FREQ_96KHZ 96

typedef enum{LEFT, RIGHT, ALL} audioChannel;

void startCodec();
void dacOutput(double voltage, audioChannel channel, unsigned short gain);
int setSampleFrequencyKHz(unsigned short freq);
unsigned short getSampleFrequencyKHz();

#endif /* INCLUDES_CODEC_H_ */
