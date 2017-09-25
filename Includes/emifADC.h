/*
 * emifADC.h
 *
 *  Created on: 24 sept. 2017
 *      Author: dene2303
 */

#ifndef INCLUDES_EMIFADC_H_
#define INCLUDES_EMIFADC_H_

#include "addresses.h"

void setupADC();
void startADConv();
unsigned short readADCvalue();

#endif /* INCLUDES_EMIFADC_H_ */
