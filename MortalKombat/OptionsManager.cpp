
#include "OptionsManager.h"
#include "MenuManager.h"

OptionsManager::OptionsManager(Texture* texture, Font font_) {

	font = font_;
	choosenOption = 0;
	music = 3;
	effects = 3;
	speed = 1;
	difficulty = false;

	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	for (int i = 0; i < MAX_EFFECTS; i++) {
		efec[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::Black);
		text[i].setCharacterSize(CHAR_SIZE);
		text[i].setOutlineColor(Color::Green);
		text[i].setOutlineThickness(2.0f);
	}

	text[0].setString("MUSICA");
	text[1].setString("EFECTOS");
	text[2].setString("VELOCIDAD");
	text[3].setString("DIFICULTAD");
	text[4].setString("SALIR");

	veloc.setFont(font);
	veloc.setFillColor(Color::Green);
	veloc.setCharacterSize(CHAR_SIZE);

	dific.setFont(font);
	dific.setFillColor(Color::Green);
	dific.setCharacterSize(CHAR_SIZE);

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect);
	backg.setTexture(texture);

}

void OptionsManager::Update() {

	text[choosenOption].setFillColor(Color::Green);
	text[choosenOption].setOutlineColor(Color::Black);

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		if (i != choosenOption && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
			text[i].setOutlineColor(Color::Green);
		}
	}

	for (int i = 0; i < MAX_MUSIC; i++) {

		if (i <= music) {
			musi[i].setFillColor(Color::Green);
		}
		else {
			musi[i].setFillColor(Color::Black);
		}

	}

	for (int i = 0; i < MAX_EFFECTS; i++) {

		if (i <= effects) {
			efec[i].setFillColor(Color::Green);
		}
		else {
			efec[i].setFillColor(Color::Black);
		}

	}

	switch (speed) {
	case 0:
		veloc.setString("LENTA");
		break;
	case 1:
		veloc.setString("NORMAL");
		break;

	case 2:
		veloc.setString("RAPIDA");
		break;
	}

	if (difficulty) {
		dific.setString("DIFICIL");
	}
	else {
		dific.setString("NORMAL");
	}

}

void OptionsManager::Enter(Music& music_) {

	switch (choosenOption) {
	case 0: //MUSICA
		if (music + 1 < MAX_MUSIC) {
			music++;
		}
		music_.setVolume((music + 1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (effects + 1 < MAX_EFFECTS) {
			effects++;
		}
		break;
	case 2: //VELOCIDAD
		if (speed + 1 < MAX_SPEED) {
			speed++;
		}
		break;
	case 3: //DIFICULTAD
		difficulty = !difficulty;
		break;
	}

}

void OptionsManager::Izquierda(Music& music_) {

	switch (choosenOption) {
	case 0: //MUSICA
		if (music - 1 >= -1) {
			music--;
		}
		music_.setVolume((music + 1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (effects - 1 >= -1) {
			effects--;
		}
		break;
	case 2: //VELOCIDAD
		if (speed - 1>= 0) {
			speed--;
		}
		break;
	case 3: //DIFICULTAD
		difficulty = !difficulty;
		break;
	}

}

int OptionsManager::ChoosenOption() {

	return choosenOption;

}

void OptionsManager::draw(RenderWindow& window) {

	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	for (int i = 0; i < NUM_OPTIONS_OPT - 1; i++) {
		text[i].setPosition(Vector2f(width_window / 10, height_window / 10 + CHAR_SIZE * (i * 1.3)));
		window.draw(text[i]);
	}

	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i].setPosition(Vector2f(width_window / 1.6 + (i * (CHAR_SIZE / 2)), height_window / 10));
		window.draw(musi[i]);
	}

	for (int i = 0; i < MAX_EFFECTS; i++) {
		efec[i].setPosition(Vector2f(width_window / 1.6 + (i * (CHAR_SIZE / 2)), height_window / 10 + CHAR_SIZE * 1.5));
		window.draw(efec[i]);
	}

	veloc.setPosition(Vector2f(width_window / 1.6, height_window / 10 + CHAR_SIZE * (2 * 1.3)));
	window.draw(veloc);

	dific.setPosition(Vector2f(width_window / 1.6, height_window / 10 + CHAR_SIZE * (3 * 1.3)));
	window.draw(dific);

	text[NUM_OPTIONS_OPT - 1].setPosition(Vector2f(width_window / 10, height_window / 1.2 - (CHAR_SIZE + 5)));
	window.draw(text[NUM_OPTIONS_OPT - 1]);

}

void OptionsManager::MoveCursor(bool arriba) {

	if (arriba) {
		choosenOption--;
		if (choosenOption < 0) {
			choosenOption = NUM_OPTIONS_OPT - 1;
		}
	}
	else if (!arriba) {
		choosenOption++;
		if (choosenOption == NUM_OPTIONS_OPT) {
			choosenOption = 0;
		}
	}

}
