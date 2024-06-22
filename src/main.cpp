#include <Arduino.h>
#include <LinkedList.h>
#include "Tools/BPM/BPM.hpp"
#include "Components/Potentiometer/Potentiometer.hpp"
#include "Outputs/Led/Led.hpp"

LinkedList<Outputs::Led*> leds;
Tools::BPM bpm(60, 60, 2000);
Components::Potentiometer pot(A0, 0, 667, 60, 2000);

int iLed = 0;

void setup() {
	Serial.begin(9600);
	leds.add(new Outputs::Led(2));
	leds.add(new Outputs::Led(3));
	leds.add(new Outputs::Led(4));
	leds.add(new Outputs::Led(5));
}


void loop() {
	bpm.setBPM(pot.get());

	leds.get(iLed)->set(HIGH);
	delay(bpm.getBPMToMil());
	leds.get(iLed)->set(LOW);
	
	iLed++;
	if (iLed > leds.size() - 1){
		iLed = 0;
	}
}
