#include "Character.h"

float moveXBack;
float moveYBack;

float totalMoveXBack = 0;


Character::Character(map<AnimationType, Movement> _animations, RectangleShape& _body, RectangleShape& _shadow, map<AnimationType, vector<RectangleShape>> hitboxes_, map<AnimationType, vector<RectangleShape>> damage_hitboxes_) {
	srand(time(NULL));
	body = _body;
	shadow = _shadow;
	animation_in_process = AnimationType::IDLE;
	animations = _animations;
	hitboxes = hitboxes_;
	damage_hitboxes = damage_hitboxes_;
}

void Character::Update(float tiempo, bool secondPlayer) {
	if (internalTimer >= updateTime) {

		internalTimer = 0.0f;
		/*global_position = body.getPosition();
		if (DEBUG_POSITION) {
			cout << "X: " << global_position.x << " - Y:" << global_position.y << endl;
			cout << "Origin: " << "(" << body.getOrigin().x << ", " << body.getOrigin().y << ")" << endl;
		}*/

		if (!freeze) {
			if (!secondPlayer)	CheckAnimation();	// Dependiendo de que ha pulsado el jugador hago una animación u otra
			else CheckAnimationP2();
		}
		
		DoAnimation();		// Realizo el siguiente frame de la animación

		if (player == 1) {

			global_position += p1PositionOffset;
			p1PositionOffset = Vector2f(0, 0);

			p1Position = getPosition();
		}
		else if (player == 2) {

			global_position += p2PositionOffset;
			p2PositionOffset = Vector2f(0, 0);

			p2Position = getPosition();
		}

		shadow.setPosition(Vector2f(global_position.x, screenFloorLimit));
		body.setPosition(global_position);
	
	}
	else {
		internalTimer += 0.025f;
	}
}


void Character::UpdateIA(float tiempo, Character opponent) {
	if (internalTimer >= updateTime) {

		internalTimer = 0.0f;

		
		if (!freeze) {
			CheckIAAnimation(opponent);
		}
		DoAnimation();

		shadow.setPosition(Vector2f(global_position.x, screenFloorLimit));
		body.setPosition(global_position);
	}
	else {
		internalTimer += 0.025f;
	}
}

void Character::CheckIAAnimation(Character opponent) {
	ChangeIAState(opponent);
	if(on_air && estado == EstadoIA::MODO_ATAQUE){
		int ataque = rand() % 2;
		switch (ataque) {
		case 0:
			animation_in_process = AnimationType::PUNCH_FROM_AIR;
			music.hit6();
			break;

		case 1:
			animation_in_process == AnimationType::KICK_FROM_AIR;
			music.hit7();
			break;
		}
		estado = EstadoIA::ALEJARSE;
		
	}else if (!doing_animation) {
		AnimationType animOp = opponent.getAnimation();
		int probabilidad = rand() % 100; // entre 0 y 99 (inclusive)
		int salto = rand() % 25;
		switch (estado) {
		case EstadoIA::IDLE:
			animation_in_process = AnimationType::IDLE;
			break;

		case EstadoIA::ACERCARSE:			
			if (salto > 23) {
				speed = Vector2<float>(-400, 700);
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				music.maleJump();
				music.doubleJump();
			}
			else {
				animation_in_process = AnimationType::WALK_FORW;
			}

			break;

		case EstadoIA::ALEJARSE:
			if (salto > 23) {
				speed = Vector2<float>(400, 700);
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				music.maleJump();
				music.doubleJump();
			}
			else {
				animation_in_process = AnimationType::WALK_BACK;

				animation_in_process = AnimationType::WALK_BACK;
				break;

		case EstadoIA::MODO_ATAQUE:

			if (difficulty_lvl == DifficultyLevel::HARD) {
				if (animOp == AnimationType::BLOCK) {
					animation_in_process = AnimationType::WIN;
				}
			}
			else {
				cout << "ATACO";
				int ataque = rand() % 4;
				switch (ataque) {
				case 0:
					if (!on_air) {
						animation_in_process = AnimationType::PUNCH;
						music.hit6();
					}
					else {
						animation_in_process = AnimationType::PUNCH_FROM_AIR;
						music.hit8();
					}

					break;

				case 1:
					if (!on_air) {
						animation_in_process = AnimationType::PUNCH_UPPER;
						music.hit6();
					}

					break;

				case 2:
					if (!on_air) {
						animation_in_process = AnimationType::KICK;
						music.hit7();
					}
					else {
						animation_in_process == AnimationType::KICK_FROM_AIR;
						music.hit8();
					}
					break;

				case 3:
					if (!on_air) {
						animation_in_process = AnimationType::KICK_LOW;
						music.hit7();
					}
					break;
				}
				estado = EstadoIA::ALEJARSE;
			}
		case EstadoIA::MODO_SEXO:
			break;

			}
		}
	}
}



