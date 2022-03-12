#include "BackgroundManager.h"

void BackgroundManager::Actualizar() {

}

void BackgroundManager::draw(RenderWindow& window) {

	for(RectangleShape rect : backgroundVector) {
		window.draw(rect);
	}

}
