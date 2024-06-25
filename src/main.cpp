#include "Screen/SSD1306/SSD1306.hpp"
#include "bitmap/bli7.hpp"

Screen::SSD1306 display(128, 64, -1);
bool boot = true;

void setup() {
    // Initialiser la communication série pour le débogage
    Serial.begin(9600);
    display.init();
}

void splash_screen()
{
    display.clear();
    display.drawBitmap(0, 0, bli7_logo, 128, 64);
    display.render();
    delay(2000);
}

void loop() {
    if (boot) {
        splash_screen();
        boot = false;
    }
    display.clear();
    display.drawText(0, 0, 1, WHITE, "Hello, World!");
    display.drawText(0, 10, 1, WHITE, "This is a test.");
    display.render();
}