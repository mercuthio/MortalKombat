#ifndef BLOODEFFECT_H
#define BLOODEFFECT_H

#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "GlobalVars.h"

using namespace sf;
using namespace std;

class BloodEffect {
public:
	BloodEffect();
	//~BloodEffect() = delete;

	void bloodEffectAt(BloodType type, Vector2f position);
	bool bloodEffectAnimation();

	void Update();
	void draw(RenderWindow&);

private:
	Texture* spriteSheet;
	RectangleShape body;
	int totalFrames[4] = { 5, 6, 7, 3 };
	int frame;
	bool finished;
	BloodType animationInProgress;
	Clock clock;
	float internalTimer;
};

#endif
