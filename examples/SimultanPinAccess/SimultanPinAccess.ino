/**************************************************************************
 *
 * File: SimultanPinAccess.ino
 * Author: Julian Schuler (https://github.com/julianschuler)
 * License: MIT License, see LICENSE.txt
 * Description: This file is an example from the MCP23S08 library.
 *              It shows advanced usage of the MCP23S08 port expander
 *              by controlling 8 LEDs simultaniously.
 *
 **************************************************************************/
 

#include <MCP23S08.h>


#define CS_PIN  10

MCP23S08 expander(CS_PIN);


void setup() {
  expander.begin();                     // begin communication with the I/O expander
  expander.setPinModes(B11111111);      // set all pins to output
  expander.setOutputStates(B01010101);  // turn one half of the LEDs on, one half off
}


void loop() {
  uint8_t outputStates = expander.getOutputStates();  // get output states of all pins
  expander.setOutputStates(~(outputStates));          // set output states to am inverse of the previous states
  delay(500);                                         // wait half a second
}
