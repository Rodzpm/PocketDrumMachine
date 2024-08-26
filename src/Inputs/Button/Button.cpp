#include "Button.hpp"

namespace Inputs {
    Button::Button(uint8_t pin) {
        this->_pin = pin;
        this->_button_state = NONE;
        pinMode(this->_pin, INPUT);
    }

    int Button::get() {
        int button_val = digitalRead(this->_pin);
        if (button_val == HIGH) {
            if (this->_button_state == PRESSED || this->_button_state == HOLD) {
                this->_button_state = HOLD;
            } else {
                this->_button_state = PRESSED;
            }
        } else {
            if (this->_button_state == PRESSED || this->_button_state == HOLD) {
                this->_button_state = RELEASED;
            } else {
                this->_button_state = NONE;
            }
        }
        return this->_button_state;
    }
}