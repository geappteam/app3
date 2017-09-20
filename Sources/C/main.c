/*
 * main.c
 */

#include "leds.h"
#include "timer.h"

main(void){

    setLed(2, HIGH);
    setLed(3, HIGH);

    loop_waitSeconds(5);

    setLed(3, LOW);


    configAndStartTimer1();

    while(1);
}
