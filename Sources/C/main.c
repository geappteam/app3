/*
 * main.c
 */

#include "leds.h"
#include "timer.h"
#include "interrupts.h"
#include "codec.h"
#include <stdbool.h>
#include <math.h>

volatile bool timerFlag1;
volatile bool codecFlag = false;
unsigned long long timerCounter1 = 0;

double SIN_FREQUENCY = 500.0;
const double PI = 3.14159265;

main(void){

    // Start codec
    startCodec();

    while(1){

        if (codecFlag)
        {
            codecFlag = false;

            ++timerCounter1;
            double output = sin(SIN_FREQUENCY * (double)(timerCounter1) / (getSampleFrequencyKHz()* 1000.0) * 2 * PI);
            dacOutput(output * 0.2, ALL);
        }
    }
}
