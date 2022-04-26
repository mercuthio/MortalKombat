#ifndef GlobalVars_H
#define GlobalVars_H

#include "MusicManager.h"

using namespace sf;

extern MusicManager music;

extern float loadingTime;
extern float moveXBack;
extern float moveYBack;

extern int screenLeftLimit;
extern int screenRightLimit;
extern int screenFloorLimit;

extern int screenLeftHardLimit;
extern int screenRightHardLimit;

const int NUMBER_TRACKS = 191;
const double ASPECT_RATIO = 4.0/3.0;

static float width_window = 1024;
static float height_window = 768;

static Keyboard::Key jumpButton = Keyboard::W;
static Keyboard::Key forwButton = Keyboard::D;
static Keyboard::Key backButton = Keyboard::A;
static Keyboard::Key downButton = Keyboard::S;
static Keyboard::Key punchButton = Keyboard::R;
static Keyboard::Key punchButton2 = Keyboard::T;
static Keyboard::Key kickButton = Keyboard::F;
static Keyboard::Key grabButton = Keyboard::G;
static Keyboard::Key specialButton = Keyboard::V;
static Keyboard::Key blockButton = Keyboard::B;

static Keyboard::Key jumpButtonP2 = Keyboard::Up;
static Keyboard::Key forwButtonP2 = Keyboard::Right;
static Keyboard::Key backButtonP2 = Keyboard::Left;
static Keyboard::Key downButtonP2 = Keyboard::Down;
static Keyboard::Key punchButtonP2 = Keyboard::J;
static Keyboard::Key punchButton2P2 = Keyboard::K;
static Keyboard::Key kickButtonP2 = Keyboard::I;
static Keyboard::Key grabButtonP2 = Keyboard::O;
static Keyboard::Key specialButtonP2 = Keyboard::N;
static Keyboard::Key blockButtonP2 = Keyboard::M;

enum class LookingAt {
	LEFT, RIGHT
};

enum CharacterType {
	CAGE,
	KANO,
	RAIDEN,
	LIU_KANG,
	SCORPION,
	SUB_ZERO,
	SONYA,
	GORO,
	SHANG_TSUNG
};

enum background {
	COURTYARD,
	WARRIOR_SHRINE,
	THE_PIT,
	GOROS_LAIR,
	PALACE_GATES,
	THRONE_ROOM
};

enum class AnimationType {
	// Movements
	IDLE,
	JUMP,
	JUMP_AND_MOVE,
	DOWN,		// Crouch
	WALK_FORW,
	WALK_BACK,

	// Atacks 
	// -- Punch
	PUNCH,
	PUNCH_MULTIPLE,
	PUNCH_CLOSE,

	PUNCH_UPPER,
	PUNCH_UPPER_MULTIPLE,
	PUNCH_UPPER_CLOSE,

	PUNCH_FROM_DOWN,
	PUNCH_FROM_AIR,

	// -- Kick
	KICK,
	KICK_UPPER,
	KICK_LOW,
	KICK_HIGH,

	KICK_FROM_DOWN,
	KICK_FROM_AIR,

	// Get Hit - Block - Recover
	HIT_STAND,
	HIT_STAND_STRONG,
	HIT_DOWN,

	FALL,
	FALL_UPPERCUT,
	FALL_BACK,

	RECOVER,
	NUTS,

	CATCH,
	GET_CAUGHT,
	GET_CAUGHT_GORO,

	SPECIAL,

	DYING,
	CUT_HEAD,
	HEAD_FLYING,

	FATALITY,
	WIN,

	BLOCK,
	BLOCK_LOW,

	TURN_LEFT,
	TURN_RIGHT,
};

static bool isFixedMovement(AnimationType anim) {
	return (anim != AnimationType::JUMP) &&
		(anim != AnimationType::JUMP_AND_MOVE) &&
		(anim != AnimationType::PUNCH_FROM_AIR) &&
		(anim != AnimationType::KICK_FROM_AIR);
}

static bool isDamageMovement(AnimationType anim) {
	return (anim != AnimationType::PUNCH);
}

static bool hasFlag(AnimationType anim) {
	return (!isFixedMovement(anim) || anim == AnimationType::DOWN || anim == AnimationType::BLOCK || anim == AnimationType::BLOCK_LOW);
}
static bool isAnyFightKeyPressed() {
	return(
		Keyboard::isKeyPressed(punchButton) ||
		Keyboard::isKeyPressed(kickButton) ||
		Keyboard::isKeyPressed(grabButton) ||
		Keyboard::isKeyPressed(specialButton)
		);
}
static bool isAnyKeyPressed() {
	return(
		Keyboard::isKeyPressed(jumpButton) ||
		Keyboard::isKeyPressed(forwButton) ||
		Keyboard::isKeyPressed(backButton) ||
		Keyboard::isKeyPressed(downButton) ||
		Keyboard::isKeyPressed(punchButton) ||
		Keyboard::isKeyPressed(kickButton) ||
		Keyboard::isKeyPressed(grabButton) ||
		Keyboard::isKeyPressed(specialButton) ||
		Keyboard::isKeyPressed(blockButton)
	);
}

// probabilidad de fallar
enum class DifficultyLevel {
	EASY, 
	MEDIUM,
	HARD
};

enum class EstadoIA {
	IDLE,
	ACERCARSE,
	ALEJARSE,
	MODO_ATAQUE,
	MODO_SEXO,
};

static map<DifficultyLevel, int> Difficulty = {
		{DifficultyLevel::EASY, 25},
		{DifficultyLevel::MEDIUM, 50},
		{DifficultyLevel::HARD, 111}
};


#endif