
#include "MenuManager.h"

MenuManager::MenuManager(Texture* textur, Font font_) {

	font = font_;
	choosenOption = 0;

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("STORY");
	text[0].setCharacterSize(CHAR_SIZE);
	text[0].setOutlineColor(Color::Green);
	text[0].setOutlineThickness(2.0f);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("DUEL");
	text[1].setCharacterSize(CHAR_SIZE);
	text[1].setOutlineColor(Color::Green);
	text[1].setOutlineThickness(2.0f);

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("OPTIONS");
	text[2].setCharacterSize(CHAR_SIZE);
	text[2].setOutlineColor(Color::Green);
	text[2].setOutlineThickness(2.0f);

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("EXIT");
	text[3].setCharacterSize(CHAR_SIZE);
	text[3].setOutlineColor(Color::Green);
	text[3].setOutlineThickness(2.0f);

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect);
	backg.setTexture(textur);

}

void MenuManager::Update() {

	text[choosenOption].setFillColor(Color::Green);
	text[choosenOption].setOutlineColor(Color::Black);

	for (int i = 0; i < NUM_OPTIONS_MENU; i++) {
		if (i != choosenOption && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
			text[i].setOutlineColor(Color::Green);
		}
	}

}

int MenuManager::ChoosenOption() {

	return choosenOption;

}

void MenuManager::draw(RenderWindow& window) {

	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	for (int i = 0; i < NUM_OPTIONS_MENU; i++) {

		text[i].setPosition(Vector2f(width_window / 10, height_window / 7 + CHAR_SIZE * (i + 1)));
		window.draw(text[i]);

	}

}

void MenuManager::MoveCursor(bool up) {

	if (up) {
		choosenOption--;
		if (choosenOption < 0) {
			choosenOption = NUM_OPTIONS_MENU - 1;
		}
	}
	else if (!up) {
		choosenOption++;
		if (choosenOption == NUM_OPTIONS_MENU) {
			choosenOption = 0;
		}
	}

}
