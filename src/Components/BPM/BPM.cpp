#include "BPM.hpp"

namespace Components {
    Components::BPM::BPM(int bpm, int min, int max) {
        this->setBPM(bpm);
        this->_min = min;
        this->_max = max;
    }

    void Components::BPM::setBPM(int bpm) {
        if (bpm < this->_min) {
            this->_bpm = this->_min;
            return;
        }
        if (bpm > this->_max) {
            this->_bpm = this->_max;
            return;
        }
        this->_bpm = bpm;
    }

    int Components::BPM::getBPM() {
        return this->_bpm;
    }

    int Components::BPM::getBPMToMil() {
        return 60000 / this->_bpm;
    }
}