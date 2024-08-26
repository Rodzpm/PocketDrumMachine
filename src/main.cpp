#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"
#include "Inputs/Button/Button.hpp"
// #include "Inputs/Potentiometer/Potentiometer.hpp"

Components::Sequencer<uint8_t> sequencer(8, 180);
// InputsElt::Potentiometer potentiometer(0, 0, 1023, 60, 240);

void setup()
{
	Serial1.begin(115200);
	sequencer.getDisplay().setup();
	sequencer.getInputs().setup();
	delay(2000);
}

void loop()
{
	sequencer.update();
	LinkedList<InputsElt::Button *> inputs = sequencer.getInputs().getInputs();
	// for (int i = 0; i < inputs.size(); i++)
	// {
	// 	int state = inputs.get(i)->get();
	// 	if (state == InputsElt::PRESSED)
	// 	{
	// 		Serial1.print("Button ");
	// 		Serial1.print(i);
	// 		Serial1.println(" pressed");
	// 	}
	// 	else if (state == InputsElt::HOLD)
	// 	{
	// 		Serial1.print("Button ");
	// 		Serial1.print(i);
	// 		Serial1.println(" hold");
	// 	}
	// 	else if (state == InputsElt::RELEASED)
	// 	{
	// 		Serial1.print("Button ");
	// 		Serial1.print(i);
	// 		Serial1.println(" released");
	// 	}
	// }
}