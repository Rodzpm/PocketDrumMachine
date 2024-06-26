#pragma once
#include <LinkedList.h>
#include <Arduino.h>


template <typename T>
class Display {
public:
    Display(int size, int dataPin, int clockPin, int latchPin) :
        size(size),
        dataPin(dataPin),
        clockPin(clockPin),
        latchPin(latchPin),
        data(0)
    {}

    void setDisplayData(T data)
    {
        Serial.println(data);
        this->data = data;
    }

    T getDisplayData()
    {
        return this->data;
    }

    void setDisplayDataAt(int index, int data)
    {
        if (index >= this->size) {
            return;
        }
        if (data) {
            this->data |= (1 << index);
        } else {
            this->data &= ~(1 << index);
        }
    }
    int getDisplayDataAt(int index)
    {
        return (this->data & (1 << index)) ? 1 : 0;
    }

    void display()
    {
        digitalWrite(this->latchPin, LOW);
        for (int i = 0; i < this->size; i++) {
            digitalWrite(this->clockPin, LOW);
            digitalWrite(this->dataPin, (this->data & (1 << i)) ? HIGH : LOW);
            digitalWrite(this->clockPin, HIGH);
        }
        digitalWrite(this->latchPin, HIGH);
    }
    void setup()
    {
        pinMode(this->dataPin, OUTPUT);
        pinMode(this->clockPin, OUTPUT);
        pinMode(this->latchPin, OUTPUT);
    }
    void clear()
    {
        this->data = 0;
    }

    void setSize(int size)
    {
        this->size = size;
    }
    int getSize()
    {
        return this->size;
    }
private:
    int size;
    int dataPin;
    int clockPin;
    int latchPin;
    T data;
};
