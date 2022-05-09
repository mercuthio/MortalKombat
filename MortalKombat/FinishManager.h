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

	Texture* texture = new Texture();
	Font font = Font();

	int clock = 0;
	int character = 0;
	bool changed_image = false;

	RectangleShape backg = RectangleShape();

};

#endif