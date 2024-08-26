#include <Keypad.h>
#include <Inputs/MembKeypad/MembKeypad.hpp>
#include "Screen/SSD1306/SSD1306.hpp"
#include "bitmap/bli7.hpp"

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Screen::SSD1306 display(128, 64);
char curr_key = NO_KEY;

void setup()
{
	Serial1.begin(115200);
	display.init();
	display.fillScreen(BLACK);
	display.drawBitmap(0, 0, bli7_logo, WHITE, 128, 64);
	display.render();
	delay(1000);
	display.clear();
	display.render();
}

void loop()
{
	char key = keypad.getKey();

	if (key != NO_KEY)
	{
		curr_key = key;
	}
	if (curr_key != NO_KEY)
	{
		display.clear();
		display.drawText(54, 12, 5, WHITE, &curr_key);
		display.render();
	}
	delay(10);
}
