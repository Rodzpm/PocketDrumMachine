#include "Buzzer.hpp"

namespace Outputs {
    Buzzer::Buzzer(uint8_t pin) {
        _pin = pin;
        pinMode(_pin, OUTPUT);
    }

    void Buzzer::set(int value) {
    }

    void Buzzer::add(Note *note) {
        _noteList.add(note);
    }

    void Buzzer::setNotes(LinkedList<Note *> notes) {
        _noteList = notes;
    }

    LinkedList<Note *> Buzzer::getNotes() {
        return _noteList;
    }

    void Buzzer::play() {
        if (_noteList.size() > 0) {
            Note *note = _noteList.get(0);
            if (note->isFinished()) {
                _noteList.remove(0);
            } else {
                note->play();
            }
        }
    }
}