#ifndef Warrior_Shrine_H
#define Warrior_Shrine_H

#include "BackgroundManager.h"

class Warrior_Shrine : public BackgroundManager {

public:
	Warrior_Shrine() : BackgroundManager() {
		texture = new Texture();
		this->type = WARRIOR_SHRINE;
		this->speed = 10;
	}

	void loadTextures();

private:

	Texture* texture = new Texture();
};

#endif