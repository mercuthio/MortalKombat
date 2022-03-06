#ifndef PERSONAJE_OLD_H
#define PERSONAJE_OLD_H

#include <SFML/Graphics.hpp>
#include "Animacion_Old.h"

using namespace sf;
using namespace std;

class Personaje_Old {
public:

	Personaje_Old(Texture*, float, float, float, int[15][15]);
	~Personaje_Old() = default;

	float pos_x;
	float pos_y;

	void actualizar(float);
	void dibujar(RenderWindow&);

private:

	bool terminada;
	bool sentido;
	int vida;
	int fila;
	int sprite;
	int numSprites[15][15];

	RectangleShape cuerpo;
	Animacion_Old animacion;

};

Personaje_Old::Personaje_Old(Texture* textura, float pos_x_, float pos_y_, float tiempoCambio_, int numSprites_[15][15]) : animacion(tiempoCambio_) {

	vida = 200;
	fila = 0;
	sprite = 0;
	pos_x = pos_x_;
	pos_y = pos_y_;
	terminada = true;

	for (int i = 0; i < 15 && numSprites[i][0] != '\0'; i++) {
		for (int j = 0; j < 15 && numSprites_[i][j] != '\0'; j++) {
			numSprites[i][j] = numSprites_[i][j];
		}
	}

	cuerpo.setSize(Vector2f(86.0f, 162.0f));
	cuerpo.setPosition(pos_x, pos_y);
	cuerpo.setTexture(textura);

	//cuerpo.setFillColor(Color::Green); //Para ver hitboxes descomentar y comentar anterior

}

//MAPEO DE MANDO A TECLADO (JUGADOR 1)

//	Y	=	T	-	L.Punch
//	X	=	Y	-	M.Punch
//	L	=	U	-	H.Punch
//	B	=	G	-	L.Kick
//	A	=	H	-	M.Kick
//	R	=	J	-	H.Kick

void Personaje_Old::actualizar(float tiempo) {

	if (terminada) {

		sentido = true;

		if (Keyboard::isKeyPressed(Keyboard::D) && (pos_x + 750 * tiempo) < 825) { //Mover derecha

			fila = 0;

			if (Keyboard::isKeyPressed(Keyboard::W)) { //Salto hacia delante
				pos_x += 750 * tiempo;
				sprite = 3;

			}
			else if (Keyboard::isKeyPressed(Keyboard::T)) { //Forward L.Punch
				fila = 1;
				sprite = 2;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Y)) { //Forward M.Punch
				fila = 1;
				sprite = 3;
			}
			else if (Keyboard::isKeyPressed(Keyboard::U)) { //Forward H.Punch
				fila = 1;
				sprite = 4;
			}
			else if (Keyboard::isKeyPressed(Keyboard::G)) { //Forward L.Kick
				fila = 2;
				sprite = 2;
			}
			else if (Keyboard::isKeyPressed(Keyboard::H)) { //Forward M.Kick
				fila = 2;
				sprite = 3;
			}
			else if (Keyboard::isKeyPressed(Keyboard::J)) { //Forward H.Kick
				fila = 2;
				sprite = 4;
			}
			else {
				pos_x += 750 * tiempo;
				sprite = 1;

			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) { //Agacharse
			fila = 0;

			if (Keyboard::isKeyPressed(Keyboard::A)) { //Bloquear agachado
				sprite = 5;

			}
			else {
				sprite = 4;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::A) && (pos_x - 750 * tiempo) > 0) { //Mover izquierda
			pos_x -= 750 * tiempo;
			fila = 0;

			if (Keyboard::isKeyPressed(Keyboard::W)) { //Salto hacia atras
				sprite = 3;
				sentido = false;

			}
			else {
				sprite = 1;
			}

		}
		else if (Keyboard::isKeyPressed(Keyboard::W)) { //Salto
			fila = 0;
			sprite = 2;

		}
		else if (Keyboard::isKeyPressed(Keyboard::T)) { //L.Punch
			fila = 1;
			sprite = 0;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Y) || Keyboard::isKeyPressed(Keyboard::U)) { //M.Punch, H.Punch
			fila = 1;
			sprite = 1;

		}
		else if (Keyboard::isKeyPressed(Keyboard::G) || Keyboard::isKeyPressed(Keyboard::H)) { //L.Kick, M.Kick
			fila = 2;
			sprite = 0;

		}
		else if (Keyboard::isKeyPressed(Keyboard::J)) { //H.Kick
			fila = 2;
			sprite = 1;

		}
		else { //Quieto
			fila = 0;
			sprite = 0;
		}

		if (pos_x == 0.0f) {
			fila = 0;
			sprite = 0;

		}
	}

	if (sprite > 0) {
		terminada = animacion.actualizar(fila, numSprites[fila][sprite - 1], numSprites[fila][sprite], tiempo, pos_y, pos_x, sentido, cuerpo);
	}
	else {
		terminada = animacion.actualizar(fila, 0, numSprites[fila][sprite], tiempo, pos_y, pos_x, sentido, cuerpo);
	}

	cuerpo.setTextureRect(animacion.uvRect);
	cuerpo.setPosition(pos_x, pos_y);
	cuerpo.setScale(1.75, 1.75);
}

//
// Este dibujar no debería ir aquí
// Para esta versión lo dejamos, pero habrái que pensar en cambiarlo
//
void Personaje_Old::dibujar(RenderWindow& window) {

	window.draw(cuerpo);

}

#endif