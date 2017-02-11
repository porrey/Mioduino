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
// *** Mioduino - LAB 7
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
// *** This defines the value of R2 in the voltage
// *** divider. In a voltage divider, R1 is the
// *** resistror connected to the voltage source
// *** and R2 is the resistor connected to Ground.
// *** The equation is
// ***
// *** Vo = (Vi x R2) / (r1 + R2)
// ***
// *** In this lab, R1 is the 10K Ω potentiomter
// *** and R2 is a 10K Ω resistor.
// ***
#define R2 10000
#define R1_MAX 10000

// ***
// *** Defines the voltage source which
// *** is 5V0.
// ***
#define V_REF 5.0

// ***
// *** Previous resistor value. Used to limit
// *** the amount of serial output.
// ***
double _previousValue = 0.0;

// ***
// *** The amount of tolerance allowed in
// *** each reading before it is consdiered
// *** a new value. If the serial port displays
// *** a reading without touching the potentiomter,
// *** or if it seems too sensitive, adjust this
// *** number a little higher.
// ***
#define TOLERANCE .05

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
  // *** Initialize the LED
  // ***
  setLed(analogRead(ANALOG_PIN));

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
  // *** Calculate the resistance of the potentiomter
  // *** using the voltage divider equation.
  // ***
  unsigned int analogValue = analogRead(ANALOG_PIN);

  // ***
  // *** Display the voltage being read
  // ***
  double V_out = (analogValue / 1023.0) * V_REF;

  // ***
  // *** Solve for R1 using the Voltage
  // *** Divider equation.
  // ***
  double r1 = ((V_REF * R2) - (V_out * R2)) / V_out;

  // ***
  // *** If the value changes more thana the
  // *** specified tolerance then display the
  // *** data (we do not want data displaying
  // *** in every loop iteration).
  // ***
  if (isDifferent(_previousValue, r1, TOLERANCE))
  {
    // ***
    // *** Display the data if it has changed
    // ***
    Serial.print("Analog value = ");
    Serial.print(analogValue);
    Serial.print(", Vout = ");
    Serial.print(V_out);
    Serial.print("V");
    Serial.print(", R1 = ");

    if (r1 >= 1000)
    {
      // ***
      // *** Display the value in Kilo-Ohms (KΩ)
      // ***
      Serial.print(r1 / 1000.0);
      Serial.println("K");
    }
    else
    {
      // ***
      // *** Display the value in Ohms (Ω)
      // ***
      Serial.println(r1);
    }

    // ***
    // *** Update _previousValue.
    // ***
    _previousValue = int(r1);
  }

  // ***
  // *** Set the brightness of the
  // *** LED using PWM.
  // ***
  setLed(analogValue);

  // ***
  // *** Small delay
  // ***
  delay(50);
}

// ***
// *** Sets the brightness of the LED
// *** based on the analog input value.
// ***
void setLed(unsigned int analogValue)
{
  // ***
  // *** Since we are using a voltage divider, the analog
  // *** value read on the port will never be 0. We need
  // *** calculate the lowest possible value based on our
  // *** resistors values in order to get the map function
  // *** to work correctly. The minimum value will be when
  // *** the potentiometer is at its maximum value (10K).
  // ***
  // ***   Vo = (Vi x R2) / (r1 + R2)
  // ***
  double minimumVout = (V_REF * R2) / (R1_MAX + R2);

  // ***
  // *** Map this to the analog port range (0 to 1023).
  // ***
  unsigned int analogMinimum = int((minimumVout / V_REF) * 1023);

  // ***
  // *** Scale the analog value to a
  // *** number between 0 and 255 to be
  // *** passed to the analogWrite function.
  // ***
  // *** NOTE: map() does not constrain the value
  // *** so, constrain() is also used here.
  // ***
  unsigned int led = constrain(map(analogValue, analogMinimum, 1023, 0, 255), 0, 255);

  // ***
  // *** The value is inverted since the
  // *** LED cathode is tied to ground and
  // *** not the data pin.
  // ***
  analogWrite(LED_PIN, 255 - led);
}

// ***
// *** Compares the previous reading to the current reading with
// *** and specified tolerance and determines if the new reading
// *** is outside of this tolerance. If yes, then the current value
// *** is consider different.
// ***
bool isDifferent(double previousValue, double currentValue, double tolerance)
{
  bool returnValue = false;

  // ***
  // *** Calculate the upper value in the tolerance range
  // *** based on the previous value.
  // ***
  double upperValue = previousValue + (previousValue * tolerance);

  // ***
  // *** Calculate the lower value in the tolerance range
  // *** based on the previous value.
  // ***
  double lowerValue = previousValue - (previousValue * tolerance);

  // ***
  // *** Check if the current value is outside of the tolerance
  // *** or not.
  // ***
  if (currentValue < lowerValue || currentValue > upperValue)
  {
    // ***
    // *** The current value is outside of the tolerance
    // *** so return true.
    // ***
    returnValue = true;
  }

  return returnValue;
}
