#include <Arduino.h>
// #include "Components/Sequencer/Sequencer.hpp"
// #include "Inputs/Potentiometer/Potentiometer.hpp"
#include "Screen/SSD1306/SSD1306.hpp"
#include "bitmap/bli7.hpp"

// Components::Sequencer<uint16_t> sequencer(16, 180);
// InputsElt::Potentiometer potentiometer(0, 0, 1023, 60, 240);
Screen::SSD1306 display(128, 64);

void setup()
{
	Serial1.begin(115200);
	// sequencer.getDisplay().setup();
	// sequencer.getInputs().setup();
	display.init();
}

void loop()
{
	display.fillScreen(BLACK);
	display.drawBitmap(0, 0, bli7_text, WHITE, 128, 64);
	display.render();
	// int pot_val = potentiometer.get();
	// sequencer.setBPM(pot_val);
	// sequencer.update();
	// sequencer.display();
}