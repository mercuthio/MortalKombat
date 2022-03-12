#ifndef PlayerSelector_H
#define PlayerSelector_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int MAXIMO_X = 5;
const int MAXIMO_Y = 2;
const int PERSONAJES[MAXIMO_Y][MAXIMO_X] = { {1,1,0,1,1},{0,1,1,1,0} };
const int NUMBER_CHARACTERS = 7;

class PlayerSelector {

public:
	PlayerSelector(Texture*, bool);
	~PlayerSelector() = default;

	void Draw(RenderWindow& window, float);			//Dibuja el selector de personajes, le pasa tambien los segundos actuales 
	void Actualizar();								//Actualiza los sprites
	void MoverCursor(int, int, bool);				//Suma a las coordenadas del cursor los dos enteros (x e y). Mueve el segundo cursor si tercer parametro false
	void DrawChoosen(RenderWindow& window, bool);	//Dibuja la animacion de seleccion de un cursor (segundo jugador si false el tercer parametro)
	int OpcionElegida(bool);						//Devuelve la opcion elegida por el primer jugador si el tercer parametro es true
	bool Elegidos();								//Devuelve true si se han elegido todos los personajes necesarios

private:

	int x, y;										//Coordenadas del primer cursor
	int x2, y2;										//Coordenadas del segundo cursor
	bool elegido1;									//True si el primer jugador a escogido personaje
	bool elegido2;									//True si el segundo jugador a escogido personaje
	bool parpadeo;									//Variable para la animacion del marco (false = color claro, true = color oscuro)
	bool dosJugadores;								//True si hay dos jugadores
	float tiempo;									//Tiempo actual total

	IntRect uvRect_backg;							//IntRect del fondo
	IntRect uvRect_frame;							//IntRect del marco del jugador 1
	IntRect uvRect_frame2;							//IntRect del marco del jugador 2
	IntRect uvRect_chara;							//IntRect del icono de personaje
	RectangleShape marco;							//marco del jugador 1
	RectangleShape marco2;							//marco del jugador 2
	RectangleShape fondo;							//fondo del selector
	RectangleShape icons[NUMBER_CHARACTERS];		//vector de iconos de personajes


};

#endif