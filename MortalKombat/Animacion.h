#pragma once
#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace sf;
using namespace std;

class Animacion {
public:
	Animacion(int _longitud, Texture _imagen, float _tamanyo_img, bool _fijado, Vector2<float> _animacion, float _inicio, float _offset);
	~Animacion();
	void RealizarAnimacion();

private:
	int	longitud;							// Total de imagenes de la animacion
	Texture imagen;							// Spritesheet de la animacion
	Vector2<float> anim[MAX_IMG_POR_ANIM];	// Vector de posiciones de la animacion respecto la imagen
	int velocidad_refresco;					// Cada cuantos frames se realiza la animacion
	int frame_actual;
	float tamanyo_img;
};

/*
	Crea una animacion compuesta por una sprite-sheet de imagenes
	
	@param _longitud: Cuantas imaagenes componen la animacion (< )
	@param _imagen: Sprite-sheet del cual está compuesta 
	@param _tamnyo_img: tamanyo de cada frame de la animacion
	@param _fijado: 
				true  = se introduce la posicion inicial y el offset entre frames
				false = se introduce el vector de posiciones de los frames
	@param _animacion: posiciones
	@param
	@param _animacio: 
*/
Animacion::Animacion(int _longitud, Texture _imagen, float _tamanyo_img, bool _fijado, Vector2<float> _animacion, float _inicio, float _offset) {
	longitud = _longitud;
	imagen = _imagen;
	anim = _animacion;
}

void Animacion::RealizarAnimacion() {

}

#endif