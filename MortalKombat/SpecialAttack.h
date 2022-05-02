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

	void SpecialAttackAt(SpecialType type, Vector2f position, bool mirrored);
	bool SpecialAttackAnimation();

	void Update();
	void draw(RenderWindow&);

	bool getHasHit() { return hasHit; }

	void setHit() {

		if (!hasHit) {
			float posX = body.getPosition().x;
			float posY = body.getPosition().y;
			body.setPosition(Vector2f(posX + 5, posY - 5));
			hasHit = true;
		}
	}

	bool isFinished() { return finished; }

	RectangleShape body;

private:
	Texture* spriteSheet;
	int totalFramesAnim[3] = { 2, 4, 2};
	int totalFramesHit[3] = { 6, 4, 4 };
	LookingAt looking_at = LookingAt::RIGHT;
	int frame;
	float initInternalTimer;
	float internalTimer;
	SpecialType animationInProgress;
	bool finished;
	bool started;
	bool hasHit;

};

#endif