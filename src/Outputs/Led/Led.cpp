#include "Led.hpp"

namespace Outputs {
    Led::Led(uint8_t pin) {
        this->pin = pin;
        pinMode(this->pin, OUTPUT);
    }

    void Led::set(int value) {
        digitalWrite(this->pin, value);
    }
}