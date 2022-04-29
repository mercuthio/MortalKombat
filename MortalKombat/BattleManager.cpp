#include "BattleManager.h"
#include "GlobalVars.h"

using namespace std;

float loadingTime;

Vector2f p1Position;
Vector2f p2Position;

Vector2f p1PositionOffset;
Vector2f p2PositionOffset;

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

	Vector2f size_life = Vector2f(417.0f, 35.0f);
	Vector2f size_name = Vector2f(413.0f, 31.0f);
	Vector2f size_coin = Vector2f(26.0f, 31.0f);
	Vector2f size_round = Vector2f(327.0f, 82.0f);
	Vector2f size_danger = Vector2f(121.0f, 39.0f);
	Vector2f size_clock = Vector2f(38.0f, 54.0f);
	Vector2f size_fight = Vector2f(386.0f*2, 114.0f*2);

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
	rect.setOrigin(rect.getSize().x, rect.getSize().y);
	rect.rotate(180);
	rect.setPosition(531.0f, 92.0f);
	HUD_vector.push_back(rect);
	rect.rotate(180);
	rect.setOrigin(0, 0);

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
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 254.0f/2);
	HUD_vector.push_back(rect);

}

void BattleManager::LoadCharacters(){
	cout << "[*] Loading character textures..." << endl;
	LiuKang = CreateLiuKang();
	cout << "[+......] Character LiuKang loaded!" << endl;
	Scorpion = CreateScorpion();
	cout << "[++.....] Character Scorpion loaded!" << endl;
	//SonyaBlade = CreateSonyaBlade();
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
	winned_game = 0;

	points1 = 0;
	points2 = 0;

	rounds_won1 = 0;
	rounds_won2 = 0;

	finished_game = false;
	showing_fight = false;
	started_game = false;
	showing_round = true;
	inDanger1 = false;
	inDanger2 = false;

	fight_x = 0;

	totalMoveXBack = 0;

	//Cambiar escenario segun el valor de stage
	switch (stage)
	{
	case COURTYARD:
	{
		Courtyard background;
		background.loadTextures();
		BackgroundManager = background;

		music.courtyardTheme();

		break;
	}
	case WARRIOR_SHRINE:
	{
		Warrior_Shrine background;
		background.loadTextures();
		BackgroundManager = background;

		music.warriorshrineTheme();

		break;
	}
	case THE_PIT:
	{
		The_Pit background;
		background.loadTextures();
		BackgroundManager = background;

		music.thepitTheme();

		break;
	}
	case THRONE_ROOM:
	{
		Throne_Room background;
		background.loadTextures();
		BackgroundManager = background;

		music.throneroomTheme();

		break;
	}
	break;
	}

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
	player1.setFreeze(true);
	player1.initPosition(BackgroundManager.initPlayer1);
	player1.setPlayer(1);
	player1.RestartMirror(false);

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
	player2.setFreeze(true);
	player2.initPosition(BackgroundManager.initPlayer2);
	player2.setPlayer(2);
	player2.RestartMirror(true);
	player2.Mirror();

}

void BattleManager::RestartRound() {

	moveXBack = totalMoveXBack; //Movemos escenario a posicion inicial
	totalMoveXBack = 0;

	player1.setFreeze(true);
	player1.initPosition(BackgroundManager.initPlayer1);
	player1.setPlayer(1);
	player1.RestartMirror(false);

	player2.setFreeze(true);
	player2.initPosition(BackgroundManager.initPlayer2);
	player2.setPlayer(2);
	player2.RestartMirror(true);

	flash = false;
	showing_fight = false;
	started_game = false;
	showing_round = true;
	inDanger1 = false;
	inDanger2 = false;
	showed_danger1 = false;
	showed_danger2 = false;
	finishing1 = false;
	finishing2 = false;
	P1WinnedPose = false;
	P2WinnedPose = false;

	fight_x = 0;
	life1 = 100;
	life2 = 100;
	time_left = 99;
	round++;

	player1.life = life1;
	player2.life = life2;

}

