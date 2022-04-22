#ifndef	BackgroundManager_H
#define BackgroundManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

class BackgroundManager {

public:
	BackgroundManager();
	virtual ~BackgroundManager() = default;
	
	Vector2<float> initPlayer1;
	Vector2<float> initPlayer2;

	void Update();
	void draw(RenderWindow&);

protected:
	background type = COURTYARD; //0 courtyard
	int animation = 0;
	int clock = 0;
	int speed = 0;
	int sizeVector = 0;
	vector<RectangleShape> backgroundVector;

};

#endif