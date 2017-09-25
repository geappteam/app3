/*
 * main.c
 */

#include "leds.h"
#include "timer.h"
#include "interrupts.h"
#include "codec.h"
#include <stdbool.h>
#include <math.h>
#include "test.h"
#include "soundRecorder.h"

unsigned long long timerCounter1 = 0;

double SIN_FREQUENCY = 500.0;
const double PI = 3.14159265;

main(void){
   // process();

   //testMicroToDacIntegration();
   //testSDRAM();
   testADC();
}