/*
	Esto está petado de bugs
	No tiene ni puto sentido
*/
void Character::ChangeIAState(Character opponent) {
		
	int probabilidad = rand() % 100; // entre 0 y 99 (inclusive)
	//cout << probabilidad << "-";
	float distancia = abs(GetXPosition() - opponent.GetXPosition());
	AnimationType anim = opponent.getAnimation();

	// Cambiamos de estado
	bool siendoAtacado = opponent.isAttaking();
	if (siendoAtacado && Difficulty[difficulty_lvl] > probabilidad) {
		//cout << "AHHHHHHHHHHHHHH";
	}
	else {
		if (distancia < 100) {
			//cout << "\n" << Difficulty[difficulty_lvl] << " > ";
			//cout << probabilidad << endl;

			if (Difficulty[difficulty_lvl] > probabilidad) {
				//cout << "Entro en modo ataque" << endl;
				estado = EstadoIA::MODO_ATAQUE;
			}
			else {
				//cout << "Entro en modo me piro" << endl;
				estado = EstadoIA::ALEJARSE;
			}
		}
		else if (distancia > 400) {
			//cout << "\n" << "Entro en modo me acerco" << endl;
			estado = EstadoIA::ACERCARSE;
		}
	}	
}

void Character::initPosition(Vector2<float> initPos) {
	global_position = initPos;
}

