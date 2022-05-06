#ifndef Goros_Lair_H
#define Goros_Lair_H

#include "BackgroundManager.h"

class Goros_Lair : public BackgroundManager {

public:
	Goros_Lair() : BackgroundManager() {
		texture = new Texture();
		this->type = GOROS_LAIR;
		this->speed = 10;
	}

	void loadTextures();

private:

	Texture* texture;
};

#endif