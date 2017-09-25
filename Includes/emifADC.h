/*
 * emifADC.h
 *
 *  Created on: 24 sept. 2017
 *      Author: dene2303
 */

#ifndef INCLUDES_EMIFADC_H_
#define INCLUDES_EMIFADC_H_

#include "addresses.h"

#define VREF 4.096
#define MAX_VALUE 1024.0
#define MID_VALUE 512

void setupADC();
void startADConv();
unsigned short readADCvalue();
float readADCVolatge();

#endif /* INCLUDES_EMIFADC_H_ */
