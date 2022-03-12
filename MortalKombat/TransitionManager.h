#ifndef TransitionManager_H
#define TransitionManager_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int NUM_CUADRADOS = 8;
const int NUM_FRAMES = 50;

class TransitionManager {

public:
	TransitionManager();
	~TransitionManager() = default;

	void draw(RenderWindow& window);

private:

	RectangleShape fondo[NUM_CUADRADOS];

};

#endif