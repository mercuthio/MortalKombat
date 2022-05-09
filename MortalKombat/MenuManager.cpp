
#include "MenuManager.h"

MenuManager::MenuManager(Texture* textur, Font font_) {

	font = font_;
	choosenOption = 0;

	for (int i = 0; i < NUM_OPTIONS_MENU; i++) {
		text[i] = Text();
		shadow[i] = Text();
	}

	text[0].setFont(font);
	text[0].setFillColor(Color::White);
	text[0].setString("STORY");
	text[0].setCharacterSize(CHAR_SIZE);
	shadow[0] = text[0];
	shadow[0].setFillColor(Color::Black);

	text[1].setFont(font);
	text[1].setFillColor(Color::White);
	text[1].setString("DUEL");
	text[1].setCharacterSize(CHAR_SIZE);
	shadow[1] = text[1];
	shadow[1].setFillColor(Color::Black);

	text[2].setFont(font);
	text[2].setFillColor(Color::White);
	text[2].setString("OPTIONS");
	text[2].setCharacterSize(CHAR_SIZE);
	shadow[2] = text[2];
	shadow[2].setFillColor(Color::Black);

	text[3].setFont(font);
	text[3].setFillColor(Color::White);
	text[3].setString("EXIT");
	text[3].setCharacterSize(CHAR_SIZE);
	shadow[3] = text[3];
	shadow[3].setFillColor(Color::Black);

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect);
	backg.setTexture(textur);

	Texture* texture = new Texture;
	texture->loadFromFile("resources/Imagenes/Menus/icon30x30.png");
	logo.setTexture(texture);
	logo.setPosition(0, 0);
	logo.setSize(Vector2f(CHAR_SIZE, CHAR_SIZE));

}

void MenuManager::Update() {

	Color yellow = Color(255,255,0,255);

	text[choosenOption].setFillColor(yellow);

	for (int i = 0; i < NUM_OPTIONS_MENU; i++) {
		if (i != choosenOption && text[i].getFillColor() == yellow) {
			text[i].setFillColor(Color::White);
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

		text[i].setPosition(Vector2f(width_window / 5 + 20, height_window / 7 + CHAR_SIZE * (i + 1) + 100));
		shadow[i].setPosition(Vector2f(width_window / 5 + 10 + 20, height_window / 7 + CHAR_SIZE * (i + 1) + 10 + 100));
		if (i == choosenOption) {
			logo.setPosition(text[i].getPosition().x - 85, text[i].getPosition().y + 15);
		}
		window.draw(shadow[i]);
		window.draw(text[i]);
		window.draw(logo);

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
