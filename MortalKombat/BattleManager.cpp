
#include "BattleManager.h"

using namespace std;

BattleManager::BattleManager(Texture* texture, Font font_) {

	font = font_;

	time_left = 99;

	clock_timer = 0;
	clock_flash = 0;
	clock_fight = 0;

	Vector2f size_life = Vector2f(417,35);
	Vector2f size_name = Vector2f(413,31);
	Vector2f size_coin = Vector2f(26,31);
	Vector2f size_round = Vector2f(327,82);
	Vector2f size_danger = Vector2f(121, 39);
	Vector2f size_clock = Vector2f(38, 54);
	Vector2f size_fight = Vector2f(386, 114);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);

	//Barras de vida 0 y 1
	uvRect.width = 163.0f;
	uvRect.height = 12.0f;
	uvRect.left = 5406;
	uvRect.top = 63;
	rect.setSize(size_life);

	rect.setTextureRect(uvRect);
	rect.setPosition(56.0f, 90.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(529.0f, 90.0f);
	HUD_vector.push_back(rect);

	//Nombres 2 y 3 
	uvRect.width = 161.0f;
	uvRect.height = 11.0f;
	uvRect.left = 5406;
	uvRect.top = 99 + 15 * character1;
	rect.setSize(size_name);

	rect.setTextureRect(uvRect);
	rect.setPosition(58.0f, 92.0f);
	HUD_vector.push_back(rect);

	uvRect.left = 5579;
	uvRect.top = 99 + 15 * character2;
	rect.setTextureRect(uvRect);
	rect.setPosition(531.0f, 92.0f);
	HUD_vector.push_back(rect);

	//Rondas ganadas 4, 5, 6 y 7
	uvRect.width = 10.0f;
	uvRect.height = 10.0f;
	uvRect.left = 5407;
	uvRect.top = 82;
	rect.setSize(size_coin);

	rect.setTextureRect(uvRect);
	rect.setPosition(56.0f, 137.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(82.0f, 137.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(925.0f, 137.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(899.0f, 137.0f);
	HUD_vector.push_back(rect);

	//Letrero ronda 8
	uvRect.width = 77.0f;
	uvRect.height = 20.0f;
	uvRect.left = 5185;
	uvRect.top = 54 + 84 * round;
	rect.setSize(size_round);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window/2 - rect.getSize().x / 2, 254.0f);
	HUD_vector.push_back(rect);

	//Letreros peligro 9 y 10
	uvRect.width = 46.0f;
	uvRect.height = 13.0f;
	uvRect.left = 5435;
	uvRect.top = 82;
	rect.setSize(size_danger);

	rect.setTextureRect(uvRect);
	rect.setPosition(309.0f, 137.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(572.0f, 137.0f);
	HUD_vector.push_back(rect);

	//Contador 11 y 12
	uvRect.width = 14.0f;
	uvRect.height = 17.0f;
	uvRect.left = 5573 + 16 * ((time_left / 10) % 10);
	uvRect.top = 49;
	rect.setSize(size_clock);

	rect.setTextureRect(uvRect);
	rect.setPosition(464.0f, 27.0f);
	HUD_vector.push_back(rect);

	uvRect.left = 5573 + 16 * (time_left % 10);
	rect.setTextureRect(uvRect);
	rect.setPosition(500.0f, 27.0f);
	HUD_vector.push_back(rect);

	//Letrero FIGHT 13
	uvRect.width = 327.0f;
	uvRect.height = 68.0f;
	uvRect.left = 2646;
	uvRect.top = 16;
	rect.setSize(size_fight);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 254.0f);
	HUD_vector.push_back(rect);

	//Puntos del jugador 1 1, 2 y 3
	Text text;
	text.setFont(font);
	text.setString("0000");
	text.setCharacterSize(CHAR_SIZE_BATTLE);
	text.setOutlineColor(Color::Black);
	text.setOutlineThickness(2.0f);
	text.setFillColor(Color::Yellow);
	text.setPosition(40.0f, 5.0f);
	Texts.push_back(text);

	text.setPosition(200.0f, 5.0f);
	Texts.push_back(text);

	text.setFillColor(Color::Red);
	text.setPosition(150.0f, 5.0f);
	Texts.push_back(text);

}

void BattleManager::RestartCombat(character character1_, character character2_, background stage_) {

	character1 = character1_;
	character2 = character2_;
	stage = stage_;
	
	life1 = 100;
	life2 = 100;

	time_left = 99;
	round = 0;

	points1 = 0;
	points2 = 0;

	rounds_won1 = 0;
	rounds_won2 = 0;

	showing_fight = false;
	started_game = false;
	showing_round = true;
	inDanger1 = false;
	inDanger2 = false;

	fight_x = 0;

	//Cambiar escenario segun el valor de stage
	switch (stage)
	{
	case COURTYARD:
		Courtyard background;
		background.loadTextures();
		BackgroundManager = background;
		break;

	}

	/*	case GOROS_LAIR:
		break;
	case PALACE_GATES:
		break;
	case THE_PIT:
		break;
	case THRONE_ROOM:
		break;
	case WARRIOR_SHRINE:
		break;
	default:
		break;*/
}

int BattleManager::RestartRound(int winner1) {

	if (winner1) {
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

		flash = false;
		showing_fight = false;
		started_game = false;
		showing_round = true;
		inDanger1 = false;
		inDanger2 = false;
		
		fight_x = 0;
		life1 = 100;
		life2 = 100;
		time_left = 99;
		round++;

		return 0;

	}

}

void BattleManager::Update(Event event) {

	//Procesar tecla

}

void BattleManager::Update() {


	BackgroundManager.Update();

	IntRect uvRect;

	clock_timer++;
	clock_flash++;

	if (showing_round && clock_timer == 60) { //Solo se ejecuta una vez

		showing_round = false;
		showing_fight = true;
	
	}

	if (started_game && clock_timer >= 60) {

		clock_timer = 0;
		if (time_left > 0) time_left--;

		uvRect.width = 14.0f;
		uvRect.height = 17.0f;
		uvRect.left = 5573 + 16 * ((time_left / 10) % 10);
		uvRect.top = 49;
		

		HUD_vector[11].setTextureRect(uvRect);
		uvRect.left = 5573 + 16 * (time_left % 10);
		HUD_vector[12].setTextureRect(uvRect);
	
	}

	if (clock_flash == 10) {
		clock_flash = 0;
		flash = !flash;

		uvRect.width = 46.0f;
		uvRect.height = 13.0f;
		uvRect.top = 82;

		if (flash) {
			uvRect.left = 5502;
		}
		else {
			uvRect.left = 5435;
		}

		HUD_vector[9].setTextureRect(uvRect);
		HUD_vector[10].setTextureRect(uvRect);

	}

	if (showing_fight) {
		clock_fight++;

		if (clock_fight == 7) {

			clock_fight = 0;
			fight_x++;

			if (fight_x == 18) {
				showing_fight = false;
				started_game = true;
			}
			else {
				uvRect.width = 327.0f;
				uvRect.height = 68.0f;
				uvRect.left = 2646;
				uvRect.top = 16 + 72 * fight_x;
				HUD_vector[13].setTextureRect(uvRect);

			}

		}
	}

}

void BattleManager::draw(RenderWindow& window) {

	BackgroundManager.draw(window);

	int i = 0;
	for (RectangleShape rect : HUD_vector) {

		switch (i) {
		case 4:
			if (rounds_won1 > 0) window.draw(rect);
			break;
		case 5:
			if (rounds_won1 > 1) window.draw(rect);
			break;
		case 6:
			if (rounds_won2 > 0) window.draw(rect);
			break;
		case 7:
			if (rounds_won2 > 1) window.draw(rect);
			break;
		case 8:
			if (showing_round) window.draw(rect);
			break;
		case 9:
			if (inDanger1) window.draw(rect);
			break;
		case 10:
			if (inDanger2) window.draw(rect);
			break;
		case 13:
			if (showing_fight) window.draw(rect);
			break;
		default:
			window.draw(rect);
		}
		i++;

	}
	/*
	for (Text text : Texts) {
		window.draw(text);
	}
	*/

}