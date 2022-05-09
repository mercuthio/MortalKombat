#ifndef MenuManager_H
#define MenuManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"

#include <iostream>

using namespace sf;
using namespace std;

const int NUM_OPTIONS_MENU = 4;
const int CHAR_SIZE = 70;

class MenuManager {

public:
	MenuManager(Texture*, Font);
	~MenuManager() = default;

	void draw(RenderWindow& window);			//Dibuja el menu
	void Update();							//Actualiza los sprites del menu
	int ChoosenOption();						//Devuelve la opcion elegida en el menu
	void MoveCursor(bool);						//Mueve el cursor arriba si parametro true, abajo si false

private:

	int choosenOption = 0;							//Entero que guarda la opcion elegida

	IntRect uvRect = IntRect();								//IntRect del fondo
	Font font = Font();									//Variable con la fuente de letra
	Text text[NUM_OPTIONS_MENU];				//Vector con los textos de las opciones del menu
	Text shadow[NUM_OPTIONS_MENU];
	RectangleShape logo = RectangleShape();
	RectangleShape backg = RectangleShape();						//Objeto del fondo

};

#endif