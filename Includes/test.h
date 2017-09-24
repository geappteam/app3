/*
 * test.h
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#ifndef INCLUDES_TEST_H_
#define INCLUDES_TEST_H_

#include <stdbool.h>
#include <stdio.h>
#include "SDRAM.h"

//General tests (Miscellaneous)
bool testNo3Labo();
bool testNo4Labo();

//APP features unit test
void testSDRAM();
void testADC();

//APP features integration test
void testIntegrationADCSDRAMDAC();
#endif /* INCLUDES_TEST_H_ */
