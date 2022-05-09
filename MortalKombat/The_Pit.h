#ifndef The_Pit_H
#define The_Pit_H

#include "BackgroundManager.h"

class The_Pit : public BackgroundManager {

public:
	The_Pit() : BackgroundManager() {
		texture = new Texture();
		this->type = THE_PIT;
		this->speed = 10;
	}

	void loadTextures();

private:

	Texture* texture = new Texture();
};

#endif