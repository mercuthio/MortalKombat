#ifndef	BattleManager_H
#define BattleManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "BackgroundManager.h"

#include "BloodEffect.h"
#include "SpecialAttack.h"
#include "SoundEffects.h"

#include "LiuKang.h"
#include "Scorpion.h"
#include "Sonya_Blade.h"

#include "Courtyard.h"
#include "Warrior_Shrine.h"
#include "The_Pit.h"
#include "Throne_Room.h"
#include "Goros_Lair.h"

using namespace sf;
using namespace std;

const int CHAR_SIZE_BATTLE = 50;
const float SIZE_LIFE = 413.0f;

class BattleManager {

public:
	BattleManager(Texture*, Font, Clock);
	~BattleManager() = default;

	void Update(Event);									//Para que no crashee en cinematica historia (no hace nada)
	void Update();										//Actualiza el escenario y el hud
	void draw(RenderWindow&);							//Dibuja la batalla actual
	void RestartCombat(CharacterType, CharacterType, background, bool);					//Reinicia los datos del combate
	void Restart();
	void LoadTextures();
	void LoadCharacters();
	void RestartRound();								//Resetea las variables para una nueva ronda
	void increase_round(int);
	void CheckCollisions();
	void ProcessHit(AnimationType, bool);

	int finished_round();
	int isfinished();

	void shake();

private:

	CharacterType character1;										//Personaje del jugador 1
	CharacterType character2;										//Personaje del jugador 2

	Clock clock;

	bool shaking;
	bool shakeUp;
	float internalShaking;

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
	int clock_finishRound;
	int clock_finishHim;

	int fight_x;
	int finish_him_x;

	bool flash;
	bool started_game;
	bool showing_fight;
	bool showing_win;
	bool showing_finishHim;
	bool showing_round;
	bool inDanger1;
	bool inDanger2;
	bool showed_danger1;
	bool showed_danger2;
	bool twoPlayers;
	bool finished_game;
	bool finishing1;
	bool finishing2;
	bool P1WinnedPose;
	bool P2WinnedPose;
	bool finishedFinishHim;

	Texture* texture;
	Font font;											//Variable con la fuente de letra

	BackgroundManager BackgroundManager;

	Character LiuKang;
	Character Scorpion;
	Character SonyaBlade;

	BloodEffect blood;
	BloodEffect bloodGround1;
	BloodEffect bloodGround2;

	SpecialAttack player1Special;
	SpecialAttack player2Special;

	Character player1;
	Character player2;

	vector<RectangleShape> HUD_vector;

};

#endif