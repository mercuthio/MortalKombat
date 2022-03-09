#pragma once
#ifndef GORO_H
#define GORO_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Character.h"
#include "Animation.h"
#include "Definitions.h"

Character CreateGroro() {
	Texture spriteSheet;
	spriteSheet.loadFromFile("resources/Sprites/Personajes/Goro.png");
	
	Vector2<int> firstFrame = Vector2<int>(32, 277); // Posicion de la imagen en el Sprite Sheet
	Vector2<int> frameSize = Vector2<int>(507, 219); // Ancho y alto de la imagen
	
	int offset = 4;	// Pixeles entre sprites
	int frames = 7; // Numero de sprites

	Vector2<float> movement[MAX_IMG_PER_ANIM] = { // Movimiento de la imagen en el mundo
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
		Vector2<float>(0.0, 0.0),
	};

	Animation idle = Animation(frames, spriteSheet, movement, frameSize, firstFrame, offset);
	map<AnimationType, Animation> animations;
	animations[AnimationType::IDLE] = idle;
	Character goro = Character(animations);
}


#endif