#include "BPM.hpp"

namespace Tools {
    BPM::BPM(int bpm, int min, int max) {
        this->setBPM(bpm);
        this->min = min;
        this->max = max;
    }

    void BPM::setBPM(int bpm) {
        if (bpm < this->min) {
            this->bpm = this->min;
            return;
        }
        if (bpm > this->max) {
            this->bpm = this->max;
            return;
        }
        this->bpm = bpm;
    }

    int BPM::getBPM() {
        return this->bpm;
    }

    int BPM::getBPMToMil() {
        return 60000 / this->bpm;
    }
}