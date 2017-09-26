/*
 * main.c
 */

#include <stdbool.h>
#include <math.h>

#include "leds.h"
#include "timer.h"
#include "interrupts.h"
#include "codec.h"
#include "test.h"
#include "dips.h"
#include "emifADC.h"
#include "SDRAM.h"

enum { RECORD = 0, PLAY = 1 };

//Global interrupt flags for program's process
extern volatile bool timer1Flag;
extern volatile bool codecFlag;
extern volatile bool eocFlag;

//Global program process flags
bool isRecording = false;
bool isPlaying = false;

//Global counters
int timer1counter = 0;

//Sound Recorder function prototypes
void record();
void play();

main(void){

    startCodec();
    enableInterrupts();

    // Starting the timer at 8khz
    configAndStartTimer(TIMER1, TARGET_FRQ_8KHZ);

    while(1){
        int feature = -1; //No feature select

        if(isRecording)
            feature = 0;
        else if(isPlaying)
            feature = 1;
        else
            feature = readDIPS();

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
    }

    setExternalInterrupt(EXT_INT_PIN4, FALLING);
    setupADC();
    setSampleFrequencyKHz(FREQ_8KHZ);

    // Timer 1
    if (timer1Flag){
        timer1Flag = false;
        startADConv();
        if(timer1counter % 800 == 0){
            toggleLed(DEL0);
        }

        ++timer1counter;

        if(timer1counter % 8000 == 10){
            isRecording = false;
            setLed(DEL0, LOW);
            setEndOfLastRecordingAddress();
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
    }

    if(isPlaying && !(getSDRAMAddressIt() == getEndOfLastRecordingAddress())){
        dacOutput(convertADCDataToVoltage(processReadingInSDRAM()), ALL);
    }
    else if(getSDRAMAddressIt() == getEndOfLastRecordingAddress())
    {
        isPlaying = false;
        setLed(DEL1, LOW);
    }
}

