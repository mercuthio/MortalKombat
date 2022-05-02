#ifndef Character_H
#define Character_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Movement.h"
#include "Recover.h"
#include "GlobalVars.h"

//--------------DEBUG-------------
constexpr float gravedad = 2500;			// pixels/s^2
constexpr float updateTime = 0.05;			// 50 milis
constexpr bool DEBUG_POSITION = true;
//--------------------------------


using namespace sf;
using namespace std;

class Character {
public:
	Character() = default;
	Character(map<AnimationType, Movement> _animations, RectangleShape & _body, RectangleShape& _shadow, map<AnimationType, vector<RectangleShape>> hitboxes_, map<AnimationType, vector<RectangleShape>> damage_hitboxes_);
	//~Character() = delete;

	void UpdateIA(float time, Character opponent);

	void Update(float time, bool seconPlayer);
	void debugDraw(RenderWindow& window);

	void GetHit();

	void initPosition(Vector2<float> initPos);
	bool isAttaking();
	bool isBlocking() {
		return blocking;
	}

	AnimationType getAnimation() {
		return animation_in_process;
	}

	float GetLife();

	LookingAt lookingAt() {
		return looking_at;
	}

	float GetXPosition() {
		return global_position.x;
	}

	void SetXPosition(float x) {
		global_position.x += x;
	}

	void RestartMirror(bool playerTwo);
	void Mirror();

	void setPlayer(int p) {
		player = p;
	}

	void setFreeze(bool freeze_) {
		freeze = freeze_;
	};

	Vector2f getPosition() {
		return global_position;
	};
	void setPosition(Vector2f position) {
		global_position = position;
	};

	void setOnAir(bool onAir) {
		on_air = onAir;
	}

	void setSpeed(Vector2f _speed) {
		speed = _speed;
	}

	bool isCrouching() {
		return crouching;
	}

	bool isOnAir() { return on_air; }

	void setDying(bool die) {
		dying = die;
		if (die) {
			animation_in_process = AnimationType::DYING;
			global_position.y = screenFloorLimit;
		}		
	}
	void setFallen(bool fall) {
		fallen = fall;
	}

	bool CheckScreenCollisions(float movement);


	RectangleShape hitbox;
	RectangleShape damage_hitbox;

	AnimationType animation_in_process;

	int life = 100;

private:
	RectangleShape body;
	RectangleShape shadow;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion
	map<AnimationType, vector<RectangleShape>> hitboxes;
	map<AnimationType, vector<RectangleShape>> damage_hitboxes;

	float internalTimer = 0.05f;

	int freezeTimer = 0;

	bool doing_animation = false;

	bool on_air = false;
	bool punching = false;
	bool crouching = false;
	bool blocking = false;
	bool fallen = false;
	bool falling = false;
	bool dying = false;
	bool wait_air = false;
	bool fightKeyPressed = false;
	bool removePunchNext = false;
	bool freeze = true;		//Para el comienzo de partidas, no permite mover
	bool mirrorOnEnd = false;
	bool mirroring = false;
	
	LookingAt looking_at = LookingAt::RIGHT;

	Vector2<float> speed;

	bool mirrored = false;

	EstadoIA estado = EstadoIA::IDLE;
	DifficultyLevel difficulty_lvl = DifficultyLevel::MEDIUM;

	
	int player = 0;	
	int duracionEstadoActual = 0;

	void CheckDebugAnimations();
	void EndAndResetAnimation();

	void DoAnimation();
	void EndAnimation();
	void debug_animation();

	void CheckAnimation();
	void CheckAnimationP2();
	
	void CheckIAAnimation(Character opponent);
	void ChangeIAState(Character opponent);
};

/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
#endif 