#ifndef Character_H
#define Character_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Movement.h"

#include "GlobalVars.h"

//--------------DEBUG-------------
constexpr int screenLeftLimit = -1000;
constexpr int screenRightLimit = 1000;
constexpr int screenFloorLimit = 200;
constexpr float gravedad = 1800;			// pixels/s^2
constexpr float updateTime = 0.05;			// 50 milis
constexpr bool DEBUG_POSITION = true;
//--------------------------------


using namespace sf;
using namespace std;

class Character {
public:
	Character() = default;
	Character(map<AnimationType, Movement> _animations, RectangleShape & _body);
	//~Character() = delete;

	void Update(float time);
	void debugDraw(RenderWindow& window);

	void GetHit(int life);

	void initPosition(Vector2<float> initPos);

	float GetLife();

private:
	RectangleShape body;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion

	float internalTimer = 0.05f;

	int life = 100;

	bool doing_animation = false;

	bool on_air = false;
	bool punching = false;
	bool crouching = false;
	bool blocking = false;

	Vector2<float> speed;
	bool leftOfOpponent = true;
	
	AnimationType animation_in_process;

	void CheckDebugAnimations();
	void EndAndResetAnimation();

	void Mirror();

	void DoAnimation();
	void EndAnimation();
	void debug_animation();

	void CheckAnimation();
	void CheckCollisions();
	void CheckScreenCollisions();
};

/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
#endif