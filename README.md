# MCP23S08
## Overview
This library for the MCP23S08 SPI I/O expander allows adding up to 8 individual accessable I/O-pins with configurable internal pullup resistors to your projects. For a documentation and usage of the included functions, see examples.

## MCP23S08 vs MCP23008
In comparison to the MCP23008 complement using a two pin I²C bus, this expander is best suited for projects already utilizing another SPI device thus needing only one extra pin on the microcontroller resulting in a net gain of 7 I/O-pins (vs. a net gain of 6 I/O-pins when using the MCP23008 and no ther I²C devices). Furthermore using the SPI bus allows way higher communication Speeds (up to 10Mhz for SPI (MCP23S08) vs. up to 1.7Mhz @ 5V respectively up to 400kHz @ 3.3V for I²C (MCP23008)), this could be useful when using the extra I/O-pins for bitbanging operations.

## License
This project is licensed under the MIT License, see [`LICENSE.txt`](LICENSE.txt) for further information.
