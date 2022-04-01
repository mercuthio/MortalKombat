#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>

#include "GlobalVars.h"

constexpr bool DEBUG = false;

using namespace sf;
using namespace std;

class Animation {
public:
	Animation() = default;
	Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames);
	//~Animation() = delete;
	bool DoAnimation(RectangleShape& body);
	void ResetAnimation();
	bool RecieveFlagEvent();

private:
	Texture sprite_sheet;						// Spritesheet de la animacion
	int frame_number = 1;

	int	duration = 0;							// Total de imagenes de la animacion
	bool isPersistent = false;
	bool lock = false;
	int this_recovery = 0;
	int recovery = 0;
	bool recovering = false;
	bool waiting_flag = false;

	Vector2<int> first_frame;					// Localización del primer frame en el Sprite Sheet
	Vector2<int> this_frame;
	Vector2<int> size;
	Vector2<int> offset;						// Cuanto varia el ejeX hasta llegar al principio del siguiente frame
	vector<int> flagged_frames;
	int n_of_flagged_frames = 0;
	int this_flagged_frame = 0;
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _duration:		Cuantas imaagenes componen la animacion
	@param _sprite_sheet:	Sprite-sheet del cual está compuesta 
	@param _first_frame:	Localización del primer sprite en '_sprite_sheet'
	@param _size:			Tamanyo de cada frame de la animacion
	@param _offset:			Distancia en pixeles entre los frames de la animacion. Siempre es un valor positivo
	@param backwards:		'false' Si el desplazamiento se hace de izquierda a derecha. 'true' si es de izquierda a derecha 
	@param _lock:			'true' si se tiene que hacer la animacion completa antes de continuar o 'false' si se puede cancelar
	@param _recovery:		Número de frames los cuales tarda el personaje en recuperarse antes de terminar la animación
	@param _flagged_frames:	Frames los cuales la animación esperará a algún evento
	@param _mirrored:		'false' pinta el sprite tal y como aparece en _sprite_sheet. 'true' lo pinta mirando al lado opuesto en el eje x
*/

Animation::Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _lock, int _recovery, vector<int> _flagged_frames) {
	
	duration = _duration;
	sprite_sheet = _sprite_sheet;
	first_frame = _first_frame;
	size = _size;

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

	body.setTexture(&sprite_sheet);
	body.setTextureRect(IntRect(this_frame, size));

	// Si tengo que esperar que algo externo me diga que tengo que cambiar la textura
	if (n_of_flagged_frames > 0) {
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

#endif