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

	bool isFinished() { return finished; }

private:
	Texture* spriteSheet = new Texture();
	RectangleShape body = RectangleShape();
	int totalFrames[4] = { 5, 6, 7, 18 };
	int frame = 0;
	bool finished = false;
	BloodType animationInProgress = BloodType();
	Clock clock = Clock();
	float internalTimer = 0.0;
};

#endif
