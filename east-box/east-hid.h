
typedef struct {
	uint8_t buttons[2];
	uint8_t throttle;
} GamepadReport;

class Gamepad_
{
private:
	GamepadReport report;
public:
	Gamepad_(void);
	void begin(void);
	void end(void);
	void move(uint16_t b, uint8_t throttle);
};
extern Gamepad_ Gamepad;
