#ifndef INICIO_H
#define INICIO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Inicio {

public:
	Inicio(Texture*);
	~Inicio() = default;

	void draw(RenderWindow& window);

private:

	RectangleShape fondo;

};

Inicio::Inicio(Texture* textura) {

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Inicio::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

}


#endif