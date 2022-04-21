#include "BattleManager.h"

using namespace std;

float loadingTime;

BattleManager::BattleManager(Texture* texture_, Font font_, Clock clock) {

	this->clock = clock;

	texture = texture_;
	font = font_;

	time_left = 99;

	clock_timer = 0;
	clock_flash = 0;
	clock_fight = 0;

	LoadTextures();
	LoadCharacters();

	loadingTime = clock.getElapsedTime().asSeconds();

	cout << "INFO: Game loaded in " << loadingTime << "s!" << endl;

}

void BattleManager::LoadTextures() {

	cout << "[*] Loading game textures..." << endl;

	HUD_vector.clear();
	Texts.clear();

	Vector2f size_life = Vector2f(417.0f, 35.0f);
	Vector2f size_name = Vector2f(413.0f, 31.0f);
	Vector2f size_coin = Vector2f(26.0f, 31.0f);
	Vector2f size_round = Vector2f(327.0f, 82.0f);
	Vector2f size_danger = Vector2f(121.0f, 39.0f);
	Vector2f size_clock = Vector2f(38.0f, 54.0f);
	Vector2f size_fight = Vector2f(386.0f, 114.0f);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);

	//Marcos barras de vida 0 y 1
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

	//Barras de vida 2 y 3
	uvRect.width = 161.0f;
	uvRect.height = 10.0f;
	uvRect.left = 5407;
	uvRect.top = 50;
	rect.setSize(size_name);

	rect.setTextureRect(uvRect);
	rect.setPosition(58.0f, 92.0f);
	HUD_vector.push_back(rect);

	rect.setTextureRect(uvRect);
	rect.setPosition(531.0f, 92.0f);
	HUD_vector.push_back(rect);

	//Nombres 4 y 5 
	uvRect.width = 161.0f;
	uvRect.height = 11.0f;
	uvRect.left = 5406;
	uvRect.top = 99 + 15 * (int)character1;
	rect.setSize(size_name);

	rect.setTextureRect(uvRect);
	rect.setPosition(58.0f, 92.0f);
	HUD_vector.push_back(rect);

	uvRect.left = 5579;
	uvRect.top = 99 + 15 * character2;
	rect.setTextureRect(uvRect);
	rect.setPosition(531.0f, 92.0f);
	HUD_vector.push_back(rect);

	//Rondas ganadas 6, 7, 8 y 9
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

	//Letrero ronda 10
	uvRect.width = 77.0f;
	uvRect.height = 20.0f;
	uvRect.left = 5185;
	uvRect.top = 54 + 84 * round;
	rect.setSize(size_round);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 254.0f);
	HUD_vector.push_back(rect);

	//Letreros peligro 11 y 12
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

	//Contador 13 y 14
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

	//Letrero FIGHT 15
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

void BattleManager::LoadCharacters(){
	cout << "[*] Loading character textures..." << endl;
	LiuKang = CreateLiuKang();
	cout << "[+......] Character LiuKang loaded!" << endl;
	Scorpion = CreateScorpion();
	cout << "[++.....] Character Scorpion loaded!" << endl;
	SonyaBlade = CreateSonyaBlade();
	cout << "[+++....] Character Sonya Blade loaded!" << endl;
	cout << "[+++++++] All characters loaded succesfully!" << endl;
}

void BattleManager::Restart() {

	clock_timer = 0;
	clock_flash = 0;
	clock_fight = 0;
	clock_inDanger1 = 0;
	clock_inDanger2 = 0;

	LoadTextures();

}

