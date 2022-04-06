#ifndef OptionsManager_H
#define OptionsManager_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>

using namespace sf;

const int NUM_OPTIONS_OPT = 4;
const int MAX_MUSIC = 5;
const int MAX_EFFECTS = 5;


class OptionsManager {

public:
	OptionsManager(Texture*, Font);
	~OptionsManager() = default;

	void draw(RenderWindow&);			//Dibuja el menu de opciones
	void Update();					//Actualiza los sprites de opciones
	void Enter(Music&);					//Pulsa la tecla enter
	void Izquierda(Music&);				//Mueve una opcion a la izquierda
	int ChoosenOption();				//Devuelve la opcion elegida
	void MoveCursor(bool);				//Mueve el curso arriba si parametro true, abajo si false

	int music;							//Valor del volumen de la musica
	int effects;						//Valor del volumen de los efectos
	bool difficulty;					//False = normal, True = dificil

private:

	int choosenOption;					//Entero que guarda la opcion elegida

	Font font;							//Variable con la fuente de la letra
	Text text[NUM_OPTIONS_OPT + 1];		//Vector de textos de las opciones del menu
	Text dific;							//Texto de la dificultad
	IntRect uvRect;						//IntRect del fondo
	RectangleShape backg;				//Objeto del fondo
	RectangleShape musi[MAX_MUSIC];	//Vector de objetos de la musica
	RectangleShape efec[MAX_EFFECTS];//Vector de objetos de los efectos

};

#endif