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

	void draw(RenderWindow&);			//Dibuja el menu de opciones
	void Actualizar();					//Actualiza los sprites de opciones
	void Enter(Music&);					//Pulsa la tecla enter
	void Izquierda(Music&);				//Mueve una opcion a la izquierda
	int OpcionElegida();				//Devuelve la opcion elegida
	void moverCursor(bool);				//Mueve el curso arriba si parametro true, abajo si false

	int musica;							//Valor del volumen de la musica
	int efectos;						//Valor del volumen de los efectos
	int velocidad;						//Valor de la velocidad de animaciones
	bool dificultad;					//False = normal, True = dificil

private:

	int opcionElegida;					//Entero que guarda la opcion elegida

	Font font;							//Variable con la fuente de la letra
	Text text[NUMERO_OPCIONES + 1];		//Vector de textos de las opciones del menu
	Text veloc;							//Texto de la velocidad de animacion	
	Text dific;							//Texto de la dificultad
	IntRect uvRect;						//IntRect del fondo
	RectangleShape fondo;				//Objeto del fondo
	RectangleShape musi[MAXIMO_MUSICA];	//Vector de objetos de la musica
	RectangleShape efec[MAXIMO_EFECTOS];//Vector de objetos de los efectos

};

#endif