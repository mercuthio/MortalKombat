
#include "HistoryManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

HistoryManager::HistoryManager(Texture* texture_, int character_) {

	for (int i = 0; i < NUM_CHARS; i++) {
		characters[i] = 0;
	}

	character = character_;
	texture = texture_;

	Restart(character_);
}

void HistoryManager::LoadTextures() {

	Vector2f size_backg = Vector2f(width_window, height_window);
	Vector2f size_title = Vector2f(321, 63);
	Vector2f size_icon = Vector2f(66,86);
	Vector2f size_my_icon = Vector2f(80, 100);
	Vector2f size_name = Vector2f(254,56);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);

	//Fondo 0
	uvRect.width = 399.0f;
	uvRect.height = 277.0f;
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

	rect.setTextureRect(uvRect);
	rect.setSize(size_title);
	rect.setPosition(315.0f, 17.0f);
	Objects.push_back(rect);

	//Textos combates simple 2-5
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
		rect.setSize(size_name);
		rect.setPosition(542,155 + 134*i);
		Objects.push_back(rect);

	}

	//Iconos combates simples 6-9 
	uvRect.width = 26.0f;
	uvRect.height = 32.0f;
	uvRect.top = 789;

	for (int i = 0; i < NUM_CHARS; i++) {
		uvRect.left = characters[i] * 31 + 923;
		rect.setTextureRect(uvRect);
		rect.setSize(size_icon);
		rect.setPosition(380,143 + 131*i);
		Objects.push_back(rect);
	}

	//Icono personaje 10
	uvRect.left = character * 31 + 923;
	rect.setTextureRect(uvRect);
	rect.setSize(size_my_icon);
	rect.setPosition(252, 137 + 131 * ((NUM_CHARS - actual_combat) - 1));
	Objects.push_back(rect);

	//Marco personaje 11
	uvRect.width = 31.0f;
	uvRect.height = 36.0f;
	uvRect.top = 787;
	uvRect.left = 1143.0f;
	rect.setTextureRect(uvRect);
	rect.setSize(size_my_icon);
	rect.setPosition(252, 137 + 131 * ((NUM_CHARS - actual_combat) - 1));
	Objects.push_back(rect);

}

void HistoryManager::Restart(int character_) {

	character = character_;
	actual_combat = 0;
	clock = 0;
	clock_flash = 0;
	clock_move = 0;
	finish = false;

	GetCharacters();
	Objects.clear();
	LoadTextures();

	//NextCombat(); //DEBUG PARA VER EL MOVIMIENTO DEL ICONO
}

void HistoryManager::RestartVariables(){
	clock = 0;
	clock_flash = 0;
	clock_move = 0;
	finish = false;
}

bool HistoryManager::NextCombat() {
	actual_combat++;
	moving = true;

	if (actual_combat == NUM_CHARS) return true;	//Ha ganado todos los combates
	return false;
}

//Randomiza los personajes de forma que no se repitan combates.
void HistoryManager::GetCharacters() {

	//srand(time(NULL));

	for (int e = 0; e < NUM_CHARS; e++) characters[e] = -1;

	bool encontrado = false;
	int character;
	int i = 0;

	while (i < NUM_CHARS) {			//Randomizar personajes simples
		character = rand() % 4;
		for (int e = 0; e < NUM_CHARS; e++) {
			if (characters[e] == character) {
				encontrado = true;
				break;
			}
		}

		if (!encontrado) {
			characters[i] = character;
			i++;
		}
		encontrado = false;
	}

	for (int e = 0; e < NUM_CHARS; e++) {
		if (characters[e] == 1) characters[e] = 4;
		if (characters[e] == 2) characters[e] = 6;
	}

}

bool HistoryManager::Draw(RenderWindow& window, float seconds) {

	for (RectangleShape object : Objects) {
		window.draw(object);
	}

	if (clock > 280 && finish) return true;
	return false;

}

void HistoryManager::Update() {

	clock++;
	clock_flash++;

	if (moving) clock_move++;

	if (clock_flash == 7 && !finish) {
		clock_flash = 0;
		title_color = !title_color;

		IntRect uvRect;
		Vector2f size_title = Vector2f(321, 63);

		uvRect.width = 126.0f;
		uvRect.height = 18.0f;
		uvRect.top = 765;
		
		if (title_color) uvRect.left = 1049;
		else uvRect.left = 921;
		
		Objects[1].setTextureRect(uvRect);

		uvRect.width = 31.0f;
		uvRect.height = 36.0f;
		uvRect.top = 787;

		if (title_color) uvRect.left = 1143;
		else uvRect.left = 1179;

		Objects[11].setTextureRect(uvRect);

	}

	if (clock_move == 3) {
		
		clock_move = 0;

		float x = Objects[10].getPosition().x;
		float y = Objects[10].getPosition().y;

		if (y > 137 + 131 * ((NUM_CHARS - actual_combat) - 1)) y -= 3;
		else moving = false;

		Objects[10].setPosition(x,y);
		Objects[11].setPosition(x, y);

	}

	if (clock == 100) {
		music.skipHistoryTheme();
	}

	if (clock == 200) { //550

		IntRect uvRect;

		uvRect.width = 31.0f;
		uvRect.height = 36.0f;
		uvRect.top = 787;
		uvRect.left = 1215;

		Objects[11].setTextureRect(uvRect);

		uvRect.width = 126.0f;
		uvRect.height = 18.0f;
		uvRect.left = 1177;
		uvRect.top = 765;

		Objects[1].setTextureRect(uvRect);

		finish = true;
	}
}

int HistoryManager::getOpponent() {

	return characters[(NUM_CHARS - 1) - actual_combat];

}