void BattleManager::Update(Event event) {}

void BattleManager::Update() {

	finished_round();	//Comprobamos final de ronda

	if (player1.lookingAt() == LookingAt::RIGHT && player1.GetXPosition() > player2.GetXPosition() + 5) { //PLAYER 1 LEFT -> RIGHT
		player1.Mirror();
		player1.SetXPosition(15.f);
		player2.Mirror();
	}
	else if (player1.lookingAt() == LookingAt::LEFT && player1.GetXPosition() + 5 < player2.GetXPosition()) { //PLAYER 1 RIGHT -> LEFT
		player1.Mirror();
		player1.SetXPosition(-15.f);
		player2.Mirror();
	}

	float vida = player1.GetLife();
	Vector2f size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[2].getSize().y);
	HUD_vector[2].setSize(size_life);

	if (!showed_danger1 && (vida / 100.0f) <= 0.2f) inDanger1 = true;

	vida = player2.GetLife();
	size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[3].getSize().y);
	HUD_vector[3].setSize(size_life);

	if (!showed_danger2 && (vida / 100.0f) <= 0.2f) inDanger2 = true;

	player1.Update(0.05f, false);
	if (twoPlayers) { 
		player2.Update(0.05f, true); 
	} else {
		player2.UpdateIA(0.05f, player1); 
	}

	BackgroundManager.Update();

	IntRect uvRect;

	clock_timer++;
	clock_flash++;

	if (showing_round && clock_timer == 60) {
		showing_round = false;
		showing_fight = true;
	}

	if (showing_fight && clock_timer == 60) { music.fight(); }

	if (showing_fight && clock_timer == 120) { //Solo se ejecuta una vez

		showing_fight = false;
		started_game = true;
		player1.setFreeze(false);
		player2.setFreeze(false);

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

	CheckCollisions();

	blood.Update();
	bloodGround1.Update();
	bloodGround2.Update();

	if (winned_game != 0) {
		if (winned_game == 1) {
			player2.animation_in_process = AnimationType::DYING;
			//Mostrar letras finish him

			finishing2 = true;
			//Cuando golpee el contrario mostrar you win
			if (P1WinnedPose) player1.animation_in_process = AnimationType::WIN;

			//Si terminado lo anterior finished_game = 1
			finished_game = true;
		}
		else {
			player2.animation_in_process = AnimationType::DYING;
			//Mostrar letras finish him

			finishing1 = true;
			//Cuando golpee el contrario mostrar you win
			//Pose de victoria
			if (P2WinnedPose) player2.animation_in_process = AnimationType::WIN;

			//Si terminado lo anterior finished_game = 1
			finished_game = true;
		}
	}

	Vector2f size_round = Vector2f(327.0f, 82.0f);
	uvRect = HUD_vector[10].getTextureRect();
	uvRect.top = 54 + 84 * round;
	HUD_vector[10].setTextureRect(uvRect);

}

void BattleManager::CheckCollisions() {

	if (player1.damage_hitbox.getGlobalBounds().intersects(player2.hitbox.getGlobalBounds())) {

		if (isDamageMovement(player1.animation_in_process)) {	//Le pega el jugador 1
			if (finishing1) { P1WinnedPose = true; }			//El jugador 1 golpea en finish him
			
			ProcessHit(player1.animation_in_process, true);

		}

	} 

	if (player2.damage_hitbox.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds())) {

		if (isDamageMovement(player2.animation_in_process)) {	//Le pega el jugador 2
			if (finishing1) { P2WinnedPose = true; }			//El jugador 2 golpea en finish him

			ProcessHit(player2.animation_in_process, false);

		}

	}

}

