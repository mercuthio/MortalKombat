#ifndef ANIMACION_OLD_H
#define ANIMACION_OLD_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

using namespace sf;
using namespace std;

class Animacion_Old {
public:

	Animacion_Old(float);
	~Animacion_Old() = default;
	bool actualizar(int, int, int, float, float&, float&, bool, RectangleShape&);

	IntRect uvRect;

private:

	int imagenActual;
	int fila;
	int accion;
	float tiempoTotal;
	float tiempoCambio;

};

Animacion_Old::Animacion_Old(float tiempoCambio_) {

	imagenActual = 0;
	fila = 0;
	accion = 0;
	tiempoCambio = tiempoCambio_;
	tiempoTotal = 0.0f;

}

bool Animacion_Old::actualizar(int fila_, int accion_, int spriteFinal, float tiempo, float& pos_y, float& pos_x, bool sentido, RectangleShape& cuerpo) {

	bool terminada = (accion != 9 && accion != 16 && fila == 0);

	tiempoTotal += tiempo;


	if ((fila != fila_) || (accion != accion_)) {
		cout << "Nueva entrada: " << accion_ << endl;
		fila = fila_;
		accion = accion_;

		if (sentido) {
			imagenActual = accion;
		}
		else {
			imagenActual = spriteFinal;
		}

	}

	if ((accion == 9) && (imagenActual <= ((spriteFinal - accion_) / 2) + accion_)) { //Esta subiendo (salto simple)
		if (pos_y - 80 / 6 > 0)
			pos_y -= 80 / 6;
	}
	else if ((accion == 9) && (imagenActual > ((spriteFinal - accion_) / 2) + accion_)) { //Esta cayendo
		if (pos_y + 80 / 6 < 300)
			pos_y += 80 / 6;
	}

	if ((fila == 0) && (((accion == 16) && (sentido) && (imagenActual <= ((spriteFinal - accion_) / 2) + accion_)) ||
		((accion == 16) && (!sentido) && (imagenActual > ((spriteFinal - accion_) / 2) + accion_)))) {

		if (pos_y - 80 / 6 > 0)
			pos_y -= 80 / 6;
		if (sentido && pos_x + 80 / 6 < 825)
			pos_x += 80 / 6;
		if (!sentido && pos_x - 80 / 6 > 0) {
			pos_x -= 80 / 6;
		}

	}
	else if ((fila == 0) && (((accion == 16) && (sentido) && (imagenActual > ((spriteFinal - accion_) / 2) + accion_)) ||
		((accion == 16) && (!sentido) && (imagenActual <= ((spriteFinal - accion_) / 2) + accion_)))) {

		if (pos_y + 80 / 6 < 300)
			pos_y += 80 / 6;

		if (sentido && pos_x + 80 / 6 < 825)
			pos_x += 80 / 6;
		if (!sentido && pos_x - 80 / 6 > 0)
			pos_x -= 80 / 6;
	}

	if (tiempoTotal >= tiempoCambio) {
		tiempoTotal -= tiempoCambio;

		if ((accion != 24 && accion != 26)) { //Agachado no debe reiniciar animacion

			if (sentido) {
				imagenActual++;
			}
			else {
				imagenActual--;
			}

			if (((imagenActual == spriteFinal) && sentido) || ((imagenActual == accion_) && !sentido)) {

				if ((accion == 9) || (accion == 16) || (fila != 0)) { //Termina animacion no parable
					pos_y = 300;
					terminada = true;
				}

				imagenActual = accion;
			}
		}
	}

	uvRect.width = 49;
	uvRect.height = 90;

	cuerpo.setSize(Vector2f(86.0f, 162.0f));

	switch (fila) {
	case 0: //Primera fila
		switch (accion) {
		case 9: //Salto
			uvRect.width = 49;
			uvRect.height = 100;
			uvRect.left = imagenActual * uvRect.width + 1;
			uvRect.top = fila * uvRect.height + 5;
			break;
		case 16: //Salto hacia delante
			if (imagenActual == 18) {
				cuerpo.setSize(Vector2f(172.0f, 162.0f));
				uvRect.width = 98;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 1;
				uvRect.top = fila * uvRect.height + 15;
			}
			else if (imagenActual == 20) {
				cuerpo.setSize(Vector2f(172.0f, 162.0f));
				uvRect.width = 98;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 43 + 1;
				uvRect.top = fila * uvRect.height + 15;
			}
			else {
				uvRect.width = 49;
				uvRect.height = 100;
				uvRect.top = fila * uvRect.height + 5;
				if (imagenActual < 18) {
					uvRect.left = imagenActual * uvRect.width + 1;
				}
				else if (imagenActual == 19) {
					uvRect.left = imagenActual * uvRect.width + 43 + 1;
				}
				else {
					uvRect.left = imagenActual * 49 + 86 + 1;
				}
			}
			break;
		case 24: //Agacharse
			uvRect.left = imagenActual * uvRect.width + 86 + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		case 26: //Bloquear agachado
			uvRect.left = imagenActual * uvRect.width + 86 + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		default:
			uvRect.left = imagenActual * uvRect.width + 1;
			uvRect.top = fila * uvRect.height + 15;
			break;
		}
		break;

	case 1: //Segunda fila
		switch (accion) {
		case 18: //Forward H.Punch
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 41;
			break;
		case 11: //Forward M.Punch
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 41;
			break;
		case 8: //Puñetazo arriba
			if (imagenActual == 9) {
				cuerpo.setSize(Vector2f(94.0f, 162.0f));
				uvRect.width = 53;
				uvRect.height = 90;
				cout << cuerpo.getLocalBounds().width << endl;
				uvRect.left = imagenActual * 49 + 14 + 8 + 29 + 8 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else if (imagenActual == 10) {
				uvRect.left = imagenActual * 49 + 14 + 8 + 29 + 8 + 4 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else {
				uvRect.left = imagenActual * 49 + 14 + 8 + 29 + 8 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			break;
		case 3: //Puñetazo largo
			if (imagenActual == 4) {
				cuerpo.setSize(Vector2f(102.0f, 162.0f));
				uvRect.width = 57;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 14 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else if (imagenActual == 5) {
				cuerpo.setSize(Vector2f(144.0f, 162.0f));
				uvRect.width = 78;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 14 + 8 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else if (imagenActual == 6) {
				cuerpo.setSize(Vector2f(102.0f, 162.0f));
				uvRect.width = 57;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 14 + 8 + 29 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else if (imagenActual == 7) {
				uvRect.left = imagenActual * 49 + 14 + 8 + 29 + 8 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else {
				uvRect.left = imagenActual * uvRect.width + 14 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			break;
		default: //Puñetazo corto
			if (imagenActual == 1) {
				cuerpo.setSize(Vector2f(114.0f, 162.0f));
				uvRect.width = 65;
				uvRect.height = 90;
				uvRect.left = imagenActual * 49 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else if (imagenActual == 2) {
				uvRect.left = imagenActual * uvRect.width + 14 + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			else {
				uvRect.left = imagenActual * uvRect.width + 1;
				uvRect.top = fila * uvRect.height + 41;
			}
			break;
		}
		break;
	case 2: //Tercera fila
		switch (accion) {
		case 16: //Forward H.Kick
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 82;
			break;
		case 11: //Forward M.Kick
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 82;
			break;
		case 8: //Forward L.Kick
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 82;
			break;
		case 3: //H.Kick
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 82;
			break;
		default: //L/M.Kick
			uvRect.left = imagenActual * uvRect.width;
			uvRect.top = fila * uvRect.height + 82;
			break;
		}
		break;

	}
	return terminada;

}

#endif
