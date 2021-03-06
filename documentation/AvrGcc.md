# Getting Started With avr-gcc

You can find example code and makefiles in the [examples](../examples/avr-gcc) subdirectory of this repo.

## IDE

Here are a few of the options for writing code for AVR:

Lightweight, simple, code-aware text editors include:
  * Linux: Atom, Geany, Emacs
  * Windows: Notepad++, Emacs
  * MacOS X: TextWrangler, Emacs

Eclipse and the [AVR Plugin](http://avr-eclipse.sourceforge.net/wiki/index.php/The_AVR_Eclipse_Plugin) provide a full, if complex, IDE environment for developing for AVR processors. It is cross-platform (Linux, Mac, Windows).

## Toolchain

  * Windows: Install [Atmel AVR Toolchain for Windows](http://www.atmel.com/tools/atmelavrtoolchainforwindows.aspx)
  * Linux: Install [Atmel AVR Toolchain for Linux](http://www.atmel.com/tools/ATMELAVRTOOLCHAINFORLINUX.aspx) for either Windows or Linux.
  * For Mac, use [CrossPack for AVR](https://www.obdev.at/products/crosspack/index.html)

## Flashing with avrdude

* Install the latest version of [avrdude](http://www.nongnu.org/avrdude/).
* Example code includes makefiles that use avrdude.

## Hardware Programmer

You will also need a [Hardware Programmer](HardwareProgrammer.md)
