/*
 * dips.c
 *
 *  Created on: 24 sept. 2017
 *      Author: para2709
 */

#include "dips.h"

void readDIPS(){

    bool dip0 = USER_REG & 0x10;
    bool dip1 = USER_REG & 0x20;

    //DIP0 - RECORD
    if(dip0){
        toggleLed(0);
        toggleLed(1);
    }

    //DIP1 - PLAY
    if(dip1){
        toggleLed(2);
        toggleLed(3);
    }
}



