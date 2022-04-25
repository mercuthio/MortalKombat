#include "Character.h"

float moveXBack;
float moveYBack;


Character::Character(map<AnimationType, Movement> _animations, RectangleShape& _body, RectangleShape& _shadow, map<AnimationType, vector<RectangleShape>> hitboxes_) {
	body = _body;
	shadow = _shadow;
	animation_in_process = AnimationType::IDLE;
	animations = _animations;
	hitboxes = hitboxes_;
}

void Character::Update(float tiempo) {
	if (internalTimer >= updateTime) {

		internalTimer = 0.0f;
		/*global_position = body.getPosition();
		if (DEBUG_POSITION) {
			cout << "X: " << global_position.x << " - Y:" << global_position.y << endl;
			cout << "Origin: " << "(" << body.getOrigin().x << ", " << body.getOrigin().y << ")" << endl;
		}*/

		if (!freeze) CheckAnimation();	// Dependiendo de que ha pulsado el jugador hago una animaci�n u otra
		DoAnimation();		// Realizo el siguiente frame de la animaci�n

		CheckCollisions();

		shadow.setPosition(Vector2f(global_position.x, screenFloorLimit));
		body.setPosition(global_position);
	
	}
	else {
		internalTimer += 0.025f;
	}
}

void Character::initPosition(Vector2<float> initPos) {
	global_position = initPos;
}

void Character::CheckAnimation() {

	CheckDebugAnimations();
	
	if (fightKeyPressed) {
		if (!isAnyFightKeyPressed()) {
			fightKeyPressed = false;
		}
	}
	if (fallen) {
		if (isAnyKeyPressed()) {
			fallen = false;
			animation_in_process = AnimationType::RECOVER;
		}
	}
	else if (on_air) {					// El personaje est� en el aire
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
	else if (blocking) {
		if (!Keyboard::isKeyPressed(blockButton)) {
			blocking = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}
	else if (crouching) {			// El personaje est� agachado
		if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton) && animation_in_process != AnimationType::PUNCH_FROM_DOWN) {
			animations[animation_in_process].animation.ResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_DOWN;
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {
			animation_in_process = AnimationType::KICK_FROM_DOWN;
			fightKeyPressed = true;
		}
		else if (Keyboard::isKeyPressed(blockButton)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK_LOW;
			blocking = true;
		}
		else if (!Keyboard::isKeyPressed(downButton)) {
			crouching = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
		else {
			if (!doing_animation) {
				animation_in_process = AnimationType::DOWN;
			}			
		}
	}	
	else if (!doing_animation) {	// El personaje no est� haciendo nada
		if (Keyboard::isKeyPressed(downButton)) {													//Agacharse

			if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {
				animation_in_process = AnimationType::KICK_LOW;
				fightKeyPressed = true;
			}
			else {
				crouching = true;
				animation_in_process = AnimationType::DOWN;
			}
		}
		else if (Keyboard::isKeyPressed(forwButton)) {												//Moverse derecha
			if (Keyboard::isKeyPressed(jumpButton)) {												//Salto hacia delante
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				speed = Vector2<float>(-400, 700);
				on_air = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {											//L.Punch hacia delante
				if (Keyboard::isKeyPressed(punchButton2)) {
					animation_in_process = AnimationType::PUNCH_UPPER_MULTIPLE;
				}
				else {
					animation_in_process = AnimationType::PUNCH_UPPER;
				}
				
				fightKeyPressed = true;
				punching = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {											//M.Punch hacia delante
				animation_in_process = AnimationType::KICK_UPPER;
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_FORW;
			}
		}
		else if (Keyboard::isKeyPressed(backButton)) {												//Moverse izquierda

			if (Keyboard::isKeyPressed(jumpButton)) {												//Salto hacia atras
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				speed = Vector2<float>(400, 700);
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {												//Salto hacia delante
				if (Keyboard::isKeyPressed(punchButton2)) {
					animation_in_process = AnimationType::PUNCH_MULTIPLE;
				}
				else {
					animation_in_process = AnimationType::PUNCH;
				}
				
				punching = true;
				fightKeyPressed = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::KICK;
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_BACK;
			}

		}
		else if (Keyboard::isKeyPressed(jumpButton)) {												//Salto en parado
			animation_in_process = AnimationType::JUMP;
			speed = Vector2<float>(0, 700);
			on_air = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {		//M.Punch, H.Punch en parado
			animation_in_process = AnimationType::KICK;
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {												//L.Punch en parado
			if (Keyboard::isKeyPressed(punchButton2)) {
				animation_in_process = AnimationType::PUNCH_MULTIPLE;
			}
			else {
				animation_in_process = AnimationType::PUNCH;
			}
			
			punching = true;
			fightKeyPressed = true;
		}
		else if (Keyboard::isKeyPressed(specialButton)) {		//L.Kick, M.Kick en parado
			animation_in_process = AnimationType::SPECIAL;
		}
		else if (Keyboard::isKeyPressed(blockButton)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK;
			blocking = true;
		}
		else if (Keyboard::isKeyPressed(grabButton)) {
			animation_in_process = AnimationType::CATCH;
		}
	}
	// else -> Nothing
}

void Character::CheckDebugAnimations() {
	if (Keyboard::isKeyPressed(Keyboard::Numpad0)) { // DEBUG
		animation_in_process = AnimationType::TURN_RIGHT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad1)) {
		animation_in_process = AnimationType::GET_CAUGHT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad2)) {
		animation_in_process = AnimationType::FATALITY;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad3)) {
		animation_in_process = AnimationType::FALL;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad4)) {
		animation_in_process = AnimationType::FALL_UPPERCUT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad5)) {
		animation_in_process = AnimationType::WIN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad6)) {
		animation_in_process = AnimationType::NUTS;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad7)) {
		dying = true;
		animation_in_process = AnimationType::DYING;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad8)) {
		animation_in_process = AnimationType::FALL_BACK;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Numpad9)) {
		animation_in_process = AnimationType::TURN_LEFT;
	}
}

void Character::CheckCollisions() {
	// CheckOpponentPosition()			// Giramos el sprite si nos hemos camiado de posici�n respecto al enemigo
	if (isDamageMovement(animation_in_process)) {
		// CheckHitboxesCollisions();	// Checkeamos hitboxes si estamos golpeando
	}

}

bool Character::CheckScreenCollisions(float movement) {
	if (global_position.x < screenLeftHardLimit) {
		global_position.x = screenLeftHardLimit;
		return true;

	} else if (global_position.x > screenRightHardLimit) {
		global_position.x = screenRightHardLimit;
		return true;
	}

	if (global_position.x - movement <= screenLeftLimit) {
		moveXBack += movement;
		return true;

	} else if (global_position.x - movement >= screenRightLimit) {
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

/*
	Comprueba que tecla est� presionando el usuario y realiza una animaci�n dependiendo de eso
*/
void Character::DoAnimation() {
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
	} else { // Sigue las f�sicas del mundo (gravedad)
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

void Character::EndAnimation() {
	on_air = false;
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

	if (!mirrored) {
		speed = Vector2<float>(100, 200);
	}
	else {
		speed = Vector2<float>(-100, 200);
	}
	life -= quantity;
}

void Character::debugDraw(RenderWindow& window) {
	window.draw(hitbox);	//Para debug
	window.draw(shadow);
	window.draw(body);
}

void Character::Mirror() {
	looking_at = (looking_at == LookingAt::LEFT) ? LookingAt::RIGHT : LookingAt::LEFT;
	mirrorOnEnd = true;	
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

float Character::GetLife() {
	return life;
}

