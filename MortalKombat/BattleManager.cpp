#include "BattleManager.h"
#include "GlobalVars.h"

using namespace std;

float loadingTime;

Vector2f p1Position;
Vector2f p2Position;

Vector2f p1PositionOffset;
Vector2f p2PositionOffset;

BattleManager::BattleManager(Texture* texture_, Texture* icon_, Font font_, Clock clock) {

	this->clock = clock;

	texture = texture_;
	icon = icon_;
	font = font_;

	time_left = 99;

	clock_timer = 0;
	clock_flash = 0;
	clock_fight = 0;
	clock_finishHim = 0;
	clock_finishRound = 0;

	clapping = false;
	shaking = false;
	paused = false;
	internalShaking = 0.f;

	LoadTextures();
	LoadCharacters();

	loadingTime = clock.getElapsedTime().asSeconds();

	cout << "INFO: Game loaded in " << loadingTime << "s!" << endl;

}

void BattleManager::shake() {
	if (!shaking) {
		shaking = true;
		shakeUp = true;
		internalShaking = 0.f;
	}
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
	Vector2f size_fight = Vector2f(735.0f, 180.0f);
	Vector2f size_winner = Vector2f(735.0f, 161.0f);
	Vector2f size_icon = Vector2f(200.0f, 200.0f);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);

	pauseIcon.setTexture(icon);
	pauseIcon.setScale(1.0f, 1.0f);
	pauseIcon.setSize(size_icon);
	pauseIcon.setPosition( width_window / 2 - pauseIcon.getSize().x / 2, height_window / 2 - pauseIcon.getSize().y / 2);

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
	uvRect.left = 2647;
	uvRect.top = 16;
	rect.setSize(size_fight);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 154.0f);
	HUD_vector.push_back(rect);

	//Letrero FINISH HIM 16
	uvRect.width = 327.0f;
	uvRect.height = 68.0f;
	uvRect.left = 2983;
	uvRect.top = 16;
	rect.setSize(size_fight);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 154.0f);
	HUD_vector.push_back(rect);

	//Nombre ganador 17
	uvRect.width = 327;
	uvRect.height = 50.0f;
	uvRect.left = 3715;
	uvRect.top = 16;
	rect.setSize(size_winner);

	rect.setTextureRect(uvRect);
	rect.setPosition(width_window / 2 - rect.getSize().x / 2, 154.0f);
	HUD_vector.push_back(rect);

}

void BattleManager::LoadCharacters() {
	cout << "[*] Loading character textures..." << endl;
	LiuKang = CreateLiuKang();
	cout << "[+......] Character LiuKang loaded!" << endl;
	Scorpion = CreateScorpion();
	cout << "[++.....] Character Scorpion loaded!" << endl;
	SonyaBlade = CreateSonyaBlade();
	cout << "[+++....] Character Sonya Blade loaded!" << endl;
	JhonnyCage = CreateJhonnyCage();
	cout << "[++++...] Character Jhonny Cage loaded!" << endl;
	cout << "[+++++++] All characters loaded succesfully!" << endl;
}

void BattleManager::Restart() {

	clock_timer = 0;
	clock_flash = 0;
	clock_fight = 0;
	clock_finishHim = 0;
	clock_inDanger1 = 0;
	clock_inDanger2 = 0;
	clock_finishRound = 0;
	shaking = false;
	paused = false;

	LoadTextures();

}