void Character::CheckAnimation() {

	CheckDebugAnimations();

	if (fightKeyPressed) {
		if (!isAnyFightKeyPressed(player)) {
			fightKeyPressed = false;
		}
	}
	if (on_ground && fallen) {
		//if (isAnyKeyPressed(player)) {
			fallen = false;
			animation_in_process = AnimationType::RECOVER;
		//}
	}
	else if (on_air) {					// El personaje está en el aire
		if (Keyboard::isKeyPressed(punchButton)) {

			EndAndResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_AIR;
			music.hit6();
		}
		else if (Keyboard::isKeyPressed(kickButton)) {
			EndAndResetAnimation();
			animation_in_process = AnimationType::KICK_FROM_AIR;
			music.hit8();
		}
		// else -> nothing
	}
	else if (blocking) {
		if (!Keyboard::isKeyPressed(blockButton)) {
			blocking = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}
	else if (crouching) {			// El personaje está agachado
		if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton) && animation_in_process != AnimationType::PUNCH_FROM_DOWN) {
			animations[animation_in_process].animation.ResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_DOWN;
			music.hit7();
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {
			animation_in_process = AnimationType::KICK_FROM_DOWN;
			music.hit6();
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
	else if (!doing_animation) {	// El personaje no está haciendo nada
		if (Keyboard::isKeyPressed(downButton)) {													//Agacharse

			if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {
				animation_in_process = AnimationType::KICK_LOW;
				music.hit7();
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
				music.maleJump();
				music.doubleJump();
				speed = Vector2<float>(-400, 800);
				on_air = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {											//L.Punch hacia delante
				if (Keyboard::isKeyPressed(punchButton2)) {
					animation_in_process = AnimationType::PUNCH_UPPER_MULTIPLE;
					music.hit8();
				}
				else {
					animation_in_process = AnimationType::PUNCH_UPPER;
					music.hit6();
				}

				fightKeyPressed = true;
				punching = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {											//M.Punch hacia delante
				animation_in_process = AnimationType::KICK_UPPER;
				music.hit6();
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_FORW;
			}
		}
		else if (Keyboard::isKeyPressed(backButton)) {												//Moverse izquierda

			if (Keyboard::isKeyPressed(jumpButton)) {												//Salto hacia atras
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				music.maleJump();
				music.doubleJump();
				speed = Vector2<float>(400, 800);
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {												//Salto hacia delante
				if (Keyboard::isKeyPressed(punchButton2)) {
					animation_in_process = AnimationType::PUNCH_MULTIPLE;
					music.hit8();
				}
				else {
					animation_in_process = AnimationType::PUNCH;
					music.hit7();
				}

				punching = true;
				fightKeyPressed = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::KICK;
				music.hit6();
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_BACK;
			}

		}
		else if (Keyboard::isKeyPressed(jumpButton)) {												//Salto en parado
			animation_in_process = AnimationType::JUMP;
			music.maleJump();
			speed = Vector2<float>(0, 800);
			on_air = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButton)) {		//M.Punch, H.Punch en parado
			animation_in_process = AnimationType::KICK;
			music.hit7();
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButton)) {												//L.Punch en parado
			if (Keyboard::isKeyPressed(punchButton2)) {
				animation_in_process = AnimationType::PUNCH_MULTIPLE;
				music.hit8();
			}
			else {
				animation_in_process = AnimationType::PUNCH;
				music.hit7();
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


void Character::CheckAnimationP2() {

	CheckDebugAnimations();

	if (fightKeyPressed) {
		if (!isAnyFightKeyPressed(player)) {
			fightKeyPressed = false;
		}
	}
	if (fallen) {
		//if (isAnyKeyPressed(player)) {
			fallen = false;
			animation_in_process = AnimationType::RECOVER;
		//}
	}
	else if (on_air) {					// El personaje está en el aire
		if (Keyboard::isKeyPressed(punchButton2P2)) {

			EndAndResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_AIR;
			music.hit6();
		}
		else if (Keyboard::isKeyPressed(kickButtonP2)) {
			EndAndResetAnimation();
			animation_in_process = AnimationType::KICK_FROM_AIR;
			music.hit7();
		}
		// else -> nothing
	}
	else if (blocking) {
		if (!Keyboard::isKeyPressed(blockButtonP2)) {
			blocking = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
	}
	else if (crouching) {			// El personaje está agachado
		if (!fightKeyPressed && Keyboard::isKeyPressed(punchButtonP2) && animation_in_process != AnimationType::PUNCH_FROM_DOWN) {
			animations[animation_in_process].animation.ResetAnimation();
			animation_in_process = AnimationType::PUNCH_FROM_DOWN;
			music.hit8();
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButtonP2)) {
			animation_in_process = AnimationType::KICK_FROM_DOWN;
			music.hit7();
			fightKeyPressed = true;
		}
		else if (Keyboard::isKeyPressed(blockButtonP2)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK_LOW;
			blocking = true;
		}
		else if (!Keyboard::isKeyPressed(downButtonP2)) {
			crouching = false;
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
		else {
			if (!doing_animation) {
				animation_in_process = AnimationType::DOWN;
			}
		}
	}
	else if (!doing_animation) {	// El personaje no está haciendo nada
		if (Keyboard::isKeyPressed(downButtonP2)) {													//Agacharse

			if (!fightKeyPressed && Keyboard::isKeyPressed(kickButtonP2)) {
				animation_in_process = AnimationType::KICK_LOW;
				music.hit7();
				fightKeyPressed = true;
			}
			else {
				crouching = true;
				animation_in_process = AnimationType::DOWN;
			}
		}
		else if (Keyboard::isKeyPressed(forwButtonP2)) {												//Moverse derecha
			if (Keyboard::isKeyPressed(jumpButtonP2)) {												//Salto hacia delante
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				music.maleJump();
				music.doubleJump();
				speed = Vector2<float>(-400, 800);
				on_air = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButtonP2)) {											//L.Punch hacia delante
				if (Keyboard::isKeyPressed(punchButton2P2)) {
					animation_in_process = AnimationType::PUNCH_UPPER_MULTIPLE;
					music.hit8();
				}
				else {
					animation_in_process = AnimationType::PUNCH_UPPER;
					music.hit6();
				}

				fightKeyPressed = true;
				punching = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButtonP2)) {											//M.Punch hacia delante
				animation_in_process = AnimationType::KICK_UPPER;
				music.hit7();
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_FORW;
			}
		}
		else if (Keyboard::isKeyPressed(backButtonP2)) {												//Moverse izquierda

			if (Keyboard::isKeyPressed(jumpButtonP2)) {												//Salto hacia atras
				animation_in_process = AnimationType::JUMP_AND_MOVE;
				music.maleJump();
				music.doubleJump();
				speed = Vector2<float>(400, 800);
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButtonP2)) {												//Salto hacia delante
				if (Keyboard::isKeyPressed(punchButton2P2)) {
					music.hit8();
					animation_in_process = AnimationType::PUNCH_MULTIPLE;
				}
				else {
					animation_in_process = AnimationType::PUNCH;
					music.hit6();
				}

				punching = true;
				fightKeyPressed = true;
			}
			else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButtonP2)) {											//L.Punch hacia delante
				animation_in_process = AnimationType::KICK;
				music.hit8();
				fightKeyPressed = true;
			}
			else {																					//Solo moverse
				animation_in_process = AnimationType::WALK_BACK;
			}

		}
		else if (Keyboard::isKeyPressed(jumpButtonP2)) {												//Salto en parado
			animation_in_process = AnimationType::JUMP;
			music.maleJump();
			speed = Vector2<float>(0, 800);
			on_air = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(kickButtonP2)) {		//M.Punch, H.Punch en parado
			animation_in_process = AnimationType::KICK;
			music.hit7();
			fightKeyPressed = true;
		}
		else if (!fightKeyPressed && Keyboard::isKeyPressed(punchButtonP2)) {												//L.Punch en parado
			if (Keyboard::isKeyPressed(punchButton2P2)) {
				animation_in_process = AnimationType::PUNCH_MULTIPLE;
				music.hit8();
			}
			else {
				animation_in_process = AnimationType::PUNCH;
				music.hit6();
			}

			punching = true;
			fightKeyPressed = true;
		}
		else if (Keyboard::isKeyPressed(specialButtonP2)) {		//L.Kick, M.Kick en parado
			animation_in_process = AnimationType::SPECIAL;
		}
		else if (Keyboard::isKeyPressed(blockButtonP2)) {												//H.Kick en parado
			animation_in_process = AnimationType::BLOCK;
			blocking = true;
		}
		else if (Keyboard::isKeyPressed(grabButtonP2)) {
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
		animations[animation_in_process].animation.ResetAnimation();
		if (!mirrored) {
			speed = Vector2<float>(100, 200);
		}
		else {
			speed = Vector2<float>(-100, 200);
		}
		on_ground = false;
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

bool Character::CheckScreenCollisions(float movement) {
	Vector2f opponentPos;
	if (player == 1) {
		opponentPos = p2Position;
	}
	else if (player == 2) {
		opponentPos = p1Position;
	}

	if (global_position.x - movement <= screenLeftLimit) {

		if ((opponentPos.x + movement >= screenRightLimit) || (totalMoveXBack <= screenLeftHardLimit)) {
			return true;
		}
		else {
			moveXBack += movement;
			totalMoveXBack -= moveXBack;
			if (player == 1) {
				p2PositionOffset.x += movement;
			}
			else if (player == 2) {
				p1PositionOffset.x += movement;
			}
			return true;
		}

	} else if (global_position.x - movement >= screenRightLimit) {

		if ((opponentPos.x + movement <= screenLeftLimit) || (totalMoveXBack >= screenRightHardLimit)) {
			return true;
		} else {
			moveXBack += movement;
			totalMoveXBack -= moveXBack;
			if (player == 1) {
				p2PositionOffset.x += movement;
			}
			else if (player == 2) {
				p1PositionOffset.x += movement;
			}
			return true;
		}
	}

	if (global_position.y > screenFloorLimit) {
		global_position.y = screenFloorLimit;
		speed = Vector2<float>(0, 0);
		if (!isBlockingMovement(animation_in_process)) {
			animations[animation_in_process].animation.RecieveFlagEvent();
		}
		on_ground = true;
		return true;
	}

	return false;
}

/*
	Comprueba que tecla está presionando el usuario y realiza una animación dependiendo de eso
*/
void Character::DoAnimation() {
	doing_animation = true;
	//debug_animation();

	bool finished = false;

	if (!fallen) {
		finished = animations[animation_in_process].animation.DoAnimation(body, shadow, hitbox, mirrored,
			animations[animation_in_process].hitbox_positions_X, animations[animation_in_process].hitbox_positions_Y, global_position, hitboxes[animation_in_process],
			damage_hitbox, animations[animation_in_process].damage_hitbox_positions_X, animations[animation_in_process].damage_hitbox_positions_Y, damage_hitboxes[animation_in_process]);
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
	

	if (isFixedMovement(animation_in_process) && !isBlockingMovement(animation_in_process)) { // Sigue un desplazamiento fijado
		Vector2<float> mov = animations[animation_in_process].traslation;
		mov.x = mirrored ? -mov.x : mov.x;
		if (mov.x != 0) { 
			if (!CheckScreenCollisions(-mov.x)) {
				global_position += mov;
			}
		}
	} else { // Sigue las físicas del mundo (gravedad)

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
			if (!isBlockingMovement(animation_in_process)) {
				animations[animation_in_process].animation.RecieveFlagEvent();
			}
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
			else {
				Keyboard::Key aux = backButtonP2;
				backButtonP2 = forwButtonP2;
				forwButtonP2 = aux;
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
	window.draw(damage_hitbox);	//Para debug
	window.draw(shadow);
	window.draw(body);
}

void Character::RestartMirror(bool playerTwo) {

	forwButton = Keyboard::D;
	backButton = Keyboard::A;

	forwButtonP2 = Keyboard::Right;
	backButtonP2 = Keyboard::Left;

	mirroring = false;
	mirrorOnEnd = false;

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

bool Character::isAttaking() {
	return isAnyFightKeyPressed(player);
}