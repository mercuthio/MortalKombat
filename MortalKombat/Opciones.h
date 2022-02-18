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

	void draw(RenderWindow&);
	void Actualizar();
	void Enter(Music&);
	void Izquierda(Music&);
	int OpcionElegida();
	void moverCursor(bool);

	int musica;
	int efectos;
	int velocidad;
	bool dificultad;	//False = normal, True = dificil

private:

	int opcionElegida;

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
	velocidad = 1;
	dificultad = false;

	for (int i = 0; i < MAXIMO_MUSICA; i++) {
		musi[i].setSize(Vector2f(15, TAMANIO_LETRA));
	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {
		efec[i].setSize(Vector2f(15,TAMANIO_LETRA));
	}

	text[0].setFont(font);
	text[0].setFillColor(Color::Black);
	text[0].setString("MUSICA");
	text[0].setCharacterSize(TAMANIO_LETRA);

	text[1].setFont(font);
	text[1].setFillColor(Color::Black);
	text[1].setString("EFECTOS");
	text[1].setCharacterSize(TAMANIO_LETRA);

	text[2].setFont(font);
	text[2].setFillColor(Color::Black);
	text[2].setString("VELOCIDAD");
	text[2].setCharacterSize(TAMANIO_LETRA);

	text[3].setFont(font);
	text[3].setFillColor(Color::Black);
	text[3].setString("DIFICULTAD");
	text[3].setCharacterSize(TAMANIO_LETRA);

	text[4].setFont(font);
	text[4].setFillColor(Color::Black);
	text[4].setString("SALIR");
	text[4].setCharacterSize(TAMANIO_LETRA);

	veloc.setFont(font);
	veloc.setFillColor(Color::Black);
	veloc.setCharacterSize(TAMANIO_LETRA);

	dific.setFont(font);
	dific.setFillColor(Color::Black);
	dific.setCharacterSize(TAMANIO_LETRA);

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

	for (int i = 0; i < MAXIMO_MUSICA; i++) {

		if (i <= musica) {
			musi[i].setFillColor(Color::Red);
		}
		else {
			musi[i].setFillColor(Color::Black);
		}

	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {

		if (i <= efectos) {
			efec[i].setFillColor(Color::Red);
		}
		else {
			efec[i].setFillColor(Color::Black);
		}

	}

	switch (velocidad) {
	case 0:
		veloc.setString("LENTA");
		break;
	case 1:
		veloc.setString("NORMAL");
		break;

	case 2:
		veloc.setString("RAPIDA");
		break;
	}

	if (dificultad) {
		dific.setString("DIFICIL");
	}
	else {
		dific.setString("NORMAL");
	}

}

void Opciones::Enter(Music& music) {

	switch (opcionElegida) {
	case 0: //MUSICA
		if (musica + 1 < MAXIMO_MUSICA) {
			musica++;
		}
		music.setVolume((musica + 1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (efectos + 1 < MAXIMO_EFECTOS) {
			efectos++;
		}
		break;
	case 2: //VELOCIDAD
		if (velocidad < MAXIMO_VELOCIDAD) {
			velocidad++;
		}
		break;
	case 3: //DIFICULTAD
		dificultad = !dificultad;
		break;
	}

}

void Opciones::Izquierda(Music& music) {

	switch (opcionElegida) {
	case 0: //MUSICA
		if (musica - 1 >= -1) {
			musica--;
		}
		music.setVolume((musica+1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (efectos - 1 >= -1) {
			efectos--;
		}
		break;
	case 2: //VELOCIDAD
		if (velocidad - 1 >= 0) {
			velocidad--;
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

	for (int i = 0; i < NUMERO_OPCIONES_O - 1; i++) {
		text[i].setPosition(Vector2f(0, window.getSize().y / 2.5 + TAMANIO_LETRA * (i*1.3) ));
		window.draw(text[i]);
	}

	for (int i = 0; i < MAXIMO_MUSICA; i++) {
		musi[i].setPosition(Vector2f(window.getSize().x / 2 + (i * (TAMANIO_LETRA / 2)), window.getSize().y / 2.5));
		window.draw(musi[i]);
	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {
		efec[i].setPosition(Vector2f(window.getSize().x / 2 + (i * (TAMANIO_LETRA / 2)), window.getSize().y / 2.5 + TAMANIO_LETRA * 1.5));
		window.draw(efec[i]);
	}

	veloc.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2.5 + TAMANIO_LETRA * (2 * 1.3)));
	window.draw(veloc);

	dific.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2.5 + TAMANIO_LETRA * (3 * 1.3)));
	window.draw(dific);

	text[NUMERO_OPCIONES_O - 1].setPosition(Vector2f(0, window.getSize().y - (TAMANIO_LETRA + 5)));
	window.draw(text[NUMERO_OPCIONES_O - 1]);

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