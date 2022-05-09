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

	Texture* texture = new Texture();

	int characters[NUM_CHARS];					//Vector que contiene el orden de los personajes simples
	int actual_combat = 0;
	int character = 0;
	int clock = 0;
	int clock_flash = 0;
	int clock_move = 0;

	float time = 0.0;
	
	bool title_color = false;							//Color del titulo, true = azul, false = blanco
	bool moving = false;
	bool finish = false;

	vector<RectangleShape> Objects = vector<RectangleShape>();

};

#endif