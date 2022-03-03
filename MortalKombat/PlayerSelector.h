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
	PlayerSelector(Texture*);
	~PlayerSelector() = default;

	void Draw(RenderWindow& window, float);
	void Actualizar();
	void MoverCursor(int, int);
	void DrawChoosen(RenderWindow& window);
	int OpcionElegida();

private:

	int x, y;
	bool parpadeo;
	float tiempo;

	IntRect uvRect_backg;
	IntRect uvRect_frame;
	IntRect uvRect_chara;
	RectangleShape marco;
	RectangleShape fondo;
	RectangleShape icons[NUMBER_CHARACTERS];


};

#endif