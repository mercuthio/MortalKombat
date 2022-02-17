#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

const int NUMERO_OPCIONES = 4;
const int TAMANIO_LETRA = 55;

class Menu {

public:
	Menu(Texture*, Font);
	~Menu() = default;

	void draw(RenderWindow& window);
	void Actualizar();
	int OpcionElegida();
	void moverCursor(bool);

private:

	int opcionElegida;

	Font font;
	Text text[NUMERO_OPCIONES + 1];
	RectangleShape fondo;

};

Menu::Menu(Texture* textura, Font font_) {

	font = font_;
	opcionElegida = 0;

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("HISTORIA");
	text[0].setCharacterSize(TAMANIO_LETRA);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("DUELO");
	text[1].setCharacterSize(TAMANIO_LETRA);

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("OPCIONES");
	text[2].setCharacterSize(TAMANIO_LETRA);

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("SALIR");
	text[3].setCharacterSize(TAMANIO_LETRA);

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Menu::Actualizar() {

	text[opcionElegida].setFillColor(Color::Green);

	for (int i = 0; i < NUMERO_OPCIONES; i++) {
		if (i != opcionElegida && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
		}	
	}

}

int Menu::OpcionElegida() {

	return opcionElegida;

}

void Menu::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(fondo);

	for (int i = 0; i < NUMERO_OPCIONES; i++) {

		text[i].setPosition(Vector2f(window.getSize().x / 3, window.getSize().y / 2 + TAMANIO_LETRA * (i+1)));
		window.draw(text[i]);

	}

}

void Menu::moverCursor(bool arriba) {

	if (arriba) {
		opcionElegida--;
		if (opcionElegida < 0) {
			opcionElegida = NUMERO_OPCIONES - 1;
		}
	}
	else if (!arriba) {
		opcionElegida++;
		if (opcionElegida == NUMERO_OPCIONES) {
			opcionElegida = 0;
		}
	}

}

#endif