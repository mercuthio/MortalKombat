#ifndef MenuManager_H
#define MenuManager_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const int NUMERO_OptionsManager = 4;
const int TAMANIO_LETRA = 70;

class MenuManager {

public:
	MenuManager(Texture*, Font);
	~MenuManager() = default;

	void draw(RenderWindow& window);			//Dibuja el menu
	void Actualizar();							//Actualiza los sprites del menu
	int OpcionElegida();						//Devuelve la opcion elegida en el menu
	void moverCursor(bool);						//Mueve el cursor arriba si parametro true, abajo si false

private:

	int opcionElegida;							//Entero que guarda la opcion elegida

	IntRect uvRect;								//IntRect del fondo
	Font font;									//Variable con la fuente de letra
	Text text[NUMERO_OptionsManager + 1];		//Vector con los textos de las opciones del menu
	RectangleShape fondo;						//Objeto del fondo

};

#endif