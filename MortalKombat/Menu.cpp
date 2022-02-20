
#include "Menu.h"

Menu::Menu(Texture* textura, Font font_) {

	font = font_;
	opcionElegida = 0;

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("STORY");
	text[0].setCharacterSize(TAMANIO_LETRA);
	text[0].setOutlineColor(Color::Green);
	text[0].setOutlineThickness(2.0f);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("DUEL");
	text[1].setCharacterSize(TAMANIO_LETRA);
	text[1].setOutlineColor(Color::Green);
	text[1].setOutlineThickness(2.0f);

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("OPTIONS");
	text[2].setCharacterSize(TAMANIO_LETRA);
	text[2].setOutlineColor(Color::Green);
	text[2].setOutlineThickness(2.0f);

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("EXIT");
	text[3].setCharacterSize(TAMANIO_LETRA);
	text[3].setOutlineColor(Color::Green);
	text[3].setOutlineThickness(2.0f);

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Menu::Actualizar() {

	text[opcionElegida].setFillColor(Color::Green);
	text[opcionElegida].setOutlineColor(Color::Black);

	for (int i = 0; i < NUMERO_OPCIONES; i++) {
		if (i != opcionElegida && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
			text[i].setOutlineColor(Color::Green);
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

		text[i].setPosition(Vector2f(window.getSize().x / 3, window.getSize().y / 2 + TAMANIO_LETRA * (i + 1)));
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
