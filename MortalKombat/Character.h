#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Animation.h"
#include "Definitions.h"
#include "Movement.h"

//--------------DEBUG-------------
constexpr int screenLeftLimit = 10;
constexpr int screenRightLimit = 500;
constexpr int screenFloorLimit = 400;
constexpr float gravedad = 1000;			// pixels/s^2
constexpr float updateTime = 0.05;			// 50 milis
constexpr bool DEBUG_POSITION = true;
//--------------------------------


using namespace sf;
using namespace std;

class Character {
public:
	Character() = default;
	Character(map<AnimationType, Movement> _animations, RectangleShape& _body);
	//~Character() = delete;

	void Update(float time);
	void debugDraw(RenderWindow& window);

	void GetHit(int life);
	void UseEnergy(int quantity);

private:
	RectangleShape body;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion

	int life = 100;
	int energy = 0;

	bool doing_animation = false;

	bool on_air = false;
	bool punching = false;
	bool crouching = false;

	Vector2<float> speed;
	bool leftOfOpponent = true;
	
	AnimationType animation_in_process;

	void CheckDebugAnimations();
	void EndAndResetAnimation();

	void Mirror();

	void DoAnimation();
	void EndAnimation();
	void debug_animation();

	void CheckAnimation();
	void CheckCollisions();
	void CheckScreenCollisions();
};

Keyboard::Key jumpButton = Keyboard::W;
Keyboard::Key forwButton = Keyboard::D;
Keyboard::Key backButton = Keyboard::A;
Keyboard::Key downButton = Keyboard::S;
Keyboard::Key punchButton = Keyboard::J;
Keyboard::Key kickButton = Keyboard::K;
Keyboard::Key grabButton = Keyboard::U;
Keyboard::Key specialButton = Keyboard::I;
Keyboard::Key blockButton = Keyboard::L;


/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
Character::Character(map<AnimationType, Movement> _animations, RectangleShape& _body) {
	body = _body;
	animation_in_process = AnimationType::IDLE;
	animations = _animations;
}

void Character::Update(float tiempo) {
	global_position = body.getPosition();
	if (DEBUG_POSITION) {
		cout << "X: " << global_position.x << " - Y:" << global_position.y << endl;
		cout << "Origin: " << "(" << body.getOrigin().x << ", " << body.getOrigin().y << ")" << endl;
	}

	CheckAnimation();	// Dependiendo de que ha pulsado el jugador hago una animación u otra
	DoAnimation();		// Realizo el siguiente frame de la animación
 
	CheckCollisions();
	
	body.setPosition(global_position);
}


void Character::CheckAnimation() {
	
	CheckDebugAnimations();	

	if (on_air) {					// El personaje está en el aire
		if (Keyboard::isKeyPressed(punchButton)) {
			EndAndResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_AIR;
		}
		else if (Keyboard::isKeyPressed(kickButton)) {
			EndAndResetAnimation();
			animation_in_process = AnimationType::KICK_FROM_AIR;
		}
		// else -> nothing
	}

	else if (crouching) {			// El personaje está agachado
		if (Keyboard::isKeyPressed(punchButton)) {
			animation_in_process = AnimationType::PUNCH_FROM_DOWN;
		}
		else if (Keyboard::isKeyPressed(kickButton)) {
			animation_in_process = AnimationType::KICK_FROM_DOWN;
		}
		else if (Keyboard::isKeyPressed(blockButton)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK_LOW;
		}
		else if (!Keyboard::isKeyPressed(downButton)) {
			crouching = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}
	else if (punching) {			// El personaje está pegando
		if (Keyboard::isKeyPressed(punchButton)) {
			if (Keyboard::isKeyPressed(forwButton)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::PUNCH_UPPER_MULTIPLE;
			}
			else {
				animation_in_process = AnimationType::PUNCH_MULTIPLE;
			}
		}
	}

	else if (!doing_animation) {	// El personaje no está haciendo nada
		if (Keyboard::isKeyPressed(downButton)) {													//Agacharse

			if (Keyboard::isKeyPressed(kickButton)) {
				animation_in_process = AnimationType::KICK_LOW;
			}
			else {
				animation_in_process = AnimationType::DOWN;
			}
		}
		else if (Keyboard::isKeyPressed(forwButton)) {												//Moverse derecha
			if (Keyboard::isKeyPressed(jumpButton)) {												//Salto hacia delante
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				speed = Vector2<float>(-100, 300);
				on_air = true;
			}
			else if (Keyboard::isKeyPressed(punchButton)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::PUNCH_UPPER;
			}
			else if (Keyboard::isKeyPressed(kickButton)) {											//M.Punch hacia delante
				animation_in_process = AnimationType::KICK_UPPER; 
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_FORW;
			}
		}
		else if (Keyboard::isKeyPressed(backButton)) {												//Moverse izquierda

			if (Keyboard::isKeyPressed(jumpButton)) {												//Salto hacia atras
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				speed = Vector2<float>(100, 300);
			}
			else if (Keyboard::isKeyPressed(punchButton)) {												//Salto hacia delante
				animation_in_process = AnimationType::PUNCH;
			}
			else if (Keyboard::isKeyPressed(kickButton)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::KICK;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_BACK;
			}

		}
		else if (Keyboard::isKeyPressed(jumpButton)) {												//Salto en parado
			animation_in_process = AnimationType::JUMP;
			speed = Vector2<float>(0, 300);
			on_air = true;
		}
		else if (Keyboard::isKeyPressed(kickButton)) {		//M.Punch, H.Punch en parado
			animation_in_process = AnimationType::KICK;
		}
		else if (Keyboard::isKeyPressed(punchButton)) {												//L.Punch en parado
			animation_in_process = AnimationType::PUNCH;
		}		
		else if (Keyboard::isKeyPressed(specialButton)) {		//L.Kick, M.Kick en parado
			animation_in_process = AnimationType::SPECIAL;
		}
		else if (Keyboard::isKeyPressed(blockButton)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK;
		}
	}
	// else -> Nothing
}

void Character::CheckDebugAnimations() {
	if (Keyboard::isKeyPressed(Keyboard::M)) { // DEBUG
		Mirror();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Z)) {	// Get Caught

	}
	else if (Keyboard::isKeyPressed(Keyboard::F)) { // Fatality

	}
	else if (Keyboard::isKeyPressed(Keyboard::R)) { // Recover

	}
	else if (Keyboard::isKeyPressed(Keyboard::T)) { // Fall

	}
	else if (Keyboard::isKeyPressed(Keyboard::Y)) { // Win

	}
	else if (Keyboard::isKeyPressed(Keyboard::M)) { // Nuts

	}
}

