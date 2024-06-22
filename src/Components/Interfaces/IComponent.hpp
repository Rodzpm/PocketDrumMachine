#include <Arduino.h>

class IComponent {
    public:
        virtual int get() = 0;
    private:
        uint8_t pin;
};