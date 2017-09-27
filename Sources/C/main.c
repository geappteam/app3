/*
 * main.c
 */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "leds.h"
#include "timer.h"
#include "interrupts.h"
#include "codec.h"
#include "test.h"
#include "dips.h"
#include "emifADC.h"
#include "SDRAM.h"

enum { NO_FEATURES = -1, RECORD = 0, PLAY = 1 , TUNE_DOWN = 2 , TUNE_UP = 3};
enum {  GAIN_0 = 0,
        GAIN_1 = 1,
        GAIN_4 = 4,
        GAIN_8 = 8,
        GAIN_12 = 12,
        GAIN_16 = 16,
        GAIN_20 = 20,
        GAIN_24 = 24,
        GAIN_28 = 28,
        GAIN_32 = 32,
        GAIN_36 = 36,
        GAIN_40 = 40};

//Global interrupt flags for program's process
extern volatile bool timer1Flag;
extern volatile bool codecFlag;
extern volatile bool eocFlag;

//Global program process flags
bool isRecording = false;
bool isPlaying = false;
bool isTuningUp = false;
bool isTuningDown = false;

//Global counters
int timer1counter = 0;

//Global process variables
unsigned short volumeScaler = 5; //5 is the normal tune for the volume

//Sound Recorder function prototypes
void record();
void play();
void tuneDown();
void tuneUp();
void resetTuningFlags();
unsigned short getGain();

main(void){

    setSampleFrequencyKHz(FREQ_8KHZ);
    startCodec();
    enableInterrupts();
    setExternalInterrupt(EXT_INT_PIN4, FALLING);
    setupADC();

    // Starting the timer at 8khz
    configAndStartTimer(TIMER1, TARGET_FRQ_8KHZ);

    while(1){
        int feature = NO_FEATURES; //No feature select

        if(isRecording)
            feature = RECORD;
        else if(isPlaying)
            feature = PLAY;
        else
            feature = readDipsProcess();

        switch(feature){
            case RECORD:
                record();
                break;
            case PLAY:
                play();
                break;
        }
    }
}

void record(){
    if(!isRecording){
        isRecording = true;
        resetSDRAMIterator();
        enableTimerInterrupt(TIMER1);
        printf("\nBEGIN RECORDING\n\n");
    }

    // Timer 1
    if (timer1Flag){
        timer1Flag = false;
        startADConv();
        if(timer1counter % 800 == 0){
            toggleLed(DEL0);
        }

        ++timer1counter;

        if(timer1counter >= 80000){
            isRecording = false;
            setLed(DEL0, LOW);
            setEndOfLastRecordingAddress();
            disableTimerInterrupt(TIMER1);
            timer1counter = 0;
            printf("\nEND RECORDING\n\n");
        }
    }

    // End of conversion
    if (eocFlag){
        eocFlag = false;
        processSavingInSDRAM(readADCvalue());
    }
}

void play(){
    if(!isPlaying){
        isPlaying = true;
        setLed(DEL1, HIGH);
        resetSDRAMIterator();
        printf("\nBEGIN PLAYING\n\n");
        printf("\nIterator : %x End address : %x \n\n",getSDRAMAddressIt(), getEndOfLastRecordingAddress());
    }

    if (getSDRAMAddressIt() > getEndOfLastRecordingAddress()){
        isPlaying = false;
        setLed(DEL1, LOW);
        printf("\nIterator : %x End address : %x \n\n",getSDRAMAddressIt(), getEndOfLastRecordingAddress());
        printf("\nEND PLAYING\n\n");
    }
    else if(codecFlag && isPlaying){
        codecFlag = false;
        if((readDipsVolume() == TUNE_DOWN) && !isTuningDown){
            isTuningDown = true;
            tuneDown();
        }
        else if((readDipsVolume() == TUNE_UP) && !isTuningUp){
            isTuningUp = true;
            tuneUp();
        }

        if(readDipsVolume() == NO_FEATURES)
            resetTuningFlags();

        dacOutput(convertADCDataToVoltage(processReadingInSDRAM()), ALL, getGain());
    }
}

void tuneDown(){
    if(volumeScaler <= 0){
        --volumeScaler;
    }
}

void tuneUp(){
    if(volumeScaler >= 10){
        ++volumeScaler;
    }
}

void resetTuningFlags(){
    isTuningUp = false;
    isTuningDown = false;
}

unsigned short getGain(){

    unsigned short gain = GAIN_1;

    switch(volumeScaler){
        case 0:
            gain = GAIN_0;
            break;
        case 1:
            gain = GAIN_4;
            break;
        case 2:
            gain = GAIN_8;
            break;
        case 3:
            gain = GAIN_12;
            break;
        case 4:
            gain = GAIN_16;
            break;
        case 5:
            gain = GAIN_20;
            break;
        case 6:
            gain = GAIN_24;
            break;
        case 7:
            gain = GAIN_28;
            break;
        case 8:
            gain = GAIN_32;
            break;
        case 9:
            gain = GAIN_36;
            break;
        case 10:
            gain = GAIN_40;
            break;
    }

    return gain;
}
