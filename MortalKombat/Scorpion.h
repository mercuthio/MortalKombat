#ifndef Scorpion_H
#define Scorpion_H

#include "Character.h"

static Character CreateScorpion() {
	Texture* spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Scorpion.png");
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
	vector<int> block_lock{ 3 };
	vector<int> blockDown_lock{ 3 };
	vector<int> win_lock{ 4 };

	//(int _duration, Texture* _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames) {
	Animation idle0 = Animation(7, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation forw0 = Animation(9, spriteSheet, Vector2<int>(1904, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation back0 = Animation(9, spriteSheet, Vector2<int>(3776, 58), sz, 5, true, false, 0, null_vector, 0);

	Animation punch0 = Animation(5, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, 2, null_vector, 0);
	Animation punchDown0 = Animation(5, spriteSheet, Vector2<int>(1436, 2568), sz, 5, false, true, 0, null_vector, 0);
	Animation punchFromUp0 = Animation(5, spriteSheet, Vector2<int>(500, 3090), sz, 5, false, true, 0, null_vector, 0);
	Animation bodyToBody0 = Animation(5, spriteSheet, Vector2<int>(4010, 580), sz, 5, false, true, 0, null_vector, 0);

	Animation jump0 = Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, 0, jump_lock, 0);
	Animation jumpMove0 = Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, 0, jump_lock_2, 0);
	Animation jumpFall = Animation(3, spriteSheet, Vector2<int>(2840, 3090), sz, 5, false, true, 0, jump_lock_fall, 0);

	Animation kick0 = Animation(7, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, true, 0, null_vector, 0);
	Animation kickUp0 = Animation(7, spriteSheet, Vector2<int>(2606, 2046), sz, 5, false, true, 0, null_vector, 0);
	Animation kickDown0 = Animation(8, spriteSheet, Vector2<int>(1904, 1574), sz, 5, false, true, 0, null_vector, 0);
	Animation kickFromDown0 = Animation(5, spriteSheet, Vector2<int>(2840, 2568), sz, 5, false, true, 0, null_vector, 0);
	Animation kickFromUp0 = Animation(3, spriteSheet, Vector2<int>(1904, 3090), sz, 5, false, true, 0, null_vector, 0);

	Animation duck0 = Animation(5, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, 0, duck_lock, 0);
	
	Animation block0 = Animation(5, spriteSheet, Vector2<int>(32, 6122), sz, 5, false, true, 0, block_lock, 0);
	Animation blockDown0 = Animation(3, spriteSheet, Vector2<int>(1436, 6122), sz, 5, false, true, 0, blockDown_lock, 0);

	Animation special0 = Animation(7, spriteSheet, Vector2<int>(32, 6644), sz, 5, false, true, 0, null_vector, 0);
	Animation fatality0 = Animation(24, spriteSheet, Vector2<int>(32, 7688), sz, 5, false, true, 0, null_vector, 0);
	Animation win0 = Animation(4, spriteSheet, Vector2<int>(32, 8810), sz, 5, false, true, 0, win_lock, 0);

	AnimationGroup idle = AnimationGroup(idle0);
	AnimationGroup forwWalk = AnimationGroup(forw0);
	AnimationGroup backWalk = AnimationGroup(back0);
	AnimationGroup punch = AnimationGroup(punch0);
	AnimationGroup punchDown = AnimationGroup(punchDown0);
	AnimationGroup punchFromUp = AnimationGroup(punchFromUp0);
	AnimationGroup bodyToBody = AnimationGroup(bodyToBody0);
	AnimationGroup jump = AnimationGroup(jump0);
	jump.AddAnimation(jumpFall);
	AnimationGroup jumpMove = AnimationGroup(jumpMove0);
	jumpMove.AddAnimation(jumpFall);
	AnimationGroup kick = AnimationGroup(kick0);
	AnimationGroup kickUp = AnimationGroup(kickUp0);
	AnimationGroup kickFromDown = AnimationGroup(kickFromDown0);
	AnimationGroup kickDown = AnimationGroup(kickDown0);
	AnimationGroup kickFromUp = AnimationGroup(kickFromUp0);
	AnimationGroup block = AnimationGroup(block0);
	AnimationGroup blockDown = AnimationGroup(blockDown0);
	AnimationGroup duck = AnimationGroup(duck0);
	AnimationGroup special = AnimationGroup(special0);
	AnimationGroup fatality = AnimationGroup(fatality0);
	AnimationGroup win = AnimationGroup(win0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0) };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0) };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0) };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0) };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0) };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0) };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0) };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0) };
	Movement blockUpMov = Movement{ block, Vector2<float>(0.0,0.0) };
	Movement blockDownMov = Movement{ blockDown, Vector2<float>(0.0,0.0) };
	Movement specialMov = Movement{ special, Vector2<float>(0.0,0.0) };
	Movement fatalityMov = Movement{ fatality, Vector2<float>(0.0,0.0) };
	Movement winMov = Movement{ win, Vector2<float>(0.0,0.0) };

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMoveMov;
	animations[AnimationType::KICK] = kickMov;
	animations[AnimationType::DOWN] = duckMov;
	animations[AnimationType::BLOCK] = blockUpMov;
	animations[AnimationType::BLOCK_LOW] = blockDownMov;

	Character Scorpion = Character(animations, body);

	return Scorpion;
}

#endif //SCORPION_H
