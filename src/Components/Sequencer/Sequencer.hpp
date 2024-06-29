#pragma once
#include "Display/Display.hpp"
#include <LinkedList.h>
#include "../BPM/BPM.hpp"
#include "Pattern/Pattern.hpp"

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

        void display()
        {
            this->_display.display(this->_sequence.get(this->_currentPattern)->getPattern());
        }

        Display<T>& getDisplay()
        {
            return this->_display;
        }

    private:
        int _size;
        BPM _bpm;
        LinkedList<Pattern<T>*> _sequence;
        int _currentPattern = 0;
        Display<T> _display;
    };
}
