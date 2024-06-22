#include "Button.hpp"

namespace Inputs {
    Button::Button(uint8_t pin) {
        this->pin = pin;
        this->button_state = NONE;
        pinMode(this->pin, INPUT);
    }

    int Button::get() {
        int button_val = digitalRead(this->pin);
        if (button_val == HIGH) {
            if (this->button_state == PRESSED || this->button_state == HOLD) {
                this->button_state = HOLD;
            } else {
                this->button_state = PRESSED;
            }
        } else {
            if (this->button_state == PRESSED || this->button_state == HOLD) {
                this->button_state = RELEASED;
            } else {
                this->button_state = NONE;
            }
        }
        return this->button_state;
    }
}