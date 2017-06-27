# Arduino

Arduino is probably the simplest development environment for developing with your eeZeeTiny board. It incorporates an Integrated Development Environment, toolchain, and software to flash the chip.

The following ATtiny microcontrollers are supported by Arduino with ATTinyCore:
* ATtiny25/45/85
* ATtiny24/44/84
* ATtiny441/841
* ATtiny2313/4313

You will also need a [Hardware Programmer](HardwareProgrammer.md).

You can find example code in the [Arduino examples](../examples/arduino) folder.

1. Download and install the Arduino IDE, version 1.6.* (You should only have to do this once after installing Arduino).
* Next, open the [Boards Manager](https://learn.adafruit.com/add-boards-arduino-v164) and install Spence Konde's [ATTinyCore](https://github.com/SpenceKonde/arduino-tiny-841)
* Select a board from the ```ATTiny Universal``` section of the ```Tools > Boards``` menu:
  * eeZeeTiny: select ```ATtiny25/45/85```
  * eeZeeMedTiny: select ```ATtiny24/44/84```
  * eeZeeTiny841: select ```ATtiny441/841```
  * eeZeeBigTiny: select ```ATtiny2313/4313```
* From the ```Tools``` menu select the chip that is installed on the board.
* Select the appropriate clock frequency:
  * No external crystal? Choose an ```(internal)``` option.
  * External crystal? Select an ```(external)``` frequency option matching your crystal. The eeZee boards ship with 8, 12, 14.7456, 16, or 20 MHz crystals.
* Programmer:
  * Select a programmer labeled ```(ATtiny)``` from ```Tools > Programmers``` corresponding to the hardware programmer you're using (See *Hardware Programmer*).

You should now be able to write your code and flash the chip.

[Return to README](README.md)
