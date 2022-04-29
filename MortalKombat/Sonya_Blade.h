#ifndef SonyaBlade_H
#define SonyaBlade_H

#include "Character.h"

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

	RectangleShape shadow = RectangleShape(Vector2<float>(229, 219));
	shadow.setSize(Vector2f(229 * 3, 219 * 3));

	vector<int> null_vector{};
	vector<int> jump_lock{ 1, 1 };
	vector<int> jump_lock_2{ 7 };
	vector<int> jump_lock_fall{ 3 };
	vector<int> duck_lock{ 2 };
	vector<int> blockUp_lock{ 3 };
	vector<int> blockDown_lock{ 2 };
	vector<int> win_lock{ 8 };
	vector<int> punchOrKickAir_lock{ 3, 3 };
	vector<int> fallBack_lock{ 6 };

	vector<Recover> punchRecovery{ {1, 1} };
	vector<Recover> kickUpRecovery{ {3, 2} };
	vector<Recover> noRecovery{};

	//(int _duration, Texture* _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames) {
	Animation idle0 = Animation(7, spriteSheet, Vector2<int>(32, 58), sz, 5, false, false, noRecovery, null_vector, 3);
	Animation forw0 = Animation(9, spriteSheet, Vector2<int>(1904, 58), sz, 5, false, false, noRecovery, null_vector, 2);
	Animation back0 = Animation(9, spriteSheet, Vector2<int>(3776, 58), sz, 5, true, false, noRecovery, null_vector, 2);

	Animation punch0 = Animation(5, spriteSheet, Vector2<int>(32, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchMult0 = Animation(10, spriteSheet, Vector2<int>(1436, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchUp0 = Animation(5, spriteSheet, Vector2<int>(32, 1052), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchUpMult0 = Animation(10, spriteSheet, Vector2<int>(1436, 1052), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchDown0 = Animation(5, spriteSheet, Vector2<int>(968, 2568), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchFromUp0 = Animation(3, spriteSheet, Vector2<int>(500, 3090), sz, 5, false, true, noRecovery, punchOrKickAir_lock, 2);
	Animation bodyToBody0 = Animation(5, spriteSheet, Vector2<int>(4010, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation bodyToBodyUp0 = Animation(5, spriteSheet, Vector2<int>(4010, 1052), sz, 5, false, false, noRecovery, null_vector, 2);

	Animation jump0 = Animation(1, spriteSheet, Vector2<int>(32, 3090), sz, 5, false, true, noRecovery, jump_lock, 2);
	Animation jumpMove0 = Animation(7, spriteSheet, Vector2<int>(500, 3562), sz, 5, false, true, noRecovery, jump_lock_2, 0);
	//Animation jumpFall = Animation(3, spriteSheet, Vector2<int>(2372, 3090), sz, 5, false, true, noRecovery, jump_lock_fall, 2);

	Animation kick0 = Animation(9, spriteSheet, Vector2<int>(32, 1574), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickUp0 = Animation(7, spriteSheet, Vector2<int>(2372, 2046), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickDown0 = Animation(7, spriteSheet, Vector2<int>(2372, 1574), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickFromDown0 = Animation(6, spriteSheet, Vector2<int>(2372, 2568), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickFromUp0 = Animation(3, spriteSheet, Vector2<int>(1436, 3090), sz, 5, false, true, noRecovery, punchOrKickAir_lock, 2);

	Animation duck0 = Animation(3, spriteSheet, Vector2<int>(32, 2568), sz, 5, false, true, noRecovery, duck_lock, 2);

	Animation blockUp0 = Animation(5, spriteSheet, Vector2<int>(32, 6122), sz, 5, false, true, noRecovery, blockUp_lock, 2);
	Animation blockDown0 = Animation(2, spriteSheet, Vector2<int>(1436, 6122), sz, 5, false, true, noRecovery, blockDown_lock, 2);

	Animation special0 = Animation(5, spriteSheet, Vector2<int>(32, 6644), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation fatality0 = Animation(11, spriteSheet, Vector2<int>(32, 7688), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation win0 = Animation(8, spriteSheet, Vector2<int>(32, 8782), sz, 5, false, true, noRecovery, win_lock, 2);

	Animation fall0 = Animation(6, spriteSheet, Vector2<int>(32, 4606), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation fallBack0 = Animation(6, spriteSheet, Vector2<int>(32, 5078), sz, 5, false, true, noRecovery, fallBack_lock, 2);		// Al morir sin fatality
	Animation fallUppercut0 = Animation(7, spriteSheet, Vector2<int>(1670, 4606), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation nuts0 = Animation(3, spriteSheet, Vector2<int>(1202, 4084), sz, 5, false, true, noRecovery, null_vector, 2);			//No tiene NUTS !!!
	Animation recover0 = Animation(5, spriteSheet, Vector2<int>(1670, 5078), sz, 5, false, true, noRecovery, null_vector, 2);

	Animation getCaught0 = Animation(7, spriteSheet, Vector2<int>(1904, 5600), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation catch0 = Animation(7, spriteSheet, Vector2<int>(32, 5600), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation dying0 = Animation(7, spriteSheet, Vector2<int>(32, 7166), sz, 5, false, true, noRecovery, null_vector, 2);

	Animation turnLeft0 = Animation(3, spriteSheet, Vector2<int>(2372, 6122), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation turnRight0 = Animation(3, spriteSheet, Vector2<int>(3308, 6122), sz, 5, false, true, noRecovery, null_vector, 2);


	AnimationGroup idle = AnimationGroup(idle0);
	AnimationGroup forwWalk = AnimationGroup(forw0);
	AnimationGroup backWalk = AnimationGroup(back0);
	AnimationGroup punch = AnimationGroup(punch0);
	AnimationGroup punchMult = AnimationGroup(punchMult0);
	AnimationGroup punchUpMult = AnimationGroup(punchUpMult0);
	AnimationGroup punchUp = AnimationGroup(punchUp0);
	AnimationGroup punchFromUp = AnimationGroup(punchFromUp0);
	AnimationGroup bodyToBody = AnimationGroup(bodyToBody0);
	AnimationGroup jump = AnimationGroup(jump0);
	AnimationGroup jumpMove = AnimationGroup(jumpMove0);
	jumpMove.AddAnimation(jumpMove0);
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
	AnimationGroup turnLeft = AnimationGroup(turnLeft0);
	AnimationGroup turnRight = AnimationGroup(turnRight0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0), { 68 * 3,69 * 3,66 * 3,65 * 3,65 * 3,65 * 3,65 * 3,69 * 3}, { 60 * 3,57 * 3,54 * 3,58 * 3,61 * 3,58 * 3,54 * 3,57 * 3 } };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0), {76 * 3,90 * 3,91 * 3,95 * 3,91 * 3,87 * 3,93 * 3,93 * 3,89 * 3}, {53 * 3,49 * 3,51 * 3,50 * 3,54 * 3,50 * 3,50 * 3,50 * 3,55 * 3} };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0), {76 * 3,89 * 3,90 * 3,94 * 3,90 * 3,86 * 3,93 * 3,93 * 3,88 * 3}, {52 * 3,48 * 3,50 * 3,50 * 3,53 * 3,49 * 3,50 * 3,49 * 3,54 * 3} };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0), {67 * 3,69 * 3,70 * 3,66 * 3}, {48 * 3,45 * 3,51 * 3,48 * 3} };
	Movement punchMultMov = Movement{ punchMult, Vector2<float>(0.0, 0.0), {67 * 3,69 * 3,70 * 3,77 * 3,78 * 3,70 * 3,78 * 3,78 * 3,65 * 3}, {49 * 3,45 * 3,50 * 3,47 * 3,48 * 3,55 * 3,49 * 3,47 * 3,49 * 3} };
	Movement punchUpMov = Movement{ punchUp, Vector2<float>(0.0, 0.0), {66 * 3,70 * 3,79 * 3,66 * 3}, {49 * 3,46 * 3,45 * 3,48 * 3} };
	Movement punchFromUpMov = Movement{ punchFromUp, Vector2<float>(0.0, 0.0), {94 * 3,78 * 3,50 * 3,78 * 3,94 * 3}, {30 * 3,31 * 3,28 * 3,31 * 3,30 * 3} };
	Movement punchUpMultMov = Movement{ punchUpMult, Vector2<float>(0.0, 0.0) };
	Movement bodyToBodyMov = Movement{ bodyToBody, Vector2<float>(0.0, 0.0), {67 * 3,69 * 3,74 * 3,69 * 3,67 * 3}, {51 * 3,53 * 3,55 * 3,53 * 3,50 * 3} };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0), {72 * 3}, {39 * 3} };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0), {72 * 3,90 * 3,92 * 3,91 * 3,92 * 3,91 * 3,73 * 3}, {50 * 3,47 * 3,49 * 3,50 * 3,49 * 3,46 * 3,50 * 3} };
	Movement kickUpMov = Movement{ kickUp, Vector2<float>(0.0, 0.0), {47 * 3,66 * 3,94 * 3,100 * 3,103 * 3,88 * 3,75 * 3}, {49 * 3,53 * 3,63 * 3,50 * 3,73 * 3,830 * 3,55 * 3} };
	Movement kickDownMov = Movement{ kickDown, Vector2<float>(0.0, 0.0), {72 * 3,64 * 3,74 * 3,79 * 3,85 * 3,93 * 3,60 * 3,70 * 3}, {50 * 3,94 * 3,123 * 3,129 * 3,128 * 3,123 * 3,81 * 3,49 * 3} };
	Movement kickFromDownMov = Movement{ kickFromDown, Vector2<float>(0.0, 0.0), {68 * 3,67 * 3,67 * 3,67 * 3,68 * 3}, {64 * 3,93 * 3,107 * 3,93 * 3,64 * 3} };
	Movement kickFromUpMov = Movement{ kickFromUp, Vector2<float>(0.0, 0.0), {81 * 3,81 * 3,82 * 3,81 * 3,80 * 3}, {37 * 3,43 * 3,43 * 3,43 * 3,37 * 3} };
	Movement punchDownMov = Movement{ punchDown, Vector2<float>(0.0, 0.0), {66 * 3,71 * 3,74 * 3,87 * 3,62 * 3}, {74 * 3,60 * 3,52 * 3,39 * 3,53 * 3} };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0), {103 * 3,100 * 3,92 * 3,92 * 3,109 * 3,99 * 3,110 * 3}, {45 * 3,51 * 3,54 * 3,49 * 3,31 * 3,32 * 3,43 * 3} };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0), {68 * 3,67 * 3,67 * 3,67 * 3,68 * 3}, {64 * 3,92 * 3,107 * 3,93 * 3,64 * 3} };
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
	Movement turnLeftMov = Movement{ turnLeft, Vector2<float>(0.0, 0.0) };
	Movement turnRightMov = Movement{ turnRight, Vector2<float>(0.0, 0.0) };


	map<AnimationType, Movement> animations;
	animations[AnimationType::IDLE] = idleMov;
	animations[AnimationType::WALK_FORW] = forwMov;
	animations[AnimationType::WALK_BACK] = backMov;
	animations[AnimationType::PUNCH] = punchMov;
	animations[AnimationType::PUNCH_MULTIPLE] = punchMultMov;
	animations[AnimationType::PUNCH_UPPER] = punchUpMov;
	animations[AnimationType::PUNCH_UPPER_MULTIPLE] = punchUpMultMov;
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
	animations[AnimationType::TURN_LEFT] = turnLeftMov;
	animations[AnimationType::TURN_RIGHT] = turnRightMov;


	//Tama�os hitboxes
	Vector2f idleS[8] = { { 72 * 3, 123 * 3}, { 70 * 3,126 * 3}, {74 * 3,130 * 3}, {74 * 3,127 * 3}, {74 * 3,124 * 3}, {74 * 3,126 * 3}, {74 * 3,131 * 3}, {71 * 3,127 * 3} };
	Vector2f forwS[9] = { {71 * 3,131 * 3}, {55 * 3,135 * 3}, {56 * 3,132 * 3}, {52 * 3,132 * 3}, {56 * 3,128 * 3}, {60 * 3,133 * 3}, {53 * 3,134 * 3}, {53 * 3,134 * 3}, {62 * 3,128 * 3} };
	Vector2f backS[9] = { {62 * 3,128 * 3}, {53 * 3,134 * 3}, {53 * 3,134 * 3}, {60 * 3,133 * 3}, {56 * 3,128 * 3}, {52 * 3,132 * 3}, {56 * 3,132 * 3}, {55 * 3,135 * 3}, {71 * 3,131 * 3} };

	Vector2f punchS[4] = { {72 * 3,137 * 3}, {81 * 3,139 * 3}, {115 * 3,130 * 3}, {73 * 3,136 * 3} };
	Vector2f punchUpS[4] = { {73 * 3,135 * 3}, {80 * 3,137 * 3}, {106 * 3,137 * 3}, {71 * 3,137 * 3} };
	Vector2f punchDownS[5] = { {73 * 3,110 * 3}, {89 * 3,125 * 3}, {92 * 3,136 * 3}, {54 * 3,149 * 3}, {86 * 3,129 * 3} };
	Vector2f punchFromUpS[5] = { {73 * 3,84 * 3}, {104 * 3,78 * 3}, {145 * 3,82 * 3}, {104 * 3,77 * 3}, {73 * 3,84 * 3} };
	Vector2f bodyToBodyS[5] = { {84 * 3,134 * 3}, {73 * 3,131 * 3}, {88 * 3,128 * 3}, {74 * 3,131 * 3}, {84 * 3,135 * 3} };
	Vector2f punchMultS[9] = { {70 * 3,34 * 3}, {81 * 3,139 * 3}, {115 * 3,131 * 3}, {88 * 3,136 * 3}, {80 * 3,137 * 3}, {114 * 3,127 * 3}, {80 * 3,134 * 3}, {81 * 3,137 * 3}, {72 * 3,137 * 3} };

	Vector2f jumpS[4] = { {74 * 3,102 * 3}, {75 * 3,102 * 3}, {71 * 3,142 * 3 }, { 77 * 3,119 * 3 } };
	Vector2f jumpMoveS[7] = { {50 * 3,70 * 3}, {62 * 3,64 * 3}, {70 * 3,43 * 3}, {63 * 3,59 * 3}, {46 * 3,69 * 3}, {60 * 3,64 * 3}, {64 * 3,60 * 3} };

	Vector2f kickS[7] = { {68 * 3,135 * 3}, {62 * 3,133 * 3}, {58 * 3,131 * 3}, {109 * 3,130 * 3}, {57 * 3,132 * 3}, {61 * 3,136 * 3}, {65 * 3,133 * 3} };
	Vector2f kickUpS[7] = { {94 * 3,133 * 3}, {77 * 3,130 * 3}, {58 * 3,119 * 3}, {89 * 3,134 * 3}, {52 * 3,110 * 3}, {55 * 3,104 * 3}, {66 * 3,128 * 3} };
	Vector2f kickDownS[8] = { {68 * 3,133 * 3}, {78,89 * 3}, {70 * 3,65 * 3}, {101 * 3,62 * 3}, {124 * 3,60 * 3}, {51 * 3,89 * 3}, {89 * 3,102 * 3}, {70 * 3,135 * 3} };
	Vector2f kickFromDownS[5] = { {62 * 3,80 * 3}, {84 * 3,76 * 3}, {87 * 3,91 * 3}, {85 * 3,77 * 3}, {62 * 3,79 * 3} };
	Vector2f kickFromUpS[5] = { {78 * 3,78 * 3}, {90 * 3,79 * 3}, {110 * 3,74 * 3}, {91 * 3,77 * 3}, {77 * 3,79 * 3} };

	Vector2f duckS[5] = { {72 * 3,118 * 3}, {76 * 3,91 * 3}, {72 * 3,77 * 3}, {76 * 3,90 * 3}, {71 * 3,118 * 3} };

	Vector2f blockUpS[5] = { {77 * 3,132 * 3}, {75 * 3,135 * 3}, {74 * 3,132 * 3}, {75 * 3,134 * 3}, {76 * 3,132 * 3} };
	Vector2f blockDownS[2] = { {68 * 3,97 * 3}, {69 * 3,98 * 3} };

	Vector2f specialS[8] = { {85 * 3,118 * 3}, {78 * 3,104 * 3}, {80 * 3,121 * 3}, {63 * 3,134 * 3}, {62 * 3,130 * 3}, {63 * 3,130 * 3}, {63 * 3,129 * 3}, {63 * 3,130 * 3} };

	Vector2f nutsS[4] = { {68 * 3,105 * 3}, {67 * 3,91 * 3}, {77 * 3,90 * 3}, {73 * 3,118 * 3} };

	Vector2f catchS[7] = { {92 * 3,128 * 3}, {106 * 3,112 * 3}, {90 * 3,126 * 3}, {86 * 3,144 * 3}, {74 * 3,157 * 3}, {86 * 3,138 * 3}, {93 * 3,110 * 3} };
	Vector2f dyingS[7] = { {70 * 3,122 * 3}, {71 * 3,121 * 3}, {70 * 3,127 * 3}, {70 * 3,134 * 3}, {70 * 3,135 * 3}, {71 * 3,133 * 3}, {71 * 3,121 * 3} };

	RectangleShape rect;
	rect.setFillColor(Color::Green);
	vector<RectangleShape> idleR;
	int i = 0;
	for (Vector2f size : idleS) {
		//rect.setOrigin(animations);
		rect.setSize(size);
		idleR.push_back(rect);
		i++;
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
	vector<RectangleShape> punchMultR;
	for (Vector2f size : punchMultS) {
		rect.setSize(size);
		punchMultR.push_back(rect);
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
	hitboxes[AnimationType::PUNCH_MULTIPLE] = punchMultR;

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


	RectangleShape specialAtt = RectangleShape(Vector2<float>(68, 11));
	specialAtt.setSize(Vector2f(68 * 3, 11 * 3));

	map< AnimationType, vector<RectangleShape>> damage_hitboxes;
	Character SonyaBlade = Character(animations, body, shadow, hitboxes, damage_hitboxes);

	return SonyaBlade;
}

#endif
