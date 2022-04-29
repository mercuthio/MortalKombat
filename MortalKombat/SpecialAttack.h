#ifndef SPECIALATTACK_H
#define SPECIALATTACK_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"
#include <iostream>

using namespace sf;
using namespace std;

class SpecialAttack {
public:
	SpecialAttack();
	//~SpecialAttack() = default;

	void SpecialAttackAt(CharacterType type, Vector2f position, bool mirrored);

	void Update();
	void draw(RenderWindow&);

	bool isFinished();

private:
	RectangleShape body;
	Vector2<float> global_position;
	LookingAt looking_at = LookingAt::RIGHT;

	void DoAnimation();

};

#endif