/**************************************************************************
 *
 * File: FourButtons.ino
 * Author: Julian Schuler (https://github.com/julianschuler)
 * License: MIT License, see LICENSE.txt
 * Description: This file is an example from the MCP23S08 library.
 *              It uses the MCP23S08 I/O expander to show the state
 *              of four buttons with four corresponding LEDs.
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
