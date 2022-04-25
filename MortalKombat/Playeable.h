#pragma once
#ifndef Playeable_H
#define Playeable_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Movement.h"
#include "Recover.h"
#include "GlobalVars.h"

using namespace sf;
using namespace std;

class Playeable {
public:
	void Update(float time);

	void debugDraw(RenderWindow& window);

	void GetHit(int life);

	void initPosition(Vector2<float> initPos);
	bool isAttaking();

	AnimationType getAnimation();
	

	float GetLife();

	LookingAt lookingAt();

	float GetXPosition();

	void SetXPosition(float x);

	void Mirror();

	void setPlayer(int p);

	void setFreeze(bool freeze_);

};

/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
#endif 