#ifndef	BattleManager_H
#define BattleManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "BackgroundManager.h"

#include "Animation.h"
#include "LiuKang.h"

#include "Courtyard.h"
#include "Warrior_Shrine.h"
#include "The_Pit.h"

using namespace sf;
using namespace std;

const int CHAR_SIZE_BATTLE = 50;
const float SIZE_LIFE = 413.0f;

class BattleManager {

public:
	BattleManager(Texture*, Font);
	~BattleManager() = default;

	void Update(Event);									//Actualiza la batalla actual dada una tecla pulsada
	void Update();										//Actualiza el escenario y el hud
	void draw(RenderWindow&);							//Dibuja la batalla actual
	void RestartCombat(CharacterType, CharacterType, background);					//Reinicia los datos del combate
	void Restart();
	void LoadTextures();
	int RestartRound(int);								//Resetea las variables para una nueva ronda, devuelve 0 si no ha ganado nadie, 1 si ha ganado el jugador1 y 2 el jugador2

private:

	int character1;										//Personaje del jugador 1
	int character2;										//Personaje del jugador 2

	int life1;
	int life2;

	int stage;
	int time_left;
	int round;

	int points1;
	int points2;

	int rounds_won1;
	int rounds_won2;

	int clock_timer;
	int clock_flash;
	int clock_fight;
	int clock_start;

	int fight_x;

	bool flash;
	bool started_game;
	bool showing_fight;
	bool showing_round;
	bool inDanger1;
	bool inDanger2;

	Texture* texture;
	Font font;											//Variable con la fuente de letra

	BackgroundManager BackgroundManager;
	Character player1;
	Character player2;

	vector<Text> Texts;
	vector<RectangleShape> HUD_vector;

};

#endif