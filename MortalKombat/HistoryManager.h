#ifndef HistoryManager_H
#define HistoryManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

const int NUM_CHARS = 7;
const int NUM_DOUBLE = 3 * 2;
const int NUM_BOSSES = 2;

class HistoryManager {


public:
	HistoryManager(Texture*);
	~HistoryManager() = default;

	bool Draw(RenderWindow& window, float);		//Dibuja la torre
	void Update();								//Actualiza los sprites
	void GetCharacters();						//Randomiza el vector de personajes
	void Restart();

private:

	int characters[NUM_CHARS];					//Vector que contiene el orden de los personajes simples
	int double_characters[NUM_DOUBLE];
	int actual_combat;

	float instant;
	float time;
	
	bool title_color;							//Color del titulo, true = azul, false = blanco
	bool loaded;								//Indica si estan cargados todos los componentes de la pantalla

	vector<RectangleShape> Objects;

};

#endif