#ifndef PlayerSelector_H
#define PlayerSelector_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

const int MAX_X = 5;
const int MAX_Y = 2;
const int CHARACTERS[MAX_Y][MAX_X] = { {1,1,0,1,1},{0,1,1,1,0} };
const int NUMBER_CHARACTERS = 7;

class PlayerSelector {

public:
	PlayerSelector(Texture*, bool);
	~PlayerSelector() = default;

	void Draw(RenderWindow& window, float);				//Dibuja el selector de personajes, le pasa tambien los segundos actuales 
	void Update();										//Actualiza los sprites
	void MoveCursor(int, int, bool);					//Suma a las coordenadas del cursor los dos enteros (x e y). Mueve el segundo cursor si tercer parametro false
	void Restart();
	void LoadTextures();

	int ChoosenOption_int(bool);

	CharacterType ChoosenOption(bool);						//Devuelve la opcion elegida por el primer jugador si el primer parametro es true

	bool AnimationFinished();
	bool Choosen();										//Devuelve true si se han elegido todos los personajes necesarios

	bool choosen1 = false;									//True si el primer jugador a escogido personaje
	bool choosen2 = false;									//True si el segundo jugador a escogido personaje

private:

	int x = 0, y = 0;										//Coordenadas del primer cursor
	int x2 = 0, y2 = 0;										//Coordenadas del segundo cursor
	int clock = 0;										//Tiempo actual total
	int clock_choosen1 = 0;								//Reloj para la animación de seleccionar personaje1
	int clock_choosen2 = 0;								//Reloj para la animación de seleccionar personaje2
	int frame_choosen1 = 0;
	int frame_choosen2 = 0;

	bool flash = false;										//Variable para la animacion del marco (false = color claro, true = color oscuro)
	bool twoPlayers = false;								//True si hay dos jugadores

	Texture* texture = new Texture();
	vector<RectangleShape> Objects = vector<RectangleShape>();

};

#endif