void BattleManager::ProcessHit(AnimationType anim, bool toPlayerTwo) {

	//if ((toPlayerTwo && !isFixedMovement(player2.animation_in_process))) {
	//	return;
	//}
	//else if (!toPlayerTwo && !isFixedMovement(player1.animation_in_process)) {
	//	return;
	//}

	if ((toPlayerTwo && player2.isBlocking())) {
		life2 -= life_BLOCK;
		player2.setSpeed(Vector2f(200, 0));
		music.hitBlock();
		player2.life = life2;
		return;
	} 
	else if (!toPlayerTwo && player1.isBlocking()) {
		life1 -= life_BLOCK;
		player1.setSpeed(Vector2f(200, 0));
		music.hitBlock();
		player1.life = life1;
		return;
	}

	bool crouching = false;
	if ((toPlayerTwo && player2.isCrouching()) || !toPlayerTwo && player1.isCrouching()) {
		crouching = true;
	}

	if (anim == AnimationType::PUNCH || anim == AnimationType::PUNCH_CLOSE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND;
			}
			music.hit2();
			player2.setSpeed(Vector2f(250, 0));
		}
		else {
			life1 -= life_PUNCH;
			player1.animation_in_process = AnimationType::HIT_STAND;
			music.hit2();
			player1.setSpeed(Vector2f(250, 0));
		}

	}
	else if (anim == AnimationType::PUNCH_UPPER || anim == AnimationType::PUNCH_UPPER_CLOSE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_UPPER;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_HEAD;
			}
			music.hit9();

			int random = rand() % 10;

			player2.setSpeed(Vector2f(300, 0));

			if (player2.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 550, player2.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player2.getPosition().x + 15 * 3, player2.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x, player2.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x - 40, player2.getPosition().y + 442)); }
			}
		}
		else {
			life1 -= life_PUNCH_UPPER;
			player1.animation_in_process = AnimationType::HIT_HEAD;
			music.hit9();

			int random = rand() % 10;

			player1.setSpeed(Vector2f(300, 0));

			if (player1.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 550, player1.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player1.getPosition().x + 15 * 3, player1.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x, player1.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x - 40, player1.getPosition().y + 442)); }
			}
		}
	}
	else if (anim == AnimationType::PUNCH_FROM_DOWN) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_UPPER;
			player2.animation_in_process = AnimationType::FALL;
			music.hit1();

			int random = rand() % 10;

			player2.setOnAir(true);
			player2.setSpeed(Vector2f(500, 500));

			if (player2.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 550, player2.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player2.getPosition().x + 15 * 3, player2.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x, player2.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x - 40, player2.getPosition().y + 442)); }
			}
		}
		else {
			life1 -= life_PUNCH_UPPER;
			player1.animation_in_process = AnimationType::FALL;
			music.hit1();
			
			int random = rand() % 10;

			player1.setOnAir(true);
			player1.setSpeed(Vector2f(500, 500));

			if (player1.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 550, player1.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player1.getPosition().x + 15 * 3, player1.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x, player1.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x - 40, player1.getPosition().y + 442)); }
			}
		}
		music.excellent();
	}
	else if (anim == AnimationType::PUNCH_MULTIPLE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND_STRONG;
			}
			music.hit5();
			player2.setSpeed(Vector2f(400, 0));
		}
		else {
			life1 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND_STRONG;
			}
			music.hit5();
			player1.setSpeed(Vector2f(400, 0));
		}
	}
	else if (anim == AnimationType::PUNCH_MULTIPLE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND_STRONG;
			}
			music.hit3();
			player2.setSpeed(Vector2f(400, 0));
		}
		else {
			life1 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND_STRONG;
			}
			music.hit3();
			player1.setSpeed(Vector2f(400, 0));
		}
	}
	else if (anim == AnimationType::PUNCH_UPPER_MULTIPLE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_HEAD;
			}
			music.hit9();

			int random = rand() % 10;

			player2.setSpeed(Vector2f(400, 0));

			if (player2.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 550, player2.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player2.getPosition().x + 15 * 3, player2.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x, player2.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x - 40, player2.getPosition().y + 442)); }
			}
		}
		else {
			life1 -= life_PUNCH_MULTIPLE;
			player1.animation_in_process = AnimationType::HIT_HEAD;
			music.hit9();

			int random = rand() % 10;

			player1.setSpeed(Vector2f(400, 0));

			if (player1.lookingAt() == LookingAt::LEFT) {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::RIGHT, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 550, player1.getPosition().y + 440)); }
			}
			else {
				if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::LEFT, Vector2f(player1.getPosition().x + 15 * 3, player1.getPosition().y + 25 * 3)); }
				if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x, player1.getPosition().y + 413)); }
				if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x - 40, player1.getPosition().y + 442)); }
			}
		}
	}
	else if (anim == AnimationType::KICK || anim == AnimationType::KICK_UPPER || anim == AnimationType::KICK_HIGH || anim == AnimationType::KICK_FROM_AIR) {
		if (toPlayerTwo) {
			life2 -= life_KICK;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND;
			}
			music.hit3();
			player2.setSpeed(Vector2f(250, 0));
		}
		else {
			life1 -= life_KICK;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND;
			}
			music.hit3();
			player1.setSpeed(Vector2f(250, 0));
		}
	}
	else if (anim == AnimationType::KICK_LOW) {
		if (toPlayerTwo) {
			life2 -= life_KICK_LOW;
			player2.setOnAir(true);
			player2.animation_in_process = AnimationType::FALL;
			music.hit5();

			int random = rand() % 10;

			player2.setSpeed(Vector2f(400, 400));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 600, player2.getPosition().y + 440)); }
		}
		else {
			life1 -= life_KICK_LOW;
			player1.setOnAir(true);
			player1.animation_in_process = AnimationType::FALL;
			music.hit5();
			
			int random = rand() % 10;

			player1.setSpeed(Vector2f(400, 400));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 580, player1.getPosition().y + 440)); }
		}
	}
	else if (anim == AnimationType::KICK_FROM_DOWN) {
		if (toPlayerTwo) {
			life2 -= life_KICK_FROM_DOWN;
			player2.setOnAir(true);
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::NUTS;
			}
			music.hit2();
			player2.setSpeed(Vector2f(250, 0));
		}
		else {
			life1 -= life_KICK_FROM_DOWN;
			player1.setOnAir(true);
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
			}
			else {
				player2.animation_in_process = AnimationType::NUTS;
			}
			music.hit2();
			player1.setSpeed(Vector2f(250, 0));
		}
	}
	else if (anim == AnimationType::CATCH) {
		if (toPlayerTwo) {
			life2 -= life_CATCH;
			player2.animation_in_process = AnimationType::GET_CAUGHT;
			//Mover a player2
		}
		else {
			life1 -= life_CATCH;
			player1.animation_in_process = AnimationType::GET_CAUGHT;
			//Mover a player1
		}
	}

	player1.life = life1;
	player2.life = life2;

}

int BattleManager::isfinished() {
	if (finished_game) {
		if (life1 >= life2) return 1;
		return 2;
	}
	return 0;
}

void BattleManager::finished_round() {

	if (time_left <= 0) {
		if (life1 <= life2) increase_round(2);	//Gana el jugador 2
		else increase_round(1);					//Gana el jugador 1
		RestartRound();
	}
	if (life1 <= 0) {
		increase_round(1); 	
		RestartRound();
	}		
	if (life2 <= 0) {
		increase_round(2);  
		RestartRound();
	}	

}

void BattleManager::increase_round(int player) {

	if (player) {
		rounds_won1++;
		if (rounds_won1 >= 2) winned_game = 1;
	}
	else {
		rounds_won2++;
		if (rounds_won2 >= 2) winned_game = 2;
	}

}

void BattleManager::draw(RenderWindow& window) {

	BackgroundManager.draw(window);

	bloodGround1.draw(window);
	bloodGround2.draw(window);

	if (player2.isAttaking()) {
		player1.debugDraw(window);
		player2.debugDraw(window);
	}
	else {
		player2.debugDraw(window);
		player1.debugDraw(window);
	}

	blood.draw(window);

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

}