#ifndef	BattleManager_H
#define BattleManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "BackgroundManager.h"
#include "Courtyard.h"

using namespace sf;
using namespace std;

const int CHAR_SIZE_BATTLE = 50;

class BattleManager {

public:
	BattleManager(Texture*, Font );
	~BattleManager() = default;

	void Update();									//Actualiza la batalla actual
	void draw(RenderWindow&);							//Dibuja la batalla actual
	void RestartCombat(character, character, background);					//Reinicia los datos del combate
	int RestartRound(int);								//Resetea las variables para una nueva ronda, devuelve 0 si no ha ganado nadie, 1 si ha ganado el jugador1 y 2 el jugador2

private:


	character character1;										//Personaje del jugador 1
	character character2;										//Personaje del jugador 2

	int life1;
	int life2;

	background stage;

	int time_left;
	int round;

	int points1;
	int points2;

	int rounds_won1;
	int rounds_won2;

	Font font;											//Variable con la fuente de letra
	Text T_points1;
	Text T_points2;
	Text T_time_left;

	BackgroundManager BackgroundManager;
	//Personaje1
	//Personaje2

	RectangleShape I_life1;
	RectangleShape I_life2;
	RectangleShape I_name1;
	RectangleShape I_name2;
	RectangleShape I_winned1;
	RectangleShape I_winned2;
	RectangleShape I_danger;
	RectangleShape I_winner;
	RectangleShape I_round;

	IntRect uvRect_life;
	IntRect uvRect_name1;
	IntRect uvRect_name2;
	IntRect uvRect_winned;
	IntRect uvRect_danger;
	IntRect uvRect_winner;
	IntRect uvRect_round;

};

#endif