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

  // fade from blue to green during 5 seconds
  rgb_led.fadeColors(0x0000FF, 0x00FF00, 5000);

  // optionally fade current state (initially off) to white during 5 seconds
  //rgb_led.fadeColor(0xFFFFFF, 5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  rgb_led.tick();
}
