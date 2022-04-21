#ifndef	BattleManager_H
#define BattleManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "BackgroundManager.h"

#include "LiuKang.h"
#include "Scorpion.h"
#include "Sonya_Blade.h"

#include "Courtyard.h"
#include "Warrior_Shrine.h"
#include "The_Pit.h"

using namespace sf;
using namespace std;

const int CHAR_SIZE_BATTLE = 50;
const float SIZE_LIFE = 413.0f;

class BattleManager {

public:
	BattleManager(Texture*, Font, Clock);
	~BattleManager() = default;

	void Update(Event);									//Actualiza la batalla actual dada una tecla pulsada
	void Update();										//Actualiza el escenario y el hud
	void draw(RenderWindow&);							//Dibuja la batalla actual
	void RestartCombat(CharacterType, CharacterType, background, bool);					//Reinicia los datos del combate
	void Restart();
	void LoadTextures();
	void LoadCharacters();
	int RestartRound(int);								//Resetea las variables para una nueva ronda, devuelve 0 si no ha ganado nadie, 1 si ha ganado el jugador1 y 2 el jugador2

private:

	CharacterType character1;										//Personaje del jugador 1
	CharacterType character2;										//Personaje del jugador 2

	Clock clock;

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
	int clock_inDanger1;
	int clock_inDanger2;

	int fight_x;

	bool flash;
	bool started_game;
	bool showing_fight;
	bool showing_round;
	bool inDanger1;
	bool inDanger2;
	bool showed_danger1;
	bool showed_danger2;
	bool twoPlayers;

	Texture* texture;
	Font font;											//Variable con la fuente de letra

	BackgroundManager BackgroundManager;

	Character LiuKang;
	Character Scorpion;
	Character SonyaBlade;


	Character player1;
	Character player2;

	vector<Text> Texts;
	vector<RectangleShape> HUD_vector;

};

#endif