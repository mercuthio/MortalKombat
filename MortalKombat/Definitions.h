#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

	using namespace sf;
	using namespace std;

	enum class AnimationType {
		// Movements
		IDLE,
		JUMP,
		BACK_JUMP,
		FORW_JUMP,
		DOWN,
		FORW_WALK,
		BACK_WALK,

		// Atacks 
		// -- Punch
		L_PUNCH_IDLE,
		M_S_PUNCH_IDLE,
	
		L_PUNCH_FORW,
		M_PUNCH_FORW,
		S_PUNCH_FORW,

		L_PUNCH_DOWN,
		M_PUNCH_DOWN,
		S_PUNCH_DOWN,
	
		// -- Kick
		L_M_KICK_IDLE,
		S_KICK_IDLE,

		L_KICK_FORW,
		M_KICK_FORW,
		S_KICK_FORW,

		L_KICK_DOWN,
		M_KICK_DOWN,
		S_KICK_DOWN,

		// Herida
		BEING_HIT,
		FALL,
		RECOVER,
	};

	bool isFixedMovement(AnimationType anim) {
		return (anim != AnimationType::JUMP) ||
			(anim != AnimationType::FORW_JUMP) ||
			(anim != AnimationType::BACK_JUMP) ||
			(anim != AnimationType::BEING_HIT);
	}
#endif