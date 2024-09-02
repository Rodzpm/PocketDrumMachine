#include <Keypad.h>
#include <Inputs/MembKeypad/MembKeypad.hpp>
#include "Screen/SSD1306/SSD1306.hpp"
#include "bitmap/bli7.hpp"
#include "Outputs/Buzzer/Buzzer.hpp"
#include "Outputs/Buzzer/Note.hpp"

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Screen::SSD1306 display(128, 64);

Outputs::Buzzer buzzer(15);

void setup()
{
	Serial1.begin(115200);
	tone(15, 262, 500);
	display.init();
	display.fillScreen(BLACK);
	display.drawBitmap(0, 0, bli7_logo, WHITE, 128, 64);
	display.render();

	for (int i = 0; i < 2; i++)
	{
		buzzer.add(new Note(NOTE_C6, 20));
		buzzer.add(new Note(NOTE_E6, 20));
		buzzer.add(new Note(NOTE_G6, 20));
		buzzer.add(new Note(NOTE_C7, 20));
		buzzer.add(new Note(NOTE_G6, 20));
		buzzer.add(new Note(NOTE_E6, 20));
		buzzer.add(new Note(NOTE_C6, 20));
		buzzer.add(new Note(NOTE_E6, 20));
		buzzer.add(new Note(NOTE_G6, 20));
		buzzer.add(new Note(NOTE_C7, 20)); 
	}

	while (buzzer.getNotes().size() > 0)
	{
		buzzer.play();
	}

	display.clear();
	display.render();
}

void loop()
{
	char key = keypad.getKey();

	if (key != NO_KEY)
	{
		display.clear();
		switch (key)
		{
		case '1':
			buzzer.add(new Note(64, 23));
			buzzer.add(new Note(107, 23));
			buzzer.add(new Note(96, 23));
			buzzer.add(new Note(75, 23));
			buzzer.add(new Note(86, 23));
			buzzer.add(new Note(43, 46));
			buzzer.add(new Note(86, 46));
			buzzer.add(new Note(75, 46));
			buzzer.add(new Note(53, 46));
			buzzer.add(new Note(64, 46));
			buzzer.add(new Note(75, 69));
			buzzer.add(new Note(32, 69));
			buzzer.add(new Note(64, 69));
			buzzer.add(new Note(43, 69));
			buzzer.add(new Note(53, 69));
			buzzer.add(new Note(118, 92));
			buzzer.add(new Note(129, 92));
			buzzer.add(new Note(53, 92));
			buzzer.add(new Note(32, 92));
			buzzer.add(new Note(43, 92));
			buzzer.add(new Note(118, 116));
			buzzer.add(new Note(21, 116));
			buzzer.add(new Note(53, 116));
			buzzer.add(new Note(32, 116));
			buzzer.add(new Note(43, 116));
			buzzer.add(new Note(107, 139));
			buzzer.add(new Note(53, 139));
			buzzer.add(new Note(21, 139));
			buzzer.add(new Note(43, 139));
			buzzer.add(new Note(32, 139));
			buzzer.add(new Note(10, 162));
			buzzer.add(new Note(53, 162));
			buzzer.add(new Note(21, 162));
			buzzer.add(new Note(43, 162));
			buzzer.add(new Note(32, 162));
			buzzer.add(new Note(53, 185));
			buzzer.add(new Note(10, 185));
			buzzer.add(new Note(43, 185));
			buzzer.add(new Note(21, 185));
			buzzer.add(new Note(32, 185));
			buzzer.add(new Note(10, 208));
			buzzer.add(new Note(43, 208));
			buzzer.add(new Note(21, 208));
			buzzer.add(new Note(32, 208));
			display.drawText(54, 12, 3, WHITE, "KICK");
			break;
		case '2':
			buzzer.add(new Note(NOTE_D5, 100));
			display.drawText(54, 12, 5, WHITE, "D5");
			break;
		case '3':
			buzzer.add(new Note(800, 10));
			display.drawText(54, 12, 3, WHITE, "HI-HAT");
			break;
		case 'A':
			buzzer.add(new Note(NOTE_F5, 100));
			display.drawText(54, 12, 5, WHITE, "F5");
			break;
		case '4':
			buzzer.add(new Note(NOTE_G5, 100));
			display.drawText(54, 12, 5, WHITE, "G5");
			break;
		case '5':
			buzzer.add(new Note(NOTE_A5, 100));
			display.drawText(54, 12, 5, WHITE, "A5");
			break;
		case '6':
			buzzer.add(new Note(NOTE_B5, 100));
			display.drawText(54, 12, 5, WHITE, "B5");
			break;
		case 'B':
			buzzer.add(new Note(NOTE_C6, 100));
			display.drawText(54, 12, 5, WHITE, "C6");
			break;
		case '7':
			buzzer.add(new Note(NOTE_D6, 100));
			display.drawText(54, 12, 5, WHITE, "D6");
			break;
		case '8':
			buzzer.add(new Note(NOTE_E6, 100));
			display.drawText(54, 12, 5, WHITE, "E6");
			break;
		case '9':
			buzzer.add(new Note(NOTE_F6, 100));
			display.drawText(54, 12, 5, WHITE, "F6");
			break;
		case 'C':
			buzzer.add(new Note(NOTE_G6, 100));
			display.drawText(54, 12, 5, WHITE, "G6");
			break;
		case '*':
			buzzer.add(new Note(NOTE_A6, 100));
			display.drawText(54, 12, 5, WHITE, "A6");
			break;
		case '0':
			buzzer.add(new Note(NOTE_B6, 100));
			display.drawText(54, 12, 5, WHITE, "B6");
			break;
		case '#':
			buzzer.add(new Note(NOTE_C7, 100));
			display.drawText(54, 12, 5, WHITE, "C7");
			break;
		case 'D':
			buzzer.add(new Note(NOTE_D7, 100));
			display.drawText(54, 12, 5, WHITE, "D7");
			break;
		default:
			break;
		}
		display.render();
	} else {
		display.clear();
		display.drawText(54, 12, 5, WHITE, "N/A");
		display.render();
	}
	buzzer.play();
	delay(10);
}
