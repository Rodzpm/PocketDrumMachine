#pragma once

namespace Components {
    class BPM {
    public:
        BPM(int bpm = 60, int min = 60, int max = 2000);
        void setBPM(int bpm);
        int getBPM();
        int getBPMToMil();
    private:
        int _bpm;
        int _min = 60;
        int _max = 2000;
    };
}