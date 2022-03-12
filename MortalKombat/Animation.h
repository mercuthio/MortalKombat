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
	Animation(int _duration, Texture _sprite_sheet, Vector2<float> movement[MAX_IMG_PER_ANIM], Vector2<int> _first_frame, Vector2<int> size, int _offset, bool backwards, bool _isMutex);
	//~Animation() = default;;
	bool DoAnimation(RectangleShape& cuerpo);
	IntRect uvRect;

private:
	Texture sprite_sheet;							// Spritesheet de la animacion
	int frame_number = 0;

	int	duration = 0;								// Total de imagenes de la animacion
	bool isPersistent = false;
	bool isMutex = false;

	//Vector2<float> frame_size[N_ANIMATIONS];		// Cuanto aumenta de tamaño el sprite. En valores globales (no relativos)
	Vector2<int> first_frame;						// Localización del primer frame en el Sprite Sheet
	Vector2<int> this_frame;
	Vector2<int> size;
	Vector2<int> offset;										// Cuanto varia el ejeX hasta llegar al principio del siguiente frame
	Vector2<float> relative_mov[MAX_IMG_PER_ANIM];		// Cuanto se mueve la imagen en los ejes X e Y relativo al frame anterior
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _longitud: Cuantas imaagenes componen la animacion (< )
	@param _imagen: Sprite-sheet del cual está compuesta 
	@param _tamnyo_img: tamanyo de cada frame de la animacion
	@param
	@param _animacio: 
*/

Animation::Animation(int _duration, Texture _sprite_sheet, Vector2<float> movement[MAX_IMG_PER_ANIM], Vector2<int> _first_frame, Vector2<int> _size, int _offset, bool backwards, bool _isMutex) {
	duration = _duration;
	sprite_sheet = _sprite_sheet;
	for (int i = 0; i < _duration; i++) {	// Si hago << position = _position >> da error de compilacion
		relative_mov[i] = movement[i];		// No me deja hacerlo de otra manera
	}
	first_frame = _first_frame;
	size = _size;
	
	if (backwards) {
		offset = Vector2<int>(-size.x + _offset, 0);
	}
	else {
		offset = Vector2<int>(size.x + _offset, 0);
	}

	this_frame = first_frame;
	frame_number = 0;
	isMutex = _isMutex;
}

bool Animation::DoAnimation(RectangleShape& cuerpo) {

	bool finished = false;

	if (frame_number >= duration && !isPersistent) {
		frame_number = 0;
		this_frame = first_frame;
		finished = isMutex;
	}

	if (frame_number < duration) {
		// Modifica el tamanyo (no relativo)
		//cuerpo.setSize(frame_size[this_frame]);
		cuerpo.setTexture(&sprite_sheet);
		cuerpo.setTextureRect(IntRect(this_frame, size));
		this_frame += offset;
		// Mueve el sprite relativo a su posicion anterior (puede ser negativo)
		cuerpo.setPosition(cuerpo.getPosition() + relative_mov[frame_number]);
		cout << "\tFrame actual: " << frame_number << endl;

		// Pasa al siguiente frame 
		frame_number++;
	}

	return finished;
}

#endif