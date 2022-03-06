#pragma once
#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Animacion.h"
#include "Definiciones.h"

using namespace sf;
using namespace std;



class Personaje {
public:
	Personaje(Animacion animaciones[N_ANIMACIONES]);
	~Personaje() = default;
	void RealizarAnimacion(TipoAnimacion tipo);

private:
	Vector2<float> posicion_global;
	Animacion a_salto;
	Animacion a_golpe_flojo; // a_XXX para las animaciones
	Animacion a_golpe_fuerte;
	//...


};

/*
	Define un personaje con su conjunto de animaciones

	@param animaciones: vector de N_ANIMACIONES animaciones
	@param
	@param
	@param
*/
Personaje::Personaje(Animacion animaciones[N_ANIMACIONES]) {

}

void Personaje::RealizarAnimacion(TipoAnimacion tipo) {

	switch (tipo){
	SALTO:
		break;

	GOLPE_FUERTE:
		break;

	GOLPE_FLOJO:
		break;

	default:
		break;
	}
}

#endif