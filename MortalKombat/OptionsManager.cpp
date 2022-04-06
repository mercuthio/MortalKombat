
#include "OptionsManager.h"
#include "MenuManager.h"

OptionsManager::OptionsManager(Texture* texture, Font font_) {

	font = font_;
	choosenOption = 0;
	music = 3;
	effects = 3;
	difficulty = false;

	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	for (int i = 0; i < MAX_EFFECTS; i++) {
		efec[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(CHAR_SIZE);
	}

	text[0].setString("MUSIC");
	text[1].setString("EFFECTS");
	text[2].setString("DIFFICULTY");
	text[3].setString("EDIT CONTROLS");

	dific.setFont(font);
	dific.setFillColor(Color::White);
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

	Color yellow = Color(255, 255, 0, 255);

	text[choosenOption].setFillColor(yellow);

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		if (i != choosenOption && text[i].getFillColor() == yellow) {
			text[i].setFillColor(Color::White);
		}
	}

	for (int i = 0; i < MAX_MUSIC; i++) {

		if (i <= music) {
			musi[i].setFillColor(yellow);
		}
		else {
			musi[i].setFillColor(Color::White);
		}

	}

	for (int i = 0; i < MAX_EFFECTS; i++) {

		if (i <= effects) {
			efec[i].setFillColor(yellow);
		}
		else {
			efec[i].setFillColor(Color::White);
		}

	}

	if (difficulty) {
		dific.setString("HARD");
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
	case 2: //DIFICULTAD
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
	case 2: //DIFICULTAD
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

	for (int i = 0; i < NUM_OPTIONS_OPT; i++) {
		//text[i].setPosition(Vector2f(width_window / 10, height_window / 10 + CHAR_SIZE * (i * 1.3)));
		text[i].setPosition(Vector2f(width_window / 3 + 20, height_window / 7 + CHAR_SIZE * (i + 1) + 50));
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

	dific.setPosition(Vector2f(width_window / 1.6, height_window / 10 + CHAR_SIZE * (3 * 1.3)));
	window.draw(dific);

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
