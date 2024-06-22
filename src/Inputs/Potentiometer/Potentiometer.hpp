#pragma once
#include "../Interfaces/IInput.hpp"

namespace Inputs {
    class Potentiometer : public IInput {
        public:
            Potentiometer(uint8_t pin, int pot_min = 0, int pot_max = 1023, int min_val = 0, int max_val = 0);
            int get();
        private:
            uint8_t pin;
            int pot_val;
            int pot_min;
            int pot_max;
            int min_val;
            int max_val;
    };
}