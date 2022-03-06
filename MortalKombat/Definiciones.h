#pragma once
#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Definiciones de constantes generales
constexpr int N_ANIMACIONES = 8;	// Total de animaciones de los personajes;
constexpr int MAX_IMG_POR_ANIM = 15;

// Definiciones de enumeraciones generales
enum class TipoAnimacion {
	// Movimientos
	SALTO,
	AGACHE,
	ALANTE,
	ATRAS,
	// Ataques
	GOLPE_FLOJO_DEPIE,
	GOLPE_FLOJO_AGACHADO,
	GOLPE_FUERTE_DEPIE,
	GOLPE_FUERTE_AGACHADO,
	//...
};

#endif