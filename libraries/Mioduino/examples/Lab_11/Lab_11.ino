// Copyright © 2016-2017 Daniel Porrey. All Rights Reserved.
//
// This file is part of the Mioduino project.
//
// The Mioduino project is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The Mioduino project is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with the Mioduino project. If not,
// see http://www.gnu.org/licenses/.
//

// ***
// *** Mioduino - LAB 11
// *** by Daniel Porrey
// ***

// ***
// *** Include the necessary libraries.
// ***
#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

#define NUM_PIXELS 1
#define NEO_PIXEL_PIN 3

// ***
// *** Initial the NeoPixel instance.
// ***
Adafruit_NeoPixel _rgb = Adafruit_NeoPixel(NUM_PIXELS, NEO_PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// ***
// *** The setup function runs once when the Arduino
// *** is powered up or when it is reset.
// ***
void setup()
{
  // ***
  // *** Setup of the serial port. Make sure the
  // *** serial speed is set to this same value in
  // *** the Serial Monitor.
  // ***
  Serial.begin(115200);
  Serial.println("Initializing...");

  // ***
  // *** Initialize all pixels to 'off'.
  // ***
  _rgb.begin();
  _rgb.setBrightness(100);
  _rgb.show();

  // ***
  // *** Send a message to the Serial Monitor
  // *** that the loop is starting.
  // ***
  Serial.println("Initialization complete.");
}

// ***
// *** The loop function runs over and over again forever.
// ***
void loop()
{
  // ***
  // *** Cycle through the colors on all NeoPixels.
  // ***
  rainbowCycle(_rgb, 20);
}

// ***
// *** Cycles through the color spetrum on each
// *** NeoPixel.
// ***
void rainbowCycle(Adafruit_NeoPixel& strip, uint8_t wait)
{
  uint16_t i, j;

  // ***
  // *** 5 cycles of all colors on wheel
  // ***
  for (j = 0; j < 256 * 5; j++)
  {
    for (i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, Wheel(strip, ((i * 256 / strip.numPixels()) + j) & 255));
    }

    strip.show();
    delay(wait);
  }
}

// ***
// *** Input a value 0 to 255 to get a color value.
// *** The colours are a transition r - g - b - back to r.
// ***
uint32_t Wheel(Adafruit_NeoPixel& strip, byte wheelPos) 
{
  wheelPos = 255 - wheelPos;
  
  if(wheelPos < 85) 
  {
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  
  if(wheelPos < 170)
  {
    wheelPos -= 85;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  
  wheelPos -= 170;
  
  return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}
