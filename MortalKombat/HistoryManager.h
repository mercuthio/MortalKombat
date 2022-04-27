#ifndef HistoryManager_H
#define HistoryManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

const int NUM_CHARS = 3;


class HistoryManager {


public:
	HistoryManager(Texture*, int character_);
	~HistoryManager() = default;

	bool Draw(RenderWindow& window, float);		//Dibuja la torre
	void Update();								//Actualiza los sprites
	void GetCharacters();						//Randomiza el vector de personajes
	void Restart(int character);
	void LoadTextures();
	bool NextCombat();
	void RestartVariables();
	int getOpponent();

private:

	Texture* texture;

	int characters[NUM_CHARS];					//Vector que contiene el orden de los personajes simples
	int actual_combat;
	int character;
	int clock;
	int clock_flash;
	int clock_move;

	float time;
	
	bool title_color;							//Color del titulo, true = azul, false = blanco
	bool moving;
	bool finish;

	vector<RectangleShape> Objects;

};

#endif