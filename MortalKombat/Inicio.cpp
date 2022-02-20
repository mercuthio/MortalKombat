
#include "Inicio.h"

Inicio::Inicio(Texture* textura) {

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Inicio::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

}

