
#include "StartManager.h"

StartManager::StartManager(Texture* textura) {

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void StartManager::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

}

