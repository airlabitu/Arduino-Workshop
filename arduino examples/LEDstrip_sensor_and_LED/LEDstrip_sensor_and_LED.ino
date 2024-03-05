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
#define SENSOR_PIN A0
int sensorVal = 0;
CRGB leds[NUM_LEDS];

void setup() 
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  
  // turn off the LED
  leds[3] = CRGB(0,0,0);
  FastLED.show();
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
}


void loop()
{
  sensorVal = analogRead(SENSOR_PIN);
  Serial.println(sensorVal);

  if (sensorVal > 500){
    // turn on LED [3] (the fourth)
    leds[3] = CRGB(255,0,0);
  }
  else {
    // turn off LED [3] (the fourth)
    leds[3] = CRGB(0,0,0);
  }
  
  FastLED.show();
  delay(1);

}
