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
	void RealizarAnimacion();
	void Actualizar(float tiempo);
	void TerminarAnimacion();
	void RecibirGolpe(int vida);
	void GastarEnergia(int cantidad);
	void ComprobarMovimiento();
	void ComprobarColisiones();

private:
	RectangleShape cuerpo;
	Vector2<float> posicion_global;
	int vida;
	int energia;
	map<TipoAnimacion, Animacion> animaciones; // mapa de enum -> animacion
	TipoAnimacion animacion_en_proceso;
};

/*
	Define un personaje con su conjunto de animaciones

	@param animaciones: vector de N_ANIMACIONES animaciones
	@param
	@param
	@param
*/
Personaje::Personaje(Animacion animaciones[N_ANIMACIONES]) {
	animacion_en_proceso = TipoAnimacion::IDLE;
}

void Personaje::Actualizar(float tiempo) {

	ComprobarMovimiento();

	RealizarAnimacion();

	ComprobarColisiones();
}

void Personaje::ComprobarMovimiento() {
	
	if (Keyboard::isKeyPressed(Keyboard::S)) {												//Agacharse

		if (Keyboard::isKeyPressed(Keyboard::A)) {												//Bloquear agachado

		}
		else {																					//Solo moverse
			animacion_en_proceso = TipoAnimacion::AGACHE;
		}
	
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {											//Moverse derecha

		if (Keyboard::isKeyPressed(Keyboard::W)) {												//Salto hacia delante
			animacion_en_proceso = TipoAnimacion::SALTO_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::T)) {											//L.Punch hacia delante
			animacion_en_proceso = TipoAnimacion::PUNYO_FLOJO_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Y)) {											//M.Punch hacia delante
			animacion_en_proceso = TipoAnimacion::PUNYO_MEDIO_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::U)) {											//H.Punch hacia delante
			animacion_en_proceso = TipoAnimacion::PUNYO_FUERTE_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::G)) {											//L.Kick hacia delante
			animacion_en_proceso = TipoAnimacion::PATADA_FLOJO_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::H)) {											//M.Kick hacia delante
			animacion_en_proceso = TipoAnimacion::PATADA_MEDIO_ALANTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::J)) {											//H.Kick hacia delante
			animacion_en_proceso = TipoAnimacion::PATADA_FUERTE_ALANTE;
		}
		else {																					//Solo moverse
			animacion_en_proceso = TipoAnimacion::ALANTE;
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {											//Moverse izquierda

		if (Keyboard::isKeyPressed(Keyboard::W)) {												//Salto hacia atras
			animacion_en_proceso = TipoAnimacion::SALTO_ATRAS;
		}
		else {																					//Solo moverse
			animacion_en_proceso = TipoAnimacion::ATRAS;
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) {											//Salto en parado
		animacion_en_proceso = TipoAnimacion::SALTO;
	}
	else if (Keyboard::isKeyPressed(Keyboard::T)) {											//L.Punch en parado
		animacion_en_proceso = TipoAnimacion::PUNYO_FLOJO_PARADO;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Y) || Keyboard::isKeyPressed(Keyboard::U)) {	//M.Punch, H.Punch en parado
		animacion_en_proceso = TipoAnimacion::PUNYO_FUERTE_PARADO;
	}
	else if (Keyboard::isKeyPressed(Keyboard::G) || Keyboard::isKeyPressed(Keyboard::H)) {	//L.Kick, M.Kick en parado
		animacion_en_proceso = TipoAnimacion::PATADA_FLOJO_PARADO;
	}
	else if (Keyboard::isKeyPressed(Keyboard::J)) {											//H.Kick en parado
		animacion_en_proceso = TipoAnimacion::PATADA_FUERTE_PARADO;
	}
}

void Personaje::ComprobarColisiones() {
	// TO BE PROGRAMMED
}

void Personaje::RealizarAnimacion() {
	animaciones[animacion_en_proceso].RealizarAnimacion(cuerpo);
}

void Personaje::TerminarAnimacion() {
	animacion_en_proceso = TipoAnimacion::IDLE;
}

void Personaje::RecibirGolpe(int cantidad) {
	vida -= cantidad;
}

void Personaje::GastarEnergia(int cantidad) {
	energia -= cantidad;
}

#endif