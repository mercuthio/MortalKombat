#ifndef GlobalVars_H
#define GlobalVars_H

#include "MusicManager.h"

using namespace sf;

extern MusicManager music;

extern float loadingTime;
extern float moveXBack;
extern float moveYBack;

extern float totalMoveXBack;

extern Vector2f p1Position;
extern Vector2f p2Position;

extern Vector2f p1PositionOffset;
extern Vector2f p2PositionOffset;

extern int screenLeftLimit;
extern int screenRightLimit;
extern int screenFloorLimit;

extern int screenLeftHardLimit;
extern int screenRightHardLimit;

extern bool clapping;

const int NUMBER_TRACKS = 191;
const double ASPECT_RATIO = 4.0/3.0;

static float width_window = 1024;
static float height_window = 768;

extern Keyboard::Key jumpButton;
extern Keyboard::Key forwButton;
extern Keyboard::Key backButton;
extern Keyboard::Key downButton;
extern Keyboard::Key punchButton;
extern Keyboard::Key punchButton2;
extern Keyboard::Key kickButton;
extern Keyboard::Key grabButton;
extern Keyboard::Key specialButton;
extern Keyboard::Key blockButton;

extern Keyboard::Key jumpButtonP2;
extern Keyboard::Key forwButtonP2;
extern Keyboard::Key backButtonP2;
extern Keyboard::Key downButtonP2;
extern Keyboard::Key punchButtonP2;
extern Keyboard::Key punchButton2P2;
extern Keyboard::Key kickButtonP2;
extern Keyboard::Key grabButtonP2;
extern Keyboard::Key specialButtonP2;
extern Keyboard::Key blockButtonP2;


const int life_BLOCK = 1;
const int life_PUNCH = 2;
const int life_PUNCH_MULTIPLE = 2;
const int life_PUNCH_CLOSE = 2;
const int life_PUNCH_UPPER = 3;
const int life_PUNCH_UPPER_MULTIPLE = 2;
const int life_PUNCH_UPPER_CLOSE = 2;
const int life_PUNCH_FROM_DOWN = 2;
const int life_PUNCH_FROM_AIR = 2;
const int life_KICK = 4;
const int life_KICK_UPPER = 5;
const int life_KICK_LOW = 4;
const int life_KICK_HIGH = 5;
const int life_KICK_FROM_DOWN = 4;
const int life_KICK_FROM_AIR = 4;
const int life_CATCH = 8;
const int life_SPECIAL = 5;

enum class LookingAt {
	LEFT, RIGHT
};

enum class BloodType {
	RIGHT,
	LEFT,
	UP,
	GROUND,
};

enum class SpecialType {
	LIU_KANG,
	SCORPION,
	SONYA
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
	THRONE_ROOM,
	GOROS_LAIR,
	PALACE_GATES
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
	HIT_HEAD,
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
		(anim != AnimationType::KICK_FROM_AIR) &&
		(anim != AnimationType::FALL) &&
		(anim != AnimationType::HIT_DOWN) &&
		(anim != AnimationType::HIT_HEAD) &&
		(anim != AnimationType::HIT_STAND) &&
		(anim != AnimationType::HIT_STAND_STRONG) &&
		(anim != AnimationType::FALL_BACK) &&
		(anim != AnimationType::FALL_UPPERCUT) &&
		(anim != AnimationType::NUTS);
}

static bool isBlockingMovement(AnimationType anim) {
	return (anim == AnimationType::BLOCK || anim == AnimationType::BLOCK_LOW);
}

static bool isDamageMovement(AnimationType anim) {
	return (anim == AnimationType::PUNCH) ||
		(anim == AnimationType::PUNCH_MULTIPLE) ||
		(anim == AnimationType::PUNCH_CLOSE) ||
		(anim == AnimationType::PUNCH_UPPER) ||
		(anim == AnimationType::PUNCH_UPPER_MULTIPLE) ||
		(anim == AnimationType::PUNCH_UPPER_CLOSE) ||
		(anim == AnimationType::PUNCH_FROM_DOWN) ||
		(anim == AnimationType::PUNCH_FROM_AIR) ||
		(anim == AnimationType::KICK) ||
		(anim == AnimationType::KICK_UPPER) ||
		(anim == AnimationType::KICK_LOW) ||
		(anim == AnimationType::KICK_HIGH) ||
		(anim == AnimationType::KICK_FROM_DOWN) ||
		(anim == AnimationType::KICK_FROM_AIR) ||
		(anim == AnimationType::CATCH) ||
		(anim == AnimationType::SPECIAL) ||
		(anim == AnimationType::FATALITY);
}

