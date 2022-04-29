#include "Animation.h"

Animation::Animation(int _duration, Texture* _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, vector<Recover> _recovery, vector<int> _flagged_frames, int _wait_until) {

	duration = _duration;
	sprite_sheet = _sprite_sheet;
	first_frame = _first_frame;
	size = _size;
	wait_until = _wait_until;

	if (backwards) {
		offset = Vector2<int>(-size.x - _offset, 0);
	}
	else {
		offset = Vector2<int>(size.x + _offset, 0);
	}

	recovery = _recovery;
	this_frame = first_frame;
	lock = _lock;

	flagged_frames = _flagged_frames;
	n_of_flagged_frames = flagged_frames.size();
	this_flagged_frame = 0;
}

/*
	Realiza la printura en el sprite 'cuerpo' del siguiente frame de la animación
	el cual puede estar condicionado por factores externos
*/

bool Animation::DoAnimation(RectangleShape& body, RectangleShape& shadow, RectangleShape& hitbox, bool mirrored,
	float hitbox_positions_X[], float hitbox_positions_Y[], Vector2<float> globalPosition, vector<RectangleShape> hitboxes,
	RectangleShape& damage_hitbox, float damage_hitbox_positions_X[], float damage_hitbox_positions_Y[], vector<RectangleShape> damage_hitboxes) {

	bool finished = !lock;

	shadow.setTexture(sprite_sheet);
	body.setTexture(sprite_sheet);

	float position_x = hitbox_positions_X[frame_number-1];
	float position_y = hitbox_positions_Y[frame_number-1];

	//cout << hitboxes.size() << "-----" << frame_number << endl;

	if (hitboxes.size() >= frame_number) {		//No todas las animaciones tienen hitbox
		hitbox = hitboxes[frame_number - 1];
	}

	if (damage_hitboxes.size() >= frame_number) {
		damage_hitbox = damage_hitboxes[frame_number - 1];
	}

	if (mirrored) {

		position_x = body.getSize().x - (position_x + hitbox.getSize().x);
		hitbox.setPosition(globalPosition.x + position_x, globalPosition.y + position_y);

		position_x = damage_hitbox_positions_X[frame_number - 1];
		position_x = body.getSize().x - (position_x + hitbox.getSize().x);
		position_y = damage_hitbox_positions_Y[frame_number - 1];
		damage_hitbox.setPosition(globalPosition.x + position_x, globalPosition.y + position_y);

		IntRect uRectBody;
		uRectBody.left = this_frame.x - (size.x * -1);
		uRectBody.top = this_frame.y;
		uRectBody.width = size.x * -1;
		uRectBody.height = size.y;

		IntRect uRectShadow;
		uRectShadow.left = this_frame.x - (size.x * -1);
		uRectShadow.top = this_frame.y + 228;
		uRectShadow.width = size.x * -1;
		uRectShadow.height = size.y;

		body.setTextureRect(uRectBody);
		shadow.setTextureRect(uRectShadow);
	}
	else {

		hitbox.setPosition(globalPosition.x + position_x, globalPosition.y + position_y);

		position_x = damage_hitbox_positions_X[frame_number - 1];
		position_y = damage_hitbox_positions_Y[frame_number - 1];

		damage_hitbox.setPosition(globalPosition.x + position_x, globalPosition.y + position_y);

		body.setTextureRect(IntRect(this_frame, size));
		shadow.setTextureRect(IntRect(Vector2i(this_frame.x, this_frame.y + 228), size));
	}

	current_wait++;
	if (current_wait < wait_until) {
		return false;
	}
	current_wait = 0;

	// Si tengo que esperar que algo externo me diga que tengo que cambiar la textura
	if (n_of_flagged_frames > 0 && this_flagged_frame < n_of_flagged_frames) {
		if (flagged_frames[this_flagged_frame] == frame_number) {
			return false;
		}
	}

	if (this_recovery < recovery.size()) {
		if (recovery[this_recovery].frame == frame_number) {
			recovering = true;
			this_recover_frame++;
			if (this_recover_frame > recovery[this_recovery].rec_frames) {
				this_recovery++;
				this_recover_frame = 0;
				recovering = false;
			}
		}
	}
	
	if(!recovering) {
		this_frame += offset;
		frame_number++;
	}

	// Si se ha acabado la animación
	if (frame_number > duration && !isPersistent) {
		frame_number = 1;
		this_recovery = 0;
		this_frame = first_frame;
		finished = true;
		recovering = false;
		
	}

	return finished;
}

/*
	Avisa a la animación de que puede continuar con el siguiente frame

	Función útil para movimientos que dependen de la gravedad o presiones de teclas
	por parte del usuario
*/
bool Animation::RecieveFlagEvent() {
	// if (isPersistent){}
	this_flagged_frame++;
	return this_flagged_frame < n_of_flagged_frames;
}

void Animation::ResetAnimation() {
	frame_number = 1;
	this_recovery = 0;
	this_frame = first_frame;
	this_flagged_frame = 0;
}