#include "Animation.h"

Animation::Animation(int _duration, Texture* _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames, int _wait_until) {

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

bool Animation::DoAnimation(RectangleShape& body) {
	bool finished = !lock;
	if (DEBUG)
		cout << "\tFA: " << frame_number << "\tRE: " << this_recovery << endl;

	body.setTexture(sprite_sheet);
	body.setTextureRect(IntRect(this_frame, size));

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

	// Si no me estoy recuperando
	if (!recovering) {
		// Pasa al siguiente frame 
		this_frame += offset;
		frame_number++;
	}

	// Si se ha acabado la animación
	if (frame_number > duration && !isPersistent) {
		// No me estoy recueprando
		if (!recovering) {
			this_frame -= offset;
		}
		recovering = true;
		// Aún no me he terminado de recueprar
		if (this_recovery < recovery) {
			this_recovery++;
		}
		// Ya ha terminado de recuperarme
		else {
			frame_number = 1;
			this_recovery = 0;
			this_frame = first_frame;
			finished = true;
			recovering = false;
		}
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