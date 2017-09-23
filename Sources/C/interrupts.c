/*
 * interrupts.c
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include <interrupts.h>
#include "timer.h"

bool setExternalInterrupt(unsigned short extIntPin, interOpt setting){
    // Checking if input pin is in range
    if (extIntPin < 4 || extIntPin > 7)
        return false;

    if (setting == DISABLED){   // Disabling the interrupt
        // Not yet implemented
        return false;
    }
    else if (setting == RISING){
        setInterrupt(extIntPin, ON);
        GPEN |= 1 << extIntPin;
        GPDIR &= ~( 1 << extIntPin );
        GPPOL &= ~( 1 << extIntPin );
    }
    else if (setting == FALLING){
        setInterrupt(extIntPin, ON);
        GPEN |= 1 << extIntPin;
        GPDIR &= ~( 1 << extIntPin );
        GPPOL |=  1 << extIntPin;
    }
    else return false;

    return true;
}

bool enableTimerInterrupt(unsigned int timer){

    setInterrupt(14 + timer, ON);

    return true;
}

bool disableTimerInterrupt(unsigned int timer){

    setInterrupt(14 + timer, OFF);

    return true;
}
