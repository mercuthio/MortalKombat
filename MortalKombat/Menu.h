#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const int NUMERO_OPCIONES = 4;
const int TAMANIO_LETRA = 55;

class Menu {

public:
	Menu(Texture*, Font);
	~Menu() = default;

	void draw(RenderWindow& window);
	void Actualizar();
	int OpcionElegida();
	void moverCursor(bool);

private:

	int opcionElegida;

	Font font;
	Text text[NUMERO_OPCIONES + 1];
	RectangleShape fondo;

};

#endif