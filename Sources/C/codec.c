/*
 * codec.c
 *
 *  Created on: 23 sept. 2017
 *      Author: dene2303
 */

#include "codec.h"

unsigned int fs = DSK6713_AIC23_FREQ_44KHZ;

const double GAIN_ADJUSTMENT = 800.0;

void startCodec(){
    comm_intr();
}

void dacOutput(double voltage, audioChannel channel, unsigned short gain){

    unsigned short outputValue = ((short)(voltage * GAIN_ADJUSTMENT))*gain;

    if (channel == ALL){
        int val =  outputValue | (outputValue  << 16);
        output_sample(val);
    }
    else if (channel == RIGHT){
        output_right_sample(outputValue);
    }
    else if (channel == LEFT){
        output_left_sample(outputValue);
    }
}

unsigned short getSampleFrequencyKHz(){
    unsigned short freq = 0;

    switch(fs){
    case DSK6713_AIC23_FREQ_8KHZ:
        freq = 8;
        break;
    case DSK6713_AIC23_FREQ_16KHZ:
        freq = 16;
        break;
    case DSK6713_AIC23_FREQ_24KHZ:
        freq = 24;
        break;
    case DSK6713_AIC23_FREQ_32KHZ:
        freq = 32;
        break;
    case DSK6713_AIC23_FREQ_44KHZ:
        freq = 44;
        break;
    case DSK6713_AIC23_FREQ_48KHZ:
        freq = 48;
        break;
    case DSK6713_AIC23_FREQ_96KHZ:
        freq = 96;
        break;
    }

    return freq;
}

int setSampleFrequencyKHz(unsigned short freq){
    int code = 0;

    switch(freq){
    case FREQ_8KHZ:
        code = DSK6713_AIC23_FREQ_8KHZ;
        break;
    case FREQ_16KHZ:
        code = DSK6713_AIC23_FREQ_16KHZ;
        break;
    case FREQ_24KHZ:
        code = DSK6713_AIC23_FREQ_24KHZ;
        break;
    case FREQ_32KHZ:
        code = DSK6713_AIC23_FREQ_32KHZ;
        break;
    case FREQ_44KHZ:
        code = DSK6713_AIC23_FREQ_44KHZ;
        break;
    case FREQ_48KHZ:
        code = DSK6713_AIC23_FREQ_48KHZ;
        break;
    case FREQ_96KHZ:
        code = DSK6713_AIC23_FREQ_96KHZ;
        break;
    }

    if (code){
        fs = code;
        return 0;
    }

    return -1;
}

