#include "BackgroundManager.h"

int screenLeftLimit;
int screenRightLimit;
int screenFloorLimit;

int screenLeftHardLimit;
int screenRightHardLimit;

BackgroundManager::BackgroundManager() {
	screenLeftLimit = -1000;
	screenRightLimit = 1000;
	screenFloorLimit = 200;

	screenLeftHardLimit = -1000;
	screenRightHardLimit = 1000;
}

void BackgroundManager::Update() {

	IntRect uvRect;
	RectangleShape tile;

	for (int i = 0; i < backgroundVector.size(); i++) {
		if (i != 0) { 
			if (i != backgroundVector.size() - 1) {
				backgroundVector[i].setPosition(backgroundVector[i].getPosition().x + moveXBack/1.5, backgroundVector[i].getPosition().y + moveYBack/1.5);
			}
			else {
				backgroundVector[i].setPosition(backgroundVector[i].getPosition().x + moveXBack, backgroundVector[i].getPosition().y + moveYBack);
			}
		}
	}
	moveXBack = 0.f;

	switch (type) {
	case COURTYARD:

		float rectWidth_monks = 1037.0f;
		float rectHeight_monks = 128.0f;

		Vector2f sizeBackground_monks = Vector2f(rectWidth_monks * (height_window / 281.0), rectHeight_monks * (height_window / 281.0));

		//uvRect.top = 32.0f + 136.0 * animation;
		uvRect.top = 929.0f + 136.0 * animation;
		uvRect.left = 1121.0f;
		uvRect.width = rectWidth_monks;
		uvRect.height = rectHeight_monks;

		backgroundVector[4].setTextureRect(uvRect);

		clock++;

		if (clock == speed) {
			clock = 0;
			animation++;
			if (animation > 2) {
				animation = 0;
			}
		}
		break;
	}

}

void BackgroundManager::draw(RenderWindow& window) {


	for(RectangleShape rect : backgroundVector) {
		window.draw(rect);
	}

}
