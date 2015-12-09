
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
