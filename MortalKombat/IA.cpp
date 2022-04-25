#include "IA.h"
#include <stdlib.h>

IA::IA(map<AnimationType, Movement> _animations, RectangleShape& _body, RectangleShape& _shadow, map<AnimationType, vector<RectangleShape>> _hitboxes, Difficulty _difficulty, Character _opponent){
	body = _body;
	shadow = _shadow;
	animation_in_process = AnimationType::IDLE;
	animations = _animations;
	hitboxes = _hitboxes;
	difficulty = _difficulty;
	opponent = _opponent;
}

void Character::initPosition(Vector2<float> initPos) {
	global_position = initPos;
}

void IA::Update(float tiempo) {

	if (freeze && freezeTimer < 10) {
		freezeTimer++;
	}
	else {
		freezeTimer = 0;		
		CheckAnimation();
	}
			
	DoAnimation();
	CheckCollisions();

	shadow.setPosition(Vector2f(global_position.x, screenFloorLimit));
	body.setPosition(global_position);
}

void IA::ChangeState() {
	duracionEstadoActual++;
	if (duracionEstadoActual > 10) {
		int probabilidad = rand() % 100; // entre 0 y 99 (inclusive)

		// Cambiamos de estado
		if (difficulty > probabilidad) {
			duracionEstadoActual = 0;
			bool siendoAtacado = opponent.isAttaking();
			float distancia = GetXPosition() - opponent.GetXPosition();
			AnimationType anim = opponent.getAnimation();
			
			// Cambiar de estado dependiendo de varios factores
			if (siendoAtacado && distancia < 15) {

			}
		}
	}
}

// Ejecutar después del del jugador
void IA::CheckAnimation() {
	if (!doing_animation) {
		ChangeState();
		int probabilidad = rand() % 100; // entre 0 y 99 (inclusive)

		switch (estado) {
		case EstadoIA::IDLE:
			animation_in_process = AnimationType::IDLE;
			break;

		case EstadoIA::ACERCARSE:
			animation_in_process = AnimationType::WALK_FORW;
			break;

		case EstadoIA::ALEJARSE:
			animation_in_process = AnimationType::WALK_BACK;
			break;

		case EstadoIA::MODO_ATAQUE:
			// Check mas cosas
			break;		

		case EstadoIA::MODO_SEXO:
			break;
		}
	}
}

bool IA::CheckScreenCollisions(float movement) {
	if (global_position.x < screenLeftHardLimit) {
		global_position.x = screenLeftHardLimit;
		return true;

	}
	else if (global_position.x > screenRightHardLimit) {
		global_position.x = screenRightHardLimit;
		return true;
	}

	if (global_position.x - movement <= screenLeftLimit) {
		moveXBack += movement;
		return true;

	}
	else if (global_position.x - movement >= screenRightLimit) {
		moveXBack += movement;
		return true;
	}

	if (global_position.y > screenFloorLimit) {
		global_position.y = screenFloorLimit;
		speed = Vector2<float>(0, 0);
		return true;
	}

	return false;
}

void IA::DoAnimation() {
	doing_animation = true;
	//debug_animation();

	bool finished = false;

	if (!fallen) {

		finished = animations[animation_in_process].animation.DoAnimation(body, shadow, hitbox, mirrored,
			animations[animation_in_process].hitbox_positions_X, animations[animation_in_process].hitbox_positions_Y, global_position);
	}

	if (finished) {
		if (animation_in_process == AnimationType::FALL || animation_in_process == AnimationType::FALL_UPPERCUT) {
			finished = false;
			fallen = true;
		}
		else if (animation_in_process == AnimationType::DYING) {
			finished = false;
			animations[animation_in_process].animation.ResetAnimation();
		}
		punching = punching ? false : punching;
	}


	if (isFixedMovement(animation_in_process)) { // Sigue un desplazamiento fijado
		Vector2<float> mov = animations[animation_in_process].traslation;
		mov.x = mirrored ? -mov.x : mov.x;
		if (mov.x != 0) {
			if (!CheckScreenCollisions(-mov.x)) {
				global_position += mov;
			}
		}
	}
	else { // Sigue las físicas del mundo (gravedad)
		Vector2<float> mov;
		mov.y = speed.y * updateTime;
		global_position.y -= mov.y;

		CheckScreenCollisions(0);

		mov.x = speed.x * updateTime;
		mov.x = mirrored ? -mov.x : mov.x;
		if (mov.x != 0) {
			if (!CheckScreenCollisions(mov.x)) {
				global_position.x -= mov.x;
			}
		}

		Vector2<float> pre_speed = speed;
		speed.y = speed.y - gravedad * updateTime;

		// Pasamos de subir a bajar
		if (pre_speed.y >= 0 && speed.y < 0) {
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}

	if (finished) {
		AnimationType anim_pre = animation_in_process;

		if (!hasFlag(animation_in_process)) {
			EndAnimation();
		}
		else {
			EndAndResetAnimation();
		}

		if (anim_pre != AnimationType::IDLE && mirrorOnEnd) {
			mirrorOnEnd = false;
			mirroring = true;
		}

		if (mirrorOnEnd) {
			animation_in_process = AnimationType::TURN_LEFT;

			mirroring = true;
			mirrorOnEnd = false;

		}
		else if (mirroring) {
			mirroring = false;
			if (player == 1) {
				Keyboard::Key aux = backButton;
				backButton = forwButton;
				forwButton = aux;
			}
			mirrored = !mirrored;
		}
	}
}

void IA::EndAnimation() {
	on_air = false;
	doing_animation = false;
	animation_in_process = AnimationType::IDLE;
}

void IA::EndAndResetAnimation() {
	animations[animation_in_process].animation.ResetAnimation();
	EndAnimation();
}

void IA::GetHit(int quantity) {

	EndAndResetAnimation();

	if (animation_in_process == AnimationType::BLOCK) {
		return;
	}

	animation_in_process = AnimationType::FALL;

	if (!mirrored) {
		speed = Vector2<float>(100, 200);
	}
	else {
		speed = Vector2<float>(-100, 200);
	}
	life -= quantity;
}

void IA::debugDraw(RenderWindow& window) {
	window.draw(hitbox);	//Para debug
	window.draw(shadow);
	window.draw(body);
}

void IA::Mirror() {
	looking_at = (looking_at == LookingAt::LEFT) ? LookingAt::RIGHT : LookingAt::LEFT;
	mirrorOnEnd = true;
}