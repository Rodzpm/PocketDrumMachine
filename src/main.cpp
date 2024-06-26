#include "Screen/SSD1306/SSD1306.hpp"
#include "bitmap/bli7.hpp"
#include "bitmap/icon.hpp"
#include "Tools/BPM/BPM.hpp"
#include "Inputs/Potentiometer/Potentiometer.hpp"

Screen::SSD1306 display(128, 64, -1);
Tools::BPM bpm(120);
Inputs::Potentiometer potentiometer(A3, 0, 1023, 60, 200);
bool boot = true;

void setup() {
    // Initialiser la communication série pour le débogage
    Serial.begin(9600);
    display.init();
}

void splash_screen()
{
    display.clear();
    display.drawBitmap(0, 0, bli7_logo, WHITE, 128, 64);
    display.render();
    delay(2000);
}

void loop() {
    if (boot) {
        splash_screen();
        boot = false;
    }
    int value = potentiometer.get();
    bpm.setBPM(value);
    display.clear();
    display.fillScreen(WHITE);
    display.drawBitmap(0, 0, metronome, BLACK, 16, 16);
    display.drawText(15, 5, 1, BLACK, String(bpm.getBPM()).c_str());
    display.render();
}