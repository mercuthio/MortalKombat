#ifndef Courtyard_H
#define Courtyard_H

#include "BackgroundManager.h"

class Courtyard : public BackgroundManager{

public:
	Courtyard(Texture* t) : BackgroundManager(t) {}

private:
	void loadTextures();

};

#endif
