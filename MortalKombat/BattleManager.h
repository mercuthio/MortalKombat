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
#include "Jhonny_Cage.h"

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
	BattleManager(Texture*,Texture*, Font, Clock);
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
	void Pause();

	int finished_round();
	int isfinished();

	void shake();

private:

	CharacterType character1 = CharacterType();										//Personaje del jugador 1
	CharacterType character2 = CharacterType();										//Personaje del jugador 2

	Clock clock = Clock();

	bool shaking = false;
	bool shakeUp = false;
	bool paused = false;
	float internalShaking = 0.0;

	int life1 = 0;
	int life2 = 0;

	int stage = 0;
	int time_left = 0;
	int round = 0;

	int points1 = 0;
	int points2 = 0;

	int rounds_won1 = 0;
	int rounds_won2 = 0;

	int clock_timer = 0;
	int clock_flash = 0;
	int clock_fight = 0;
	int clock_start = 0;
	int clock_inDanger1 = 0;
	int clock_inDanger2 = 0;
	int clock_finishRound = 0;
	int clock_finishHim = 0;

	int fight_x = 0;
	int finish_him_x = 0;

	bool flash = false;
	bool started_game = false;
	bool showing_fight = false;
	bool showing_win = false;
	bool showing_finishHim = false;
	bool showing_round = false;
	bool inDanger1 = false;
	bool inDanger2 = false;
	bool showed_danger1 = false;
	bool showed_danger2 = false;
	bool twoPlayers = false;
	bool finished_game = false;
	bool finishing1 = false;
	bool finishing2 = false;
	bool P1WinnedPose = false;
	bool P2WinnedPose = false;
	bool finishedFinishHim = false;
	bool waitingToEnd = false;

	Texture* texture = new Texture();
	Texture* icon = new Texture();
	Font font = Font();											//Variable con la fuente de letra

	BackgroundManager BackgroundManager;
	RectangleShape pauseIcon;

	Character LiuKang = Character();
	Character Scorpion = Character();
	Character SonyaBlade = Character();
	Character JhonnyCage = Character();

	BloodEffect blood = BloodEffect();
	BloodEffect bloodGround1 = BloodEffect();
	BloodEffect bloodGround2 = BloodEffect();

	SpecialAttack player1Special = SpecialAttack();
	SpecialAttack player2Special = SpecialAttack();

	Character player1 = Character();
	Character player2 = Character();

	vector<RectangleShape> HUD_vector = vector<RectangleShape>();

};

#endif