void Character::CheckCollisions() {
	CheckScreenCollisions();
	// CheckOpponentPosition()			// Giramos el sprite si nos hemos camiado de posición respecto al enemigo
	if ( isDamageMovement(animation_in_process) ) {
		// CheckHitboxesCollisions();	// Checkeamos hitboxes si estamos golpeando
	}
	
}

void Character::CheckScreenCollisions() {
	if (global_position.x < screenLeftLimit) {
		global_position.x = screenLeftLimit;
	}
	else if (global_position.x > screenRightLimit) {
		global_position.x = screenRightLimit;
	}

	if (global_position.y > screenFloorLimit) {
		global_position.y = screenFloorLimit;
		speed = Vector2<float>(0, 0);
		EndAndResetAnimation();		// Probar a quitar, queda muy feo
		on_air = false;
	}
}

/*
	Comprueba que tecla está presionando el usuario y realiza una animación dependiendo de eso
*/
void Character::DoAnimation() {
	doing_animation = true;
	//debug_animation();
	bool finished = animations[animation_in_process].animation.DoAnimation(body);

	if (isFixedMovement(animation_in_process)) { // Sigue un desplazamiento fijado
		Vector2<float> mov = animations[animation_in_process].traslation;
		mov.x = leftOfOpponent ? mov.x : -mov.x;
		global_position += mov;
	}
	else { // Sigue las físicas del mundo (gravedad)
		global_position = global_position - speed * updateTime;
		Vector2<float> pre_speed = speed;
		speed.y = speed.y - gravedad * updateTime;
		
		// Pasamos de subir a bajar
		if (pre_speed.y >= 0 && speed.y < 0) {
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}

	if (finished) {
		EndAnimation();
	}
}

void Character::EndAnimation() {
	doing_animation = false;
	animation_in_process = AnimationType::IDLE;
}

void Character::EndAndResetAnimation() {
	animations[animation_in_process].animation.ResetAnimation();
	EndAnimation();
}

void Character::GetHit(int quantity) {

	EndAndResetAnimation();
	
	if (animation_in_process == AnimationType::BLOCK) {
		return;
	}
	
	animation_in_process = AnimationType::FALL;

	if (leftOfOpponent) {
		speed = Vector2<float>(100, 200);
	}
	else {
		speed = Vector2<float>(-100, 200);
	}
	life -= quantity;
}

void Character::UseEnergy(int quantity) {
	energy -= quantity;
}

void Character::debugDraw(RenderWindow& window) {
	window.draw(body);
}

void Character::Mirror() {
	// Recalculate hitboxes positions
	if (leftOfOpponent) {

	}
	leftOfOpponent = !leftOfOpponent;
	body.setOrigin(125, 0);
	body.setScale(body.getScale().x *-1, 1);
	//body.setOrigin(0, 0);
}

void Character::debug_animation() {
	cout << "Realizando Animacion: ";
	switch (animation_in_process) {
	case (AnimationType::IDLE):
		cout << "idle";
		break;
	case (AnimationType::WALK_FORW):
		cout << "forward walk";
		break;
	case (AnimationType::WALK_BACK):
		cout << "back walk";
		break;
	default:
		cout << "unknown";
	}
	cout << "\tVelocidad: " << speed.x << " " << speed.y << "\t";
}
#endif