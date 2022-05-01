#ifndef CONTROLSMANAGER_H
#define CONTROLSMANAGER_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"

const int NUM_CONTROLS = 16;
const int CHAR_SIZE_CONTROLS = 12;

class ControlsManager {

public:
	ControlsManager(Texture*, Font);
	//~ControlsManager() = default;

	void draw(RenderWindow&);			//Dibuja el menu de opciones
	void Update();						//Actualiza los sprites de opciones
	void Right();						//Pulsa la tecla D
	void Enter();						//Pulsa la tecla enter
	void Izquierda();					//Mueve una opcion a la izquierda
	int	ChoosenOption();				//Devuelve la opcion elegida
	void MoveCursor(bool);				//Mueve el curso arriba si parametro true, abajo si false


private:

	int choosenOption;					//Entero que guarda la opcion elegida
	Font font;							//Variable con la fuente de la letra
	Text text[16];						//Vector de textos de las opciones del menu
	Text shadow[16];
	IntRect uvRect;						//IntRect del fondo
	RectangleShape backg;				//Objeto del fondo
	RectangleShape logo;
};

#endif
