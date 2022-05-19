#include "OptionsManager.h"
#include "MenuManager.h"

DifficultyLevel chosen_difficulty = DifficultyLevel::MEDIUM;
bool noHitMode = false;
bool noBlockMode = false;

OptionsManager::OptionsManager(Texture* texture, Font font_) {

	for (int i = 0; i < NUM_OPTIONS_OPT + 1; i++) {
		text[i] = Text();
		shadow[i] = Text();
	}

	for (int i = 0; i < MAX_MUSIC; i++) {
		musi[i] = RectangleShape();
		efec[i] = RectangleShape();
	}

	font = font_;
	choosenOption = 0;
	musicVolume = 3;
	effects = 3;
	speed_game = 1;
	num_mode = 0;

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
	text[4].setString("GAME SPEED");
	text[5].setString("GAMEMODE");

	for (int i = 0; i <= NUM_OPTIONS_OPT; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setCharacterSize(CHAR_SIZE);
		shadow[i] = text[i];
		shadow[i].setFillColor(Color::Black);
	}

	mode.setFont(font);
	mode.setFillColor(Color::White);
	mode.setCharacterSize(CHAR_SIZE);

	speed.setFont(font);
	speed.setFillColor(Color::White);
	speed.setCharacterSize(CHAR_SIZE);

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

	switch (chosen_difficulty)
	{
	case DifficultyLevel::EASY:
		dific.setString("EASY");
		break;

	case DifficultyLevel::MEDIUM:
		dific.setString("NORMAL");
		break;

	case DifficultyLevel::HARD:
		dific.setString("HARD");
		break;
	}

	if (speed_game == 3) {
		speed.setString("MORTAL");
	}
	else if (speed_game == 2) {
		speed.setString("FAST");
	}
	else if (speed_game == 1) {
		speed.setString("NORMAL");
	}
	else if (speed_game == 0) {
		speed.setString("SLOW");
	}

	if (num_mode == 2) {
		mode.setString("NO HIT");
	}
	else if (num_mode == 1) {
		mode.setString("NO BLOCK");
	}
	else {
		mode.setString("NONE");
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
		if (chosen_difficulty == DifficultyLevel::EASY) {
			chosen_difficulty = DifficultyLevel::MEDIUM;
		}
		else if (chosen_difficulty == DifficultyLevel::MEDIUM) {
			chosen_difficulty = DifficultyLevel::HARD;
		}
		music.moveOptions();
		break;
	case 4:
		if (speed_game + 1 < MAX_SPEED) {
			speed_game++;
		}
		break;
	case 5:
		if (num_mode < 2) {
			num_mode++;
		}
		if (num_mode == 1) {
			noBlockMode = true;
			noHitMode = false;
		}
		else {
			noBlockMode = false;
			noHitMode = true;
		}
		break;
	}

}

bool OptionsManager::Enter() {

	if (choosenOption == 3){
		return true;
	}
	return false;
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
		if (chosen_difficulty == DifficultyLevel::MEDIUM) {
			chosen_difficulty = DifficultyLevel::EASY;
		}
		else if ((chosen_difficulty == DifficultyLevel::HARD)) {
			chosen_difficulty = DifficultyLevel::MEDIUM;
		}
		music.moveOptions();
		break;
	case 4:
		if (speed_game - 1 >= -1) {
			speed_game--;
		}
		break;
	case 5:
		if (num_mode > 0) {
			num_mode--;
		}
		if (num_mode == 0) {
			noBlockMode = false;
			noHitMode = false;
		}
		else {
			noBlockMode = true;
			noHitMode = false;
		}
		break;
	}

}

int OptionsManager::ChoosenOption() {

	return choosenOption;

}

void OptionsManager::draw(RenderWindow& window) {

	switch (speed_game) {
	case 0:
		window.setFramerateLimit(45);
		break;
	case 1:
		window.setFramerateLimit(60);
		break;
	case 2:
		window.setFramerateLimit(100);
		break;
	case 3:
		window.setFramerateLimit(144);
		break;
	}

	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	for (int i = 0; i < NUM_OPTIONS_OPT; i++) {
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

	speed.setPosition(Vector2f(width_window / 1.6, height_window / 7 + CHAR_SIZE * 5 + 100));
	window.draw(speed);

	mode.setPosition(Vector2f(width_window / 1.6, height_window / 7 + CHAR_SIZE * 6 + 100));
	window.draw(mode);

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
