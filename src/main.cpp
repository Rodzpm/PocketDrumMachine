#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"

Components::Sequencer<uint16_t> sequencer(16, 180);

void setup() {
  	Serial.begin(9600);
  	sequencer.getDisplay().setup();
}

void loop() {
  sequencer.update();
	sequencer.display();
}