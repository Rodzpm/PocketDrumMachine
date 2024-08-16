#pragma once
#include "Display/Display.hpp"
#include "Inputs/Inputs.hpp"
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
            _display(Display<T>(size, 8, 9, 10)),
            _inputs(Inputs<T>(size, 2, 3, 4))
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
            this->_currentInputs = this->_inputs.getInputs();

            for (int i = 0; i < this->_size; i++) {
                if (this->_currentInputs & (1 << i)) {
                    this->_sequence.get(this->_currentPattern)->setPatternAt(i, 1);
                }
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

        Inputs<T>& getInputs()
        {
            return this->_inputs;
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
        Inputs<T> _inputs;
        T _currentInputs = 0;
        Chrono _chrono;
    };
}
