/*
 * dips.c
 *
 * Functions used to interact with the DIP switches at the back of the DSK
 *
 *  Created on: 24 sept. 2017
 *      Author: para2709
 */

#include "dips.h"

int readDipsProcess(){

    //Check if RECORD
    if(USER_REG & 0x10)
        return 0;

    //Check if PLAY
    if(USER_REG & 0x20)
        return 1;

    return -1;
}

int readDipsVolume(){

    //Check if VOLUME DOWN
    if(USER_REG & 0x40)
        return 2;

    //Check if VOLUME UP
    if(USER_REG & 0x80)
        return 3;

    return -1;
}


