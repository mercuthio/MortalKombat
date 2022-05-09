#ifndef DeadManager_H
#define DeadManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

class DeadManager {


public:
	DeadManager(Texture*);
	~DeadManager() = default;

	bool Draw(RenderWindow& window);		
	void LoadTextures();
	void Update();								//Actualiza los sprites
	void Restart();


private:

	Texture* texture = new Texture();

	int clock = 0;

	RectangleShape backg = RectangleShape();

};

#endif