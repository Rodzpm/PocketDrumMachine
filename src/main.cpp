#include <Arduino.h>
#include "Components/Sequencer/Sequencer.hpp"

Components::Sequencer<uint16_t> sequencer(16);

void setup() {
  Serial.begin(9600);
  sequencer.getDisplay().setup();
  sequencer.getDisplay().setDisplayData(0b1010101010101010);
}

void loop() {
  sequencer.display();
}