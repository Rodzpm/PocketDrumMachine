#pragma once
#include "../Interfaces/IOutput.hpp"

namespace Outputs {
    class Led : public IOutput {
        public:
            Led(uint8_t pin);
            void set(int value);
        private:
            uint8_t _pin;
    };
}