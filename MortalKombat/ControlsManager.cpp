#include "ControlsManager.h"

ControlsManager::ControlsManager(Texture* texture, Font font_) {

	font = font_;
	choosenOption = 0;

	text[0].setString("J1 ATRAS");
	text[1].setString("J1 DELANTE");
	text[2].setString("J1 SALTAR");
	text[3].setString("J1 AGACHAR");
	text[4].setString("J1 BLOQUEAR");
	text[5].setString("J1 PUÑETAZO");
	text[6].setString("J1 MULTI-PUÑO");
	text[7].setString("J1 PATADA");
	text[8].setString("J2 ATRAS");
	text[9].setString("J2 DELANTE");
	text[10].setString("J2 SALTAR");
	text[11].setString("J2 AGACHAR");
	text[12].setString("J2 BLOQUEAR");
	text[13].setString("J2 PUÑETAZO");
	text[14].setString("J2 MULTI-PUÑO");
	text[15].setString("J2 PATADA");

	for (int i = 0; i < NUM_CONTROLS; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(CHAR_SIZE_CONTROLS);
		shadow[i] = text[i];
		shadow[i].setFillColor(Color::Black);
	}

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect);
	backg.setTexture(texture);

	Texture* texture2 = new Texture;
	texture2->loadFromFile("resources/Imagenes/Menus/icon30x30.png");
	logo.setTexture(texture2);
	logo.setPosition(0, 0);
	logo.setSize(Vector2f(CHAR_SIZE_CONTROLS, CHAR_SIZE_CONTROLS));
}

void ControlsManager::Update() {

	Color yellow = Color(255, 255, 0, 255);

	text[choosenOption].setFillColor(yellow);

	for (int i = 0; i < NUM_CONTROLS; i++) {
		if (i != choosenOption && text[i].getFillColor() == yellow) {
			text[i].setFillColor(Color::White);
		}
	}
}

void ControlsManager::draw(RenderWindow& window) {
	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	for (int i = 0; i < NUM_CONTROLS / 2; i++) {
		text[i].setPosition(Vector2f(width_window / 5 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i + 1) + 100));
		shadow[i].setPosition(Vector2f(width_window / 5 + 10 + 20, height_window / 7 + CHAR_SIZE_CONTROLS * (i + 1) + 10 + 100));
		if (i == choosenOption) {
			logo.setPosition(text[i].getPosition().x - 85, text[i].getPosition().y + 15);
		}

		window.draw(shadow[i]);
		window.draw(text[i]);
		window.draw(logo);
	}
}