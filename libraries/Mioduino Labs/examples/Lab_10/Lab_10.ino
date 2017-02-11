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
// *** Mioduino - LAB 10
// *** by Daniel Porrey
// ***

// ***
// *** Include the necessary libraries.
// ***
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP9808.h"

// ***
// *** Create the MCP9808 temperature sensor object.
// ***
Adafruit_MCP9808 _temperature = Adafruit_MCP9808();

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
  // *** Initialize the MCP9808 and make sure it was found. We are
  // *** using the default address. This assumes no connections
  // *** have been made to the address pins on the breakout.
  // ***
  if (!_temperature.begin())
  {
    Serial.println("The MCP9808 could not be found. Please check your wiring and reset the Arduino.");

    // ***
    // *** Sit here forever...
    // ***
    while (true);
  }

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
  // *** Get the temperature in Celius from the sensor.
  // ***
  double temperatureC = _temperature.readTempC();

  // ***
  // *** Convert the temperature to fahrenheit.
  // ***
  double temperatureF = temperatureC * 1.8 + 32;

  // ***
  // *** Display the results
  // ***
  Serial.print("Temperature = ");
  Serial.print(temperatureC);
  Serial.print(" C / ");
  Serial.print(temperatureF);
  Serial.println(" F");

  // ***
  // *** Put the sensor to sleep to conserve power.
  // ***
  _temperature.shutdown_wake(1);

  // ***
  // *** Delay 2 seconds and then take a reading again...
  // ***
  delay(2000);

  // ***
  // *** Wake the sensor for the next reading.
  // ***
  _temperature.shutdown_wake(0);
}
