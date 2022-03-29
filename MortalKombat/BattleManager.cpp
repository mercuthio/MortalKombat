
#include "BattleManager.h"

using namespace std;

BattleManager::BattleManager(Texture* texture, Font font_) {

	font = font_;

	T_points1.setFont(font);
	T_points1.setFillColor(Color::Yellow);
	T_points1.setString("0000");
	T_points1.setCharacterSize(CHAR_SIZE_BATTLE);
	T_points1.setOutlineColor(Color::Black);
	T_points1.setOutlineThickness(2.0f);

	T_points2.setFont(font);
	T_points2.setFillColor(Color::Yellow);
	T_points2.setString("0000");
	T_points2.setCharacterSize(CHAR_SIZE_BATTLE);
	T_points2.setOutlineColor(Color::Black);
	T_points2.setOutlineThickness(2.0f);

	T_time_left.setFont(font);
	T_time_left.setFillColor(Color::Red);
	T_time_left.setString("0000");
	T_time_left.setCharacterSize(CHAR_SIZE_BATTLE);
	T_time_left.setOutlineColor(Color::Black);
	T_time_left.setOutlineThickness(2.0f);

	uvRect_life.width = 163;
	uvRect_life.height = 12;
	uvRect_life.left = 5406;
	uvRect_life.top = 63;
	I_life1.setTextureRect(uvRect_life);
	I_life1.setTexture(texture);
	I_life2.setTextureRect(uvRect_life);
	I_life2.setTexture(texture);

	uvRect_name1.width = 161;
	uvRect_name1.height = 11;
	uvRect_name1.left = 5406;
	uvRect_name1.top = 99 + 15 * character1;
	I_name1.setTextureRect(uvRect_name1);
	I_name1.setTexture(texture);

	uvRect_name2.width = 161;
	uvRect_name2.height = 11;
	uvRect_name2.left = 5579;
	uvRect_name2.top = 99 + 15 * character1;
	I_name2.setTextureRect(uvRect_name2);
	I_name2.setTexture(texture);

	uvRect_winned.width = 11;
	uvRect_winned.height = 16;
	uvRect_winned.left = 5406;
	uvRect_winned.top = 79;
	I_winned1.setTextureRect(uvRect_winned);
	I_winned1.setTexture(texture);
	I_winned2.setTextureRect(uvRect_winned);
	I_winned2.setTexture(texture);

	uvRect_danger.width = 65;
	uvRect_danger.height = 16;
	uvRect_danger.left = 5433;
	uvRect_danger.top = 79;
	I_danger.setTextureRect(uvRect_danger);
	I_danger.setTexture(texture);

	uvRect_winner.width = 327;
	uvRect_winner.height = 15;
	uvRect_winner.left = 3715;
	//Definido cuando gane uno

	uvRect_round.width = 327;
	uvRect_round.height = 82;
	uvRect_round.left = 5063;
	uvRect_round.top = 16 + 84 * round;
	I_round.setTextureRect(uvRect_round);
	I_round.setTexture(texture);

}

void BattleManager::RestartCombat(int character1_, int character2_, int stage_) {

	character1 = character1_;
	character2 = character2_;
	stage = stage_;
	
	life1 = 100;
	life2 = 100;

	time_left = 90;
	round = 0;

	points1 = 0;
	points2 = 0;

	rounds_won1 = 0;
	rounds_won2 = 0;

	//Cambiar escenario segun el valor de stage
	Courtyard courtyardBackground;
	courtyardBackground.loadTextures();

	BackgroundManager = courtyardBackground;

}

int BattleManager::RestartRound(int winner) {

	if (winner) {
		rounds_won1++;
	}
	else {
		rounds_won2++;
	}

	if (rounds_won1 == 2) {
		return 1;
	}
	else if (rounds_won2 == 2) {
		return 2;
	}
	else {

		life1 = 100;
		life2 = 100;
		time_left = 90;
		round++;

		return 0;

	}

}

void BattleManager::Update(Event event) {

	BackgroundManager.Update();

}

void BattleManager::draw(RenderWindow& window) {

	BackgroundManager.draw(window);

}