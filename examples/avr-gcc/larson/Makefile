###############################################################################
# Makefile for Larson scanner
###############################################################################

## Programmer
#PORT       = usb
#PROGRAMMER = dragon_isp
PORT       = /dev/ttyUSB0
PROGRAMMER = avrispv2
#PORT       = /dev/ttyUSB0
#PROGRAMMER = usbasp

## General Flags
PROJECT    = larson
TARGET     = $(PROJECT).elf
AVRBIN 	   = /opt/avr/bin
CC         = $(AVRBIN)/avr-gcc
CPP        = $(AVRBIN)/avr-g++
OBJCOPY    = $(AVRBIN)/avr-objcopy
OBJDUMP    = $(AVRBIN)/avr-objdump
SIZE       = $(AVRBIN)/avr-size
AVRDUDE    = avrdude

ifeq ($(MAKECMDGOALS), t85)
  # ATtiny85 build variables
  MCU   = attiny85
  F_CPU = 1000000UL
  LFUSE = 0x62
  HFUSE = 0xdf
  EFUSE = 0xff
  FUSES = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
endif

ifeq ($(MAKECMDGOALS), t13)
  #ATtiny13 build variables
  MCU   = attiny13
  F_CPU = 1200000UL
  LFUSE = 0x6a
  HFUSE = 0xff
  FUSES = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m
endif

ifeq ($(MAKECMDGOALS), install)
  include target.mk
endif

## Objects that must be built in order to link
OBJECTS = larson.o 

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=$(F_CPU) -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=$(PROJECT).map

## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Targets

all:
	@echo "Please select a target MCU:"
	@echo "  make t85"
	@echo "or"
	@echo "  make t13"

# Build for t85
t85: clean save_target
t85: $(TARGET) $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss size

# Build for t13
t13: clean save_target
t13: $(TARGET) $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss size

save_target:
	@echo "saving target"
	@echo "MCU = $(MCU)" > target.mk
	@echo "FUSES = $(FUSES)" >> target.mk

## Compile
main.o: main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	$(OBJCOPY) -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-$(OBJCOPY) $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	$(OBJDUMP) -h -S $< > $@

install: $(PROJECT).hex 
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -v -U flash:w:$(PROJECT).hex $(FUSES)

## required for avr dragon to reset itself
delay: fuses
	@sleep 3

fuses:
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -v $(FUSES)

size: ${TARGET}
	@echo
	@$(SIZE) -C --mcu=$(MCU) $(TARGET)

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(PROJECT).elf dep/* $(PROJECT).hex $(PROJECT).eep $(PROJECT).lss $(PROJECT).map target.mk


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

