#ifndef SonyaBlade_H
#define SonyaBlade_H

#include "Character.h"
/*
static Character CreateSonyaBlade() {
	Texture* spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Sonya_Blade.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	Vector2<int> sz = Vector2<int>(229, 219);
	RectangleShape body = RectangleShape(Vector2<float>(229, 219));
	body.setSize(Vector2f(229 * 3, 219 * 3));

	vector<int> null_vector{};
	vector<int> jump_lock{ 1 };
	vector<int> jump_lock_2{ 7 };
	vector<int> jump_lock_fall{ 3 };
	vector<int> duck_lock{ 2 };

	//(int _duration, Texture* _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames) {
	Animation idle0 = Animation(7, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation forw0 = Animation(9, spriteSheet, Vector2<int>(1904, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation back0 = Animation(9, spriteSheet, Vector2<int>(3776, 58), sz, 5, true, false, 0, null_vector, 0);
	Animation punch0 = Animation(5, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, 5, null_vector, 0);
	Animation jump0 = Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, 0, jump_lock, 0);
	Animation jumpMove0 = Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, 0, jump_lock_2, 0);
	Animation jumpFall = Animation(3, spriteSheet, Vector2<int>(2372, 3090), sz, 5, false, true, 0, jump_lock_fall, 0);
	Animation kick0 = Animation(9, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, true, 0, null_vector, 0);
	Animation duck0 = Animation(3, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, 0, duck_lock, 0);

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
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0) };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0) };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0) };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0) };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0) };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0) };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0) };

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMoveMov;
	animations[AnimationType::KICK] = kickMov;
	animations[AnimationType::DOWN] = duckMov;

	map< AnimationType, vector<RectangleShape>> hitboxes;

	Character SonyaBlade = Character(animations, body, hitboxes, SONYA);

	return SonyaBlade;
}
*/

#endif //LIUKANG_H
