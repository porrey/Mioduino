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
// *** Mioduino - LAB 9
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the IR
// *** Reflective Sensor emitter is connected.
// ***
#define IR_E 12

// ***
// *** This is the pin on which the IR
// *** Reflective Sensor sensor is connected.
// ***
#define IR_S 9

// ***
// *** A pin that has an LED connected on it
// *** to indicate wen reflective material has
// *** been detcted. We are using the built LED
// *** on D13.
// ***
#define LED_PIN 13

// ***
// *** This flag is used to keep the last known state
// *** of the sensor.
// ***
bool _materialDetected = false;

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
  // *** Initialize the emitter pin
  // *** and turn it on.
  // ***
  pinMode(IR_E, OUTPUT);
  digitalWrite(IR_E, HIGH);

  // ***
  // *** Initialize the sensor pin.
  // ***
  pinMode(IR_S, INPUT);

  // ***
  // *** Set up the LED pin for output.
  // ***
  pinMode(LED_PIN, OUTPUT);

  // ***
  // *** Initialize the _materialDetected flag.
  // ***
  _materialDetected = !digitalRead(IR_S);

  // ***
  // *** Initialize the LED
  // ***
  setLedState(_materialDetected);

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
  // *** Check the sensor.
  // ***
  checkSensor();

  // ***
  // *** Short delay (50 mS).
  // ***
  delay(50);
}

void checkSensor()
{
  // ***
  // *** Read the digital port
  // ***
  unsigned int value = digitalRead(IR_S);

  // ***
  // *** If the value is HIGH, there is no refelective
  // *** material. If the value is LOW, then refelective
  // *** material has been detected.
  // ***
  if (value == HIGH)
  {
    // ***
    // *** Check if we previously detected material
    // ***
    if (_materialDetected)
    {
      // ***
      // *** Send the tatus to the Serial Monitor
      // ***
      Serial.println("Reflective material has been removed.");

      // ***
      // *** Update the flag.
      // ***
      _materialDetected = false;

      // ***
      // *** Set the LED state.
      // ***
      setLedState(_materialDetected);
    }
  }
  else
  {
    // ***
    // *** Check if we previously detected material
    // ***
    if (!_materialDetected)
    {
      // ***
      // *** Send the tatus to the Serial Monitor
      // ***
      Serial.println("Reflective material has been detected!");

      // ***
      // *** Update the flag.
      // ***
      _materialDetected = true;

      // ***
      // *** Set the LED state.
      // ***
      setLedState(_materialDetected);
    }
  }
}

void setLedState(bool on)
{
  // ***
  // *** Chck if the lED is to be turned
  // *** on or off.
  // ***
  if (on)
  {
    // ***
    // *** Turn the LED on.
    // ***
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    // ***
    // *** Turn the LED off.
    // ***
    digitalWrite(LED_PIN, LOW);
  }
}

