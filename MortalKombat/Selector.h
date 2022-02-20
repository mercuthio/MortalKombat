#ifndef SELECTOR_H
#define SELECTOR_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int MAXIMO_X = 5;
const int MAXIMO_Y = 2;
const int PERSONAJES[MAXIMO_Y][MAXIMO_X] = { {1,1,0,1,1},{0,1,1,1,0} };

class Selector {

public:
	Selector(Texture*, Texture*);
	~Selector() = default;

	void Draw(RenderWindow& window);
	void Actualizar();
	void MoverCursor(int, int);
	int OpcionElegida();

private:

	int x, y;
	bool parpadeo;

	RectangleShape marco;
	RectangleShape fondo;

};

#endif