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
// *** Mioduino - LAB 6A
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the LED
// *** is connected.
// ***
#define LED_PIN 3

// ***
// *** This is the pin on which the sensor
// *** is connected.
// ***
#define ANALOG_PIN 0

// ***
// *** Light threshold is a value between 0 and 1023
// *** that indicates when the LED is turned on. The
// *** voltage across the photoresistor will increase
// *** when the light increases making the value read
// *** on the analog port higher. With less light the
// *** voltage will drop and the value read on the analog
// *** port will be lower. Lowering the threshold requires
// *** less light light to activate the LED, and convrsely,
// *** more "darkness" to turn it off.
// ***
#define THRESHOLD 500

// ***
// *** Stores the current state if the night light
// ***
bool _ledIsOn = false;

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
  // *** Initialize the LED pin and
  // *** turn the LED off.
  // ***
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // ***
  // *** Initialize the LED
  // *** based on the sensor.
  // ***
  setLed(true);

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
  // *** Update the LED
  // ***
  setLed(false);

  // ***
  // *** Small delay
  // ***
  delay(50);
}

// ***
// *** Turns the LED on or off
// *** based on the amount of light
// *** detected.
// ***
void setLed(bool force)
{
  // ***
  // *** Read the sensor value from the analog port.
  // ***
  unsigned int analogValue = analogRead(ANALOG_PIN);

  // ***
  // *** Chck if the light has fallen below the
  // *** threshold.
  // ***
  if (analogValue < THRESHOLD)
  {
    // ***
    // *** If the LED is already on, do nothing.
    // ***
    if (!_ledIsOn || force)
    {
      // ***
      // *** Show the transition in the
      // *** Serial Monitor along qith
      // *** the current sensor readng.
      // ***
      Serial.print("Turning LED on (Sensor value = ");
      Serial.print(analogValue);
      Serial.println(").");

      // ***
      // *** Turn the LED on and update
      // *** the status.
      // ***
      digitalWrite(LED_PIN, LOW);
      _ledIsOn = true;
    }
  }
  else
  {
    // ***
    // *** If the LED is already off, do nothing.
    // ***
    if (_ledIsOn || force)
    {
      // ***
      // *** Show the transition in the
      // *** Serial Monitor along qith
      // *** the current sensor readng.
      // ***
      Serial.print("Turning LED off (Sensor value = ");
      Serial.print(analogValue);
      Serial.println(").");

      // ***
      // *** Turn the LED off and update
      // *** the status.
      // ***
      digitalWrite(LED_PIN, HIGH);
      _ledIsOn = false;
    }
  }
}
