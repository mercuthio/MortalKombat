#ifndef ControlsManager_H
#define ControlsManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"

const int NUM_CONTROLS = 16;
const int CHAR_SIZE_CONTROLS = 35;

class ControlsManager {

public:
	ControlsManager(Texture*, Font);
	//~ControlsManager() = default;

	void draw(RenderWindow&);			//Dibuja el menu de opciones
	void Update();						//Actualiza los sprites de opciones
	void Right();						//Pulsa la tecla D
	void Enter();						//Pulsa la tecla enter
	void Izquierda();					//Mueve una opcion a la izquierda
	void MoveCursor(bool);				//Mueve el curso arriba si parametro true, abajo si false
	void changeKey(Keyboard::Key k);

private:

	int clock_flash = 0;
	bool flash = false;

	bool changing_key = false;
	bool playerTwo = false;
	int choosenOption = 0;					//Entero que guarda la opcion elegida
	Font font = Font();							//Variable con la fuente de la letra
	Text text[16];						//Vector de textos de las opciones del menu
	Text keys[16];
	Text shadow[16];
	IntRect uvRect = IntRect();						//IntRect del fondo
	RectangleShape backg = RectangleShape();				//Objeto del fondo
	RectangleShape logo = RectangleShape();
};

#endif
