#include "BackgroundManager.h"

void BackgroundManager::Update() {

	IntRect uvRect;
	RectangleShape tile;

	switch(type) {
	case 0: //Courtyard

		float rectWidth_monks = 1037.0f;
		float rectHeight_monks = 128.0f;

		Vector2f sizeBackground_monks = Vector2f(rectWidth_monks * (600.0 / 281.0), rectHeight_monks * (600.0 / 281.0));

		uvRect.top = 32.0f + 136.0*animation;
		uvRect.left = 1121.0f;
		uvRect.width = rectWidth_monks;
		uvRect.height = rectHeight_monks;

		backgroundVector[4].setTextureRect(uvRect);

		clock++;

		if (clock == speed) {
			clock = 0;
			animation++;
			if (animation > 5) {
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
