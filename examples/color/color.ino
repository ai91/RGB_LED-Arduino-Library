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

void setup() {
  // put your setup code here, to run once:

  // set LED to red color
  rgb_led.setColor(0xFF0000);

  // optionally turn it off
  //rgb_led.setColor(0x000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  rgb_led.tick();
}
