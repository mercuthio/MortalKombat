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

	int choosenOption;							//Entero que guarda la opcion elegida

	IntRect uvRect;								//IntRect del fondo
	Font font;									//Variable con la fuente de letra
	Text text[NUM_OPTIONS_MENU + 1];		//Vector con los textos de las opciones del menu
	RectangleShape backg;						//Objeto del fondo

};

#endif