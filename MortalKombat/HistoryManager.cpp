
#include "HistoryManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

HistoryManager::HistoryManager(Texture* texture) {

	uvRect_backg.width = 400;	//Fondo
	uvRect_backg.height = 746;
	uvRect_backg.left = 505;
	uvRect_backg.top = 773;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect_backg);
	backg.setTexture(texture);
	
	uvRect_title.width = 126;	//Titulo
	uvRect_title.height = 18;
	uvRect_title.left = 921;
	uvRect_title.top = 765;

	title.setPosition(0, 0);
	title.setTextureRect(uvRect_title);
	title.setTexture(texture);

	uvRect_simple_texts.width = 70;		//Textos de combates simples
	uvRect_simple_texts.height = 16;

	GetCharacters();	//Randomizamos los personajes

	for (int i = 0; i < NUM_CHARS; i++) {	
	
		switch (characters[i]) {
		case 0:
			uvRect_title.left = 921;
			uvRect_title.top = 1006;
			break;
		case 1:
			uvRect_title.left = 993;
			uvRect_title.top = 1006;
			break;
		case 2:
			uvRect_title.left = 921;
			uvRect_title.top = 1024;
			break;
		case 3:
			uvRect_title.left = 993;
			uvRect_title.top = 1024;
			break;
		case 4:
			uvRect_title.left = 921;
			uvRect_title.top = 1042;
			break;
		case 5:
			uvRect_title.left = 993;
			uvRect_title.top = 1042;
			break;
		case 6:
			uvRect_title.left = 921;
			uvRect_title.top = 1060;
			break;
		}
		simple_texts[i].setTextureRect(uvRect_title);
		simple_texts[i].setTexture(texture);

	}

	uvRect_double_texts.width = 90;	//Textos de combates dobles
	uvRect_double_texts.height = 16;
	uvRect_double_texts.left = 921;

	for (int i = 0; i < NUM_DOUBLE; i++) {
		uvRect_double_texts.top = double_characters[i] * 18 + 932;
		double_texts[i].setTextureRect(uvRect_double_texts);
		double_texts[i].setTexture(texture);
	}

	uvRect_bosses_texts.width = 94;	//Testos de bosses
	uvRect_bosses_texts.height = 16;
	uvRect_bosses_texts.left = 921;

	uvRect_bosses_texts.top = 894;
	bosses_texts[0].setTextureRect(uvRect_bosses_texts);
	bosses_texts[0].setTexture(texture);

	uvRect_bosses_texts.top = 912;
	bosses_texts[1].setTextureRect(uvRect_bosses_texts);
	bosses_texts[1].setTexture(texture);

	uvRect_icons.width = 26;
	uvRect_icons.height = 32;
	uvRect_icons.top = 789;

	for (int i = 0; i < NUM_CHARS; i++) {	//Iconos combates simples
		uvRect_icons.left = characters[i] * 32 + 923;
		simple_icons[i].setTextureRect(uvRect_icons);
		simple_icons[i].setTexture(texture);
	}

	for (int i = 0; i < NUM_DOUBLE; i++) {	//Iconos combates dobles
		uvRect_icons.left = double_characters[i] * 32 + 923;
		double_icons[i].setTextureRect(uvRect_icons);
		double_icons[i].setTexture(texture);
	}

	//Faltan iconons dobles y de bosses

}

//Randomiza los personajes de forma que no se repitan combates.
void HistoryManager::GetCharacters() {

	srand(time(NULL));

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

void Draw(RenderWindow& window) {


}

void Update() {


}
