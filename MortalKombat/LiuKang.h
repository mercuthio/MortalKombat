#ifndef LiuKang_H
#define LiuKang_H

#include "Character.h"

static Character CreateLiuKang() {
	Texture* spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Liu Kang.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	Vector2<int> sz = Vector2<int>(229, 219);
	RectangleShape body = RectangleShape(Vector2<float>(229, 219));
	body.setSize(Vector2f(229 * 3, 219 * 3));

	vector<int> null_vector{};
	vector<int> jump_lock{ 1 };
	vector<int> jump_lock_2{ 7 };
	vector<int> jump_lock_fall{ 3 };
	vector<int> duck_lock{ 3 };
	vector<int> blockUp_lock{ 3 };
	vector<int> blockDown_lock{ 2 };
	
	Animation idle0 = Animation(8, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, 0, null_vector);
	Animation forw0 = Animation(9, spriteSheet, Vector2<int>(2138, 58), sz, 5, false, false, 0, null_vector);
	Animation back0 = Animation(9, spriteSheet, Vector2<int>(4010, 58), sz, 5, true, false, 0, null_vector);
	Animation punch0 = Animation(4, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, 5, null_vector);
	Animation jump0 = Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, 0, jump_lock);
	Animation jumpMove0 = Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, 0, jump_lock_2);
	Animation jumpFall = Animation(3, spriteSheet, Vector2<int>(3308, 3089), sz, 5, false, true, 0, jump_lock_fall);
	Animation kick0 = Animation(7, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, true, 0, null_vector);
	Animation kickUp0 = Animation(7, spriteSheet, Vector2<int>(2372, 2046), sz, 5, false, true, 0, null_vector);
	Animation kickFromDown0 = Animation(5, spriteSheet, Vector2<int>(2840, 2568), sz, 5, false, true, 0, null_vector);
	Animation kickFromUp0 = Animation(5, spriteSheet, Vector2<int>(1904, 3090), sz, 5, false, true, 0, null_vector);
	Animation punchDown0 = Animation(5, spriteSheet, Vector2<int>(1436, 2568), sz, 5, false, true, 0, null_vector);
	Animation duck0 = Animation(5, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, 0, duck_lock);
	Animation blockUp0 = Animation(5, spriteSheet, Vector2<int>(32, 6122), sz, 5, false, true, 0, blockUp_lock);
	Animation blockDown0 = Animation(2, spriteSheet, Vector2<int>(1436, 6122), sz, 5, false, true, 0, blockDown_lock);

	AnimationGroup idle = AnimationGroup(idle0);
	AnimationGroup forwWalk = AnimationGroup(forw0);
	AnimationGroup backWalk = AnimationGroup(back0);
	AnimationGroup punch = AnimationGroup(punch0);
	AnimationGroup jump = AnimationGroup(jump0);
	jump.AddAnimation(jumpFall);
	AnimationGroup jumpMove = AnimationGroup(jumpMove0);
	jumpMove.AddAnimation(jumpFall);
	AnimationGroup kick = AnimationGroup(kick0);
	AnimationGroup kickUp = AnimationGroup(kickUp0);
	AnimationGroup kickFromDown = AnimationGroup(kickFromDown0);
	AnimationGroup kickFromUp = AnimationGroup(kickFromUp0);
	AnimationGroup punchDown = AnimationGroup(punchDown0);
	AnimationGroup duck = AnimationGroup(duck0);
	AnimationGroup blockUp = AnimationGroup(blockUp0);
	AnimationGroup blockDown = AnimationGroup(blockDown0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0) };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0) };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0) };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0) };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0) };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0) };
	Movement kickUpMov = Movement{ kickUp, Vector2<float>(0.0, 0.0) };
	Movement kickFromDownMov = Movement{ kickFromDown, Vector2<float>(0.0, 0.0) };
	Movement kickFromUpMov = Movement{ kickFromUp, Vector2<float>(0.0, 0.0) };
	Movement punchDownMov = Movement{ punchDown, Vector2<float>(0.0, 0.0) };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0) };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0) };
	Movement blockUpMov = Movement{ blockUp, Vector2<float>(0.0,0.0) };
	Movement blockDownMov = Movement{ blockDown, Vector2<float>(0.0,0.0) };

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMoveMov;
	animations[AnimationType::KICK] = kickMov;
	animations[AnimationType::KICK_UPPER] = kickUpMov;
	animations[AnimationType::KICK_FROM_DOWN] = kickFromDownMov;
	animations[AnimationType::KICK_FROM_AIR] = kickFromUpMov;
	animations[AnimationType::PUNCH_FROM_DOWN] = punchDownMov;
	animations[AnimationType::DOWN] = duckMov;
	animations[AnimationType::BLOCK] = blockUpMov;
	animations[AnimationType::BLOCK_LOW] = blockDownMov;

	Character LiuKang = Character(animations, body);

	return LiuKang;
}

#endif //LIUKANG_H