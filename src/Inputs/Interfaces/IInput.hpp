#pragma once
#include <Arduino.h>

class IInput {
    public:
        virtual int get() = 0;
    private:
        uint8_t pin;
};