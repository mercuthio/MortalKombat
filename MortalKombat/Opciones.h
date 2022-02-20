#ifndef OPCIONES_H
#define OPCIONES_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>

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

#endif