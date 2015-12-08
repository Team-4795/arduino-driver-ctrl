#
# per-project makefile for use with the Arduino-Makefile package
# from https://github.com/sudar/Arduino-Makefile
#
ARDMK_DIR=../../Arduino-Makefile

# Choose your arduino board type here.
BOARD_TAG    = micro
#BOARD_TAG    = leonardo

#ARDUINO_LIBS = 

# set these to use arduino packages installed using your native 
# linux package manager. 
#AVR_TOOLS_DIR=/usr
#ARDUINO_DIR   = /usr/share/arduino
ARDUINO_DIR   = /opt/arduino-1.6.6

AVRDUDE_OPTS = -v -v

CFLAGS += -DCDC_ENABLED -DHID_JOYSTICK
CXXFLAGS += -DCDC_ENABLED -DHID_JOYSTICK -std=c++11 -fno-exceptions

include $(ARDMK_DIR)/Arduino.mk
