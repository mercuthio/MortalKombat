#ifndef LiuKang_H
#define LiuKang_H

#include "Character.h"


struct rectValues {
	float left;
	float top;
	float width;
	float height;
};


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
	Movement punchFromUpMov = Movement{punchFromUp, Vector2<float>(0.0, 0.0) };
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
	
	/*
	float left;
	float top;
	float width;
	float height;
	*/
	/*
	rectValues idle0[8] = { { 99,117, 72, 123}, {334,113, 70,126}, {564,111,74,130}, {797,114,74,127}, {1031,118,74,124}, {1266,114,74,126}, {1500,110,74,131}, {1739,113,71,127} };
	rectValues forw0[9] = { {2213,110,71,131}, {2461,106,55,135}, {2696,108,56,132}, {2934,107,52,132}, {3164,111,56,128}, {3394,107,60,133}, {3868,107,53,134}, {3868,107,53,134}, {4098,112,62,128} };
	rectValues back0[9] = { {4098,112,62,128}, {3868,107,53,134}, {3868,107,53,134}, {3394,107,60,133}, {3164,111,56,128}, {2934,107,52,132}, {2696,108,56,132}, {2461,106,55,135}, {2213,110,71,131} };

	rectValues punch0[4] = { {98,627,72,137}, {335,625,81,139}, {569,630,115,130}, {799,628,73,136} };
	rectValues punchUp0[4] = { {}, {}, {}, {} };
	rectValues punchDown0[5] = { {1501,2641,73,110}, {1740,2627,89,125}, {1977,2619,92,136}, {2224,2606,54,149}, {2433,2620,86,129} };
	rectValues punchFromUp0[5] = { {2465,3591,73,84}, {2683,3592,104,78}, {2889,3589,145,82}, {3151,3592,104,77}, {3401,3591,73,84} };
	rectValues bodyToBody0[5] = { {3608,630,84,134}, {3844,632,73,131}, {4083,634,88,128}, {4312,632,74,131}, {4544,629,84,135} };
	rectValues bodyToBodyUp0[5] = { {}, {}, {}, {}, {} };

	rectValues jump0[1] = { {103,3128,74,102} };
	rectValues jumpMove0[7] = { {603,3607,50,70}, {833,3612,62,64}, {1059,3615,70,43}, {1293,3610,63,59}, {1544,3592,46,69}, {1768,3593,60,64}, {2013,3604,64,60} };
	rectValues jumpFall[3] = { {3378,3127,75,102}, {3614,3130,71,142}, {3842,3154,77,119} };

	rectValues kick0[7] = { {103,1623,68,135}, {355,1620,62,133}, {591,1622,58,131}, {825,1623,109,130}, {1059,1622,57,132}, {1292,1619,61,136}, {1508,1623,65,133} };
	rectValues kickUp0[7] = { {2418,2904,94,133}, {2671,2098,77,130}, {2934,2108,58,119}, {3173,2095,89,134}, {3410,2119,52,110}, {3629,2125,55,104}, {3850,2100,66,128} };
	rectValues kickDown0[8] = { {1975,1623,68,133}, {2201,1667,78,89}, {2446,1696,70,65}, {2684,1702,101,62}, {2924,1701,124,60}, {3166,1696,51,89}, {3367,1654,89,102}, {3611,1622,70,135} };
	rectValues kickFromDown0[5] = { {2914,2671,62,80}, {3151,2672,84,76}, {3385,2659,87,91}, {3618,2672,85,77}, {3850,2671,62,79} };
	rectValues kickFromUp0[5] = { {3873,3597,78,78}, {4107,3597,90,79}, {4339,3598,110,74}, {4575,3597,91,77}, {4810,3597,77,79} };

	rectValues duck0[5] = { {99,2632,72,118}, {332,2660,76,91}, {566,2674,72,77}, {800,2660,76,90}, {1035,2631,71,118} };

	rectValues blockUp0[5] = { {100,6172,77,132}, {331,6170,75,135}, {563,6172,74,132}, {799,6170,75,134}, {1037,6172,76,132} };
	rectValues blockDown0[2] = { {1505,6209,68,97}, {1739,6207,69,98} };

	rectValues special0[8] = { {86,6710,85,118}, {327,6723,78,104}, {561,6706,80,121}, {794,6694,63,134}, {1025,6697,62,130}, {1258,6699,63,130}, {1492,6699,63,129}, {1726,6698,63,130} };
	
	rectValues fall0[7] = { {}, {}, {}, {}, {}, {}, {} };
	rectValues fallBack0[6] = { {}, {}, {}, {}, {}, {} };
	rectValues fallUppercut0[8] = { {}, {}, {}, {}, {}, {}, {}, {} };
	rectValues nuts0[4] = { {}, {}, {}, {} };
	rectValues recover0[7] = { {}, {}, {}, {}, {}, {}, {} };

	rectValues getCaught0[7] = { {}, {}, {}, {}, {}, {}, {} };
	rectValues catch0[7] = { {}, {}, {}, {}, {}, {}, {} };
	rectValues dying0[7] = { {}, {}, {}, {}, {}, {}, {} };


	RectangleShape rect;
	IntRect uvRect;
	vector<RectangleShape> hitboxes;
	

	for (int i = 0; i < ; i++) {

	}

	*/
	Character LiuKang = Character(animations, body);

	return LiuKang;
}

#endif //LIUKANG_H