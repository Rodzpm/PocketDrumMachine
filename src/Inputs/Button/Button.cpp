#include "Button.hpp"

namespace InputsElt {
    Button::Button(uint8_t pin) {
        this->_pin = pin;
        this->_button_state = NONE;
        pinMode(this->_pin, INPUT);
    }

    int Button::get() {
        return this->_button_state;
    }

    void Button::update_state(int button_val) {
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
    }
}