#pragma once
#include "Display/Display.hpp"

namespace Components {
    template <typename T>
    class Sequencer {
        public:
            Sequencer(int size) :
                size(size),
                _display(Display<T>(size, 8, 10, 9))
            {}

            void display()
            {
                this->_display.display();
            }
            Display<T>& getDisplay()
            {
                return this->_display;
            }
        private:
            //size of the sequencer
            int size;
            //display object
            Display<T> _display;
    };
}