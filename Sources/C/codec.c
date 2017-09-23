/*
 * codec.c
 *
 *  Created on: 23 sept. 2017
 *      Author: dene2303
 */

#include "codec.h"

unsigned int fs = DSK6713_AIC23_FREQ_44KHZ;

const double VOLT_2_DAC_VALUE = 25000.0;

void startCodec(){
    comm_intr();
}

void dacOutput(double voltage, audioChannel channel){

    short outputValue = (short)(voltage * VOLT_2_DAC_VALUE);

    if (channel == ALL){
        int val = outputValue | (outputValue  << 16);
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
    case 8:
        code = DSK6713_AIC23_FREQ_8KHZ;
        break;
    case 16:
        code = DSK6713_AIC23_FREQ_16KHZ;
        break;
    case 24:
        code = DSK6713_AIC23_FREQ_24KHZ;
        break;
    case 32:
        code = DSK6713_AIC23_FREQ_32KHZ;
        break;
    case 44:
        code = DSK6713_AIC23_FREQ_44KHZ;
        break;
    case 48:
        code = DSK6713_AIC23_FREQ_48KHZ;
        break;
    case 96:
        code = DSK6713_AIC23_FREQ_96KHZ;
        break;
    }

    if (code){
        fs = code;
        return 0;
    }

    return -1;
}

