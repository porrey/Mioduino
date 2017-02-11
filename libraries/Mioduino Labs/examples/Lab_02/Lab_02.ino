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
// *** Mioduino - LAB 2
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the LED
// *** is connected.
// ***
#define LED_PIN 13

// ***
// *** The amount of time (in milliseconds)
// *** to wait when turning the LED on or
// *** off.
// ***
#define DELAY_TIME 1000

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
  // *** Set the LED pin up for output.
  // ***
  pinMode(LED_PIN, OUTPUT);

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
  // *** Turn the LED on by setting the output
  // *** to HIGH.
  // ***
  Serial.println("Turning LED on.");
  digitalWrite(LED_PIN, HIGH);

  // ***
  // *** Delay
  // ***
  delay(DELAY_TIME);

  // ***
  // *** Turn the LED on by setting the output
  // *** to LOW.
  // ***
  Serial.println("Turning LED off.");
  digitalWrite(LED_PIN, LOW);

  // ***
  // *** Delay
  // ***
  delay(DELAY_TIME);
}
