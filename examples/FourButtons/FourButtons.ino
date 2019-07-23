/**************************************************************************
 *
 * File: FourButtons.ino
 * Author: Julian Schuler (https://github.com/julianschuler)
 * License: MIT License, see LICENSE.txt
 * Description: This file is an example from the MCP23S08 library.
 *              It uses the MCP23S08 I/O expander to show the state
 *              of four buttons with four corresponding LEDs.
 *
 * Circuit: - MCP23S08 pin 1 to SCK (D13 on Arduino Uno)
 *          - MCP23S08 pin 2 to MOSI (D11 on Arduino Uno)
 *          - MCP23S08 pin 3 to MISO (D12 on Arduino Uno)
 *          - MCP23S08 pin 4, 5, 9 to GND
 *          - MCP23S08 pin 6, 18 to 5V
 *          - MCP23S08 pin 7 to D10
 *          - MCP23S08 pin 10 - 13 to a pushbutton connected to GND
 *          - MCP23S08 pin 14 - 17 over an 220 Ohm resistor to the anode
 *              of a LED, LED kathode to GND
 *
 **************************************************************************/
 

#include <MCP23S08.h>


#define CS_PIN  10

MCP23S08 expander(CS_PIN);


void setup() {
  expander.begin();                         // begin communication with the pin/O expander
  for (uint8_t pin = 0; pin < 4; pin++) {
    expander.pinMode(pin, INPUT_PULLUP);    // set pins 0 - 3 to input and enable pullups
  }
  for (uint8_t pin = 4; pin < 8; pin++) {   
    expander.pinMode(pin, OUTPUT);          // set pins 4 - 7 to output
  }
}


void loop() {
  for (uint8_t i = 0; i < 4; i++) {
    if (expander.digitalRead(i) == LOW) {   // test if button on pin i is pressed
      expander.digitalWrite(i+4, HIGH);     // turn corresponding LED on pin i+4 on
    }
    else {
      expander.digitalWrite(i+4, LOW);      // turn corresponding LED on pin i+4 off
    }
  }
}
