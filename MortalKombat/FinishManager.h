#ifndef FinishManager_H
#define FinishManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

class FinishManager {


public:
	FinishManager(Texture*);
	~FinishManager() = default;

	bool Draw(RenderWindow& window);
	void LoadTextures();
	void Update();								//Actualiza los sprites
	void Restart(int);


private:

	Texture* texture;
	Font font;

	int clock;
	int character;
	bool changed_image;

	RectangleShape backg;

};

#endif