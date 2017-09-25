/*
 * soundRecorder.c
 *
 *  Created on: 24 sept. 2017
 *      Author: para2709
 */

#include "soundRecorder.h"

void process(){

    configAndStartTimer(1, 8000);
    enableTimerInterrupt(1);

    while(1){
        switch(readDIPS()){
            case RECORD:
                record();
                break;
            case PLAY:
                play();
                break;
            default:
                //printf("\n---ERROR---\n\n");
        }

    }
}

void record(){

}

void play(){

}
