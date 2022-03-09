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
	Animation(int _duration, Texture _sprite_sheet, Vector2<float> movement[MAX_IMG_PER_ANIM], Vector2<int> _first_frame, Vector2<int> size, int _offset);
	~Animation();
	void DoAnimation(RectangleShape& cuerpo);
	IntRect uvRect;

private:
	Texture sprite_sheet;							// Spritesheet de la animacion
	int this_frame;

	int	duration;								// Total de imagenes de la animacion
	bool isPersistent;
	
	//Vector2<float> frame_size[N_ANIMATIONS];		// Cuanto aumenta de tamaño el sprite. En valores globales (no relativos)
	Vector2<int> first_frame;						// Localización del primer frame en el Sprite Sheet
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
Animation::Animation(int _duration, Texture _sprite_sheet, Vector2<float> movement[MAX_IMG_PER_ANIM], Vector2<int> _first_frame, Vector2<int> size, int _offset) {
	duration = _duration;
	sprite_sheet = _sprite_sheet;
	for (int i = 0; i < _duration; i++) {	// Si hago << position = _position >> da error de compilacion
		relative_mov[i] = movement[i];		// No me deja hacerlo de otra manera
	}
	first_frame = _first_frame;
	offset = Vector2<int>(first_frame.x + _offset, 0);
	this_frame = 0;
}

void Animation::DoAnimation(RectangleShape& cuerpo) {

	if (this_frame <= duration) {
		// Modifica el tamanyo (no relativo)
		//cuerpo.setSize(frame_size[this_frame]);

		cuerpo.setTextureRect(IntRect(first_frame + offset, size));

		// Mueve el sprite relativo a su posicion anterior (puede ser negativo)
		cuerpo.setPosition(cuerpo.getPosition() + relative_mov[this_frame]);

		// Pasa al siguiente frame 
		this_frame++;
	}
	else if (!isPersistent) {
		// Reiniciamos la animacion si hemos terminado
		this_frame = 0;
	}
}

#endif