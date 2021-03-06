// -*- mode: C -*-
#include "east-hid.h"

void setup() {
	pinMode(0,  INPUT_PULLUP);
	pinMode(1,  INPUT_PULLUP);
	pinMode(2,  INPUT_PULLUP);
	pinMode(3,  INPUT_PULLUP);
	pinMode(4,  INPUT_PULLUP);
	pinMode(5,  INPUT_PULLUP);
	pinMode(6,  INPUT_PULLUP);
	pinMode(7,  INPUT_PULLUP);
	pinMode(8,  INPUT_PULLUP);
	pinMode(9,  INPUT_PULLUP);
	pinMode(10, INPUT_PULLUP);
	pinMode(11, INPUT_PULLUP);
	pinMode(12, INPUT_PULLUP);

	pinMode(13, OUTPUT);    // for arduino debug LED
}

static   uint16_t prev_btns;
static   uint16_t prev_ana0;

void loop() {
	uint16_t btns;
	uint16_t ana0;

        ana0 = analogRead(0);
	btns = 0;
	if(digitalRead(0)  == 0) btns |= 1<<0;
	if(digitalRead(1)  == 0) btns |= 1<<1;
	if(digitalRead(2)  == 0) btns |= 1<<2;
	if(digitalRead(3)  == 0) btns |= 1<<3;
	if(digitalRead(4)  == 0) btns |= 1<<4;
	if(digitalRead(5)  == 0) btns |= 1<<5;
	if(digitalRead(6)  == 0) btns |= 1<<6;
	if(digitalRead(7)  == 0) btns |= 1<<7;
	if(digitalRead(8)  == 0) btns |= 1<<8;
	if(digitalRead(9)  == 0) btns |= 1<<9;
	if(digitalRead(10) == 0) btns |= 1<<10;
	if(digitalRead(11) == 0) btns |= 1<<11;
	if(digitalRead(12) == 0) btns |= 1<<12;

	// test hack: last few buttons always pressed.
	btns |= 1<<14;
	btns |= 1<<15;

	if(btns != prev_btns || ana0 != prev_ana0) {
		Gamepad.move(btns, ana0>>2);
	}

	prev_btns = btns;
        prev_ana0 = ana0;
}
