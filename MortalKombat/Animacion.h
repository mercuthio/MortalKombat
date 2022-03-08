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
	void RealizarAnimacion(RectangleShape& cuerpo);
	IntRect uvRect;

private:
	int	duracion;							// Total de imagenes de la animacion
	bool persistente;
	Texture imagen;							// Spritesheet de la animacion
	Vector2<float> anim[MAX_IMG_POR_ANIM];	// Vector de posiciones de la animacion respecto la imagen
	int velocidad_refresco;					// Cada cuantos frames se realiza la animacion
	int frame_actual;
	Vector2<float> tamanyo_frame[MAX_IMG_POR_ANIM];
	Vector2<float> despl_relativo[MAX_IMG_POR_ANIM];
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
Animacion::Animacion(int _duracion, Texture _imagen, float _tamanyo_img, bool _fijado, Vector2<float> _animacion, float _inicio, float _offset) {
	duracion = _duracion;
	imagen = _imagen;
	anim = _animacion;
	frame_actual = 0;
}

void Animacion::RealizarAnimacion(RectangleShape& cuerpo) {

	if (frame_actual <= duracion) {
		// Modifica el tamanyo (no relativo)
		cuerpo.setSize(tamanyo_frame);

		// Mueve el sprite relativo a su posicion anterior (puede ser negativo)
		cuerpo.setPosition(cuerpo.getPosition() + despl_relativo[frame_actual]);

		// Pasa al siguiente frame 
		frame_actual++;
	}
	else if (!persistente) {
		// Reiniciamos la animacion si hemos terminado
		frame_actual = 0;
	}
}

#endif