void BattleManager::RestartCombat(CharacterType character1_, CharacterType character2_, background stage_, bool twoPlayers_) {
	twoPlayers = twoPlayers_;
	character1 = character1_;
	character2 = character2_;
	stage = stage_;
	
	life1 = 100;
	life2 = 100;

	if (noHitMode && twoPlayers) {
		life1 = 1;
		life2 = 1;
	}
	else if (noHitMode && !twoPlayers) {
		life1 = 1;
	}

	time_left = 99;
	round = 0;

	points1 = 0;
	points2 = 0;

	rounds_won1 = 0;
	rounds_won2 = 0;

	finished_game = false;
	showing_fight = false;
	showing_win = false;
	showing_finishHim = false;
	started_game = false;
	showing_round = true;
	inDanger1 = false;
	inDanger2 = false;
	finishedFinishHim = false;
	finishing1 = false;
	finishing2 = false;
	waitingToEnd = false;
	paused = false;

	clapping = false;

	fight_x = 0;
	finish_him_x = 0;

	totalMoveXBack = 0;

	player1Special.resetSpecial();
	player2Special.resetSpecial();

	//Cambiar escenario segun el valor de stage
	switch (stage)
	{
	case COURTYARD:
	{
		Courtyard background = Courtyard();
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
	case GOROS_LAIR:
	{
		Goros_Lair background;
		background.loadTextures();
		BackgroundManager = background;

		music.goroslairTheme();

		break;
	}
	break;
	}

	switch (character1) {
	case CAGE:
		player1 = JhonnyCage;
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

	switch (character2) {
	case CAGE:
		player2 = JhonnyCage;
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
	player2.Mirror();

}

void BattleManager::Pause() {
	if (paused) paused = false;
	else paused = true;
}

void BattleManager::RestartRound() {

	moveXBack = totalMoveXBack; //Movemos escenario a posicion inicial
	totalMoveXBack = 0;

	player1.damage_hitbox.setSize(Vector2f(0, 0));

	player1.fullReset();
	player2.fullReset();

	player1.initPosition(BackgroundManager.initPlayer1);
	player1.setPlayer(1);

	player2.damage_hitbox.setSize(Vector2f(0, 0));

	player2.initPosition(BackgroundManager.initPlayer2);
	player2.setPlayer(2);
	player2.Mirror();

	flash = false;
	showing_fight = false;
	showing_win = false;
	showing_finishHim = false;
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
	finishedFinishHim = false;
	waitingToEnd = false;
	paused = false;

	shaking = false;

	fight_x = 0;
	finish_him_x = 0;
	life1 = 100;
	life2 = 100;

	if (noHitMode && twoPlayers) {
		life1 = 1;
		life2 = 1;
	}
	else if (noHitMode && !twoPlayers) {
		life1 = 1;
	}

	time_left = 99;
	round++;
	clock_timer = 0;

	player1.life = life1;
	player2.life = life2;

	switch (stage)
	{
	case COURTYARD:
		music.courtyardTheme();
		break;
	case WARRIOR_SHRINE:
		music.warriorshrineTheme();
		break;
	case THE_PIT:
		music.thepitTheme();
		break;
	case THRONE_ROOM:
		music.throneroomTheme();
		break;
	case GOROS_LAIR:
		music.goroslairTheme();
		break;
	}

}

void BattleManager::Update(Event event) {}

void BattleManager::Update() {

	if (!paused) {
		// Shake effect
		if (!shaking && player1.getShake()) {
			player1.setShake(false);
			shake();
		}
		if (!shaking && player2.getShake()) {
			player2.setShake(false);
			shake();
		}

		if (shaking) {
			if (internalShaking >= 0.20f) {
				view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
				shaking = false;
				shakeUp = false;
			}
			else {
				if (shakeUp) {
					view.setCenter(view.getSize().x / 2, view.getSize().y / 2 + 5);
				}
				else {
					view.setCenter(view.getSize().x / 2, view.getSize().y / 2 - 5);
				}
				shakeUp = !shakeUp;
				internalShaking += 0.025;
			}
		}

		// Mirror
		if (player1.lookingAt() == LookingAt::RIGHT && player1.GetXPosition() > player2.GetXPosition() + 5) { //PLAYER 1 LEFT -> RIGHT
			player1.Mirror();
			player2.Mirror();
			player1.SetXPosition(10.f);
		}
		else if (player1.lookingAt() == LookingAt::LEFT && player1.GetXPosition() + 5 < player2.GetXPosition()) { //PLAYER 1 RIGHT -> LEFT
			player1.Mirror();
			player2.Mirror();
			player1.SetXPosition(-10.f);
		}

		// Life
		float vida = life1;
		if (life1 < 0) vida = 0;
		Vector2f size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[2].getSize().y);
		HUD_vector[2].setSize(size_life);

		if (!showed_danger1 && (vida / 100.0f) <= 0.2f) inDanger1 = true;

		vida = life2;
		if (life2 < 0) vida = 0;
		size_life = Vector2f(SIZE_LIFE * (vida / 100.0f), HUD_vector[3].getSize().y);
		HUD_vector[3].setSize(size_life);

		if (!showed_danger2 && (vida / 100.0f) <= 0.2f) inDanger2 = true;

		player1.Update(0.05f, false);
		if (twoPlayers) {
			player2.Update(0.05f, true);
		}
		else {
			player2.setDifficulty();
			player2.UpdateIA(0.05f, player1);
		}

		// Background
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


		if ((!finishing1 && !finishing2) && started_game && clock_timer >= 60) {

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
			//Danger
			HUD_vector[11].setTextureRect(uvRect);
			HUD_vector[12].setTextureRect(uvRect);

			if (finishing1 || finishing2) {

				//Letras victoria
				RectangleShape rect = HUD_vector[17];
				uvRect = rect.getTextureRect();
				if (flash) {
					uvRect.left = 4046.0f;
				}
				else {
					uvRect.left = 3715.0f;
				}

				rect.setTextureRect(uvRect);
				HUD_vector[17] = rect;
			}

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

		if (showing_finishHim) {
			clock_finishHim++;

			if (clock_finishHim == 7) {

				clock_finishHim = 0;
				finish_him_x++;
				if (finish_him_x == 18) {
					showing_finishHim = false;
				}
				else {

					RectangleShape rect = HUD_vector[16];
					uvRect = rect.getTextureRect();
					uvRect.top = 16 + 72 * finish_him_x;
					rect.setTextureRect(uvRect);
					HUD_vector[16] = rect;

				}
			}

		}

		if (player1.animation_in_process == AnimationType::SPECIAL) {
			if (player1Special.isFinished()) {
				if (player1.lookingAt() == LookingAt::RIGHT) {
					Vector2f pos = Vector2f(player1.getPosition().x + 375, player1.getPosition().y + 205);
					switch (character1)
					{
					case LIU_KANG:
						player1Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, false);
						break;
					case SCORPION:
						player1Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, false);
						break;
					case SONYA:
						player1Special.SpecialAttackAt(SpecialType::SONYA, pos, false);
						break;
					case CAGE:
						player1Special.SpecialAttackAt(SpecialType::CAGE, pos, false);
						break;
					}
				}
				else {
					Vector2f pos = Vector2f(player1.getPosition().x + 75, player1.getPosition().y + 205);
					switch (character1)
					{
					case LIU_KANG:
						player1Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, true);
						break;
					case SCORPION:
						player1Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, true);
						break;
					case SONYA:
						player1Special.SpecialAttackAt(SpecialType::SONYA, pos, true);
						break;
					case CAGE:
						player1Special.SpecialAttackAt(SpecialType::CAGE, pos, true);
						break;
					}
				}
			}
		}

		if (player2.animation_in_process == AnimationType::SPECIAL) {
			if (player2Special.isFinished()) {
				if (player2.lookingAt() == LookingAt::RIGHT) {
					Vector2f pos = Vector2f(player2.getPosition().x + 375, player2.getPosition().y + 205);
					switch (character2)
					{
					case LIU_KANG:
						player2Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, false);
						break;
					case SCORPION:
						player2Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, false);
						break;
					case SONYA:
						player2Special.SpecialAttackAt(SpecialType::SONYA, pos, false);
						break;
					case CAGE:
						player2Special.SpecialAttackAt(SpecialType::CAGE, pos, false);
						break;
					}
				}
				else {
					Vector2f pos = Vector2f(player2.getPosition().x + 75, player2.getPosition().y + 205);
					cout << pos.x << endl;
					switch (character2)
					{
					case LIU_KANG:
						player2Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, true);
						break;
					case SCORPION:
						player2Special.SpecialAttackAt(SpecialType::LIU_KANG, pos, true);
						break;
					case SONYA:
						player2Special.SpecialAttackAt(SpecialType::SONYA, pos, true);
						break;
					case CAGE:
						player2Special.SpecialAttackAt(SpecialType::CAGE, pos, true);
						break;
					}
				}
			}
		}

		player1Special.Update();
		player2Special.Update();

		CheckCollisions();

		blood.Update();
		bloodGround1.Update();
		bloodGround2.Update();

		if (finishing1 || finishing2) {

			shaking = false;

			if (showing_finishHim && finishing1) HUD_vector[3].setSize(Vector2f(0, 0));
			else if (showing_finishHim && finishing2) HUD_vector[2].setSize(Vector2f(0, 0));

			inDanger1 = false;
			inDanger2 = false;

			clock_finishRound++;

			bool inFinishHim = (rounds_won1 == 2 || rounds_won2 == 2);
			if ((finishedFinishHim || !inFinishHim) && clock_finishRound == 80) {
				music.clapsPublic();
				clapping = true;
			}

			if (!finishedFinishHim && !inFinishHim && clock_finishRound >= 480) {			//Terminado periodo de gracia
				showing_win = false;
				clock_finishRound = 0;
				finishing1 = false;
				finishing2 = false;
				clapping = false;
				RestartRound();
			}
			else if (!finishedFinishHim && (inFinishHim && clock_finishRound >= 400) || (P1WinnedPose || P2WinnedPose)) {	//En finish him se ha acabado el tiempo sin golpearle o le ha golpeado

				showing_win = true;
				waitingToEnd = true;
				if (!waitingToEnd) clock_finishRound = 0;
				finishedFinishHim = true;
				P1WinnedPose = false;
				P2WinnedPose = false;

				if (finishing1) {

					switch (character1) {
					case LIU_KANG:	//Liu Kang
						music.LiuKangWins();
						break;
					case SCORPION: //Scorpion
						music.ScorpionWins();
						break;
					case SONYA:	//Sonya Blade
						music.SonyaBladeWins();
						break;
					case CAGE:	//Jhonny Cage
						music.JhonnyCageWins();
						break;
					}

					characterFall03(character2);
					player1.animation_in_process = AnimationType::WIN;
					player2.animation_in_process = AnimationType::FALL_BACK;
					player2.setSpeed(Vector2f(500, 0));
				}
				else if (finishing2) {

					switch (character2) {
					case LIU_KANG:	//Liu Kang
						music.LiuKangWins();
						break;
					case SCORPION: //Scorpion
						music.ScorpionWins();
						break;
					case SONYA:	//Sonya Blade
						music.SonyaBladeWins();
						break;
					case CAGE:	//Jhonny Cage
						music.JhonnyCageWins();
						break;
					}

					characterFall03(character1);
					player2.animation_in_process = AnimationType::WIN;
					player1.animation_in_process = AnimationType::FALL_BACK;
					player1.setSpeed(Vector2f(500, 0));
				}

				player1.setFreeze(true);
				player2.setFreeze(true);

				music.clapsPublic();
				clapping = true;

			}

			if (waitingToEnd && clock_finishRound >= 480) {	//Acabar partida
				clock_finishRound = 0;
				waitingToEnd = false;
				finished_game = true;
			}

		}
		else {

			int winner_round = finished_round();							//Comprobamos final de ronda

			if (winner_round == 1) {										//Jugador 1 acaba de ganar una ronda

				music.stopMusic();

				if (rounds_won1 == 1) {										//Todavia no ha ganado la partida

					switch (character1) {
					case LIU_KANG:	//Liu Kang
						music.LiuKangWins();
						break;
					case SCORPION: //Scorpion
						music.ScorpionWins();
						break;
					case SONYA:	//Sonya Blade
						music.SonyaBladeWins();
						break;
					case CAGE:	//Jhonny Cage
						music.JhonnyCageWins();
						break;
					}

					finishing1 = true;
					showing_win = true;

					uvRect.width = 327;
					uvRect.height = 50.0f;
					uvRect.left = 3715;
					uvRect.top = 16 + (character1 * 52);

					RectangleShape rect = HUD_vector[17];
					rect.setTextureRect(uvRect);
					HUD_vector[17] = rect;

					characterFall02(character2);
					player1.animation_in_process = AnimationType::WIN;
					player2.animation_in_process = AnimationType::FALL;
					player2.setSpeed(Vector2f(500, 0));

					player1.setFreeze(true);
					player2.setFreeze(true);
				}
				else {														//Acaba de ganar la partida
					finishing1 = true;
					showing_finishHim = true;

					RectangleShape rect = HUD_vector[16];
					uvRect = rect.getTextureRect();
					if (character2 == CharacterType::SONYA) {
						uvRect.left = 3317.0f;
						music.finishHer();
					}
					else {
						music.finishHim();
					}
					rect.setTextureRect(uvRect);
					HUD_vector[16] = rect;

					player2.setDying(true);
					player2.setFreeze(true);
				}

			}
			else if (winner_round == 2) {

				if (rounds_won2 == 1) {										//Todavia no ha ganado la partida

					music.stopMusic();
					switch (character2) {
					case LIU_KANG:	//Liu Kang
						music.LiuKangWins();
						break;
					case SCORPION: //Scorpion
						music.ScorpionWins();
						break;
					case SONYA:	//Sonya Blade
						music.SonyaBladeWins();
						break;
					case CAGE:	//Jhonny Cage
						music.JhonnyCageWins();
						break;
					}

					finishing2 = true;
					showing_win = true;

					uvRect.width = 327;
					uvRect.height = 50.0f;
					uvRect.left = 3715;
					uvRect.top = 16 + (character2 * 52);

					RectangleShape rect = HUD_vector[17];
					rect.setTextureRect(uvRect);
					HUD_vector[17] = rect;

					characterFall02(character1);
					player2.animation_in_process = AnimationType::WIN;
					player1.animation_in_process = AnimationType::FALL;
					player1.setSpeed(Vector2f(500, 0));

					player2.setFreeze(true);
					player1.setFreeze(true);
				}
				else {														//Acaba de ganar la partida
					//cout << "932 de BATTLE MANAGER" << endl;
					finishing2 = true;
					showing_finishHim = true;
					music.finishHim();

					RectangleShape rect = HUD_vector[16];
					uvRect = rect.getTextureRect();
					if (character1 == CharacterType::SONYA) {
						uvRect.left = 3317.0f;
						music.finishHer();
					}
					else {
						music.finishHim();
					}
					rect.setTextureRect(uvRect);
					HUD_vector[16] = rect;

					player1.setDying(true);
					player1.setFreeze(true);
				}
			}
		}

		Vector2f size_round = Vector2f(327.0f, 82.0f);
		uvRect = HUD_vector[10].getTextureRect();
		uvRect.top = 54 + 84 * round;
		HUD_vector[10].setTextureRect(uvRect);
	}

}

