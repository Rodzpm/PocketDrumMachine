#include <Arduino.h>
#include <LinkedList.h>
#include "Tools/BPM/BPM.hpp"
#include "Inputs/Button/Button.hpp"
#include "Outputs/Led/Led.hpp"
#include <Chrono.h>

//Objectif:
//appui sur bouton edit tu cliques sur les boutons ça les activent ou désactivent
//quand tu rappui sur edit ça enregistre les valeurs et ça lance le séquenceur qui allument les led qui correspondent aux boutons activés 

//TODO: Placer les résistances plus éloignées elles font un court circuit

Tools::BPM bpm(150, 60, 2000);
int index = 0;

Inputs::Button editButton(2);
bool editMode = false;
Chrono myChrono;
LinkedList<int> ledsState;
LinkedList<Outputs::Led *> leds;
LinkedList<Inputs::Button *> sequencer;

void setup() {
	Serial.begin(9600);
  ledsState.add(1);
  ledsState.add(1);
  ledsState.add(1);
  ledsState.add(1);
  leds.add(new Outputs::Led(5));
  leds.add(new Outputs::Led(6));
  leds.add(new Outputs::Led(9));
  leds.add(new Outputs::Led(10));

  sequencer.add(new Inputs::Button(3));
  sequencer.add(new Inputs::Button(4));
  sequencer.add(new Inputs::Button(7));
  sequencer.add(new Inputs::Button(8));
}


void loop() {
  int value = editButton.get();
  if (value == Inputs::RELEASED) {
    editMode = !editMode;
    for (int i = 0; i != 4; i++) {
      leds.get(i)->set(LOW);
    }
  }
  if (!editMode) {
    leds.get(index)->set(ledsState.get(index));
    if (myChrono.hasPassed(bpm.getBPMToMil())) {
      leds.get(index)->set(LOW);
      myChrono.restart();
      index += 1;
      if (index == 4) {
        index = 0;
      }
    }
  } else {
    for (int i = 0; i != 4; i++) {
      int value = sequencer.get(i)->get();
      if (value == Inputs::RELEASED) {
        ledsState.set(i, !ledsState.get(i));
      }
    }
    for (int i = 0; i != 4; i++) {
      leds.get(i)->set(ledsState.get(i));
    }
  }
}