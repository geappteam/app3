/*
 * main.c
 */

#include "leds.h"
#include "timer.h"
#include "test.h"


main(void){

    setLed(0, LOW);
    setLed(1, LOW);
    setLed(2, LOW);
    setLed(3, LOW);

    testNo4Labo();

    while(1){

    }
}
