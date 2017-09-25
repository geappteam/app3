/*
 * dips.c
 *
 *  Created on: 24 sept. 2017
 *      Author: para2709
 */

#include "dips.h"

int readDIPS(){

    //Check if RECORD
    if(USER_REG & 0x10)
        return 0;

    //Check if PLAY
    if(USER_REG & 0x20)
        return 1;

    return -1;
}



