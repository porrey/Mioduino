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
// *** Mioduino - LAB 8
// *** by Daniel Porrey
// ***

// ***
// *** This is the pin on which the sensor
// *** is connected.
// ***
#define ANALOG_PIN 0

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
  // *** Get a reading from the sensor.
  // ***
  unsigned int analogValue = analogRead(ANALOG_PIN);

  // ***
  // *** Calculate the voltage from the sensor (in mV)
  // ***
  double Vout = (analogValue / 1023.0) * 5.0;

  // ***
  // *** Convert the ADC reading to a Temperature in °C
  // ***
  double temperatureC = (100 * Vout) - 50;

  // ***
  // *** Convert the Temperature in °C to a Temperature in °F
  // ***
  double temperatureF = convertToFahrenheit(temperatureC);

  // ***
  // *** Display the results.
  // ***
  Serial.print("Analog Value = ");
  Serial.print(analogValue);
  Serial.print(", Voltage = ");
  Serial.print(Vout);
  Serial.print(" V, Temperature = ");
  Serial.print(temperatureC);
  Serial.print(" C / ");
  Serial.print(temperatureF);
  Serial.println(" F");

  // ***
  // *** Read the second every 2 seconds.
  // ***
  delay(2000);
}

// ***
// *** Converts temperature from Celsius to Fahrenheit.
// ***
double convertToFahrenheit(double celsius)
{
  return (celsius * 1.8) + 32.0;
}
