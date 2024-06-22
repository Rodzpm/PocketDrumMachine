#include "Potentiometer.hpp"

namespace Components {
    Potentiometer::Potentiometer(uint8_t pin, int pot_min = 0, int pot_max = 1023, int min_val = 0, int max_val = 0) {
        this->pin = pin;
        this->pot_min = pot_min;
        this->pot_max = pot_max;
        this->min_val = min_val;
        this->max_val = max_val;
    }

    int Potentiometer::get() {
        this->pot_val = analogRead(this->pin);
        this->pot_val = map(this->pot_val, this->pot_max, this->pot_min, this->min_val, this->max_val);
        return this->pot_val;
    }
}