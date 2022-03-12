#ifndef OptionsManager_H
#define OptionsManager_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>

using namespace sf;

const int NUMERO_OPCIONES = 5;
const int MAXIMO_MUSICA = 5;
const int MAXIMO_EFECTOS = 5;
const int MAXIMO_VELOCIDAD = 3;


class OptionsManager {

public:
	OptionsManager(Texture*, Font);
	~OptionsManager() = default;

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
	Text text[NUMERO_OPCIONES + 1];
	Text veloc;
	Text dific;
	IntRect uvRect;
	RectangleShape fondo;
	RectangleShape musi[MAXIMO_MUSICA];
	RectangleShape efec[MAXIMO_EFECTOS];

};

#endif