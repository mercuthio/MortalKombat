#ifndef PlayerSelector_H
#define PlayerSelector_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int MAXIMO_X = 5;
const int MAXIMO_Y = 2;
const int PERSONAJES[MAXIMO_Y][MAXIMO_X] = { {1,1,0,1,1},{0,1,1,1,0} };
const int NUMBER_CHARACTERS = 7;

class PlayerSelector {

public:
	PlayerSelector(Texture*, bool);
	~PlayerSelector() = default;

	void Draw(RenderWindow& window, float);
	void Actualizar();
	void MoverCursor(int, int, bool);
	void DrawChoosen(RenderWindow& window, bool);
	int OpcionElegida(bool);
	bool Elegidos();

private:

	int x, y;
	int x2, y2;
	bool elegido1;
	bool elegido2;
	bool parpadeo;
	bool dosJugadores;
	float tiempo;

	IntRect uvRect_backg;
	IntRect uvRect_frame;
	IntRect uvRect_frame2;
	IntRect uvRect_chara;
	RectangleShape marco;
	RectangleShape marco2;
	RectangleShape fondo;
	RectangleShape icons[NUMBER_CHARACTERS];


};

#endif