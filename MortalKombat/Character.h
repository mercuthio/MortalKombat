#ifndef Character_H
#define Character_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Movement.h"
#include "Recover.h"
#include "GlobalVars.h"

//--------------DEBUG-------------
constexpr float gravedad = 1800;			// pixels/s^2
constexpr float updateTime = 0.05;			// 50 milis
constexpr bool DEBUG_POSITION = true;
//--------------------------------


using namespace sf;
using namespace std;

class Character {
public:
	Character() = default;
	Character(map<AnimationType, Movement> _animations, RectangleShape & _body, RectangleShape& _shadow, map<AnimationType, vector<RectangleShape>> hitboxes_);
	//~Character() = delete;

	void Update(float time);
	void UpdateIA(float time);
	void debugDraw(RenderWindow& window);

	void GetHit(int life);

	void initPosition(Vector2<float> initPos);

	float GetLife();

	bool isMirrored() {
		return mirrored;
	}

	float GetXPosition() {
		return global_position.x;
	}

	void SetXPosition(float x) {
		global_position.x += x;
	}

	void Mirror();

	void setPlayer(int p) {
		player = p;
	}

	void setFreeze(bool freeze_) {
		freeze = freeze_;
	};

private:
	RectangleShape body;
	RectangleShape shadow;
	RectangleShape hitbox;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion
	map<AnimationType, vector<RectangleShape>> hitboxes;

	float internalTimer = 0.05f;

	int life = 100;

	bool doing_animation = false;

	bool on_air = false;
	bool punching = false;
	bool crouching = false;
	bool blocking = false;
	bool fallen = false;
	bool dying = false;
	bool wait_air = false;

	Vector2<float> speed;

	bool mirrored = false;

	int player = 0;

	bool freeze = true;		//Para el comienzo de partidas, no permite mover
	
	AnimationType animation_in_process;

	void CheckDebugAnimations();
	void EndAndResetAnimation();

	void DoAnimation();
	void EndAnimation();
	void debug_animation();

	void CheckAnimation();
	void CheckCollisions();
	bool CheckScreenCollisions(float movement);
};

/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
#endif 