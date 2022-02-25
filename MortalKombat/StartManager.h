#ifndef StartManager_H
#define StartManager_H

#include "SFML/Graphics.hpp"

using namespace sf;

class StartManager {

public:
	StartManager(Texture*);
	~StartManager() = default;

	void draw(RenderWindow& window);

private:

	RectangleShape fondo;

};

#endif