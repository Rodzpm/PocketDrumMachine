#include <Arduino.h>
#include <LinkedList.h>
#include "Tools/BPM/BPM.hpp"
#include "Inputs/Button/Button.hpp"
#include "Outputs/Led/Led.hpp"

//Objectif:
//appui sur bouton edit tu cliques sur les boutons ça les activent ou désactivent
//quand tu rappui sur edit ça enregistre les valeurs et ça lance le séquenceur qui allument les led qui correspondent aux boutons activés 

//TODO: Placer les résistances plus éloignées elles font un court circuit

Tools::BPM bpm(100, 60, 2000);
int index = 0;

Inputs::Button editButton(12);
bool editMode = false;
LinkedList<int> ledsState;
LinkedList<Outputs::Led *> leds;
LinkedList<Inputs::Button *> sequencer;

void setup() {
	Serial.begin(9600);
  ledsState.add(0);
  ledsState.add(1);
  ledsState.add(0);
  ledsState.add(0);
  leds.add(new Outputs::Led(8));
  leds.add(new Outputs::Led(9));
  leds.add(new Outputs::Led(10));
  leds.add(new Outputs::Led(11));

  sequencer.add(new Inputs::Button(2));
  sequencer.add(new Inputs::Button(3));
  sequencer.add(new Inputs::Button(4));
  sequencer.add(new Inputs::Button(5));
}


void loop() {
  if (editButton.get() == Inputs::RELEASED) {
    editMode = !editMode;
  }
  if (!editMode) {
    Serial.println("CACA");
    leds.get(0)->set(ledsState.get(0));
    // for (int i = 0; i != 4; i++) {
    //   leds.get(i)->set(ledsState.get(i));
    //   delay(bpm.getBPMToMil());
    //   leds.get(i)->set(LOW);
    // }
  }
}