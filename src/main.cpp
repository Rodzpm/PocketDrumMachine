#include <Arduino.h>
#include "Inputs/MembKeypad/MembKeypad.hpp"

Keypad keymap(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS);

void setup()
{
	Serial1.begin(115200);
}

void loop()
{
	char key = keymap.getKey();
	if (key)
	{
		Serial1.println(key);
	}
	delay(10);
}