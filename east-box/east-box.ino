// -*- mode: C -*-

// based on http://arduino.cc/en/Tutorial/KeyboardMessage

void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  pinMode(13, OUTPUT);    // for a debug LED
#ifdef HID_KEYBOARD
  Keyboard.begin();
#endif

}

static   uint8_t prev_btns;

void loop() {
	uint8_t btns;
  
	btns = 0;
	if(digitalRead(8) == 0)
		btns |= 1;
	if(digitalRead(10) == 0)
		btns |= 2;
	if(digitalRead(11) == 0)
		btns |= 4;
	if(digitalRead(12) == 0)
		btns |= 8;

	if((btns&1) != (prev_btns&1)) {
		if(btns&1)  {
			Gamepad.press(1);
//			digitalWrite(13, HIGH);
		} else {
			Gamepad.release(1);
//			digitalWrite(13, LOW);
		}
	}
	if((btns&2) != (prev_btns&2)) {
		if(btns&2) 
			Gamepad.press(2);
		else
			Gamepad.release(2);
	}
	if((btns&4) != (prev_btns&4)) {
		if(btns&4) 
			Gamepad.press(4);
		else
			Gamepad.release(4);
	}
	if((btns&8) != (prev_btns&8)) {
		if(btns&8) 
			Gamepad.press(8);
		else
			Gamepad.release(8);
	}
	prev_btns = btns;
}
