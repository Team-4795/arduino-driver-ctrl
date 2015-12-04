# arduino-driver-ctrl
Code for custom driver station control boxes with arduino
By Steve Tell and FRC Team 4795


Building:

1. patch the files in arduino-core into your arduino library installation, 
replacing the same-named files found there.   More details in arduino-core/Readme.

2. if using the arduino GUI, open east-box/east-box.ino and compile.

3. To compile using traditional linux make, get Arduino-Makefile from 
   https://github.com/sudar/Arduino-Makefile.  type:
   git clone https://github.com/sudar/Arduino-Makefile.git

4. then cd into east-box, and type make.

5. to program to your Arduino board, type "make upload".
   you'll probably have to hit the reset button on the board just as you hit
   return after "make upload"
