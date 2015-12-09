// USB HID Gamepad/joystick code
//
// based on http://arduino.cc/en/Tutorial/KeyboardMessage
// and PluggableHID-howto on arduino github.

#include "HID.h"
#include "east-hid.h"

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
