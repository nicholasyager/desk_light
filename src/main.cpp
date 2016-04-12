/* Neopixels */
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(21, 3, NEO_RGBW + NEO_KHZ800);

int incomingByte = 0;   // for incoming serial data
int ledState[3][4];
int stateBuffer[6];

void setup() {
  strip.begin();

  Serial.begin(9600);
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'

}

int bri = 255;
int multiplier = 1;
void loop() {

  // Read the available data.
  if (Serial.available() > 4) {
      // read the incoming byte:
      for ( int index = 0; index < 5; index++) {
        char value = Serial.read();
        stateBuffer[index] = value;
      }
      Serial.print(stateBuffer[0]);
      Serial.print(" ");
      for ( int index = 1; index < 5; index++) {
        ledState[stateBuffer[0]][index - 1] = stateBuffer[index];
        Serial.print(ledState[stateBuffer[0]][index-1]);
        Serial.print(" ");
      }
      Serial.print("\n");
  }

  int alarm = 0;
  for (int led = 0; led < 3; led++) {
    for (int pixel = (led * 7); pixel < ((led + 1) * 7); pixel ++) {
      strip.setPixelColor(pixel, ledState[led][1], ledState[led][0], ledState[led][2]);
    }
    if (ledState[led][3] == 1) {
        alarm = 1;
    }
  }

  // Alarm
  if (alarm) {
  for (int color = 0; color < 3; color++) {

    if (bri > 254) {
      multiplier = -1;
    } else if (bri < 2) {
      multiplier = 1;
    }

    bri += multiplier;
    strip.setBrightness(bri);
  }
} else {
  bri = 255;
  strip.setBrightness(bri);
}

  strip.show(); // Initialize all pixels to 'off'
  delay(20);
}