static bool hasFlag(AnimationType anim) {
	return (!isFixedMovement(anim) || anim == AnimationType::DOWN || anim == AnimationType::BLOCK || anim == AnimationType::BLOCK_LOW);
}
static bool isAnyFightKeyPressed(int player) {

	if (player == 1) {
		return(
			Keyboard::isKeyPressed(punchButton) ||
			Keyboard::isKeyPressed(kickButton) ||
			Keyboard::isKeyPressed(grabButton) ||
			Keyboard::isKeyPressed(specialButton)
			);
	}
	else {
		return(
			Keyboard::isKeyPressed(punchButtonP2) ||
			Keyboard::isKeyPressed(kickButtonP2) ||
			Keyboard::isKeyPressed(grabButtonP2) ||
			Keyboard::isKeyPressed(specialButtonP2)
			);
	}
}
static bool isAnyKeyPressed(int player) {

	if (player == 1) {
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
	else {
		return(
			Keyboard::isKeyPressed(jumpButtonP2) ||
			Keyboard::isKeyPressed(forwButtonP2) ||
			Keyboard::isKeyPressed(backButtonP2) ||
			Keyboard::isKeyPressed(downButtonP2) ||
			Keyboard::isKeyPressed(punchButtonP2) ||
			Keyboard::isKeyPressed(kickButtonP2) ||
			Keyboard::isKeyPressed(grabButtonP2) ||
			Keyboard::isKeyPressed(specialButtonP2) ||
			Keyboard::isKeyPressed(blockButtonP2)
			);
	}
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

static string fromKtoS(const sf::Keyboard::Key& k) {
    string ret;
    switch (k) {

    case sf::Keyboard::A:

        ret = "A";
        break;
    case sf::Keyboard::B:

        ret = "B";
        break;
    case sf::Keyboard::C:

        ret = "C";
        break;
    case sf::Keyboard::D:

        ret = "D";
        break;
    case sf::Keyboard::E:

        ret = "E";
        break;
    case sf::Keyboard::F:

        ret = "F";
        break;
    case sf::Keyboard::G:

        ret = "G";
        break;
    case sf::Keyboard::H:

        ret = "H";
        break;
    case sf::Keyboard::I:

        ret = "I";
        break;
    case sf::Keyboard::J:

        ret = "J";
        break;
    case sf::Keyboard::K:

        ret = "K";
        break;
    case sf::Keyboard::L:

        ret = "L";
        break;
    case sf::Keyboard::M:

        ret = "M";
        break;
    case sf::Keyboard::N:

        ret = "N";
        break;
    case sf::Keyboard::O:

        ret = "O";
        break;
    case sf::Keyboard::P:

        ret = "P";
        break;
    case sf::Keyboard::Q:

        ret = "Q";
        break;
    case sf::Keyboard::R:

        ret = "R";
        break;
    case sf::Keyboard::S:

        ret = "S";
        break;
    case sf::Keyboard::T:

        ret = "T";
        break;
    case sf::Keyboard::U:

        ret = "U";
        break;
    case sf::Keyboard::V:

        ret = "V";
        break;
    case sf::Keyboard::W:

        ret = "W";
        break;
    case sf::Keyboard::X:

        ret = "X";
        break;
    case sf::Keyboard::Y:

        ret = "Y";
        break;
    case sf::Keyboard::Z:

        ret = "Z";
        break;
    case sf::Keyboard::Num0:

        ret = "Num0";
        break;
    case sf::Keyboard::Num1:

        ret = "Num1";
        break;
    case sf::Keyboard::Num2:

        ret = "Num2";
        break;
    case sf::Keyboard::Num3:

        ret = "Num3";
        break;
    case sf::Keyboard::Num4:

        ret = "Num4";
        break;
    case sf::Keyboard::Num5:

        ret = "Num5";
        break;
    case sf::Keyboard::Num6:

        ret = "Num6";
        break;
    case sf::Keyboard::Num7:

        ret = "Num7";
        break;
    case sf::Keyboard::Num8:

        ret = "Num8";
        break;
    case sf::Keyboard::Num9:

        ret = "Num9";
        break;
    case sf::Keyboard::Escape:

        ret = "Escape";
        break;
    case sf::Keyboard::LControl:

        ret = "LControl";
        break;
    case sf::Keyboard::LShift:

        ret = "LShift";
        break;
    case sf::Keyboard::LAlt:

        ret = "LAlt";
        break;
    case sf::Keyboard::LSystem:

        ret = "LSystem";
        break;
    case sf::Keyboard::RControl:

        ret = "RControl";
        break;
    case sf::Keyboard::RShift:

        ret = "RShift";
        break;
    case sf::Keyboard::RAlt:

        ret = "RAlt";
        break;
    case sf::Keyboard::RSystem:

        ret = "RSystem";
        break;
    case sf::Keyboard::Menu:

        ret = "Menu";
        break;
    case sf::Keyboard::LBracket:

        ret = "LBracket";
        break;
    case sf::Keyboard::RBracket:

        ret = "RBracket";
        break;
    case sf::Keyboard::SemiColon:

        ret = "SemiColon";
        break;
    case sf::Keyboard::Comma:

        ret = "Comma";
        break;
    case sf::Keyboard::Period:

        ret = "Period";
        break;
    case sf::Keyboard::Quote:

        ret = "Quote";
        break;
    case sf::Keyboard::Slash:

        ret = "Slash";
        break;
    case sf::Keyboard::BackSlash:

        ret = "BackSlash";
        break;
    case sf::Keyboard::Tilde:

        ret = "Tilde";
        break;
    case sf::Keyboard::Equal:

        ret = "Equal";
        break;
    case sf::Keyboard::Dash:

        ret = "Dash";
        break;
    case sf::Keyboard::Space:

        ret = "Space";
        break;
    case sf::Keyboard::Return:

        ret = "Return";
        break;
    case sf::Keyboard::BackSpace:

        ret = "BackSpace";
        break;
    case sf::Keyboard::Tab:

        ret = "Tab";
        break;
    case sf::Keyboard::PageUp:

        ret = "PageUp";
        break;
    case sf::Keyboard::PageDown:

        ret = "PageDown";
        break;
    case sf::Keyboard::End:

        ret = "End";
        break;
    case sf::Keyboard::Home:

        ret = "Home";
        break;
    case sf::Keyboard::Insert:

        ret = "Insert";
        break;
    case sf::Keyboard::Delete:

        ret = "Delete";
        break;
    case sf::Keyboard::Add:

        ret = "Add";
        break;
    case sf::Keyboard::Subtract:

        ret = "Subtract";
        break;
    case sf::Keyboard::Multiply:

        ret = "Multiply";
        break;
    case sf::Keyboard::Divide:

        ret = "Divide";
        break;
    case sf::Keyboard::Left:

        ret = "Left";
        break;
    case sf::Keyboard::Right:

        ret = "Right";
        break;
    case sf::Keyboard::Up:

        ret = "Up";
        break;
    case sf::Keyboard::Down:

        ret = "Down";
        break;
    case sf::Keyboard::Numpad0:

        ret = "Numpad0";
        break;
    case sf::Keyboard::Numpad1:

        ret = "Numpad1";
        break;
    case sf::Keyboard::Numpad2:

        ret = "Numpad2";
        break;
    case sf::Keyboard::Numpad3:

        ret = "Numpad3";
        break;
    case sf::Keyboard::Numpad4:

        ret = "Numpad4";
        break;
    case sf::Keyboard::Numpad5:

        ret = "Numpad5";
        break;
    case sf::Keyboard::Numpad6:

        ret = "Numpad6";
        break;
    case sf::Keyboard::Numpad7:

        ret = "Numpad7";
        break;
    case sf::Keyboard::Numpad8:

        ret = "Numpad8";
        break;
    case sf::Keyboard::Numpad9:

        ret = "Numpad9";
        break;
    case sf::Keyboard::F1:

        ret = "F1";
        break;
    case sf::Keyboard::F2:

        ret = "F2";
        break;
    case sf::Keyboard::F3:

        ret = "F3";
        break;
    case sf::Keyboard::F4:

        ret = "F4";
        break;
    case sf::Keyboard::F5:

        ret = "F5";
        break;
    case sf::Keyboard::F6:

        ret = "F6";
        break;
    case sf::Keyboard::F7:

        ret = "F7";
        break;
    case sf::Keyboard::F8:

        ret = "F8";
        break;
    case sf::Keyboard::F9:

        ret = "F9";
        break;
    case sf::Keyboard::F10:

        ret = "F10";
        break;
    case sf::Keyboard::F11:

        ret = "F11";
        break;
    case sf::Keyboard::F12:

        ret = "F12";
        break;
    case sf::Keyboard::F13:

        ret = "F13";
        break;
    case sf::Keyboard::F14:

        ret = "F14";
        break;
    case sf::Keyboard::F15:

        ret = "F15";
        break;
    case sf::Keyboard::Pause:

        ret = "Pause";
        break;
    case sf::Keyboard::KeyCount:

        ret = "KeyCount";
        break;


    default:
        ret = "Unknow";
        break;
    }
    return ret;






}

#endif