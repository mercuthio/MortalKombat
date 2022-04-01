#ifndef GORO_H
#define GORO_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Character.h"
#include "Animation.h"
#include "GlobalVars.h"
#include "Movement.h"
/*
Character CreateGoro() {

	Texture spriteSheet;
	Image spriteSheetImage;
	Color back = Color(165,231,255,255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Goro.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet.loadFromImage(spriteSheetImage);

	Vector2<int> sz = Vector2<int>(251, 220);
	RectangleShape body = RectangleShape(Vector2<float>(250, 219));
	body.setPosition(200, 400);

	vector<int> null_vector {};
	vector<int> jump_lock { 4, 7 };
	Movement idleMov = makeMovent(spriteSheet, Vector2<int>(32, 58), sz, 5, 7, Vector2<float>(0.0, 0.0), false, false, 0, null_vector, true, body.getScale());
	Movement forwMov = makeMovent(spriteSheet, Vector2<int>(2080, 58), sz, 5, 9, Vector2<float>(5.0, 0.0), false, false, 0, null_vector, true, body.getScale());
	Movement backMov = makeMovent(spriteSheet, Vector2<int>(4128, 58), sz, 5, 9, Vector2<float>(-2.5, 0.0), true, false, 0, null_vector, true, body.getScale());
	Movement punchMov = makeMovent(spriteSheet, Vector2<int>(32, 580), sz, 5, 4, Vector2<float>(0.0, 0.0), false, true, 3, null_vector, true, body.getScale());
	Movement jumpMov = makeMovent(spriteSheet, Vector2<int>(32, 1624), sz, 5, 9, Vector2<float>(0.0, 0.0), false, true, 0, jump_lock, true, body.getScale());

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMov;

	Character goro = Character(animations, body);

	return goro;
	
}
*/


#endif