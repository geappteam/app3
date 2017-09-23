/*
 * codec.h
 *
 *  Created on: 23 sept. 2017
 *      Author: dene2303
 */

#ifndef INCLUDES_CODEC_H_
#define INCLUDES_CODEC_H_

#include "C6713Helper_UdeS.h"

#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011

typedef enum{LEFT, RIGHT, ALL} audioChannel;

void startCodec();
void dacOutput(double voltage, audioChannel channel);
int setSampleFrequencyKHz(unsigned short freq);
unsigned short getSampleFrequencyKHz();

#endif /* INCLUDES_CODEC_H_ */
