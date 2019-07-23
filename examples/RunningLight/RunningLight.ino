/**************************************************************************
 *
 * File: RunningLight.ino
 * Author: Julian Schuler (https://github.com/julianschuler)
 * License: MIT License, see LICENSE.txt
 * Description: This file is an example from the MCP23S08 library.
 *              It uses the MCP23S08 I/O expander to control 8 LEDs
 *              to display a small running light animation.
 *
 * Circuit: - MCP23S08 pin 1 to SCK (D13 on Arduino Uno)
 *          - MCP23S08 pin 2 to MOSI (D11 on Arduino Uno)
 *          - MCP23S08 pin 3 to MISO (D12 on Arduino Uno)
 *          - MCP23S08 pin 4, 5, 9 to GND
 *          - MCP23S08 pin 6, 18 to 5V
 *          - MCP23S08 pin 7 to D10
 *          - MCP23S08 pin 10 - 17 over an 220 Ohm resistor to the anode
 *              of a LED, LED kathode to GND
 *
 **************************************************************************/
 

#include <MCP23S08.h>


#define CS_PIN  10

MCP23S08 expander(CS_PIN);


void setup() {
  expander.begin();                         // begin communication with the pin/O expander
  for (uint8_t pin = 0; pin < 8; pin++) {   // pins 0 - 7 available
    expander.pinMode(pin, OUTPUT);          // set all pins to output
  }
}


void loop() {
  for (uint8_t pin = 0; pin < 7; pin++) {   // fist half of the animation, light running up
    expander.digitalWrite(pin, HIGH);       // turn LED on pin on
    delay(100);                             // wait 100ms
    expander.digitalWrite(pin, LOW);        // turn LED on pin off
  }
  for (uint8_t pin = 7; pin > 0; pin--) {   // fist half of the animation, light running down
    expander.digitalWrite(pin, HIGH);       // turn LED on pin on
    delay(100);                             // wait 100ms
    expander.digitalWrite(pin, LOW);        // turn LED on pin off
  }
}
