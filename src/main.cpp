#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"

Components::Sequencer<uint16_t> sequencer(16);

void setup() {
  Serial.begin(9600);
  sequencer.getDisplay().setup();
  sequencer.getDisplay().setDisplayData(0b1111111110111111);
}

void loop() {
  sequencer.display();
}