#ifndef MenuManager_H
#define MenuManager_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const int NUMERO_OptionsManager = 4;
const int TAMANIO_LETRA = 55;

class MenuManager {

public:
	MenuManager(Texture*, Font);
	~MenuManager() = default;

	void draw(RenderWindow& window);
	void Actualizar();
	int OpcionElegida();
	void moverCursor(bool);

private:

	int opcionElegida;

	Font font;
	Text text[NUMERO_OptionsManager + 1];
	RectangleShape fondo;

};

#endif