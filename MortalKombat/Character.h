#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Animation.h"
#include "Definitions.h"

using namespace sf;
using namespace std;

struct Movement {
	Animation animation;
	Vector2<float> traslation;
};

class Character {
public:
	Character() = default;
	Character(map<AnimationType, Movement> _animations, RectangleShape _body);
	//~Character() = delete;

	void Update(float time);
	void DoAnimation();
	void EndAnimation();
	
	void CheckMovement();
	void CheckCollisions();

	void GetHit(int life);
	void UseEnergy(int quantity);

	void draw(RenderWindow& window);

	void debug_animation();

private:
	RectangleShape body;

	Vector2<float> global_position;
	map<AnimationType, Movement> animations; // mapa de enum -> animacion

	int life = 100;
	int energy = 0;
	bool doing_animation = false;
	
	AnimationType animation_in_process;
};

/*
	Define un personaje con su conjunto de animaciones

	@param _animations: map compuesto de AnimationType que da un Movement
	@param _body: RectangleShape que define el sprite en el mundo
*/
Character::Character(map<AnimationType, Movement> _animations, RectangleShape _body) {
	body = _body;
	animation_in_process = AnimationType::IDLE;
	animations = _animations;
}

void Character::Update(float tiempo) {

	CheckMovement();

	DoAnimation();

	//CheckCollisions();
}

/*
	Comprueba que tecla está presionando el usuario y realiza una animación dependiendo de eso
*/
void Character::CheckMovement() {
	
	if (!doing_animation) {
		if (Keyboard::isKeyPressed(Keyboard::S)) {												//Agacharse

			if (Keyboard::isKeyPressed(Keyboard::A)) {												//Bloquear agachado

			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::DOWN;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::D)) {											//Moverse derecha

			if (Keyboard::isKeyPressed(Keyboard::W)) {												//Salto hacia delante
				animation_in_process = AnimationType::FORW_JUMP;
			}
			else if (Keyboard::isKeyPressed(Keyboard::T)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::L_PUNCH_FORW;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Y)) {											//M.Punch hacia delante
				animation_in_process = AnimationType::M_PUNCH_FORW;
			}
			else if (Keyboard::isKeyPressed(Keyboard::U)) {											//H.Punch hacia delante
				animation_in_process = AnimationType::S_PUNCH_FORW;
			}
			else if (Keyboard::isKeyPressed(Keyboard::G)) {											//L.Kick hacia delante
				animation_in_process = AnimationType::L_KICK_FORW;
			}
			else if (Keyboard::isKeyPressed(Keyboard::H)) {											//M.Kick hacia delante
				animation_in_process = AnimationType::M_KICK_FORW;
			}
			else if (Keyboard::isKeyPressed(Keyboard::J)) {											//H.Kick hacia delante
				animation_in_process = AnimationType::S_KICK_FORW;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::FORW_WALK;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::A)) {											//Moverse izquierda

			if (Keyboard::isKeyPressed(Keyboard::W)) {												//Salto hacia atras
				animation_in_process = AnimationType::BACK_JUMP;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::BACK_WALK;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) {											//Salto en parado
			animation_in_process = AnimationType::JUMP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::T)) {											//L.Punch en parado
			animation_in_process = AnimationType::L_PUNCH_IDLE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Y) || Keyboard::isKeyPressed(Keyboard::U)) {	//M.Punch, H.Punch en parado
			animation_in_process = AnimationType::M_S_PUNCH_IDLE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::G) || Keyboard::isKeyPressed(Keyboard::H)) {	//L.Kick, M.Kick en parado
			animation_in_process = AnimationType::L_M_KICK_IDLE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::J)) {											//H.Kick en parado
			animation_in_process = AnimationType::S_KICK_IDLE;
		}
	}
}

void Character::CheckCollisions() {
	// TO BE PROGRAMMED
}

void Character::DoAnimation() {
	doing_animation = true;
	debug_animation();
	bool terminada = animations[animation_in_process].animation.DoAnimation(body);

	if (isFixedMovement(animation_in_process)) { // Sigue un desplazamiento fijado
		body.setPosition(body.getPosition() + animations[animation_in_process].traslation);
	}
	else { // Sigue las físicas del mundo (pj: gravedad y distancia al suelo)

	}

	if (terminada) {
		EndAnimation();
	}
}

void Character::EndAnimation() {
	doing_animation = false;
	animation_in_process = AnimationType::IDLE;
}

void Character::GetHit(int quantity) {
	life -= quantity;
}

void Character::UseEnergy(int quantity) {
	energy -= quantity;
}

void Character::draw(RenderWindow& window) {
	window.draw(body);
}

void Character::debug_animation() {
	cout << "Realizando Animacion: ";
	switch (animation_in_process) {
	case (AnimationType::IDLE):
		cout << "idle";
		break;
	case (AnimationType::FORW_WALK):
		cout << "forwaed walk";
		break;
	case (AnimationType::BACK_WALK):
		cout << "back walk";
		break;
	default:
		cout << "unknown";
	}
}
#endif