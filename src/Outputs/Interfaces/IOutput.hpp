#pragma once
#include <Arduino.h>

class IOutput {
    public:
        virtual void set(int value) = 0;
    private:
        uint8_t pin;
};