#pragma once
#include "../Interfaces/IInput.hpp"

namespace InputsElt {
    class Potentiometer : public IInput {
        public:
            Potentiometer(uint8_t pin, int pot_min = 0, int pot_max = 1023, int min_val = 0, int max_val = 0);
            int get();
        private:
            uint8_t _pin;
            int _pot_val;
            int _pot_min;
            int _pot_max;
            int _min_val;
            int _max_val;
    };
}