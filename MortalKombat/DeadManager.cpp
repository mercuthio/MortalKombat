
#include "DeadManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

DeadManager::DeadManager(Texture* texture_, Font font_) {

	font = font_;
	texture = texture_;

	Restart();
}

void DeadManager::LoadTextures() {

	Vector2f size_backg = Vector2f(width_window, height_window);

	IntRect uvRect;

	backg.setTexture(texture);
	backg.setScale(1.0f, 1.0f);

	//Fondo 0
	uvRect.width = 400;
	uvRect.height = 254;
	uvRect.left = 4010;
	uvRect.top = 1551;
	backg.setSize(size_backg);

	backg.setTextureRect(uvRect);
	backg.setPosition(0.0f, 0.0f);

}

void DeadManager::Restart() {

	clock = 0;

	LoadTextures();
}

bool DeadManager::Draw(RenderWindow& window) {

	window.draw(backg);

	return clock > 280;

}

void DeadManager::Update() {

	clock++;
}
