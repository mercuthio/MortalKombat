#pragma once
#ifndef GORO_H
#define GORO_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Character.h"
#include "Animation.h"
#include "Definitions.h"

void testGoro(RenderWindow& window) {
	Texture spriteSheet;
	spriteSheet.loadFromFile("resources/Sprites/Personajes/Goro.png");
	RectangleShape body = RectangleShape(Vector2<float>(251, 219));
	
	body.setTexture(&spriteSheet);
	body.setPosition(20, 10);

	IntRect rect = IntRect(Vector2<int>(32, 58), Vector2<int>(251, 219));
	body.setTextureRect(rect);

	window.draw(body);
}

Movement makeMovent(Texture spriteSheet, Vector2<int> firstFrame, Vector2<int> frameSize, int offset, int n_frames, Vector2<float> translation, bool backwards, bool lock, int rec, vector<int> vector) {
	
	Animation anim = Animation(n_frames, spriteSheet, firstFrame, frameSize, offset, backwards, lock, rec, vector, false);
	return Movement{ anim, translation };
}

Character CreateGoro() {
	Texture spriteSheet;
	spriteSheet.loadFromFile("resources/Sprites/Personajes/Goro.png");

	RectangleShape body = RectangleShape(Vector2<float>(251, 219));
	body.setPosition(50, 400);

	vector<int> null_vector {};
	vector<int> jump_lock { 4, 7 };
	Movement idleMov = makeMovent(spriteSheet, Vector2<int>(32, 58), Vector2<int>(251, 219), 5, 7, Vector2<float>(0.0, 0.0), false, false, 0, null_vector);
	Movement forwMov = makeMovent(spriteSheet, Vector2<int>(2080, 58), Vector2<int>(251, 219), 5, 9, Vector2<float>(5.0, 0.0), false, false, 0, null_vector);
	Movement backMov = makeMovent(spriteSheet, Vector2<int>(4128, 58), Vector2<int>(251, 219), 5, 9, Vector2<float>(-2.5, 0.0), true, false, 0, null_vector);
	Movement punchMov = makeMovent(spriteSheet, Vector2<int>(32, 580), Vector2<int>(251, 219), 5, 4, Vector2<float>(0.0, 0.0), false, true, 3, null_vector);
	Movement jumpMov = makeMovent(spriteSheet, Vector2<int>(32, 1624), Vector2<int>(251, 219), 5, 9, Vector2<float>(0.0, 0.0), false, true, 1, jump_lock);
	
	//Movement punchMov = makeMovent(spriteSheet, Vector2<int>(), Vector2<int>(), 0, 0, Vector2<float>(), false, false);
	//Movement punchMov = makeMovent(spriteSheet, Vector2<int>(), Vector2<int>(), 0, 0, Vector2<float>(), false, false);
	//Movement punchMov = makeMovent(spriteSheet, Vector2<int>(), Vector2<int>(), 0, 0, Vector2<float>(), false, false);


	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::FORW_WALK] = forwMov;
	animations[AnimationType::BACK_WALK] = backMov;
	animations[AnimationType::L_PUNCH_IDLE] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::FORW_JUMP] = jumpMov;
	animations[AnimationType::BACK_JUMP] = jumpMov;

	Character goro = Character(animations, body);

	return goro;
}



#endif