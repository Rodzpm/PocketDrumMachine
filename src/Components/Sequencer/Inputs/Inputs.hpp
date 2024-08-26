#pragma once
#include <Arduino.h>
#include <LinkedList.h>
#include <Chrono.h>
#include "Inputs/Button/Button.hpp"


template <typename T>
class Inputs {
public:
    Inputs(int size, int dataPin, int clockPin, int latchPin) :
        _size(size),
        _dataPin(dataPin),
        _clockPin(clockPin),
        _latchPin(latchPin)
    {
        //create all the buttons
        for (int i = 0; i < size; i++)
        {
            this->_buttons.add(new InputsElt::Button(0));
        }
    }

    LinkedList<InputsElt::Button *> getInputs(void)
    {
        if (this->_chrono.hasPassed(50)) {      
            digitalWrite(this->_latchPin, LOW);
            digitalWrite(this->_latchPin, HIGH);

            for (int i = 0; i < this->_size; i++)
            {
                int pin = digitalRead(this->_dataPin);
                this->_buttons.get(i)->update_state(pin);
                digitalWrite(this->_clockPin, HIGH); // Shift out the next bit
                digitalWrite(this->_clockPin, LOW);
                Serial1.print(pin);

            //     int state = this->_buttons.get(i)->get();
            //     if (state == InputsElt::PRESSED)
            //     {
            //         Serial1.print("Button ");
            //         Serial1.print(i);
            //         Serial1.println(" pressed");
            //     }
            //     else if (state == InputsElt::HOLD)
            //     {
            //         Serial1.print("Button ");
            //         Serial1.print(i);
            //         Serial1.println(" hold");
            //     }
            //     else if (state == InputsElt::RELEASED)
            //     {
            //         Serial1.print("Button ");
            //         Serial1.print(i);
            //         Serial1.println(" released");
            //     }
            }
            Serial1.println();

            this->_chrono.restart();
        }

        return this->_buttons;
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
    LinkedList<InputsElt::Button *> _buttons;
    int _dataPin;
    int _clockPin;
    int _latchPin;
    Chrono _chrono;
};
