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
	vector<int> win_lock{ 14 };
	vector<int> punchOrKickAir_lock{ 5, 5 };
	vector<int> fallBack_lock{ 6 };


	Animation idle0 = Animation(8, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation forw0 = Animation(9, spriteSheet, Vector2<int>(2138, 58), sz, 5, false, false, 0, null_vector, 0);
	Animation back0 = Animation(9, spriteSheet, Vector2<int>(4010, 58), sz, 5, true, false, 0, null_vector, 0);

	Animation punch0 = Animation(4, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, 5, null_vector, 2);
	Animation punchUp0 = Animation(4, spriteSheet, Vector2<int>(32, 1052), sz, 5, false, true, 5, null_vector, 0);
	Animation punchDown0 = Animation(5, spriteSheet, Vector2<int>(1436, 2568), sz, 5, false, false, 0, null_vector, 0);
	Animation punchFromUp0 = Animation(5, spriteSheet, Vector2<int>(500, 3090), sz, 5, false, true, 0, punchOrKickAir_lock, 0);
	Animation bodyToBody0 = Animation(5, spriteSheet, Vector2<int>(3542, 580), sz, 5, false, false, 0, null_vector, 0);
	Animation bodyToBodyUp0 = Animation(5, spriteSheet, Vector2<int>(3542, 1052), sz, 5, false, false, 0, null_vector, 0);

	Animation jump0 = Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, 0, jump_lock, 0);
	Animation jumpMove0 = Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, 0, jump_lock_2, 0);
	Animation jumpFall = Animation(3, spriteSheet, Vector2<int>(3308, 3089), sz, 5, false, true, 0, jump_lock_fall, 0);

	Animation kick0 = Animation(7, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, false, 0, null_vector, 0);
	Animation kickUp0 = Animation(7, spriteSheet, Vector2<int>(2372, 2046), sz, 5, false, false, 0, null_vector, 0);
	Animation kickDown0 = Animation(8, spriteSheet, Vector2<int>(1904, 1574), sz, 5, false, false, 0, null_vector, 0);
	Animation kickFromDown0 = Animation(5, spriteSheet, Vector2<int>(2840, 2568), sz, 5, false, false, 0, null_vector, 0);
	Animation kickFromUp0 = Animation(5, spriteSheet, Vector2<int>(1904, 3090), sz, 5, false, true, 0, punchOrKickAir_lock, 0);

	Animation duck0 = Animation(5, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, 0, duck_lock, 0);

	Animation blockUp0 = Animation(5, spriteSheet, Vector2<int>(32, 6122), sz, 5, false, true, 0, blockUp_lock, 0);
	Animation blockDown0 = Animation(2, spriteSheet, Vector2<int>(1436, 6122), sz, 5, false, true, 0, blockDown_lock, 0);

	Animation special0 = Animation(8, spriteSheet, Vector2<int>(32, 6644), sz, 5, false, true, 0, null_vector, 0);
	Animation fatality0 = Animation(14, spriteSheet, Vector2<int>(32, 7688), sz, 5, false, true, 0, null_vector, 0);
	Animation win0 = Animation(14, spriteSheet, Vector2<int>(32, 8210), sz, 5, false, true, 0, win_lock, 0);

	Animation fall0 = Animation(7, spriteSheet, Vector2<int>(32, 4606), sz, 5, false, true, 0, null_vector, 0);
	Animation fallBack0 = Animation(6, spriteSheet, Vector2<int>(32, 5078), sz, 5, false, true, 0, fallBack_lock, 0);		// Al morir sin fatality
	Animation fallUppercut0 = Animation(8, spriteSheet, Vector2<int>(1904, 4606), sz, 5, false, true, 0, null_vector, 0);
	Animation nuts0 = Animation(4, spriteSheet, Vector2<int>(4010, 4606), sz, 5, false, true, 0, null_vector, 0);
	Animation recover0 = Animation(7, spriteSheet, Vector2<int>(1670, 5078), sz, 5, false, true, 0, null_vector, 0);

	Animation getCaught0 = Animation(7, spriteSheet, Vector2<int>(1904, 5600), sz, 5, false, true, 0, null_vector, 0);
	Animation catch0 = Animation(7, spriteSheet, Vector2<int>(32, 5600), sz, 5, false, true, 0, null_vector, 0);
	Animation dying0 = Animation(7, spriteSheet, Vector2<int>(32, 7166), sz, 5, false, true, 0, null_vector, 0);

	AnimationGroup idle = AnimationGroup(idle0);
	AnimationGroup forwWalk = AnimationGroup(forw0);
	AnimationGroup backWalk = AnimationGroup(back0);
	AnimationGroup punch = AnimationGroup(punch0);
	AnimationGroup punchUp = AnimationGroup(punchUp0);
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
	AnimationGroup punchDown = AnimationGroup(punchDown0);
	AnimationGroup duck = AnimationGroup(duck0);
	AnimationGroup blockUp = AnimationGroup(blockUp0);
	AnimationGroup blockDown = AnimationGroup(blockDown0);
	AnimationGroup special = AnimationGroup(special0);
	AnimationGroup fatality = AnimationGroup(fatality0);
	AnimationGroup win = AnimationGroup(win0);
	AnimationGroup fall = AnimationGroup(fall0);
	AnimationGroup fallBack = AnimationGroup(fallBack0);
	AnimationGroup fallUppercut = AnimationGroup(fallUppercut0);
	AnimationGroup recover = AnimationGroup(recover0);
	AnimationGroup nuts = AnimationGroup(nuts0);
	AnimationGroup getCaught = AnimationGroup(getCaught0);
	AnimationGroup catchAnim = AnimationGroup(catch0);
	AnimationGroup dying = AnimationGroup(dying0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0) };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0) };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0) };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0) };
	Movement punchUpMov = Movement{ punchUp, Vector2<float>(0.0, 0.0) };
	Movement punchFromUpMov = Movement{ punchFromUp, Vector2<float>(0.0, 0.0) };
	Movement bodyToBodyMov = Movement{ bodyToBody, Vector2<float>(0.0, 0.0) };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0) };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0) };
	Movement kickUpMov = Movement{ kickUp, Vector2<float>(0.0, 0.0) };
	Movement kickDownMov = Movement{ kickDown, Vector2<float>(0.0, 0.0) };
	Movement kickFromDownMov = Movement{ kickFromDown, Vector2<float>(0.0, 0.0) };
	Movement kickFromUpMov = Movement{ kickFromUp, Vector2<float>(0.0, 0.0) };
	Movement punchDownMov = Movement{ punchDown, Vector2<float>(0.0, 0.0) };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0) };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0) };
	Movement blockUpMov = Movement{ blockUp, Vector2<float>(0.0,0.0) };
	Movement blockDownMov = Movement{ blockDown, Vector2<float>(0.0,0.0) };
	Movement specialMov = Movement{ special, Vector2<float>(0.0,0.0) };
	Movement fatalityMov = Movement{ fatality, Vector2<float>(0.0,0.0) };
	Movement winMov = Movement{ win, Vector2<float>(0.0,0.0) };
	Movement fallMov = Movement{ fall, Vector2<float>(0.0, 0.0) };
	Movement fallBackMov = Movement{ fallBack, Vector2<float>(0.0, 0.0) };
	Movement fallUppercutMov = Movement{ fallUppercut, Vector2<float>(0.0, 0.0) };
	Movement nutsMov = Movement{ nuts, Vector2<float>(0.0, 0.0) };
	Movement recoverMov = Movement{ recover, Vector2<float>(0.0, 0.0) };
	Movement getCaughtMov = Movement{ getCaught, Vector2<float>(5.0, 0.0) };
	Movement catchMov = Movement{ catchAnim, Vector2<float>(0.0, 0.0) };
	Movement dyingMov = Movement{ dying, Vector2<float>(0.0, 0.0) };

	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::PUNCH_UPPER] = punchUpMov;
	animations[AnimationType::PUNCH_FROM_AIR] = punchFromUpMov;
	animations[AnimationType::PUNCH_CLOSE] = bodyToBodyMov;
	animations[AnimationType::JUMP] = jumpMov;
	animations[AnimationType::JUMP_AND_MOVE] = jumpMoveMov;
	animations[AnimationType::KICK] = kickMov;
	animations[AnimationType::KICK_LOW] = kickDownMov;
	animations[AnimationType::KICK_UPPER] = kickUpMov;
	animations[AnimationType::KICK_FROM_DOWN] = kickFromDownMov;
	animations[AnimationType::KICK_FROM_AIR] = kickFromUpMov;
	animations[AnimationType::PUNCH_FROM_DOWN] = punchDownMov;
	animations[AnimationType::DOWN] = duckMov;
	animations[AnimationType::BLOCK] = blockUpMov;
	animations[AnimationType::BLOCK_LOW] = blockDownMov;
	animations[AnimationType::SPECIAL] = specialMov;
	animations[AnimationType::FATALITY] = fatalityMov;
	animations[AnimationType::WIN] = winMov;
	animations[AnimationType::FALL] = fallMov;
	animations[AnimationType::RECOVER] = recoverMov;
	animations[AnimationType::FALL_UPPERCUT] = fallUppercutMov;
	animations[AnimationType::NUTS] = nutsMov;
	animations[AnimationType::FALL_BACK] = fallBackMov;
	animations[AnimationType::GET_CAUGHT] = getCaughtMov;
	animations[AnimationType::CATCH] = catchMov;
	animations[AnimationType::DYING] = dyingMov;

	Vector2f idleS[8] = { { 72, 123}, { 70,126}, {74,130}, {74,127}, {74,124}, {74,126}, {74,131}, {71,127} };
	Vector2f forwS[9] = { {71,131}, {55,135}, {56,132}, {52,132}, {56,128}, {60,133}, {53,134}, {53,134}, {62,128} };
	Vector2f backS[9] = { {62,128}, {53,134}, {53,134}, {60,133}, {56,128}, {52,132}, {56,132}, {55,135}, {71,131} };

	Vector2f punchS[4] = { {72,137}, {81,139}, {115,130}, {73,136} };
	Vector2f punchUpS[4] = { {73,135}, {80,137}, {106,137}, {71,137} };
	Vector2f punchDownS[5] = { {73,110}, {89,125}, {92,136}, {54,149}, {86,129} };
	Vector2f punchFromUpS[5] = { {73,84}, {104,78}, {145,82}, {104,77}, {73,84} };
	Vector2f bodyToBodyS[5] = { {84,134}, {73,131}, {88,128}, {74,131}, {84,135} };

	Vector2f jumpS[4] = { {74,102}, {75,102}, {71,142 }, { 77,119 } };
	Vector2f jumpMoveS[7] = { {50,70}, {62,64}, {70,43}, {63,59}, {46,69}, {60,64}, {64,60} };

	Vector2f kickS[7] = { {68,135}, {62,133}, {58,131}, {109,130}, {57,132}, {61,136}, {65,133} };
	Vector2f kickUpS[7] = { {94,133}, {77,130}, {58,119}, {89,134}, {52,110}, {55,104}, {66,128} };
	Vector2f kickDownS[8] = { {68,133}, {78,89}, {70,65}, {101,62}, {124,60}, {51,89}, {89,102}, {70,135} };
	Vector2f kickFromDownS[5] = { {62,80}, {84,76}, {87,91}, {85,77}, {62,79} };
	Vector2f kickFromUpS[5] = { {78,78}, {90,79}, {110,74}, {91,77}, {77,79} };

	Vector2f duckS[5] = { {72,118}, {76,91}, {72,77}, {76,90}, {71,118} };

	Vector2f blockUpS[5] = { {77,132}, {75,135}, {74,132}, {75,134}, {76,132} };
	Vector2f blockDownS[2] = { {68,97}, {69,98} };

	Vector2f specialS[8] = { {85,118}, {78,104}, {80,121}, {63,134}, {62,130}, {63,130}, {63,129}, {63,130} };

	Vector2f nutsS[4] = { {68,105}, {67,91}, {77,90}, {73,118} };

	Vector2f catchS[7] = { {92,128}, {106,112}, {90,126}, {86,144}, {74,157}, {86,138}, {93,110} };
	Vector2f dyingS[7] = { {70,122}, {71,121}, {70,127}, {70,134}, {70,135}, {71,133}, {71,121} };


	RectangleShape rect;
	vector<RectangleShape> idleR;
	for (Vector2f size : idleS) {
		rect.setSize(size);
		idleR.push_back(rect);
	}
	vector<RectangleShape> forwR;
	for (Vector2f size : forwS) {
		rect.setSize(size);
		forwR.push_back(rect);
	}
	vector<RectangleShape> backR;
	for (Vector2f size : backS) {
		rect.setSize(size);
		backR.push_back(rect);
	}

	vector<RectangleShape> punchR;
	for (Vector2f size : punchS) {
		rect.setSize(size);
		punchR.push_back(rect);
	}
	vector<RectangleShape> punchUpR;
	for (Vector2f size : punchUpS) {
		rect.setSize(size);
		punchUpR.push_back(rect);
	}
	vector<RectangleShape> punchDownR;
	for (Vector2f size : punchDownS) {
		rect.setSize(size);
		punchDownR.push_back(rect);
	}
	vector<RectangleShape> punchFromUpR;
	for (Vector2f size : punchFromUpS) {
		rect.setSize(size);
		punchFromUpR.push_back(rect);
	}
	vector<RectangleShape> bodyToBodyR;
	for (Vector2f size : bodyToBodyS) {
		rect.setSize(size);
		bodyToBodyR.push_back(rect);
	}

	vector<RectangleShape> jumpR;
	for (Vector2f size : jumpS) {
		rect.setSize(size);
		jumpR.push_back(rect);
	}
	vector<RectangleShape> jumpMoveR;
	for (Vector2f size : jumpMoveS) {
		rect.setSize(size);
		jumpMoveR.push_back(rect);
	}

	vector<RectangleShape> kickR;
	for (Vector2f size : kickS) {
		rect.setSize(size);
		kickR.push_back(rect);
	}
	vector<RectangleShape> kickUpR;
	for (Vector2f size : kickUpS) {
		rect.setSize(size);
		kickUpR.push_back(rect);
	}
	vector<RectangleShape> kickDownR;
	for (Vector2f size : kickDownS) {
		rect.setSize(size);
		kickDownR.push_back(rect);
	}
	vector<RectangleShape> kickFromDownR;
	for (Vector2f size : kickFromDownS) {
		rect.setSize(size);
		kickFromDownR.push_back(rect);
	}
	vector<RectangleShape> kickFromUpR;
	for (Vector2f size : kickFromUpS) {
		rect.setSize(size);
		kickFromUpR.push_back(rect);
	}

	vector<RectangleShape> duckR;
	for (Vector2f size : duckS) {
		rect.setSize(size);
		duckR.push_back(rect);
	}

	vector<RectangleShape> blockUpR;
	for (Vector2f size : blockUpS) {
		rect.setSize(size);
		blockUpR.push_back(rect);
	}
	vector<RectangleShape> blockDownR;
	for (Vector2f size : blockDownS) {
		rect.setSize(size);
		blockDownR.push_back(rect);
	}

	vector<RectangleShape> specialR;
	for (Vector2f size : specialS) {
		rect.setSize(size);
		specialR.push_back(rect);
	}

	vector<RectangleShape> nutsR;
	for (Vector2f size : nutsS) {
		rect.setSize(size);
		nutsR.push_back(rect);
	}

	vector<RectangleShape> catchR;
	for (Vector2f size : catchS) {
		rect.setSize(size);
		catchR.push_back(rect);
	}
	vector<RectangleShape> dyingR;
	for (Vector2f size : dyingS) {
		rect.setSize(size);
		dyingR.push_back(rect);
	}

	map< AnimationType, vector<RectangleShape>> hitboxes;
	hitboxes[AnimationType::IDLE] = idleR;
	hitboxes[AnimationType::WALK_FORW] = forwR;
	hitboxes[AnimationType::WALK_BACK] = backR;

	hitboxes[AnimationType::PUNCH] = punchR;
	hitboxes[AnimationType::PUNCH_UPPER] = punchUpR;
	hitboxes[AnimationType::PUNCH_FROM_DOWN] = punchDownR;
	hitboxes[AnimationType::PUNCH_FROM_AIR] = punchFromUpR;
	hitboxes[AnimationType::PUNCH_CLOSE] = bodyToBodyR;

	hitboxes[AnimationType::JUMP] = jumpR;
	hitboxes[AnimationType::JUMP_AND_MOVE] = jumpMoveR;

	hitboxes[AnimationType::KICK] = kickR;
	hitboxes[AnimationType::KICK_UPPER] = kickUpR;
	hitboxes[AnimationType::KICK_LOW] = kickDownR;
	hitboxes[AnimationType::KICK_FROM_DOWN] = kickFromDownR;
	hitboxes[AnimationType::KICK_FROM_AIR] = kickFromUpR;

	hitboxes[AnimationType::DOWN] = duckR;

	hitboxes[AnimationType::BLOCK] = blockUpR;
	hitboxes[AnimationType::BLOCK_LOW] = blockDownR;

	hitboxes[AnimationType::SPECIAL] = specialR;

	hitboxes[AnimationType::NUTS] = nutsR;

	hitboxes[AnimationType::CATCH] = catchR;
	hitboxes[AnimationType::DYING] = dyingR;


	Character LiuKang = Character(animations, body, hitboxes);

	return LiuKang;
}

#endif //LIUKANG_H