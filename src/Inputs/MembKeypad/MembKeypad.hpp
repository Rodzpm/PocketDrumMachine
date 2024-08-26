#pragma once
#include <Arduino.h>
#include <Keypad.h>

const uint8_t ROWS = 4;
const uint8_t COLS = 4;

char keyMap[ROWS][COLS] = {
    { '1', '2', '3', 'A' },
    { '4', '5', '6', 'B' },
    { '7', '8', '9', 'C' },
    { '*', '0', '#', 'D' }
};
        
uint8_t rowPins[ROWS] = { 26, 22, 21, 20 }; // Pins connected to R1, R2, R3, R4
uint8_t colPins[COLS] = { 19, 18, 17, 16 }; // Pins connected to C1, C2, C3, C4

namespace Inputs {
    class MembKeypad {
        public:
            MembKeypad(uint8_t pin);
            int get();
        private:
            Keypad *_keypad;
            u_int8_t _pin;
    };
}