/*
 * This file contains the routines of the Interrupt vector table
 *    Interupt vector table : ../ASM/Vectors_intr.asm
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include <stdbool.h>

volatile bool timer1Flag = false;
volatile bool codecFlag = false;
volatile bool eocFlag = false;

interrupt void codec_int(){
    codecFlag = true;
}

interrupt void endOfConv(){
    eocFlag = true;
}

interrupt void timerIsr1(){
    timer1Flag = true;
}
