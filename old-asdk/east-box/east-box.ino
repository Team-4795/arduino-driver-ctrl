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

static   uint16_t prev_btns;

void loop() {
	uint16_t btns;
  
	btns = 0;
	btns |= 0x8000;  // test hack: button 15 always pressed.

	if(digitalRead(8) == 0)
		btns |= 1;
	if(digitalRead(10) == 0)
		btns |= 2;
	if(digitalRead(11) == 0)
		btns |= 4;
	if(digitalRead(12) == 0)
		btns |= 8;

	if(btns != prev_btns) {
		Gamepad.move(btns);
	}

	prev_btns = btns;
}
