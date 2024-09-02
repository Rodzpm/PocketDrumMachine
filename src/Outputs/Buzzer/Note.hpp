#pragma once

#include "pitches.hpp"
#include <Chrono.h>
#include <Arduino.h>

class Note {
    public:
        Note(): _note(NOTE_E5), _duration(1000) {}
        Note(int note, int duration): _note(note), _duration(duration) {}
        void play() {
            if (!finished) {
                if (!_isPlaying) {
                    _chrono.restart();
                    _isPlaying = true;
                    tone(15, _note, _duration);
                }
                if (_chrono.elapsed() >= _duration) {
                    finished = true;
                }
            }
        }

        bool isFinished() {
            return finished;
        }

    private:
        int _note;
        int _duration;
        Chrono _chrono;
        bool finished = false;
        bool _isPlaying = false;
};