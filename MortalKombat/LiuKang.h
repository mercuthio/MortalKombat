#ifndef LiuKang_H
#define LiuKang_H

#include "Character.h"

static Character CreateLiuKang() {

	Texture* spriteSheet = new Texture();
	Image spriteSheetImage;
	Color back = Color(165, 231, 255, 255);

	spriteSheetImage.loadFromFile("resources/Sprites/Personajes/Liu_Kang.png");
	spriteSheetImage.createMaskFromColor(back);

	spriteSheet->loadFromImage(spriteSheetImage);

	Texture* spriteSheetP2 = new Texture();
	Image spriteSheetImageP2;

	spriteSheetImageP2.loadFromFile("resources/Sprites/Personajes/Liu_Kang2.png");
	spriteSheetImageP2.createMaskFromColor(back);

	spriteSheetP2->loadFromImage(spriteSheetImageP2);

	Vector2<int> sz = Vector2<int>(229, 219);
	RectangleShape body = RectangleShape(Vector2<float>(229, 219));
	body.setSize(Vector2f(229 * 3, 219 * 3));

	RectangleShape shadow = RectangleShape(Vector2<float>(229, 219));
	shadow.setSize(Vector2f(229 * 3, 219 * 3));

	vector<int> null_vector{};
	vector<int> jump_lock{ 1, 1 };
	vector<int> jump_lock_2{ 7, 7 };
	vector<int> jump_lock_fall{ 1 };
	vector<int> duck_lock{ 3 };
	vector<int> blockUp_lock{ 3 };
	vector<int> blockDown_lock{ 2 };
	vector<int> win_lock{ 14 };
	vector<int> punchOrKickAir_lock{ 5, 5 };
	vector<int> fallBack_lock{ 6 };
	vector<int> fall_lock{ 3, 7, 7 };

	vector<Recover> punchRecovery{ {1, 1} };
	vector<Recover> kickUpRecovery{ {3, 2} };
	vector<Recover> catchRecovery{ {1, 7} };
	vector<Recover> noRecovery{};


	Animation idle0 = Animation(8, spriteSheet, spriteSheetP2, Vector2<int>(32, 58), sz, 5, false, false, noRecovery, null_vector, 3);
	Animation forw0 = Animation(9, spriteSheet, spriteSheetP2, Vector2<int>(2138, 58), sz, 5, false, false, noRecovery, null_vector, 2);
	Animation back0 = Animation(9, spriteSheet, spriteSheetP2, Vector2<int>(4010, 58), sz, 5, true, false, noRecovery, null_vector, 2);

	Animation punch0 = Animation(4, spriteSheet, spriteSheetP2, Vector2<int>(32, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchMult0 = Animation(9, spriteSheet, spriteSheetP2, Vector2<int>(1202, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchUp0 = Animation(4, spriteSheet, spriteSheetP2, Vector2<int>(32, 1052), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchUpMult0 = Animation(9, spriteSheet, spriteSheetP2, Vector2<int>(1202, 1052), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchDown0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(1436, 2568), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation punchFromUp0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(500, 3090), sz, 5, false, true, noRecovery, punchOrKickAir_lock, 2);
	Animation bodyToBody0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(3542, 580), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation bodyToBodyUp0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(3542, 1052), sz, 5, false, false, noRecovery, null_vector, 2);

	Animation jump0 = Animation(1, spriteSheet, spriteSheetP2, Vector2<int>(32, 3090), sz, 5, false, true, noRecovery, jump_lock, 2);
	Animation jumpMove0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(500, 3562), sz, 5, false, true, noRecovery, null_vector, 0);
	Animation jumpMove1 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(500, 3562), sz, 5, false, true, noRecovery, jump_lock_2, 0);
	Animation jumpFall0 = Animation(1, spriteSheet, spriteSheetP2, Vector2<int>(32, 58), sz, 5, false, false, noRecovery, null_vector, 0);

	Animation kick0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(32, 1574), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickUp0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(2372, 2046), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickDown0 = Animation(8, spriteSheet, spriteSheetP2, Vector2<int>(1904, 1574), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickFromDown0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(2840, 2568), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation kickFromUp0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(1904, 3090), sz, 5, false, true, noRecovery, punchOrKickAir_lock, 2);

	Animation duck0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(32, 2568), sz, 5, false, true, noRecovery, duck_lock, 2);

	Animation blockUp0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(32, 6122), sz, 5, false, true, noRecovery, blockUp_lock, 2);
	Animation blockDown0 = Animation(2, spriteSheet, spriteSheetP2, Vector2<int>(1436, 6122), sz, 5, false, true, noRecovery, blockDown_lock, 2);

	Animation special0 = Animation(8, spriteSheet, spriteSheetP2, Vector2<int>(32, 6644), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation fatality0 = Animation(14, spriteSheet, spriteSheetP2, Vector2<int>(32, 7688), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation win0 = Animation(14, spriteSheet, spriteSheetP2, Vector2<int>(32, 8210), sz, 5, false, true, noRecovery, win_lock, 2);

	Animation fall0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(32, 4606), sz, 5, false, true, noRecovery, fall_lock, 2);
	Animation fallBack0 = Animation(6, spriteSheet, spriteSheetP2, Vector2<int>(32, 5078), sz, 5, false, true, noRecovery, fallBack_lock, 2);		// Al morir sin fatality
	Animation fallUppercut0 = Animation(8, spriteSheet, spriteSheetP2, Vector2<int>(1904, 4606), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation nuts0 = Animation(4, spriteSheet, spriteSheetP2, Vector2<int>(4010, 4606), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation recover0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(1670, 5078), sz, 5, false, true, noRecovery, null_vector, 2);

	Animation getCaught0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(1904, 5600), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation catch0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(32, 5600), sz, 5, false, true, punchRecovery, null_vector, 2);
	Animation dying0 = Animation(7, spriteSheet, spriteSheetP2, Vector2<int>(32, 7166), sz, 5, false, true, noRecovery, null_vector, 2);

	Animation turnLeft0 = Animation(3, spriteSheet, spriteSheetP2, Vector2<int>(2138, 6122), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation turnRight0 = Animation(3, spriteSheet, spriteSheetP2, Vector2<int>(3074, 6122), sz, 5, false, true, noRecovery, null_vector, 2);

	Animation hit0 = Animation(4, spriteSheet, spriteSheetP2, Vector2<int>(32, 4084), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation hitHard0 = Animation(5, spriteSheet, spriteSheetP2, Vector2<int>(2372, 4084), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation hitHead0 = Animation(4, spriteSheet, spriteSheetP2, Vector2<int>(1202, 4084), sz, 5, false, true, noRecovery, null_vector, 2);
	Animation hitDuck0 = Animation(3, spriteSheet, spriteSheetP2, Vector2<int>(3776, 4084), sz, 5, false, true, noRecovery, null_vector, 2);

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
	jump.AddAnimation(jumpFall0);
	AnimationGroup jumpMove = AnimationGroup(jumpMove0);
	jumpMove.AddAnimation(jumpMove1);
	jumpMove.AddAnimation(jumpFall0);
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
	AnimationGroup hit = AnimationGroup(hit0);
	AnimationGroup hitHard = AnimationGroup(hitHard0);
	AnimationGroup hitHead = AnimationGroup(hitHead0);
	AnimationGroup hitDuck = AnimationGroup(hitDuck0);

	Movement idleMov = Movement{ idle, Vector2<float>(0.0, 0.0), {83*3,85*3,81*3,83*3,82*3,83*3,84*3,83*3}, {59*3,54*3,51*3,56*3,59*3,57*3,52*3,54*3} };
	Movement forwMov = Movement{ forwWalk, Vector2<float>(15.0, 0.0), {93*3,96*3,98*3,98*3,99*3,98*3,98*3,95*3,95*3},{53*3,49*3,50*3,49*3,53*3,49*3,51*3,50*3,55*3} };
	Movement backMov = Movement{ backWalk, Vector2<float>(-10, 0.0), {93 * 3,96 * 3,98 * 3,98 * 3,99 * 3,98 * 3,98 * 3,95 * 3,95 * 3},{53 * 3,49 * 3,50 * 3,49 * 3,53 * 3,49 * 3,51 * 3,50 * 3,55 * 3} };
	Movement punchMov = Movement{ punch, Vector2<float>(0.0, 0.0),{92 * 3,102 * 3,108 * 3,92 * 3},{47 * 3,45 * 3,49 * 3,47 * 3},
		{0,0,149*3,0},{0,0,74*3,0} };
	Movement punchMultMov = Movement{ punchMult, Vector2<float>(0.0, 0.0),{91*3,97*3,103*3,116*3,114*3,117*3,110*3,112*3,92*3},{46*3,42*3,48*3,45*3,47*3,54*3,46*3,45*3,47*3},
		{0,0,150*3,0,0,157*3,0,0},{0,0,74*3,0,0,73*3,0,0} };
	Movement punchUpMov = Movement{ punchUp, Vector2<float>(0.0, 0.0), {94 * 3,104 * 3,111 * 3,94 * 3},{48 * 3,45 * 3,45 * 3,48 * 3},
		{0,0,153*3,0},{0,0,53*3,0}};
	Movement punchFromUpMov = Movement{ punchFromUp, Vector2<float>(0.0, 0.0), {113 * 3,122 * 3,117 * 3,123 * 3,120 * 3},{29 * 3,29 * 3,28 * 3,30 * 3,28 * 3},
		{0,0,170*3,0,0},{0,0,71*3,0,0} };
	Movement punchUpMultMov = Movement{ punchUpMult, Vector2<float>(0.0, 0.0), {97*3,101*3,112*3,113*3,117*3,112*3,117*3,113*3,94*3},{47*3,45*3,46*3,46*3,48*3,49*3,48*3,45*3,48*3},
		{0,0,153*3,0,0,155*3,0,0,0},{0,0,52*3,0,0,56*3,0,0,0} };
	Movement bodyToBodyMov = Movement{ bodyToBody, Vector2<float>(0.0, 0.0), {93 * 3,100 * 3,108 * 3,102 * 3,96 * 3},{49 * 3,52 * 3,54 * 3,52 * 3,50 * 3},
		{0,0,149*3,0,0},{0,0,67*3,0,0} };
	Movement jumpMov = Movement{ jump, Vector2<float>(0.0, 0.0), {80*3},{37*3} };
	Movement kickMov = Movement{ kick, Vector2<float>(0.0, 0.0),  {86*3,94*3,95*3,100*3,93*3,92*3,87*3},{48*3,46*3,49*3,50*3,49*3,47*3,49*3},
		{0,0,0,158*3,0,0,0},{0,0,0,64*3,0,0,0} };
	Movement kickUpMov = Movement{ kickUp, Vector2<float>(0.0, 0.0), {73*3,86*3,92*3,99*3,103*3,108*3,97*3},{48*3,52*3,63*3,48*3,87*3,76*3,52*3},
		{0,0,0,151*3,0,0,0},{0,0,0,44*3,0,0,0} };
	Movement kickDownMov = Movement{ kickDown, Vector2<float>(0.0, 0.0), {89*3,78*3,73*3,79*3,86*3,98*3,105*3,87*3},{49*3,95*3,119*3,125*3,124*3,121*3,79*3,48*3},
		{0,0,0,0,161*3,0,0,0},{0,0,0,0,157*3,0,0,0} };
	Movement kickFromDownMov = Movement{ kickFromDown, Vector2<float>(0.0, 0.0),{83*3,82*3,84*3,84*3,83*3},{102*3,104*3,109*3,105*3,104*3},
		{0,0,135*3,0,0},{0,0,91*3,0,0} };
	Movement kickFromUpMov = Movement{ kickFromUp, Vector2<float>(0.0, 0.0), {92*3,99*3,101*3,96*3,91*3},{37*3,41*3,43*3,42*3,37*3},
		{0,0,146*3,0,0},{0,0,48*3,0,0} };
	Movement punchDownMov = Movement{ punchDown, Vector2<float>(0.0, 0.0), {96*3,92*3,95*3,104*3,93*3},{74*3,58*3,50*3,51*3,53*3},
		{0,0,142*3,0,0},{0,0,52*3,0,0} };
	Movement jumpMoveMov = Movement{ jumpMove, Vector2<float>(0.0, 0.0),  {109*3,101*3,95*3,101*3,105*3,100*3,108*3},{44*3,50*3,52*3,46*3,37*3,48*3,44*3} };
	Movement duckMov = Movement{ duck, Vector2<float>(0.0,0.0),  {80 * 3, 84 * 3, 91 * 3, 86 * 3, 85 * 3},{63 * 3, 92 * 3, 104 * 3, 92 * 3, 63 * 3} };
	Movement blockUpMov = Movement{ blockUp, Vector2<float>(0.0,0.0), {91 * 3, 90 * 3, 87 * 3, 89 * 3, 91 * 3},{52 * 3, 52 * 3, 54 * 3, 52 * 3, 51 * 3} };
	Movement blockDownMov = Movement{ blockDown, Vector2<float>(0.0,0.0), {78 * 3, 72 * 3},{89 * 3, 87 * 3} };
	Movement specialMov = Movement{ special, Vector2<float>(0.0,0.0), {68*3,63*3,61*3,63*3,60*3,61*3,61*3,61*3},{68*3,79*3,64*3,51*3,56*3,55*3,56*3,56*3} };
	Movement fatalityMov = Movement{ fatality, Vector2<float>(0.0,0.0), {},{},{},{} };
	Movement winMov = Movement{ win, Vector2<float>(0.0,0.0)};
	Movement fallMov = Movement{ fall, Vector2<float>(0.0, 0.0) };
	Movement fallBackMov = Movement{ fallBack, Vector2<float>(0.0, 0.0) };
	Movement fallUppercutMov = Movement{ fallUppercut, Vector2<float>(0.0, 0.0) };
	Movement nutsMov = Movement{ nuts, Vector2<float>(0.0, 0.0), {84*3,81*3,84*3,84*3},{79*3,91*3,92*3,63*3} };
	Movement recoverMov = Movement{ recover, Vector2<float>(0.0, 0.0) };
	Movement getCaughtMov = Movement{ getCaught, Vector2<float>(5.0, 0.0) };
	Movement catchMov = Movement{ catchAnim, Vector2<float>(0.0, 0.0), {96*3,109*3,88*3,88*3,78*3,63*3,61*3},{55*3,72*3,58*3,53*3,50*3,58*3,73*3} };
	Movement dyingMov = Movement{ dying, Vector2<float>(0.0, 0.0), {94*3,101*3,96*3,88*3,83*3,81*3,89*3},{61*3,61*3,56*3,50*3,50*3,52*3,61*3} };

	Movement turnLeftMov = Movement{ turnLeft, Vector2<float>(0.0, 0.0), {88*3,88*3,91*3},{54*3,54*3,53*3} };
	Movement turnRightMov = Movement{ turnRight, Vector2<float>(0.0, 0.0), {92*3,92*3,87*3},{54*3,54*3,53*3} };

	Movement hitMov = Movement{ hit, Vector2<float>(0.0, 0.0), {81 * 3, 80 * 3, 75 * 3, 78 * 3},{53 * 3, 53 * 3, 55 * 3, 53 * 3} };
	Movement hitHardMov = Movement{ hitHard, Vector2<float>(0.0, 0.0), {77 * 3, 79 * 3, 86 * 3, 81 * 3, 85 * 3},{53 * 3, 43 * 3, 45 * 3, 47 * 3, 59 * 3} };
	Movement hitHeadMov = Movement{ hitHead, Vector2<float>(0.0, 0.0), {69 * 3, 77 * 3, 68 * 3, 79 * 3},{57 * 3, 47 * 3, 57 * 3, 45 * 3} };
	Movement hitDuckMov = Movement{ hitDuck, Vector2<float>(0.0, 0.0), {60 * 3, 64 * 3, 73 * 3},{89 * 3, 82 * 3, 87 * 3} };
	

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
	animations[AnimationType::HIT_STAND] = hitMov;
	animations[AnimationType::HIT_STAND_STRONG] = hitHardMov;
	animations[AnimationType::HIT_HEAD] = hitHeadMov;
	animations[AnimationType::HIT_DOWN] = hitDuckMov;
	animations[AnimationType::TURN_LEFT] = turnLeftMov;
	animations[AnimationType::TURN_RIGHT] = turnRightMov;
	
	//Tama�o damage hitboxes
	Vector2f punchD[4] = { {0,0},{0,0},{35*3,13*3},{0,0} };
	Vector2f punchUpD[4] = { {0,0},{0,0},{32*3,19*3},{0,0} };
	Vector2f punchDownD[5] = { {0,0},{0,0},{24*3,28*3},{0,0} };
	Vector2f punchFromUpD[5] = { {0,0},{0,0},{23*3,26*3},{0,0},{0,0} };
	Vector2f bodyToBodyD[5] = { {0,0},{0,0},{12*3,13*3},{0,0},{0,0} };
	Vector2f punchMultD[9] = { {0,0},{0,0},{35*3,13*3},{0,0},{0,0},{25*3,15*3},{0,0},{0,0},{0,0} };
	Vector2f punchMultUpD[9] = { {0,0},{0,0},{32*3,22*3},{0,0},{0,0},{29*3,17*3},{0,0},{0,0},{0,0} };

	Vector2f kickD[7] = { {0,0},{0,0},{0,0},{42*3,34*3},{0,0},{0,0},{0,0} };
	Vector2f kickUpD[7] = { {0,0},{0,0},{0,0},{37*3,35*3},{0,0},{0,0},{0,0} };
	Vector2f kickDownD[8] = { {0,0},{0,0},{0,0},{0,0},{47*3,30*3},{0,0},{0,0},{0,0} };
	Vector2f kickFromDownD[5] = { {0,0},{0,0},{29*3,41*3},{0,0},{0,0} };
	Vector2f kickFromUpD[5] = { {0,0},{0,0},{24*3,33*3},{0,0},{0,0} };


	RectangleShape rect;
	rect.setFillColor(Color::Red);
	
	vector<RectangleShape> punchR;
	for (Vector2f size : punchD) {
		rect.setSize(size);
		punchR.push_back(rect);
	}
	vector<RectangleShape> punchUpR;
	for (Vector2f size : punchUpD) {
		rect.setSize(size);
		punchUpR.push_back(rect);
	}
	vector<RectangleShape> punchUpMultR;
	for (Vector2f size : punchMultUpD) {
		rect.setSize(size);
		punchUpMultR.push_back(rect);
	}
	vector<RectangleShape> punchDownR;
	for (Vector2f size : punchDownD) {
		rect.setSize(size);
		punchDownR.push_back(rect);
	}
	vector<RectangleShape> punchFromUpR;
	for (Vector2f size : punchFromUpD) {
		rect.setSize(size);
		punchFromUpR.push_back(rect);
	}
	vector<RectangleShape> punchMultR;
	for (Vector2f size : punchMultD) {
		rect.setSize(size);
		punchMultR.push_back(rect);
	}
	vector<RectangleShape> bodyToBodyR;
	for (Vector2f size : bodyToBodyD) {
		rect.setSize(size);
		bodyToBodyR.push_back(rect);
	}

	vector<RectangleShape> kickR;
	for (Vector2f size : kickD) {
		rect.setSize(size);
		kickR.push_back(rect);
	}
	vector<RectangleShape> kickUpR;
	for (Vector2f size : kickUpD) {
		rect.setSize(size);
		kickUpR.push_back(rect);
	}
	vector<RectangleShape> kickDownR;
	for (Vector2f size : kickDownD) {
		rect.setSize(size);
		kickDownR.push_back(rect);
	}
	vector<RectangleShape> kickFromDownR;
	for (Vector2f size : kickFromDownD) {
		rect.setSize(size);
		kickFromDownR.push_back(rect);
	}
	vector<RectangleShape> kickFromUpR;
	for (Vector2f size : kickFromUpD) {
		rect.setSize(size);
		kickFromUpR.push_back(rect);
	}

	map< AnimationType, vector<RectangleShape>> damage_hitboxes;

	damage_hitboxes[AnimationType::PUNCH] = punchR;
	damage_hitboxes[AnimationType::PUNCH_UPPER] = punchUpR;
	damage_hitboxes[AnimationType::PUNCH_FROM_DOWN] = punchDownR;
	damage_hitboxes[AnimationType::PUNCH_FROM_AIR] = punchFromUpR;
	damage_hitboxes[AnimationType::PUNCH_CLOSE] = bodyToBodyR;
	damage_hitboxes[AnimationType::PUNCH_MULTIPLE] = punchMultR;
	damage_hitboxes[AnimationType::PUNCH_UPPER_MULTIPLE] = punchUpMultR;


	damage_hitboxes[AnimationType::KICK] = kickR;
	damage_hitboxes[AnimationType::KICK_UPPER] = kickUpR;
	damage_hitboxes[AnimationType::KICK_LOW] = kickDownR;
	damage_hitboxes[AnimationType::KICK_FROM_DOWN] = kickFromDownR;
	damage_hitboxes[AnimationType::KICK_FROM_AIR] = kickFromUpR;

	punchR.clear();
	punchUpR.clear();
	punchDownR.clear();
	punchFromUpR.clear();
	bodyToBodyR.clear();
	punchMultR.clear();
	punchUpMultR.clear();
	kickR.clear();
	kickUpR.clear();
	kickDownR.clear();
	kickFromDownR.clear();
	kickFromUpR.clear();


	//Tama�os hitboxes
	Vector2f idleS[8] = { {31*3,123*3}, {31*3,129*3}, {35*3,134*3}, {33*3,128*3}, {31*3,125*3}, {32*3,128*3}, {31*3,133*3}, {33*3,130*3} };
	Vector2f forwS[9] = { {35*3,129*3}, {27*3,134*3}, {28*3,134*3}, {32*3,133*3}, {29*3,129*3}, {27*3,134*3}, {30*3,132*3}, {34*3,134*3}, {34*3,127*3} };
	Vector2f backS[9] = { {35 * 3,129 * 3}, {27 * 3,134 * 3}, {28 * 3,134 * 3}, {32 * 3,133 * 3}, {29 * 3,129 * 3}, {27 * 3,134 * 3}, {30 * 3,132 * 3}, {34 * 3,134 * 3}, {34 * 3,127 * 3} };

	Vector2f punchS[4] = { {35*3,135*3},{34*3,138*3},{37*3,133*3},{38*3,138*3} };
	Vector2f punchUpS[4] = { {36*3,136*3},{34*3,139*3},{36*3,138*3},{41*3,136*3} };
	Vector2f punchDownS[5] = { {33*3,110*3},{35*3,124*3},{34*3,134*3},{26*3,136*3},{37*3,130*3} };
	Vector2f punchFromUpS[5] = { {45*3,81*3},{41*3,73*3},{52*3,72*3},{38*3,74*3},{43*3,81*3} };
	Vector2f bodyToBodyS[5] = { {41*3,136*3},{37*3,131*3},{40*3,128*3},{35*3,129*3},{39*3,135*3} };
	Vector2f punchMultS[9] = { {35*3,138*3},{37*3,141*3},{43*3,134*3},{31*3,136*3},{32*3,135*3},{37*3,128*3},{38*3,136*3},{35*3,138*3},{39*3,137*3} };
	Vector2f punchMultUpS[9] = { {32*3,138*3},{37*3,139*3},{36*3,137*3},{35*3,138*3},{33*3,136*3},{39*3,134*3},{33*3,136*3},{36*3,138*3},{36*3,136*3} };

	Vector2f jumpS[4] = { {53*3,103*3},{35*3,99*3},{36*3,132*3},{35*3,116*3} };
	Vector2f jumpMoveS[7] = { {45*3,71*3},{60*3,64*3},{66*3,51*3},{53*3,63*3},{50*3,62*3},{57*3,48*3},{48*3,61*3} };

	Vector2f kickS[7] = { {35*3,133*3},{31*3,136*3},{32*3,133*3},{33*3,130*3},{33*3,133*3},{35*3,135*3},{31*3,133*3} };
	Vector2f kickUpS[7] = { {42*3,134*3},{32*3,130*3},{37*3,120*3},{39*3,99*3},{35*3,96*3},{33*3,107*3},{40*3,131*3} };
	Vector2f kickDownS[8] = { {30*3,133*3},{33*3,89*3},{65*3,67*3},{51*3,63*3},{48*3,63*3},{40*3,91*3},{36*3,104*3},{35*3,131*3} };
	Vector2f kickFromDownS[5] = { {45*3,76*3},{49*3,77*3},{44*3,73*3},{40*3,77*3},{46*3,78*3} };
	Vector2f kickFromUpS[5] = { {30*3,141*3},{47*3,84*3},{43*3,72*3},{46*3,81*3},{39*3,120*3} };
	Vector2f duckS[5] = { {37 * 3,118 * 3}, {43 * 3,90 * 3}, {39 * 3,79 * 3}, {39 * 3,89 * 3}, {33 * 3,119 * 3} };

	Vector2f blockUpS[5] = { {31 * 3,128 * 3}, {35 * 3,130 * 3}, {35 * 3,127 * 3}, {34 * 3,131 * 3}, {32 * 3,130 * 3} };
	Vector2f blockDownS[2] = { {33 * 3,95 * 3}, {38 * 3,97 * 3} };

	Vector2f turnLeftS[3] = { {28 * 3,130 * 3}, {30 * 3,139 * 3}, {36 * 3,129 * 3} };
	Vector2f turnRightS[3] = { {31 * 3,129 * 3}, {30 * 3,130 * 3}, {31 * 3,130 * 3} };

	Vector2f nutsS[4] = { {40 * 3,105 * 3}, {41 * 3,92 * 3}, {39 * 3,91 * 3}, {31 * 3,119 * 3} };
	Vector2f hitS[4] = { {38 * 3,129 * 3}, {35 * 3,130 * 3}, {43 * 3,128 * 3}, {37 * 3,129 * 3} };
	Vector2f hitHeadS[4] = { {46 * 3,126 * 3}, {37 * 3,136 * 3}, {39 * 3,126 * 3}, {33 * 3,136 * 3} };
	Vector2f hitHardS[5] = { {31 * 3,128 * 3}, {33 * 3,141 * 3}, {33 * 3,136 * 3}, {37 * 3,133 * 3}, {35 * 3,123 * 3} };
	Vector2f hitDuckS[3] = { {49 * 3,95 * 3}, {43 * 3,101 * 3}, {38 * 3,96 * 3}};

	Vector2f specialS[8] = { {41*3,116*3}, {39*3,105*3}, {38*3,121*3}, {38*3,134*3}, {32*3,128*3}, {31*3,131*3}, {37*3,128*3}, {32*3,128*3} };

	Vector2f catchS[7] = { {36*3,127*3}, {38*3,110*3}, {48*3,125*3}, {39*3,131*3}, {33*3,131*3}, {34*3,117*3}, {42*3,110*3} };
	Vector2f dyingS[7] = { {39*3,121*3}, {36*3,123*3}, {35*3,126*3}, {35*3,132*3}, {35*3,134*3}, {31*3,131*3}, {34*3,122*3} };

	vector<RectangleShape> idleR;
	rect.setFillColor(Color::Green);
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

	for (Vector2f size : punchS) {
		rect.setSize(size);
		punchR.push_back(rect);
	}

	for (Vector2f size : punchUpS) {
		rect.setSize(size);
		punchUpR.push_back(rect);
	}

	for (Vector2f size : punchMultUpS) {
		rect.setSize(size);
		punchUpMultR.push_back(rect);
	}

	for (Vector2f size : punchDownS) {
		rect.setSize(size);
		punchDownR.push_back(rect);
	}

	for (Vector2f size : punchFromUpS) {
		rect.setSize(size);
		punchFromUpR.push_back(rect);
	}

	for (Vector2f size : punchMultS) {
		rect.setSize(size);
		punchMultR.push_back(rect);
	}

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

	for (Vector2f size : kickS) {
		rect.setSize(size);
		kickR.push_back(rect);
	}
	for (Vector2f size : kickUpS) {
		rect.setSize(size);
		kickUpR.push_back(rect);
	}
	for (Vector2f size : kickDownS) {
		rect.setSize(size);
		kickDownR.push_back(rect);
	}
	for (Vector2f size : kickFromDownS) {
		rect.setSize(size);
		kickFromDownR.push_back(rect);
	}
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
	vector<RectangleShape> turnLeftR;
	for (Vector2f size : turnLeftS) {
		rect.setSize(size);
		turnLeftR.push_back(rect);
	}
	vector<RectangleShape> turnRightR;
	for (Vector2f size : turnRightS) {
		rect.setSize(size);
		turnRightR.push_back(rect);
	}
	vector<RectangleShape> hitR;
	for (Vector2f size : hitS) {
		rect.setSize(size);
		hitR.push_back(rect);
	}
	vector<RectangleShape> hitHardR;
	for (Vector2f size : hitHardS) {
		rect.setSize(size);
		hitHardR.push_back(rect);
	}
	vector<RectangleShape> hitHeadR;
	for (Vector2f size : hitHeadS) {
		rect.setSize(size);
		hitHeadR.push_back(rect);
	}
	vector<RectangleShape> hitDuckR;
	for (Vector2f size : hitDuckS) {
		rect.setSize(size);
		hitDuckR.push_back(rect);
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
	hitboxes[AnimationType::PUNCH_UPPER_MULTIPLE] = punchUpMultR;

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

	hitboxes[AnimationType::TURN_LEFT] = turnLeftR;
	hitboxes[AnimationType::TURN_RIGHT] = turnRightR;


	RectangleShape specialAtt = RectangleShape(Vector2<float>(68, 11));
	specialAtt.setSize(Vector2f(68 * 3, 11 * 3));

	Character LiuKang = Character(animations, body, shadow, hitboxes, damage_hitboxes);

	return LiuKang;
}
#endif //LIUKANG_H