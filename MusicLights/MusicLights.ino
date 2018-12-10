#include <FastLED.h>

#define LEDstrip 6
#define NUM_LEDS 50
#define sound 7

CRGBArray<NUM_LEDS> leds;

void setup()
{
   FastLED.addLeds<NEOPIXEL,LEDstrip>(leds, NUM_LEDS); 
  pinMode(sound,INPUT); //SIG of the Parallax Sound Impact Sensor connected to Digital Pin 7
    Serial.begin(9600);
}
//this function will make the LED dim once the Parallax Sound Impact Sensor sends a 1 signal, and then return to it’s original brightness.

void loop()
{
  static uint8_t hue;
  boolean soundstate = digitalRead(sound);
  if (soundstate != 1) {
    Serial.println("sound");
    for(int i = 0; i < NUM_LEDS/2; i++) {
    // fade everything out
    leds.fadeToBlackBy(40);
    // let's set an led value
    leds[i] = CHSV(hue++,255,255);

    // now, let's first 20 leds to the top 20 leds, 
    leds(NUM_LEDS/2,NUM_LEDS-1) = leds(NUM_LEDS/2 - 1 ,0);
    FastLED.delay(5);
    }
    }else{
}
  }
  

