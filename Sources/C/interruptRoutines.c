/*
 * This file contains the routines of the Interrupt vector table
 *    Interupt vector table : ../ASM/Vectors_intr.asm
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include "leds.h"
#include "test.h"
#include "interruptsConfig.h"
#include "C6713Helper_UdeS.h"

bool testNo4LaboStarted = false;

volatile unsigned short loopIndex = 0;
const int sinTable[8] = {0,707,1000,707,0,-707,-1000,-707};
unsigned long timerCounter = 0;
Uint32 fs = DSK6713_AIC23_FREQ_8KHZ;   //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; //select input


interrupt void handlePin4(){
    toggleLed(0);
    toggleLed(1);
    toggleLed(2);
    toggleLed(3);
}

interrupt void handlePin5(){
    if(testNo4LaboStarted)
        return;

    testNo4LaboStarted = true;
    setLed(3, HIGH);
    enableTimerInterrupt(1);
}

interrupt void codec_int(){
    //output_left_sample(10 * sinTable[timerCounter % 8]);

    ++timerCounter;

    if (timerCounter > 20000){
        testNo4LaboStarted = false;
        timerCounter = 0;
        loopIndex = 0;
        //output_left_sample(0);

        disableTimerInterrupt(1);

        setLed(3, LOW);
    }
}
