#pragma once

#include "../Interfaces/IOutput.hpp"
#include "Note.hpp"
#include <LinkedList.h>

namespace Outputs {
    class Buzzer : public IOutput {
        public:
            Buzzer(uint8_t pin);
            void set(int value);
            void add(Note *note);
            void setNotes(LinkedList<Note *> notes);
            LinkedList<Note *> getNotes();
            void play();
        private:
            uint8_t _pin;
            LinkedList<Note *> _noteList;
    };
}