void BattleManager::CheckCollisions() {

	if (player1.damage_hitbox.getGlobalBounds().intersects(player2.hitbox.getGlobalBounds())) {

		if (isDamageMovement(player1.animation_in_process)) {	//Le pega el jugador 1
			bool inFinishHim = (rounds_won1 == 2 || rounds_won2 == 2);
			if (inFinishHim && finishing1 && clock_finishRound > 5) { P1WinnedPose = true; }			//El jugador 1 golpea en finish him

			ProcessHit(player1.animation_in_process, true);

		}

	}

	if (player2.damage_hitbox.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds())) {

		if (isDamageMovement(player2.animation_in_process)) {	//Le pega el jugador 2
			bool inFinishHim = (rounds_won1 == 2 || rounds_won2 == 2);
			if (inFinishHim && finishing2 && clock_finishRound > 5) { P2WinnedPose = true; }			//El jugador 2 golpea en finish him

			ProcessHit(player2.animation_in_process, false);

		}

	}

	if (player1.hitbox.getGlobalBounds().intersects(player2.hitbox.getGlobalBounds()) 
		&& player1.animation_in_process == AnimationType::WALK_FORW
		&& player2.animation_in_process != AnimationType::WALK_FORW) {

		Vector2f p2Pos = player2.getPosition();
		float addX = (player1.lookingAt() == LookingAt::RIGHT) ? 15.f : -15.f;
		if (!player2.CheckScreenCollisions(-addX)) {
			player2.setPosition(Vector2f(p2Pos.x + addX, p2Pos.y));
		}
	}
	else if (player2.hitbox.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds()) 
		&& player2.animation_in_process == AnimationType::WALK_FORW
		&& player1.animation_in_process != AnimationType::WALK_FORW) {

		Vector2f p1Pos = player1.getPosition();
		float addX = (player2.lookingAt() == LookingAt::RIGHT) ? 15.f : -15.f;
		if (!player1.CheckScreenCollisions(-addX)) {
			player1.setPosition(Vector2f(p1Pos.x + addX, p1Pos.y));
		}
	}
	else if (player2.hitbox.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds())
		&& player2.animation_in_process == AnimationType::WALK_FORW
		&& player1.animation_in_process == AnimationType::WALK_FORW) {
		Vector2f p1Pos = player1.getPosition();
		Vector2f p2Pos = player2.getPosition();

		float addXP1 = (player1.lookingAt() == LookingAt::RIGHT) ? 15.f : -15.f;
		float addXP2 = (player2.lookingAt() == LookingAt::RIGHT) ? 15.f : -15.f;
		player1.setPosition(Vector2f(p1Pos.x + addXP2, p1Pos.y));
		player2.setPosition(Vector2f(p2Pos.x + addXP1, p2Pos.y));
	}

	if (player1Special.body.getGlobalBounds().intersects(player2.hitbox.getGlobalBounds()) && !player1Special.isFinished() && !player1Special.getHasHit() && player1Special.hasStarted()) {
		player1Special.setHit();
		bool inFinishHim = (rounds_won1 == 2 || rounds_won2 == 2);
		if (inFinishHim && finishing1 && clock_finishRound > 5) { P1WinnedPose = true; }			//El jugador 1 golpea en finish him

		ProcessHit(AnimationType::SPECIAL, true);
	}
	if (player2Special.body.getGlobalBounds().intersects(player1.hitbox.getGlobalBounds()) && !player2Special.isFinished() && !player2Special.getHasHit() && player2Special.hasStarted()) {
		player2Special.setHit();
		bool inFinishHim = (rounds_won1 == 2 || rounds_won2 == 2);
		if (inFinishHim && finishing2 && clock_finishRound > 5) { P2WinnedPose = true; }
		ProcessHit(AnimationType::SPECIAL, false);
	}

}

