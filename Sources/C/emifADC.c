/*
 * emifADC.c
 *
 * This document contains the functions to configure and read from
 * a TLC1550 through the EMIF
 *
 *
 *  Created on: 24 sept. 2017
 *      Author: dene2303
 */

#include "emifADC.h"

#define ASYNC16 0x1
#define ASYNC32 0x2

void setupADC(){
    unsigned int cectlSettings = 0;

    // using the EMIF as a 16 bit asynchronus interface
    cectlSettings |= ASYNC16 << MTYPE;

    // The EMIF clock frequency is running at 90MHz
    // resulting in a 11.1 ns period

    // Write setup time -> no time required
    cectlSettings |= 1 << WRSETUP;
    // Write strobe time >= 50ns -> minimum 6 clock cycles
    cectlSettings |= 6 << WRSTRB;
    // Write hold time -> no time requires
    cectlSettings |= 1 << WRHLD;

    // Write setup time -> no time required
    cectlSettings |= 1 << RDSETUP;
    // Write strobe time >= 50ns -> minimum 6 clock cycles
    cectlSettings |= 6 << RDSTRB;
    // Write hold time >= 30 ns -> minimum of 4 clock cycles
    cectlSettings |= 4 << RDHLD;

    // Applying settings
    CECTL3 = cectlSettings;
}

void startADConv(){
    // Reading the ADC to clear any previously started reading
    // Writing to the EMIF starts the conversion
    TLC1550 = TLC1550 + 0;
}

unsigned short readADCvalue(){
    // Eliminating the 6 MSB as per 10 bit ADC
    unsigned int data;
    data = TLC1550;
    data = data << 22;
    data = data >> 22;
    return data;
}

float readADCVolatge(){
    int data = readADCvalue();

    data -= MID_VALUE;
    return ((float)data/MAX_VALUE)*VREF;
}
