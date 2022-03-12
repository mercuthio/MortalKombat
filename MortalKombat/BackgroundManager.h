#ifndef	BackgroundManager_H
#define BackgroundManager_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class BackgroundManager {

public:
	BackgroundManager(Texture*);
	~BackgroundManager() = default;

	void Actualizar();
	void draw(RenderWindow&);

protected:
	int sizeVector;
	vector<RectangleShape> backgroundVector;

};

#endif