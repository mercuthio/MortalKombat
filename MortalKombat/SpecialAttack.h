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
	int totalFramesHit[3] = { 6, 2, 4 };
	LookingAt looking_at = LookingAt::RIGHT;
	int frame;
	float initInternalTimer;
	float internalTimer;
	SpecialType animationInProgress;
	bool finished;
	bool started;
	bool hasHit;

	float initY;

	Vector2f size_liuAnim = Vector2f(68.0f, 11.0f);
	Vector2f size_liuHit = Vector2f(65.0f, 87.0f);

	Vector2f size_scorpionAnim = Vector2f(321.0f, 27.0f);
	Vector2f size_scorpionHit = Vector2f(258.0f, 27.0f);
	Vector2f size_scorpionGetRow1 = Vector2f(50.0f, 27.0f);
	Vector2f size_scorpionGetRow2 = Vector2f(50.0f, 27.0f);
	Vector2f size_scorpionGetRow3 = Vector2f(71.0f, 27.0f);

	Vector2f size_sonyaAnim = Vector2f(41.0f, 35.0f);
	Vector2f size_sonyaHit = Vector2f(43.0f, 129.0f);

};

#endif