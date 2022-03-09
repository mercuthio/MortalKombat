#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Definiciones de constantes generales
constexpr int N_ANIMATIONS = 8;	// Total de animaciones de los personajes;
constexpr int MAX_IMG_PER_ANIM = 15;

class Position {
	float x;
	float y;
};

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

#endif