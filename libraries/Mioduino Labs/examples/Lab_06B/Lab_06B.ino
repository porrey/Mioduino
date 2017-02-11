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
// *** Mioduino - LAB 6B
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
// *** The values below specify the minimum and maximum
// *** values that can be read on the analog port. The
// *** values 0 and 1023 represent the minimum and maximum
// *** based on the pin. The circuit, however, will not
// *** have these same values because the voltage will not
// *** reach 0V or 5V because we are using a voltage divider.
// *** Try "tuning" these values to make the night light
// *** respond better to changing light. HINT: Display the
// *** analog value read from the port in the Serial Monitor
// *** using a Serial.println() statement and then use a
// *** flashlight to see the actual range of the values.
// *** Plug these values into the define statements below
// *** and then re-upload the sketch.
// ***
#define ANALOG_MINIMUM 0
#define ANALOG_MAXIMUM 1023

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
  setLed();

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
void setLed()
{
  // ***
  // *** Read the sensor value from the analog port.
  // ***
  unsigned int analogValue = analogRead(ANALOG_PIN);

  // ***
  // *** Uncomment this line to view the
  // *** value being read from the analog
  // *** port.
  // ***
  //Serial.print("Analog value = "); Serial.println(analogValue);

  // ***
  // *** Adjust the LED using PWM. If the sensor detects less
  // *** light (it is darker) then the LED will get brighter.
  // *** When more light is detected on the sensor, the LED
  // *** will decrease in intensity.
  // ***
  unsigned int led = constrain(map(analogValue, ANALOG_MINIMUM, ANALOG_MAXIMUM, 0, 255), 0, 255);
  analogWrite(LED_PIN, led);

  // ***
  // *** Uncomment this line to view the
  // *** value being used on the LED. Remember
  // *** that since the LED is connected to 5V,
  // *** a higher number reduces intensity.
  // ***
  //Serial.print("\tPWM value = "); Serial.println(led);
}