void BattleManager::RestartCombat(CharacterType character1_, CharacterType character2_, background stage_, bool twoPlayers_) {
	twoPlayers = twoPlayers_;
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
	{
		Courtyard background;
		background.loadTextures();
		BackgroundManager = background;
		break;
	}
	case WARRIOR_SHRINE:
	{
		Warrior_Shrine background;
		background.loadTextures();
		BackgroundManager = background;
		break;
	}
	case THE_PIT:
	{
		The_Pit background;
		background.loadTextures();
		BackgroundManager = background;
		break;
	}
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
	default:
		break;*/

	switch (character1){
	case CAGE:
		player1 = Scorpion;
		break;
	case KANO:
		player1 = Scorpion;
		break;
	case RAIDEN:
		player1 = Scorpion;
		break;
	case LIU_KANG:
		player1 = LiuKang;
		break;
	case SCORPION:
		player1 = Scorpion;
		break;
	case SUB_ZERO:
		player1 = Scorpion;
		break;
	case SONYA:
		player1 = SonyaBlade;
		break;
	default:
		player1 = Scorpion;
		break;
	}
	player1.initPosition(BackgroundManager.initPlayer1);

	if (character2 == 0) character2 = (CharacterType)(rand() % 7);
	switch (character2) {
	case CAGE:
		player2 = Scorpion;
		break;
	case KANO:
		player2 = Scorpion;
		break;
	case RAIDEN:
		player2 = Scorpion;
		break;
	case LIU_KANG:
		player2 = LiuKang;
		break;
	case SCORPION:
		player2 = Scorpion;
		break;
	case SUB_ZERO:
		player2 = Scorpion;
		break;
	case SONYA:
		player2 = SonyaBlade;
		break;
	default:
		player2 = Scorpion;
		break;
	}
	player2.initPosition(BackgroundManager.initPlayer2);

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
		showed_danger1 = false;
		showed_danger2 = false;

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

	float vida = player1.GetLife();
	Vector2f size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[2].getSize().y);
	HUD_vector[2].setSize(size_life);

	if (!showed_danger1 && (vida / 100.0f) <= 0.2f) inDanger1 = true;

	vida = player2.GetLife();
	size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[3].getSize().y);
	HUD_vector[3].setSize(size_life);

	if (!showed_danger2 && (vida / 100.0f) <= 0.2f) inDanger2 = true;

	player1.Update(0.05f);
	if (twoPlayers) { 
		player2.Update(0.05f); 
	} else { 
		player2.UpdateIA(0.05f); 
	}

	BackgroundManager.Update();

	IntRect uvRect;

	clock_timer++;
	clock_flash++;

	if (showing_round && clock_timer == 60) { //Solo se ejecuta una vez

		showing_round = false;
		showing_fight = true;
		music.fight();

	}

	if (started_game && clock_timer >= 60) {

		clock_timer = 0;
		if (time_left > 0) time_left--;

		uvRect.width = 14.0f;
		uvRect.height = 17.0f;
		uvRect.left = 5573 + 16 * ((time_left / 10) % 10);
		uvRect.top = 49;


		HUD_vector[13].setTextureRect(uvRect);
		uvRect.left = 5573 + 16 * (time_left % 10);
		HUD_vector[14].setTextureRect(uvRect);

	}

	if (inDanger1) {
		clock_inDanger1++;
		if (clock_inDanger1 == 100) {
			showed_danger1 = true;
			inDanger1 = false;
		}
	}

	if (inDanger2) {
		clock_inDanger2++;
		if (clock_inDanger2 == 100) {
			showed_danger2 = true;
			inDanger2 = false;
		}
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

		HUD_vector[11].setTextureRect(uvRect);
		HUD_vector[12].setTextureRect(uvRect);

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
				HUD_vector[15].setTextureRect(uvRect);

			}

		}
	}

}

void BattleManager::draw(RenderWindow& window) {

	BackgroundManager.draw(window);
	player1.debugDraw(window);
	player2.debugDraw(window);

	int i = 0;
	for (RectangleShape rect : HUD_vector) {

		switch (i) {
		case 6:
			if (rounds_won1 > 0) window.draw(rect);
			break;
		case 7:
			if (rounds_won1 > 1) window.draw(rect);
			break;
		case 8:
			if (rounds_won2 > 0) window.draw(rect);
			break;
		case 9:
			if (rounds_won2 > 1) window.draw(rect);
			break;
		case 10:
			if (showing_round) window.draw(rect);
			break;
		case 11:
			if (inDanger1) window.draw(rect);
			break;
		case 12:
			if (inDanger2) window.draw(rect);
			break;
		case 15:
			if (showing_fight) { window.draw(rect); }
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