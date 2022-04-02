#pragma once
#ifndef LIUKANG_H
#define LIUKANG_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Character.h"
#include "Animation.h"
#include "AnimationGroup.h"
#include "Definitions.h"
#include "Movement.h"

#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

Character CreateLiuKang() {

	Texture* spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Liu Kang.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	Vector2<int> sz = Vector2<int>(229, 219);
	RectangleShape body = RectangleShape(Vector2<float>(229, 219));
	body.setPosition(50, 400);

	vector<int> null_vector{};
	vector<int> jump_lock{ 1 };
	vector<int> jump_lock_2{ 7 };
	vector<int> jump_lock_fall{ 3 };
	vector<int> duck_lock{3};

	Animation idle0		= Animation(8, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, 0, null_vector);
	Animation forw0		= Animation(9, spriteSheet, Vector2<int>(2138, 58), sz, 5, false, false, 0, null_vector);
	Animation back0		= Animation(9, spriteSheet, Vector2<int>(4010, 58), sz, 5, true, false, 0, null_vector);
	Animation punch0	= Animation(4, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, 3, null_vector);
	Animation jump0		= Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, 0, jump_lock);
	Animation jumpMove0	= Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, 0, jump_lock_2);
	Animation jumpFall	= Animation(3, spriteSheet, Vector2<int>(3308, 3089), sz, 5, false, true, 0, jump_lock_fall);
	Animation kick0		= Animation(7, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, true, 0, null_vector);
	Animation duck0		= Animation(5, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, 0, duck_lock);

	AnimationGroup idle = AnimationGroup(idle0);
	AnimationGroup forwWalk = AnimationGroup(forw0);
	AnimationGroup backWalk = AnimationGroup(back0);
	AnimationGroup punch = AnimationGroup(punch0);
	AnimationGroup jump = AnimationGroup(jump0); 
	jump.AddAnimation(jumpFall);
	AnimationGroup jumpMove = AnimationGroup(jumpMove0);
	jumpMove.AddAnimation(jumpFall);
	AnimationGroup kick = AnimationGroup(kick0);
	AnimationGroup duck = AnimationGroup(duck0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0) };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(10.0, 0.0) };
	Movement backMov = Movement{ backWalk, Vector2<float>(-5, 0.0) };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0) };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0) };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0) };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0) };
	Movement duckMov = Movement{duck, Vector2<float>(0.0,0.0)};

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMoveMov;
	animations[AnimationType::KICK] = kickMov;
	animations[AnimationType::DOWN] = duckMov;

	Character LiuKang = Character(animations, body);
	
	return LiuKang;
}

#endif //LIUKANG_H