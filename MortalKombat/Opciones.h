#ifndef OPCIONES_H
#define OPCIONES_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int NUMERO_OPCIONES_O = 5;
const int MAXIMO_MUSICA = 5;
const int MAXIMO_EFECTOS = 5;
const int MAXIMO_VELOCIDAD = 3;


class Opciones {

public:
	Opciones(Texture*, Font);
	~Opciones() = default;

	void draw(RenderWindow& window);
	void Actualizar();
	void Cambiar();
	int OpcionElegida();
	void moverCursor(bool);

private:

	int opcionElegida;
	int musica;
	int efectos;
	int velocidad;
	bool dificultad;	//False = facil, true = dificil

	Font font;
	Text text[NUMERO_OPCIONES_O + 1];
	Text veloc;
	Text dific;
	RectangleShape fondo;
	RectangleShape musi[MAXIMO_MUSICA];
	RectangleShape efec[MAXIMO_EFECTOS];

};

Opciones::Opciones(Texture* textura, Font font_) {

	font = font_;
	opcionElegida = 0;
	musica = 3;
	efectos = 3;
	velocidad = 0;
	dificultad = false;

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("MUSICA");
	text[0].setCharacterSize(TAMANIO_LETRA);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("EFECTOS DE SONIDO");
	text[1].setCharacterSize(TAMANIO_LETRA);

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("VELOCIDAD PELEA");
	text[2].setCharacterSize(TAMANIO_LETRA);

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("DIFICULTAD");
	text[3].setCharacterSize(TAMANIO_LETRA);

	text[4].setFont(font);
	text[4].setFillColor(Color::Black);
	text[4].setString("SALIR");
	text[4].setCharacterSize(TAMANIO_LETRA);

	fondo.setPosition(0, 0);
	fondo.setTexture(textura);

}

void Opciones::Actualizar() {

	text[opcionElegida].setFillColor(Color::Green);

	for (int i = 0; i < NUMERO_OPCIONES_O; i++) {
		if (i != opcionElegida && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
		}
	}

}

void Opciones::Cambiar() {

	switch (opcionElegida) {
	case 0: //MUSICA
		musica++;
		if (musica == MAXIMO_MUSICA) {
			musica = 0;
		}
		break;
	case 1: //EFECTOS
		efectos++;
		if (efectos == MAXIMO_EFECTOS) {
			efectos = 0;
		}
		break;
	case 2: //VELOCIDAD
		velocidad++;
		if (velocidad == MAXIMO_VELOCIDAD) {
			velocidad = 0;
		}
		break;
	case 3: //DIFICULTAD
		dificultad = !dificultad;
		break;
	}

}

int Opciones::OpcionElegida() {

	return opcionElegida;

}

void Opciones::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

	for (int i = 0; i < NUMERO_OPCIONES_O; i++) {

		text[i].setPosition(Vector2f(0, window.getSize().y / 5 + TAMANIO_LETRA * (i*1.2) ));
		window.draw(text[i]);

	}

}

void Opciones::moverCursor(bool arriba) {

	if (arriba) {
		opcionElegida--;
		if (opcionElegida < 0) {
			opcionElegida = NUMERO_OPCIONES_O - 1;
		}
	}
	else if (!arriba) {
		opcionElegida++;
		if (opcionElegida == NUMERO_OPCIONES_O) {
			opcionElegida = 0;
		}
	}

}

#endif