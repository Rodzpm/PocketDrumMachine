#pragma once
#include "Display/Display.hpp"
#include <LinkedList.h>
#include "../BPM/BPM.hpp"
#include "Pattern/Pattern.hpp"
#include <Chrono.h>

namespace Components {
    template <typename T>
    class Sequencer {
    public:
        Sequencer(int size, int tempo) :
            _size(size),
            _bpm(BPM(tempo)),
            _sequence(),
            _display(Display<T>(size, 8, 9, 10))
        {
            // Ajoute 16 patterns à la séquence
            for (int i = 0; i < 16; i++) {
                this->_sequence.add(new Pattern<T>(size, "Pattern"));
            }
        }

        void update()
        {
            if (this->_chrono.hasPassed(this->_bpm.getBPMToMil() / 4)) {
                this->_currentStep++;
                if (this->_currentStep >= this->_size) {
                    this->_currentStep = 0;
                }
                this->_chrono.restart();
            }
        }

        void display()
        {
            T pattern = this->_sequence.get(this->_currentPattern)->getPattern();
            pattern |= (1 << (this->_size - this->_currentStep));
            
            this->_display.display(pattern);
        }

        Display<T>& getDisplay()
        {
            return this->_display;
        }

        void setBPM(int bpm)
        {
            this->_bpm.setBPM(bpm);
        }

    private:
        int _size;
        BPM _bpm;
        LinkedList<Pattern<T>*> _sequence;
        int _currentPattern = 0;
        int _currentStep = 0;
        Display<T> _display;
        Chrono _chrono;
    };
}