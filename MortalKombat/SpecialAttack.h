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

		bodyHit = body.getPosition();

		if (!hasHit) {
			float posX = body.getPosition().x;
			float posY = body.getPosition().y;
			body.setPosition(Vector2f(posX + 5, posY - 5));
			hasHit = true;
		}
	}

	void resetSpecial() {
		finished = true;
		started = false;
		hasHit = false;
		frame = 0;
	}

	bool isFinished() { return finished; }

	bool hasStarted() { return started; }

	RectangleShape body = RectangleShape();

private:
	Texture* spriteSheet = new Texture();
	int totalFramesAnim[4] = { 2, 4, 2, 2 };
	int totalFramesHit[4] = { 6, 1, 4, 4 };
	LookingAt looking_at = LookingAt::RIGHT;
	int frame = 0;
	float initInternalTimer = 0.0;
	float internalTimer = 0.0;
	SpecialType animationInProgress = SpecialType();
	bool finished = false;
	bool started = false;
	bool hasHit = false;

	bool mirrored = false;

	float initY = 0.0;
	Vector2f bodyHit = Vector2f();

	Vector2f size_liuAnim = Vector2f(68.0f, 11.0f);
	Vector2f size_liuHit = Vector2f(65.0f, 87.0f);

	Vector2f size_scorpionAnim = Vector2f(321.0f, 27.0f);
	Vector2f size_scorpionHit1 = Vector2f(33.0f, 27.0f);
	Vector2f size_scorpionHit2 = Vector2f(5.0f, 27.0f);

	Vector2f size_sonyaAnim = Vector2f(41.0f, 35.0f);
	Vector2f size_sonyaHit = Vector2f(43.0f, 129.0f);

	Vector2f size_cageAnim = Vector2f(64.0f, 19.0f);
	Vector2f size_cageHit = Vector2f(48.0f, 86.0f);

};

#endif