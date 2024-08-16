#include "SSD1306.hpp"

namespace Screen
{
    SSD1306::SSD1306(int width, int height, int resetPin)
    {
        this->screenWidth = width;
        this->screenHeight = height;
        this->display = Adafruit_SSD1306(width, height, &Wire, resetPin);
    }

    void SSD1306::render()
    {
        this->display.display();
    }

    void SSD1306::clear()
    {
        this->display.clearDisplay();
    }

    void SSD1306::init()
    {
        if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        { // Address 0x3D for 128x64
            Serial.println(F("SSD1306 allocation failed"));
            for (;;)
                ;
        }
    }

    void SSD1306::fillScreen(int color)
    {
        this->display.fillScreen(color);
    }

    void SSD1306::drawBitmap(int x, int y, const unsigned char *bitmap, int color, int width, int height)
    {
        this->display.drawBitmap(x, y, bitmap, width, height, color);
    }

    void SSD1306::drawText(int x, int y, int size, int color, const char *text)
    {
        this->display.setTextSize(size);
        this->display.setTextColor(color);
        this->display.setCursor(x, y);
        this->display.print(text);
    }

    void SSD1306::setScreenWidth(int width)
    {
        this->screenWidth = width;
    }

    void SSD1306::setScreenHeight(int height)
    {
        this->screenHeight = height;
    }

    int SSD1306::getScreenWidth()
    {
        return this->screenWidth;
    }

    int SSD1306::getScreenHeight()
    {
        return this->screenHeight;
    }
}