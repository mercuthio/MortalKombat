#pragma once
#ifndef GORO_H
#define GORO_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "Character.h"
#include "Animation.h"
#include "Definitions.h"

void testGoro(RenderWindow& window) {
	Texture spriteSheet;
	spriteSheet.loadFromFile("resources/Sprites/Personajes/Goro.png");
	RectangleShape body = RectangleShape(Vector2<float>(251, 219));
	
	body.setTexture(&spriteSheet);
	body.setPosition(50, 50);

	IntRect rect = IntRect(Vector2<int>(32, 58), Vector2<int>(251, 219));
	body.setTextureRect(rect);

	window.draw(body);
}

Character CreateGoro() {
	Texture spriteSheet;
	spriteSheet.loadFromFile("resources/Sprites/Personajes/Goro.png");



	Vector2<int> firstFrame = Vector2<int>(32, 58);  // Posicion de la imagen en el Sprite Sheet
	Vector2<int> frameSize = Vector2<int>(251, 219); // Ancho y alto de la imagen

	int offset = 5;	// Pixeles entre sprites
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

	Animation idle = Animation(frames, spriteSheet, movement, firstFrame, frameSize, offset, false, false);
	




	firstFrame = Vector2<int>(2080, 58);  // Posicion de la imagen en el Sprite Sheet
	frameSize = Vector2<int>(251, 219); // Ancho y alto de la imagen

	offset = 5;	// Pixeles entre sprites + 1
	frames = 9; // Numero de sprites

	Vector2<float> movement2[MAX_IMG_PER_ANIM] = { // Movimiento de la imagen en el mundo
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
		Vector2<float>(5.0, 0.0),
	};

	Animation forw = Animation(frames, spriteSheet, movement2, firstFrame, frameSize, offset, false, false);



	firstFrame = Vector2<int>(4128, 58);  // Posicion de la imagen en el Sprite Sheet
	frameSize = Vector2<int>(251, 219); // Ancho y alto de la imagen

	offset = -5;	// Pixeles entre sprites + 1
	frames = 9; // Numero de sprites

	Vector2<float> movement3[MAX_IMG_PER_ANIM] = { // Movimiento de la imagen en el mundo
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
		Vector2<float>(-2.5, 0.0),
	};

	Animation back = Animation(frames, spriteSheet, movement3, firstFrame, frameSize, offset, true, false);




	RectangleShape body = RectangleShape(Vector2<float>(251, 219));
	body.setTexture(&spriteSheet);
	body.setPosition(50, 50);

	map<AnimationType, Animation> animations;
	animations[AnimationType::IDLE] = idle;
	animations[AnimationType::FORW_WALK] = forw;
	animations[AnimationType::BACK_WALK] = back;

	Character goro = Character(animations, body);

	return goro;
}

#endif