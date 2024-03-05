/* LEDstrip Barebone | AIRLAB CCC#2
 * 
 * The code serves as an absolut minimum for working with LED strips
 * 
 * Syntax for changing color:
 * leds[number of LED] = CRGB(Red value, Green value, Blue value); (Values are 0-255)
 * FastLED.show()
 * 
 */

#include <FastLED.h>
#define NUM_LEDS 10
#define DATA_PIN 3
CRGB leds[NUM_LEDS];


void setup() 
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  // turn off the LED
  leds[3] = CRGB(0,0,0);
  FastLED.show();
}


void loop()
{
  // turn on LED [3] (the fourth)
  leds[3] = CRGB(255,80,190);
  FastLED.show();
  delay(1000); // wait 1 sec
  
  // turn off LED [3] (the fourth)
  leds[3] = CRGB(0,0,0);
  FastLED.show();
  delay(1000); // wait 1 sec

}
