
#include "OptionsManager.h"
#include "MenuManager.h"

OptionsManager::OptionsManager(Texture* texture, Font font_) {

	font = font_;
	choosenOption = 0;
	musicVolume = 3;
	effects = 3;
	showing_controls = false;
	difficulty = false;

	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	for (int i = 0; i < MAX_EFFECTS; i++) {
		efec[i].setSize(Vector2f(15, CHAR_SIZE));
	}

	text[0].setString("MUSIC");
	text[1].setString("EFFECTS");
	text[2].setString("DIFFICULTY");
	text[3].setString("CONTROLS");

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(CHAR_SIZE);
		shadow[i] = text[i];
		shadow[i].setFillColor(Color::Black);
	}

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

	Texture* texture2 = new Texture;
	texture2->loadFromFile("resources/Imagenes/Menus/icon30x30.png");
	logo.setTexture(texture2);
	logo.setPosition(0, 0);
	logo.setSize(Vector2f(CHAR_SIZE, CHAR_SIZE));

	//texture2->loadFromFile("resources/Imagenes/Menus/Controls.png");
	//controls_backg.setTexture(texture);
	controls_backg.setSize(Vector2f(width_window / 2, height_window / 2));
	controls_backg.setOrigin(controls_backg.getSize().x / 2, controls_backg.getSize().y / 2);
	controls_backg.setPosition(width_window/2, height_window/2);

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

		if (i <= musicVolume) {
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

void OptionsManager::Right() {

	switch (choosenOption) {
	case 0: //MUSICA
		if (musicVolume + 1 < MAX_MUSIC) {
			musicVolume++;
			music.addVolumeMusic();
			music.updateMusicVolume();
			music.moveOptions();
		}
		break;
	case 1: //EFECTOS
		if (effects + 1 < MAX_EFFECTS) {
			effects++;
			music.addVolumeEffects();
			music.moveOptions();
		}
		break;
	case 2: //DIFICULTAD
		difficulty = !difficulty;
		music.moveOptions();
		break;
	case 3:
		showing_controls = true;
		break;
	}

}

void OptionsManager::Enter() {

	if (choosenOption == 3){
		showing_controls = !showing_controls;
	}
}

void OptionsManager::Izquierda() {

	switch (choosenOption) {
	case 0: //MUSICA
		if (musicVolume - 1 >= -1) {
			musicVolume--;
			music.reduceVolumeMusic();
			music.updateMusicVolume();
			music.moveOptions();
		}
		break;
	case 1: //EFECTOS
		if (effects - 1 >= -1) {
			effects--;
			music.reduceVolumeEffects();
			music.moveOptions();
		}
		break;
	case 2: //DIFICULTAD
		difficulty = !difficulty;
		music.moveOptions();
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
		text[i].setPosition(Vector2f(width_window / 5 + 20, height_window / 7 + CHAR_SIZE * (i + 1) + 100));
		shadow[i].setPosition(Vector2f(width_window / 5 + 10 + 20, height_window / 7 + CHAR_SIZE * (i + 1) + 10 + 100));
		if (i == choosenOption) {
			logo.setPosition(text[i].getPosition().x - 85, text[i].getPosition().y + 15);
		}

		window.draw(shadow[i]);
		window.draw(text[i]);
		window.draw(logo);
	}
	
	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i].setPosition(Vector2f(width_window / 1.6 + (i * (CHAR_SIZE / 2)), height_window / 7 + CHAR_SIZE + 100));
		window.draw(musi[i]);
	}

	for (int i = 0; i < MAX_EFFECTS; i++) {
		efec[i].setPosition(Vector2f(width_window / 1.6 + (i * (CHAR_SIZE / 2)), height_window / 7 + CHAR_SIZE*2 + 110));
		window.draw(efec[i]);
	}

	dific.setPosition(Vector2f(width_window / 1.6, height_window / 7 + CHAR_SIZE * 3 + 100));
	window.draw(dific);
	
	if (showing_controls) {
		window.draw(controls_backg);
	}

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

	music.moveOptions();

}
