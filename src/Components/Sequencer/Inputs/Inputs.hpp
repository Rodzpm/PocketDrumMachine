#pragma once
#include <Arduino.h>


template <typename T>
class Inputs {
public:
    Inputs(int size, int dataPin, int clockPin, int latchPin) :
        _size(size),
        _dataPin(dataPin),
        _clockPin(clockPin),
        _latchPin(latchPin)
    {}

    T getInputs(void)
    {
        T data = 0;
        digitalWrite(this->_latchPin, LOW);
        digitalWrite(this->_latchPin, HIGH);

        for (int i = 0; i < this->_size; i++) {
            digitalWrite(this->_clockPin, LOW);
            data |= digitalRead(this->_dataPin) << i;
            digitalWrite(this->_clockPin, HIGH);
        }

        return data;
    }
    void setup()
    {
        pinMode(this->_dataPin, INPUT);
        pinMode(this->_clockPin, OUTPUT);
        pinMode(this->_latchPin, OUTPUT);
    }

    void setSize(int size)
    {
        this->_size = size;
    }
    int getSize()
    {
        return this->_size;
    }
private:
    int _size;
    int _dataPin;
    int _clockPin;
    int _latchPin;
};
