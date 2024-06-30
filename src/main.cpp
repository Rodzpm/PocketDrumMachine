#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"
#include "Inputs/Potentiometer/Potentiometer.hpp"

Components::Sequencer<uint16_t> sequencer(16, 180);
Inputs::Potentiometer potentiometer(2, 0, 1023, 60, 240);


void setup() {
  	Serial.begin(9600);
  	sequencer.getDisplay().setup();
}

void loop() {
	//update potentiometer
	int pot_val = potentiometer.get();
	Serial.println(pot_val);
	sequencer.setBPM(pot_val);
	sequencer.update();
	sequencer.display();
}