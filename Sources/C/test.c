/*
 * test.c
 *
 *  Unit and integration tests to validate development
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */
#include <interrupts.h>
#include "test.h"
#include "timer.h"
#include "emifADC.h"
#include "codec.h"

extern volatile bool timer1Flag;
extern volatile bool codecFlag;
extern volatile bool eocFlag;

void testSDRAM(){

    unsigned int it = (unsigned int)&SDRAM_BEGIN;
    unsigned int it_max = it+0x80000;

    short digitalSoundData = 0x0;

    //TESTING WRITING
    while(it <= it_max){
        ++digitalSoundData;

        processSavingInSDRAM(digitalSoundData);

        if(digitalSoundData == 0x7FFF)
            digitalSoundData = 0x0;

        ++it;
    }

    //TESTING READING
    resetSDRAMIterator();

    it = (unsigned int)&SDRAM_BEGIN;

    while(it <= it_max){
        printf("\nValue : %d\tAddress : %x\n",getSDRAMData(), it);
        ++it;
    }
}

void testADC(){

    enableInterrupts();
    enableTimerInterrupt(1);
    setExternalInterrupt(4, FALLING);
    configAndStartTimer(1, 1.0);
    setupADC();

    while (true){

        // Timer 1
        if (timer1Flag){
            timer1Flag = false;
            printf("\nStart conversion ...\n");

            startADConv();
        }

        // End of conversion
        if (eocFlag){
            eocFlag = false;

            int value = readADCvalue();
            printf("ADC value: %d\n", value);
        }
    }
}

void testMicroToDacIntegration(){

    enableInterrupts();
    setExternalInterrupt(EXT_INT_PIN4, FALLING);
    setupADC();
    setSampleFrequencyKHz(44);
    startCodec();

    while (true){

        // Timer 1
        if (codecFlag){
            codecFlag = false;

            startADConv();
        }

        // End of conversion
        if (eocFlag){
            eocFlag = false;

            float voltage = readADCVoltage();
            dacOutput(voltage, ALL , 1);
        }
    }
}
