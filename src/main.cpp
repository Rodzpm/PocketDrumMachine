#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"
#include "Inputs/Potentiometer/Potentiometer.hpp"

Components::Sequencer<uint16_t> sequencer(16, 180);
InputsElt::Potentiometer potentiometer(0, 0, 1023, 60, 240);

void setup()
{
	Serial1.begin(115200);
	sequencer.getDisplay().setup();
	sequencer.getInputs().setup();
}

void loop()
{
	int pot_val = potentiometer.get();
	sequencer.setBPM(pot_val);
	sequencer.update();
	sequencer.display();
}