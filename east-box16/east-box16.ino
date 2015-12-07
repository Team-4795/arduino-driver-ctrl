// -*- mode: C -*-

// based on http://arduino.cc/en/Tutorial/KeyboardMessage
// and PluggableHID-howto on arduino github.

#include "HID.h"

#ifdef _USING_HID

#include "USBAPI.h"

static const u8 _hidReportDescriptor[] PROGMEM = {
    // Gamepad
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x05,                    // USAGE (Game Pad)
    0xa1, 0x01,                    // COLLECTION (Application)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x85, 0x03,                    //     REPORT_ID (3)  -- arg to HID_SendReport
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x10,                    //     USAGE_MAXIMUM (Button 16)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x95, 0x10,                    //     REPORT_COUNT (16)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)

    0xc0,                          //   END_COLLECTION
    0xc0                           // END_COLLECTION
};

typedef struct {
	uint8_t buttons[2];
} GamepadReport;

class Gamepad_
{
private:
	GamepadReport report;
public:
	Gamepad_(void);
	void begin(void);
	void end(void);
	void move(uint16_t b);
};
extern Gamepad_ Gamepad;

// putting this outside gets rid of one __cxa_guard_acquire error.
HIDSubDescriptor desc_node(_hidReportDescriptor, sizeof(_hidReportDescriptor));

Gamepad_::Gamepad_(void)
{
//	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&desc_node);
	report.buttons[0] = 0;
	report.buttons[1] = 0;
}

void Gamepad_::begin(void)
{
}

void Gamepad_::end(void)
{
}

void Gamepad_::move(uint16_t bs)
{
	report.buttons[0] = bs & 0xff;
	report.buttons[1] = bs >> 8;
	HID().SendReport(3, &report, 2);
}


Gamepad_ Gamepad;  // single object instance.

#endif

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
