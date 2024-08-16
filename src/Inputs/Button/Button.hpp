#pragma once
#include "../Interfaces/IInput.hpp"

namespace InputsElt {

    enum ButtonState {
        PRESSED,
        HOLD,
        RELEASED,
        NONE
    };

    class Button : public IInput {
        public:
            Button(uint8_t pin);
            int get();
        private:
            uint8_t _pin;
            ButtonState _button_state;
    };
}