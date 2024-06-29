#include "Led.hpp"

namespace Outputs {
    Led::Led(uint8_t pin) {
        this->_pin = pin;
        pinMode(this->_pin, OUTPUT);
    }

    void Led::set(int value) {
        digitalWrite(this->_pin, value);
    }
}