#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Definitions.h"

using namespace sf;
using namespace std;

class Animation {
public:
	Animation() = default;
	Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> size, int _offset, bool backwards, bool _isMutex, int _recovery);
	//~Animation() = delete;
	bool DoAnimation(RectangleShape& cuerpo);
	IntRect uvRect;

private:
	Texture sprite_sheet;							// Spritesheet de la animacion
	int frame_number = 1;

	int	duration = 0;								// Total de imagenes de la animacion
	bool isPersistent = false;
	bool isMutex = false;
	int this_recovery = 0;
	int recovery = 0;
	bool recovering = false;

	Vector2<int> first_frame;						// Localización del primer frame en el Sprite Sheet
	Vector2<int> this_frame;
	Vector2<int> size;
	Vector2<int> offset;								// Cuanto varia el ejeX hasta llegar al principio del siguiente frame
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _duration: Cuantas imaagenes componen la animacion
	@param _sprite_sheet: Sprite-sheet del cual está compuesta 
	@param _first_frame: Localización del primer sprite en '_sprite_sheet'
	@param _size: tamanyo de cada frame de la animacion
	@param _offset: distancia en pixeles entre los frames de la animacion
	@param backwards: si el desplazamiento se hace de izquierda a derecha (false) o de izquierda a derecha (true)
	@param _isMutex: 'true' si se tiene que hacer la animacion completa antes de continuar o 'false' si se puede cancelar
*/

Animation::Animation(int _duration, Texture _sprite_sheet, Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _isMutex, int _recovery) {
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
	isMutex = _isMutex;
}

bool Animation::DoAnimation(RectangleShape& cuerpo) {

	bool finished = !isMutex;
	cout << "\FA: " << frame_number << "\tRE: " << this_recovery << endl;

	cuerpo.setTexture(&sprite_sheet);
	cuerpo.setTextureRect(IntRect(this_frame, size));

	if (!recovering) {
		// Pasa al siguiente frame 
		this_frame += offset;
		frame_number++;
	}

	if (frame_number > duration && !isPersistent) {
		if (!recovering) {
			this_frame -= offset;
		}
		recovering = true;
		if (this_recovery < recovery) {
			this_recovery++;
		}
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

#endif