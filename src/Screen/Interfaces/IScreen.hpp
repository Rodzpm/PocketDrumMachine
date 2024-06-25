#pragma once

class IScreen {
    public:
        virtual void render() = 0;
        virtual void clear() = 0;
        virtual void init() = 0;
        virtual void drawBitmap(int x, int y, const unsigned char* bitmap, int width, int height) = 0;
        virtual void drawText(int x, int y, int size, int color, const char* text) = 0;
        virtual void setScreenWidth(int width) = 0;
        virtual void setScreenHeight(int height) = 0;
        virtual int getScreenWidth() = 0;
        virtual int getScreenHeight() = 0;
    private:
        int screenWidth;
        int screenHeight;
};