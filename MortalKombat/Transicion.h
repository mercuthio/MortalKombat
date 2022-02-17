#ifndef TRANSICIO_H
#define TRANSICIO_H

#include "SFML/Graphics.hpp"
#include <chrono>
#include <thread>

using namespace sf;

const int NUM_CUADRADOS = 8;
const int NUM_FRAMES = 50;

class Transicion {

public:
	Transicion();
	~Transicion() = default;

	void draw(RenderWindow& window);

private:

	RectangleShape fondo[NUM_CUADRADOS];

};

Transicion::Transicion() {

	for (int i = 0; i < NUM_CUADRADOS; i++) {
		fondo[i].setFillColor(Color::Black);
	}

}

void Transicion::draw(RenderWindow& window) {

	for (int i = 0; i < NUM_CUADRADOS; i++) {
		fondo[i].setSize(Vector2f(window.getSize().x, window.getSize().y / NUM_CUADRADOS));
		fondo[i].setScale(1.01f, 1.01f);
		fondo[i].setPosition(0,i * fondo[i].getSize().y);
	}

	float resta = 2;

	while(fondo[NUM_CUADRADOS - 1].getSize().y > resta) {

		for (int e = 0; e < NUM_CUADRADOS; e++) {

			fondo[e].setSize(Vector2f(fondo[e].getSize().x, fondo[e].getSize().y - resta));
			window.draw(fondo[e]);

		}

		window.display();
		this_thread::sleep_for(chrono::milliseconds(10));

	}
	
}

#endif