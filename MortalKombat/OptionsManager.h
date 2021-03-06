#ifndef OptionsManager_H
#define OptionsManager_H

#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>
#include "GlobalVars.h"

using namespace sf;

const int NUM_OPTIONS_OPT = 6;
const int MAX_MUSIC = 5;
const int MAX_EFFECTS = 5;
const int MAX_SPEED = 4;


class OptionsManager {

public:
	OptionsManager(Texture*, Font);
	~OptionsManager() = default;

	void draw(RenderWindow&);			//Dibuja el menu de opciones
	void Update();					//Actualiza los sprites de opciones
	void Right();					//Pulsa la tecla D
	bool Enter();					//Pulsa la tecla enter, devuelve true si ha seleccionado controles
	void Izquierda();				//Mueve una opcion a la izquierda
	int ChoosenOption();				//Devuelve la opcion elegida
	void MoveCursor(bool);				//Mueve el curso arriba si parametro true, abajo si false

	int musicVolume = 0;					//Valor del volumen de la musica
	int effects = 0;						//Valor del volumen de los efectos
	int speed_game = 0;
	int num_mode = 0;

private:

	int choosenOption = 0;					//Entero que guarda la opcion elegida
	
	//ControlsManager ControlsManager;

	Font font = Font();							//Variable con la fuente de la letra
	Text text[NUM_OPTIONS_OPT + 1];		//Vector de textos de las opciones del menu
	Text shadow[NUM_OPTIONS_OPT + 1];
	Text dific = Text();							//Texto de la dificultad
	Text speed = Text();
	Text mode = Text();
	IntRect uvRect = IntRect();						//IntRect del fondo
	RectangleShape backg = RectangleShape();				//Objeto del fondo
	RectangleShape logo = RectangleShape();
	RectangleShape musi[MAX_MUSIC];	//Vector de objetos de la musica
	RectangleShape efec[MAX_EFFECTS];//Vector de objetos de los efectos
};

#endif