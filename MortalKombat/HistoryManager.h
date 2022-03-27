#ifndef HistoryManager_H
#define HistoryManager_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const int NUM_CHARS = 7;
const int NUM_DOUBLE = 3 * 2;
const int NUM_BOSSES = 2;

class HistoryManager {


public:
	HistoryManager(Texture*);
	~HistoryManager() = default;

	bool Draw(RenderWindow& window, float);			//Dibuja la torre
	void Update();								//Actualiza los sprites
	void GetCharacters();						//Randomiza el vector de personajes

private:

	int characters[NUM_CHARS];					//Vector que contiene el orden de los personajes simples
	int double_characters[NUM_DOUBLE];

	int actual_combat;
	float instant;
	float time;
	bool title_color;							//Color del titulo, true = azul, false = blanco
	bool loaded;								//Indica si estan cargados todos los componentes de la pantalla

	IntRect uvRect_backg;
	IntRect uvRect_simple_texts;
	IntRect uvRect_double_texts;
	IntRect uvRect_bosses_texts;
	IntRect uvRect_icons;
	IntRect uvRect_bosses_icons;
	IntRect uvRect_bossIcons;
	IntRect uvRect_title;

	RectangleShape simple_icons[NUM_CHARS];					//Iconos de todos los personajes simples
	RectangleShape simple_texts[NUM_CHARS];					//Textos de todos los personajes simples
	RectangleShape double_icons[NUM_DOUBLE];				//Iconos de los personajes dobles
	RectangleShape double_texts[NUM_DOUBLE];				//Iconos de los personajes dobles
	RectangleShape bosses_icons[NUM_BOSSES];				//Iconos de los dos bosses finales
	RectangleShape bosses_texts[NUM_BOSSES];				//Textos de los dos bosses finales
	RectangleShape title;									//Texto del titulo
	RectangleShape backg;									//Objeto del fondo
	RectangleShape player_icon;								//Icono del personaje del jugador

};

#endif