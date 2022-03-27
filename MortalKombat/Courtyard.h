#ifndef Courtyard_H
#define Courtyard_H

#include "BackgroundManager.h"

class Courtyard : public BackgroundManager{

public:
	Courtyard() : BackgroundManager() {
		courtyardTexture = new Texture();
		this->type = 0;
		this->speed = 10;
	}

	void loadTextures();

private:

	Texture* courtyardTexture;
};

#endif
