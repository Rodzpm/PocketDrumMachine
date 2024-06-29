#pragma once
#include <Arduino.h>


template <typename T>
class Display {
public:
    Display(int size, int dataPin, int latchPin, int clockPin) :
        _size(size),
        _dataPin(dataPin),
        _clockPin(clockPin),
        _latchPin(latchPin)
    {}

    void display(T data)
    {
        digitalWrite(this->_latchPin, LOW);
        for (int i = 0; i < this->_size; i++) {
            digitalWrite(this->_clockPin, LOW);
            digitalWrite(this->_dataPin, (data & (1 << i)) ? HIGH : LOW);
            digitalWrite(this->_clockPin, HIGH);
        }
        digitalWrite(this->_latchPin, HIGH);
    }
    void setup()
    {
        pinMode(this->_dataPin, OUTPUT);
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
