# arduino-driver-ctrl
Code for custom driver station control boxes with arduino
By Steve Tell and FRC Team 4795


Prerequisites:

Arduino software development kit.  This has been tested with arduino-1.6.6
from https://www.arduino.cc/en/Main/Software


Building:

1. If using the arduino GUI, open east-box/east-box.ino 
	Select your board
	compile
	upload      

2. To compile using traditional linux make, retrieve
   Arduino-Makefile from https://github.com/sudar/Arduino-Makefile and put it
   into the directory above this one.  type:
   cd ..
   git clone https://github.com/sudar/Arduino-Makefile.git

3. Then cd into east-box, and type make.

4. To program to your Arduino board, type "make upload".
   you might have to hit the reset button on the board just as you hit
   return after "make upload"


For older versions of the arduino SDK: see instructions in old-asdk/Readme.