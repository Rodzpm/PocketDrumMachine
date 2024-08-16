#include "Potentiometer.hpp"

namespace InputsElt {
    Potentiometer::Potentiometer(uint8_t pin, int pot_min, int pot_max, int min_val, int max_val) {
        this->_pin = pin;
        this->_pot_min = pot_min;
        this->_pot_max = pot_max;
        this->_min_val = min_val;
        this->_max_val = max_val;
    }

    int Potentiometer::get() {
        this->_pot_val = analogRead(this->_pin);
        this->_pot_val = map(this->_pot_val, this->_pot_min, this->_pot_max, this->_min_val, this->_max_val);
        return this->_pot_val;
    }
}