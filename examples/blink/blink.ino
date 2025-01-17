/*
*    set RGB led legs to;
*    red   --->   digital pin 7 
*    green --->   digital pin 6
*    blue  --->   digital pin 5
*
*/

#include "RGB_LED.h"

#define RED_PIN D7
#define GREEN_PIN D6
#define BLUE_PIN D5

RGB_LED rgb_led(RED_PIN, GREEN_PIN, BLUE_PIN, COMMON_CATHOD);
unsigned long  yellow_blink[] = {
  2,
  0Xffef03L,
  300L,
  0,
  300L
}; 

unsigned long  darkblue_blink[] = {
  2,
  0X004684L,
  300L,
  0,
  300L
}; 

void setup() {
  // put your setup code here, to run once:
  //rgb_led.set(yellow_blink, 0); uncomment this for yellow blink
  rgb_led.set(darkblue_blink, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  rgb_led.tick();
}
