#include <FastLED.h>
#define LED_PIN     12
#define NUM_LEDS    450

CRGB leds[NUM_LEDS];

int soundPin = 0;
float amp = 0.1;
int brightness = 50;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  //Serial.begin(9600);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  pinMode(soundPin, INPUT);
}
void loop() {
  int thing = analogRead(soundPin);
  //Serial.print(thing);
  if (thing > 400) {
    amp = .6;
    brightness = thing * amp;
  }else if(thing > 390){
    amp = 0.3;
    brightness = thing * amp;
  }else{
    //brightness = 50;
  }
  FastLED.setBrightness(brightness);
  FastLED.show();
  //delayMicroseconds(10);
  //Serial.println();
}
