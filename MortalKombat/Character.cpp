#include "Character.h"

float moveXBack;
float moveYBack;

Character::Character(map<AnimationType, Movement> _animations, RectangleShape& _body, map<AnimationType, vector<RectangleShape>> hitboxes_) {
	body = _body;
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


		CheckAnimation();	// Dependiendo de que ha pulsado el jugador hago una animación u otra
		DoAnimation();		// Realizo el siguiente frame de la animación

		CheckCollisions();

		int current_frame = animations[animation_in_process].animation.current_animation;
		int frame = animations[animation_in_process].animation.animations[current_frame].frame_number;

		hitbox = hitboxes[animation_in_process][frame-1];

		cout << "X: " << hitbox.getSize().x / 3 << endl;
		cout << "Y: " << hitbox.getSize().y / 3 << endl;
		cout << "Frame actual: " << frame - 1 << endl;
		cout << "OX: " << hitbox.getOrigin().x << endl;
		cout << "OY: " << hitbox.getOrigin().y << endl;

		hitbox.setPosition(global_position.x + 302, global_position.y + 340);

		body.setPosition(global_position);
	
	}
	else {
		internalTimer += 0.025f;
	}
}

void Character::UpdateIA(float time) {
	if (internalTimer >= updateTime) {

		internalTimer = 0.0f;

		//Elijo una acción dependiendo del jugador
		DoAnimation();		// Realizo el siguiente frame de la animación

		CheckCollisions();

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
	if (fallen) {
		if (isAnyKeyPressed()) {
			fallen = false;
			animation_in_process = AnimationType::RECOVER;
		}
	}
	else if (on_air) {					// El personaje está en el aire
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
				speed = Vector2<float>(400, 700);
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
			speed = Vector2<float>(0, 700);
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
		else if (Keyboard::isKeyPressed(grabButton)) {
			animation_in_process = AnimationType::CATCH;
		}
	}
	// else -> Nothing
}

void Character::CheckDebugAnimations() {
	if (Keyboard::isKeyPressed(Keyboard::M)) { // DEBUG
		Mirror();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Z)) {
		animation_in_process = AnimationType::GET_CAUGHT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::F)) {
		animation_in_process = AnimationType::FATALITY;
	}
	else if (Keyboard::isKeyPressed(Keyboard::T)) {
		animation_in_process = AnimationType::FALL;
	}
	else if (Keyboard::isKeyPressed(Keyboard::R)) {
		animation_in_process = AnimationType::FALL_UPPERCUT;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Y)) {
		animation_in_process = AnimationType::WIN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::N)) { 
		animation_in_process = AnimationType::NUTS;
	}
	else if (Keyboard::isKeyPressed(Keyboard::C)) {
		dying = true;
		animation_in_process = AnimationType::DYING;
	}
	else if (Keyboard::isKeyPressed(Keyboard::V)) {
		animation_in_process = AnimationType::FALL_BACK;
	}
}

void Character::CheckCollisions() {
	CheckScreenCollisions();
	// CheckOpponentPosition()			// Giramos el sprite si nos hemos camiado de posición respecto al enemigo
	if (isDamageMovement(animation_in_process)) {
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
	}
}

/*
	Comprueba que tecla está presionando el usuario y realiza una animación dependiendo de eso
*/
void Character::DoAnimation() {
	doing_animation = true;
	//debug_animation();

	bool finished = false;
	
	if (!fallen) {
		finished = animations[animation_in_process].animation.DoAnimation(body);
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
	}
	

	if (isFixedMovement(animation_in_process)) { // Sigue un desplazamiento fijado
		Vector2<float> mov = animations[animation_in_process].traslation;
		mov.x = leftOfOpponent ? mov.x : -mov.x;
		moveXBack = mov.x;
		cout << moveXBack << " MUEVE ESCENARIO" << endl;
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
		if (!hasFlag(animation_in_process)) {
			EndAnimation();
		}
		else {
			EndAndResetAnimation();
		}
	}
}

void Character::EndAnimation() {
	cout << "ENDING ANIMATION\n";

	doing_animation = false;
	on_air = false;
	crouching = false;
	punching = false;
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

void Character::debugDraw(RenderWindow& window) {
	window.draw(hitbox);	//Para debug
	window.draw(body);
}

void Character::Mirror() {
	Keyboard::Key aux = backButton;
	backButton = forwButton;
	forwButton = aux;

	// Recalculate hitboxes positions
	if (leftOfOpponent) {

	}
	leftOfOpponent = !leftOfOpponent;
	body.setOrigin(125, 0);
	body.setScale(body.getScale().x * -1, 1);
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

float Character::GetLife() {
	return life;
}

