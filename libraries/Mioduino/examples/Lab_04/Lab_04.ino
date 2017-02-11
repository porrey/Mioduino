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
// *** Mioduino - LAB 4
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the LED
// *** is connected.
// ***
#define LED_PIN 3

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
  // *** Start with the LED off
  // ***
  analogWrite(LED_PIN, 255);

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
  // *** Increase the LED from off to fully on
  // ***
  Serial.println("Increasing brightness...");
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(LED_PIN, i);
    delay(8);
  }

  // ***
  // *** Increase the LED from off to fully on
  // ***
  Serial.println("Decreasing brightness...");
  for (int i = 1; i < 255; i++)
  {
    analogWrite(LED_PIN, i);
    delay(8);
  }
}
