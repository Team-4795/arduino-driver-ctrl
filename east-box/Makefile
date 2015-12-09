#
# per-project makefile for use with the Arduino-Makefile package
# based on https://github.com/sudar/Arduino-Makefile

# settings here might need to be changed.

# Where you've put the Arduino-Makefile package
ARDMK_DIR=../../Arduino-Makefile

# Choose your arduino board type here.
BOARD_TAG    = micro
#BOARD_TAG    = leonardo

#ARDUINO_LIBS = 

# uncomment these to use the arduino packages installed using your native 
# linux package manager. 
#AVR_TOOLS_DIR=/usr
#ARDUINO_DIR   = /usr/share/arduino

# this is where I put the contents of arduino-1.6.6-linux32.tar.xz
# or arduino-1.6.6-linux64.tar.xz
# change it if you've put it somewhere else.
ARDUINO_DIR   = /opt/arduino-1.6.6

AVRDUDE_OPTS = -v -v

CFLAGS += -DCDC_ENABLED -DHID_JOYSTICK
CXXFLAGS += -DCDC_ENABLED -DHID_JOYSTICK -std=c++11 -fno-exceptions

include $(ARDMK_DIR)/Arduino.mk
