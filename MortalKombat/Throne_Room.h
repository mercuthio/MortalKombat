#ifndef Throne_Room_H
#define Throne_Room_H

#include "BackgroundManager.h"

class Throne_Room : public BackgroundManager {

public:
	Throne_Room() : BackgroundManager() {
		texture = new Texture();
		this->type = THRONE_ROOM;
		this->speed = 10;
	}

	void loadTextures();

private:

	Texture* texture = new Texture();
};

#endif
