
#include "StartManager.h"
#include <iostream>
using namespace std;
StartManager::StartManager(Texture* textura) {

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1890;
	uvRect.top = 1555;

	fondo.setPosition(0, 0);
	fondo.setTextureRect(uvRect);
	fondo.setTexture(textura);

}

void StartManager::draw(RenderWindow& window, float segundos) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));

	if (segundos > 3.0f) {
		uvRect.left = 2320;
		fondo.setTextureRect(uvRect);
	}
	window.draw(fondo);

}

void StartManager::actualizar() {

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 2500;
	uvRect.top = 1555;

}

