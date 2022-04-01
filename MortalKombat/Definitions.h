#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

	using namespace sf;
	using namespace std;

	#include "Animation.h"

	enum class AniamtioTypeGoro {

	};

	enum class AnimationTypeElViejoEsteQueNoSeComoSeLlama {

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

	bool isFixedMovement(AnimationType anim) {
		return (anim != AnimationType::JUMP) &&
			(anim != AnimationType::JUMP_AND_MOVE) &&
			(anim != AnimationType::PUNCH_FROM_AIR) &&
			(anim != AnimationType::KICK_FROM_AIR);
	}

	bool isDamageMovement(AnimationType anim) {
		return (anim != AnimationType::PUNCH);
	}

#endif