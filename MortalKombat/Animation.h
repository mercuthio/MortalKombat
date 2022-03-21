#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Definitions.h"

using namespace sf;
using namespace std;

class Animation {
public:
	Animation() = default;
	Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> size, int _offset, bool backwards, bool _isMutex, int _recovery, vector<int> _flagged_frames, bool _mirrored);
	//~Animation() = delete;
	bool DoAnimation(RectangleShape& cuerpo);
	bool RecieveFlagEvent();

private:
	Texture sprite_sheet;						// Spritesheet de la animacion
	int frame_number = 1;

	int	duration = 0;							// Total de imagenes de la animacion
	bool isPersistent = false;
	bool isMutex = false;
	int this_recovery = 0;
	int recovery = 0;
	bool recovering = false;
	bool waiting_flag = false;

	Vector2<int> first_frame;					// Localización del primer frame en el Sprite Sheet
	Vector2<int> this_frame;
	Vector2<int> size;
	Vector2<int> offset;						// Cuanto varia el ejeX hasta llegar al principio del siguiente frame
	vector<int> flagged_frames;
	int n_of_flagged_frames;
	int this_flagged_frame;
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _duration:		Cuantas imaagenes componen la animacion
	@param _sprite_sheet:	Sprite-sheet del cual está compuesta 
	@param _first_frame:	Localización del primer sprite en '_sprite_sheet'
	@param _size:			Tamanyo de cada frame de la animacion
	@param _offset:			Distancia en pixeles entre los frames de la animacion. Siempre es un valor positivo
	@param backwards:		'false' Si el desplazamiento se hace de izquierda a derecha. 'true' si es de izquierda a derecha 
	@param _isMutex:		'true' si se tiene que hacer la animacion completa antes de continuar o 'false' si se puede cancelar
	@param _recovery:		Número de frames los cuales tarda el personaje en recuperarse antes de terminar la animación
	@param _flagged_frames:	Frames los cuales la animación esperará 
	@param _mirrored:		'false' pinta el sprite tal y como aparece en _sprite_sheet. 'true' lo pinta mirando al lado opuesto en el eje x
*/

Animation::Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _isMutex, int _recovery, vector<int> _flagged_frames, bool _mirrored) {
	
	duration = _duration;
	sprite_sheet = _sprite_sheet;
	first_frame = _first_frame;
	size = _size;

	// TODO: No he probado a poner mirrored + backwards juntos, muy probablemnte falle
	if (_mirrored) {
		first_frame.x += size.x;
		size.x = -size.x;
	}
	
	if (backwards) {
		offset = Vector2<int>(-size.x - _offset, 0);
	}
	else {
		offset = Vector2<int>(size.x + _offset, 0);
	}

	recovery = _recovery;
	this_frame = first_frame;
	isMutex = _isMutex;

	flagged_frames = _flagged_frames;
	n_of_flagged_frames = flagged_frames.size();
	this_flagged_frame = 0;
}

/*
	Realiza la printura en el sprite 'cuerpo' del siguiente frame de la animación
	el cual puede estar condicionado por factores externos
*/
bool Animation::DoAnimation(RectangleShape& cuerpo) {

	bool finished = !isMutex;
	cout << "\FA: " << frame_number << "\tRE: " << this_recovery << endl;

	cuerpo.setTexture(&sprite_sheet);
	cuerpo.setTextureRect(IntRect(this_frame, size));

	// Si tengo que esperar que algo externo me diga que tengo que cambiar la textura
	if (flagged_frames[this_flagged_frame] == frame_number) {
		return finished;
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
	waiting_flag = false;
	this_flagged_frame++;	
}

#endif