void BattleManager::ProcessHit(AnimationType anim, bool toPlayerTwo) {
	
	if ((toPlayerTwo && player2.isBlocking())) {
		if (player2.isCrouching()) {
			life2 -= life_BLOCK;
			player2.setSpeed(Vector2f(200, 0));
			music.hitBlock();
			player2.life = life2;
			return;
		}
		else if (!player2.isCrouching() && isUpperDamage(anim)) {
			life2 -= life_BLOCK;
			player2.setSpeed(Vector2f(200, 0));
			music.hitBlock();
			player2.life = life2;
			return;
		}
	}
	else if (!toPlayerTwo && player1.isBlocking()) {
		if (player1.isCrouching()) {
			life1 -= life_BLOCK;
			player1.setSpeed(Vector2f(200, 0));
			music.hitBlock();
			player1.life = life1;
			return;
		} else if (!player1.isCrouching() && isUpperDamage(anim)) {
			life1 -= life_BLOCK;
			player1.setSpeed(Vector2f(200, 0));
			music.hitBlock();
			player1.life = life1;
			return;
		}
	}

	bool crouching = false;
	bool onAir = false;
	if ((toPlayerTwo && player2.isCrouching()) || !toPlayerTwo && player1.isCrouching()) {
		crouching = true;
	}
	if ((toPlayerTwo && player2.isOnAir()) || !toPlayerTwo && player1.isOnAir()) {
		onAir = true;
	}

	if (toPlayerTwo) {
		player2.GetHit();
	}
	else {
		player1.GetHit();
	}


	if (anim == AnimationType::PUNCH || anim == AnimationType::PUNCH_CLOSE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(350, 0));
			}
			else if (onAir) {
				characterFall01(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(600, 250));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND;
				player2.setSpeed(Vector2f(450, 0));
			}
			music.hit2();
		}
		else {
			life1 -= life_PUNCH;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(350, 0));
			}
			else if (onAir) {
				characterFall02(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(600, 250));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND;
				player1.setSpeed(Vector2f(450, 0));
			}
			music.hit2();
		}

	}
	else if (anim == AnimationType::PUNCH_UPPER || anim == AnimationType::PUNCH_UPPER_CLOSE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_UPPER;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(600, 250));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_HEAD;
				player2.setSpeed(Vector2f(600, 0));
			}

			int random = rand() % 10;

			if (random > 5) music.hit9();
			else music.hit8();

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
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall04(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(600, 250));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_HEAD;
				player1.setSpeed(Vector2f(600, 0));
			}
			music.hit9();

			int random = rand() % 10;

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
		shake();
		if (toPlayerTwo) {
			life2 -= life_PUNCH_UPPER;
			player2.animation_in_process = AnimationType::FALL;
			music.hit1();
			characterFall03(character2);

			int random = rand() % 10;
			player2.setSpeed(Vector2f(500, 1200));

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
			characterFall04(character1);

			int random = rand() % 10;
			player1.setSpeed(Vector2f(500, 1200));

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

		if (rand() % 10 > 8) music.excellent();
		if (rand() % 10 < 3) music.loosePublic();
	}
	else if (anim == AnimationType::PUNCH_MULTIPLE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {

				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(500, 250));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player2.setSpeed(Vector2f(650, 0));
			}
			music.hit5();
		}
		else {
			life1 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {

				characterFall04(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(500, 250));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player1.setSpeed(Vector2f(650, 0));
			}
			music.hit5();
		}
	}
	else if (anim == AnimationType::PUNCH_UPPER_MULTIPLE) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_MULTIPLE;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(500, 250));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_HEAD;
				player2.setSpeed(Vector2f(650, 0));
			}
			music.hit9();

			int random = rand() % 10;

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
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall03(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(500, 250));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_HEAD;
				player1.setSpeed(Vector2f(650, 0));
			}
			music.hit9();

			int random = rand() % 10;

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
	else if (anim == AnimationType::KICK_UPPER) {
		shake();
		if (toPlayerTwo) {
			life2 -= life_KICK;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall02(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(650, 300));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_HEAD;
				player2.setSpeed(Vector2f(600, 0));
			}
			music.hit1();

			int random = rand() % 10;

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
			life1 -= life_KICK;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall01(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(650, 300));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_HEAD;
				player1.setSpeed(Vector2f(600, 0));
			}
			music.hit1();

			int random = rand() % 10;

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
	else if (anim == AnimationType::KICK_LOW) {
		if (toPlayerTwo) {
			life2 -= life_KICK_LOW;
			player2.animation_in_process = AnimationType::FALL_UPPERCUT;
			music.hit5();
			characterFall01(character2);

			int random = rand() % 10;

			player2.setSpeed(Vector2f(500, 500));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 600, player2.getPosition().y + 440)); }
		}
		else {
			life1 -= life_KICK_LOW;
			player1.animation_in_process = AnimationType::FALL_UPPERCUT;
			music.hit5();
			characterFall01(character1);

			int random = rand() % 10;

			player1.setSpeed(Vector2f(500, 500));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 580, player1.getPosition().y + 440)); }
		}
	}
	else if (anim == AnimationType::KICK || anim == AnimationType::KICK_HIGH || anim == AnimationType::KICK_FROM_AIR) {
		if (toPlayerTwo) {
			life2 -= life_KICK;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {

				characterFall01(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(600, 250));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player2.setSpeed(Vector2f(650, 0));
			}
			music.hit3();
		}
		else {
			life1 -= life_KICK;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(450, 0));
			}
			else if (onAir) {
				characterFall02(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(600, 250));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player1.setSpeed(Vector2f(650, 0));
			}
			music.hit3();
		}
	}
	else if (anim == AnimationType::KICK_LOW) {
		if (toPlayerTwo) {
			life2 -= life_KICK_LOW;
			player2.animation_in_process = AnimationType::FALL_UPPERCUT;
			music.hit5();
			characterFall02(character2);

			int random = rand() % 10;

			player2.setSpeed(Vector2f(500, 500));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player2.getPosition().x + 141 * 3, player2.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 485, player2.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player2.getPosition().x + 600, player2.getPosition().y + 440)); }
		}
		else {
			life1 -= life_KICK_LOW;
			player1.animation_in_process = AnimationType::FALL_UPPERCUT;
			music.hit5();
			characterFall01(character1);

			int random = rand() % 10;

			player1.setSpeed(Vector2f(500, 500));

			if (blood.isFinished() && random > 2) { blood.bloodEffectAt(BloodType::UP, Vector2f(player1.getPosition().x + 141 * 3, player1.getPosition().y + 45 * 3)); }
			if (bloodGround1.isFinished() && random > 3) { bloodGround1.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 485, player1.getPosition().y + 415)); }
			if (bloodGround2.isFinished() && random > 7) { bloodGround2.bloodEffectAt(BloodType::GROUND, Vector2f(player1.getPosition().x + 580, player1.getPosition().y + 440)); }
		}
	}
	else if (anim == AnimationType::KICK_FROM_DOWN) {
		if (toPlayerTwo) {
			life2 -= life_KICK_FROM_DOWN;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(150, 0));
			}
			else if (onAir) {
				characterFall04(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(450, 100));
			}
			else {
				player2.animation_in_process = AnimationType::NUTS;
				player2.setSpeed(Vector2f(350, 0));
			}
			music.hit2();
		}
		else {
			life1 -= life_KICK_FROM_DOWN;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(150, 0));
			}
			else if (onAir) {
				characterFall03(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(450, 100));
			}
			else {
				player1.animation_in_process = AnimationType::NUTS;
				player1.setSpeed(Vector2f(350, 0));
			}
			music.hit2();
		}
	}
	else if (anim == AnimationType::PUNCH_FROM_AIR) {
		if (toPlayerTwo) {
			life2 -= life_PUNCH_FROM_AIR;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(300, 0));
			}
			else if (onAir) {
				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(600, 650));
			}
			else {
				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(500, 650));
			}
			music.hit2();
		}
		else {
			life1 -= life_PUNCH_FROM_AIR;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(300, 0));
			}
			else if (onAir) {
				characterFall04(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(600, 650));
			}
			else {
				characterFall03(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(500, 650));
			}
			music.hit2();
		}
	}
	else if (anim == AnimationType::SPECIAL) {
		if (toPlayerTwo) {
			life2 -= life_SPECIAL;
			if (crouching) {
				player2.animation_in_process = AnimationType::HIT_DOWN;
				player2.setSpeed(Vector2f(250, 0));
			}
			else if (onAir) {
				characterFall03(character2);
				player2.animation_in_process = AnimationType::FALL;
				player2.setSpeed(Vector2f(450, 100));
			}
			else {
				player2.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player2.setSpeed(Vector2f(600, 0));
			}
			switch (character1)
			{
			case LIU_KANG:
				music.liuKangSpecial02();
				break;
			case SCORPION:
				break;
			case SONYA:
				music.sonyaSpecial02();
				break;
			case CAGE:
				music.liuKangSpecial02();
				break;
			default:
				break;
			}
		}
		else {
			life1 -= life_SPECIAL;
			if (crouching) {
				player1.animation_in_process = AnimationType::HIT_DOWN;
				player1.setSpeed(Vector2f(250, 0));
			}
			else if (onAir) {
				characterFall04(character1);
				player1.animation_in_process = AnimationType::FALL;
				player1.setSpeed(Vector2f(450, 100));
			}
			else {
				player1.animation_in_process = AnimationType::HIT_STAND_STRONG;
				player1.setSpeed(Vector2f(600, 0));
			}
			switch (character2)
			{
			case LIU_KANG:
				music.liuKangSpecial02();
				break;
			case SCORPION:
				break;
			case SONYA:
				music.sonyaSpecial02();
				break;
			case CAGE:
				music.liuKangSpecial02();
				break;
			default:
				break;
			}
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

	if (player2.dying) {
		player2.animation_in_process = AnimationType::DYING;
	}
	else if (player1.dying) {
		player1.animation_in_process = AnimationType::DYING;
	}

	player1.life = life1 > 0 ? life1 : 0;
	player2.life = life2 > 0 ? life2 : 0;

}

int BattleManager::isfinished() {
	if (finished_game) {
		if (life1 > life2) return 1;
		return 2;
	}
	return 0;
}

int BattleManager::finished_round() {

	if (time_left <= 0) {
		if (life1 <= life2) {
			increase_round(2);
			return 2;					//Gana el jugador 2
		}
		else {
			increase_round(1);
			return 1;					//Gana el jugador 1
		}
	}
	if (life1 <= 0) {
		increase_round(2);
		return 2;
	}
	if (life2 <= 0) {
		increase_round(1);
		return 1;
	}
	return 0;

}

void BattleManager::increase_round(int player) {
	if (player == 1) {
		rounds_won1++;
	}
	else {
		rounds_won2++;
	}
}

void BattleManager::draw(RenderWindow& window) {

	BackgroundManager.draw(window);

	bloodGround1.draw(window);
	bloodGround2.draw(window);

	if (!player2Special.getHasHit()) {
		player2Special.draw(window);
	}

	if (!player1Special.getHasHit()) {
		player1Special.draw(window);
	}


	if (player2.isAttaking()) {
		player1.debugDraw(window);
		player2.debugDraw(window);
	}
	else {
		player2.debugDraw(window);
		player1.debugDraw(window);
	}

	if (player2Special.getHasHit()) {
		player2Special.draw(window);
	}

	if (player1Special.getHasHit()) {
		player1Special.draw(window);
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
		case 16:	//FINISH HIM
			if (showing_finishHim) window.draw(rect);
			else if (showing_finishHim) window.draw(rect);
			break;
		case 17:	//CHARACTER WINS
			if (showing_win) { window.draw(rect); }
			break;
		default:
			window.draw(rect);
		}
		i++;

	}

	if (paused) {
		window.draw(pauseIcon);
	}

}