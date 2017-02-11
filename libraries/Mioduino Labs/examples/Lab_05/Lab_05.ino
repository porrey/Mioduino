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
// *** Mioduino - LAB 5
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the LED
// *** is connected.
// ***
#define LED_PIN 3

// ***
// *** This is the pin on which the
// *** button is connected.
// ***
#define BUTTON_PIN 2

// ***
// *** Stores previous state of button
// ***
byte _previousState;

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
  // *** Set the LED pin for OUTPUT
  // ***
  pinMode(LED_PIN, OUTPUT);

  // ***
  // *** Set the button pin for
  // *** INPUT.
  // ***
  pinMode(BUTTON_PIN, INPUT);

  // ***
  // *** Initialize previous state
  // ***
  _previousState = digitalRead(BUTTON_PIN);

  // ***
  // *** Initialize the LED
  // ***
  digitalWrite(LED_PIN, _previousState);

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
  // *** Get the state of the button
  // ***
  byte buttonState = digitalRead(BUTTON_PIN);

  // ***
  // *** Check the value of the button pin
  // ***
  if (buttonState == LOW && _previousState == HIGH)
  {
    // ***
    // *** The button was pushed, turn the LED on.
    // ***
    Serial.println("The button was pushed, turning LED on.");
    digitalWrite(LED_PIN, LOW);
    _previousState = buttonState;
  }
  else if (buttonState == HIGH && _previousState == LOW)
  {
    // ***
    // *** The button was released, turn the LED off.
    // ***
    Serial.println("The button was released, turning LED off.");
    digitalWrite(LED_PIN, HIGH);
    _previousState = buttonState;
  }

  // ***
  // *** Short delay (to help de-bounce the switch)
  // ***
  delay(25);
}
