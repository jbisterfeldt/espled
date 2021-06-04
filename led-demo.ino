#include "FastLED.h"

#define FASTLED_ESP8266_RAW_PIN_ORDER
#define NUM_LEDS 50
#define DATA_PIN 12

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}

// basic demo
void loop() {
  leds[0] = CRGB::Purple;
  FastLED.show();
  delay(200);
  leds[0] = CRGB::Black;
  delay(200);
}

// TODO: iterations
void chase() {
  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB::Purple;
    delay(300);
  }
}

// TODO: iterations
void chaseback() {
  for (int led = (NUM_LEDS - 1); led >= 0 ; led--) {
    leds[led] = CRGB::HotPink;
    FastLED.show();
    delay(400);
  }

  for (int led = 0; led < NUM_LEDS; led++) {
    leds[led] = CRGB::White;
    FastLED.show();
    delay(300);
  }

}
