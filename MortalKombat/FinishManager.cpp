
#include "FinishManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

FinishManager::FinishManager(Texture* texture_) {

	texture = texture_;

	Restart(6);
}

void FinishManager::LoadTextures() {

	Vector2f size_backg = Vector2f(width_window, height_window);

	IntRect uvRect;

	backg.setTexture(texture);
	backg.setScale(1.0f, 1.0f);

	//Fondo
	uvRect.width = 399;
	uvRect.height = 254;

	switch (character) {
	case 0:	//Jhonny Cage
		uvRect.left = 5;
		uvRect.top = 5;
		break;
	case 3:	//Liu Kang
		uvRect.left = 812;
		uvRect.top = 264;
		break;
	case 4: //Scorpion
		uvRect.left = 5;
		uvRect.top = 523;
		break;
	case 6:	//Sonya Blade
		uvRect.left = 5;
		uvRect.top = 782;
		break;
	}

	backg.setSize(size_backg);

	backg.setTextureRect(uvRect);
	backg.setPosition(0.0f, 0.0f);

}

void FinishManager::Restart(int character_) {

	character = character_;
	clock = 0;
	changed_image = false;

	LoadTextures();
}

bool FinishManager::Draw(RenderWindow& window) {

	window.draw(backg);
	return clock > 900;

}

void FinishManager::Update() {

	clock++;
	if (clock > 450 && !changed_image) {

		changed_image = true;
		IntRect uvRect;
		uvRect = backg.getTextureRect();
		uvRect.left += 403;
		backg.setTextureRect(uvRect);
	}
}
