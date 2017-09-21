/*
 * interrupts.c
 *
 *  Created on: 21 sept. 2017
 *      Author: dene2303
 */

#include <interruptsConfig.h>

bool setExternalInterrupt(unsigned short extIntPin, interOpt setting){
    // Checking if input pin is in range
    if (extIntPin < 4 || extIntPin > 7)
        return false;

    if (setting == DISABLED){   // Disabling the interrupt
        // Not yet implemented
        return false;
    }
    else if (setting == RISING){
        GPEN |= 1 << extIntPin;
        GPDIR &= ~( 1 << extIntPin );
        GPPOL &= ~( 1 << extIntPin );
    }
    else if (setting == FALLING){
        GPEN |= 1 << extIntPin;
        GPDIR &= ~( 1 << extIntPin );
        GPPOL |=  1 << extIntPin;
    }
    else return false;

    return true;
}
