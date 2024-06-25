#pragma once

#include "../Interfaces/IScreen.hpp"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

namespace Screen {
    class SSD1306 : public IScreen {
        public:
            SSD1306(int width, int height, int resetPin = -1);
            void render() override;
            void clear() override;
            void init() override;
            void drawBitmap(int x, int y, const unsigned char* bitmap, int width, int height) override;
            void drawText(int x, int y, int size, int color, const char* text) override;
            void setScreenWidth(int width) override;
            void setScreenHeight(int height) override;
            int getScreenWidth() override;
            int getScreenHeight() override;
        private:
            int screenWidth;
            int screenHeight;
            Adafruit_SSD1306 display;
    };
}