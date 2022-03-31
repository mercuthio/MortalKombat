
#include "HistoryManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

HistoryManager::HistoryManager(Texture* texture) {

	instant = 0;
	loaded = false;
	actual_combat = 0;

	Vector2f size_backg = Vector2f(400, 746);
	Vector2f size_title = Vector2f(126, 18);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);


	//Fondo 0
	uvRect.width = 100.0f;
	uvRect.height = 746.0f;
	uvRect.left = 505;
	uvRect.top = 773;
	rect.setSize(size_backg);

	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	//Titulo 1
	uvRect.width = 126.0f;
	uvRect.height = 18.0f;
	uvRect.left = 921;
	uvRect.top = 765;
	rect.setSize(size_backg);

	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	//Textos combates simple 2 - 9
	uvRect.width = 70.0f;
	uvRect.height = 16.0f;

	GetCharacters();	//Randomizamos los personajes

	for (int i = 0; i < NUM_CHARS; i++) {	
	
		switch (characters[i]) {
		case 0:
			uvRect.left = 921;
			uvRect.top = 1006;
			break;
		case 1:
			uvRect.left = 993;
			uvRect.top = 1006;
			break;
		case 2:
			uvRect.left = 921;
			uvRect.top = 1024;
			break;
		case 3:
			uvRect.left = 993;
			uvRect.top = 1024;
			break;
		case 4:
			uvRect.left = 921;
			uvRect.top = 1042;
			break;
		case 5:
			uvRect.left = 993;
			uvRect.top = 1042;
			break;
		case 6:
			uvRect.left = 921;
			uvRect.top = 1060;
			break;
		}
		rect.setTextureRect(uvRect);
		rect.setPosition(0.0f, 0.0f);
		Objects.push_back(rect);

	}

	//Textos combates dobles 10 - 16
	uvRect.width = 90.0f;
	uvRect.height = 16.0f;
	uvRect.left = 921;

	for (int i = 0; i < NUM_DOUBLE; i++) {
		uvRect.top = double_characters[i] * 18 + 932;
		rect.setTextureRect(uvRect);
		rect.setPosition(0.0f, 0.0f);
		Objects.push_back(rect);
	}

	//Textos bosses 17 y 18
	uvRect.width = 94.0f;
	uvRect.height = 16.0f;
	uvRect.left = 921;
	uvRect.top = 894;

	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	uvRect.top = 912;
	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	//Iconos combates simples 19 - 26
	uvRect.width = 26.0f;
	uvRect.height = 32.0f;
	uvRect.top = 789;

	for (int i = 0; i < NUM_CHARS; i++) {
		uvRect.left = characters[i] * 32 + 923;
		rect.setTextureRect(uvRect);
		rect.setPosition(0.0f, 0.0f);
		Objects.push_back(rect);
	}

	//Iconos combates dobles 27 - 33
	for (int i = 0; i < NUM_DOUBLE; i++) {
		uvRect.left = double_characters[i] * 32 + 923;
		rect.setTextureRect(uvRect);
		rect.setPosition(0.0f, 0.0f);
		Objects.push_back(rect);
	}

	//Iconos bosses 34 y 35
	uvRect.width = 46.0f;
	uvRect.height = 57.0f;
	uvRect.top = 827;

	uvRect.left = 974;
	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	uvRect.left = 923;
	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

}

void HistoryManager::Restart() {

	instant = 0;

}

//Randomiza los personajes de forma que no se repitan combates.
void HistoryManager::GetCharacters() {

	//srand(time(NULL));

	bool encontrado = false;
	int character;
	int i = 0;

	while (i < NUM_CHARS) {			//Randomizar personajes simples
		character = rand() % 8;
		for (int e = 0; e < NUM_CHARS; e++) {
			if (characters[e] == character) {
				encontrado = true;
			}
		}
		if (!encontrado) {
			characters[i] = character;
			i++;
		}
		encontrado = false;
	}

	i = 0;
	encontrado = false;
	while (i < NUM_DOUBLE) {		//Randomizar personajes dobles
		character = rand() % 8;
		for (int e = 0; e < NUM_CHARS; e++) {
			if (double_characters[e] == character) {
				encontrado = true;
			}
		}
		if (!encontrado) {
			double_characters[i] = character;
			i++;
		}
		encontrado = false;
	}

}

bool HistoryManager::Draw(RenderWindow& window, float seconds) {
	float mov = 4.6;
	/*
	if (!loaded) {

		title.setPosition(width_window / 3.4, height_window / 20);
		title.setSize(Vector2f(float(width_window / 3), float(height_window / 15)));

		for (int i = 0; i < NUM_BOSSES; i++) {

			if (i == 0) {
				bosses_icons[0].setPosition(width_window / 2.736, height_window / 4.8);
				bosses_texts[0].setPosition(width_window / 1.84, height_window / 3.6);
			}
			else {
				bosses_icons[1].setPosition(width_window / 2.736, height_window / 2);
				bosses_texts[1].setPosition(width_window / 1.84, height_window / 1.75);
			}
			bosses_icons[i].setSize(Vector2f(float(width_window / 8.77), float(height_window / 4.58)));
			bosses_texts[i].setSize(Vector2f(float(width_window / 4.2), float(height_window /17)));

		}
		loaded = true;

	}

	uvRect_backg.height = height_window / 2.3;
	
	if (Objects[0].getTexture().top + uvRect_backg.height + 2 <= 1519) {

		uvRect_backg.top += 2;
		title.setPosition(title.getPosition().x, title.getPosition().y - mov);

		for (int i = 0; i < NUM_BOSSES; i++) {
			bosses_icons[i].setPosition(bosses_icons[i].getPosition().x, bosses_icons[i].getPosition().y - mov);
			bosses_texts[i].setPosition(bosses_texts[i].getPosition().x, bosses_texts[i].getPosition().y - mov);
		}

		backg.setTextureRect(uvRect_backg);
		backg.setSize(Vector2f(width_window, height_window));
	}
	else {
		return true;
	}
	
	backg.setTextureRect(uvRect_backg);
	backg.setSize(Vector2f(width_window, height_window));
	window.draw(backg);

	for (int i = 0; i < NUM_BOSSES; i++) {
		window.draw(bosses_icons[i]);
		window.draw(bosses_texts[i]);
	}

	window.draw(title);
	//--------------Update---------------------
	if (seconds - time >= 0.1f) {

		Update();

		if (title_color) {
			uvRect_title.left = 1049;
		}
		else {
			uvRect_title.left = 921;
		}
		uvRect_title.top = 765;
		title.setTextureRect(uvRect_title);

		time = seconds;
	}
	*/
	return true;

}

void HistoryManager::Update() {

	title_color = !title_color;

}
