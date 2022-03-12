#ifndef PlayerSelector_H
#define PlayerSelector_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int MAX_X = 5;
const int MAX_Y = 2;
const int CHARACTERS[MAX_Y][MAX_X] = { {1,1,0,1,1},{0,1,1,1,0} };
const int NUMBER_CHARACTERS = 7;

class PlayerSelector {

public:
	PlayerSelector(Texture*, bool);
	~PlayerSelector() = default;

	void Draw(RenderWindow& window, float);			//Dibuja el selector de personajes, le pasa tambien los segundos actuales 
	void Update();								//Actualiza los sprites
	void MoveCursor(int, int, bool);				//Suma a las coordenadas del cursor los dos enteros (x e y). Mueve el segundo cursor si tercer parametro false
	void DrawChoosen(RenderWindow& window, bool);	//Dibuja la animacion de seleccion de un cursor (segundo jugador si false el tercer parametro)
	int ChoosenOption(bool);						//Devuelve la opcion elegida por el primer jugador si el tercer parametro es true
	bool Choosen();								//Devuelve true si se han elegido todos los personajes necesarios

private:

	int x, y;										//Coordenadas del primer cursor
	int x2, y2;										//Coordenadas del segundo cursor
	bool choosen1;									//True si el primer jugador a escogido personaje
	bool choosen2;									//True si el segundo jugador a escogido personaje
	bool flash;									//Variable para la animacion del marco (false = color claro, true = color oscuro)
	bool twoPlayers;								//True si hay dos jugadores
	float time;									//Tiempo actual total

	IntRect uvRect_backg;							//IntRect del fondo
	IntRect uvRect_frame;							//IntRect del marco del jugador 1
	IntRect uvRect_frame2;							//IntRect del marco del jugador 2
	IntRect uvRect_chara;							//IntRect del icono de personaje
	RectangleShape frame;							//marco del jugador 1
	RectangleShape frame2;							//marco del jugador 2
	RectangleShape backg;							//fondo del selector
	RectangleShape icons[NUMBER_CHARACTERS];		//vector de iconos de personajes


};

#endif