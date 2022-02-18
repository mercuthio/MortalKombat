#ifndef	FLUJO_H
#define FLUJO_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Inicio.h"
#include "Menu.h"
#include "Transicion.h"
#include "Opciones.h"

using namespace sf;
using namespace std;

class Flujo {

public:
	Flujo(Texture[], Font);
	~Flujo() = default;

	void Actualizar(Event);
	void draw(RenderWindow&);

	void setClock(Clock);

private:

	void drawTransicion(RenderWindow& window);

	int estado;	//0 = Inicio, 1 = Menu, 2 = Historia, 3 = Duelo, 4 = Opciones, 5 = Salir
	bool cambiadoEstado = false;
	Menu menu;
	Inicio inicio;
	Opciones opciones;
	Transicion transicion;
	Clock clock;

};

Flujo::Flujo(Texture texturas[], Font fuente) : inicio(&texturas[0]), menu(&texturas[1], fuente), opciones(&texturas[2],fuente) {

	estado = 0;

}

void Flujo::setClock(Clock clock) {

	this->clock = clock;

}

void Flujo::Actualizar(Event evento) {

	cout << estado << endl;
	switch (estado) {
	case 0: //Pantalla inicial
		cambiadoEstado = true;
		estado = 1;
		inicio.~Inicio();
		menu.Actualizar();
		break;
	case 1: //Menu
		switch (evento.key.code) {
		case Keyboard::W:
			menu.moverCursor(true);
			break;

		case Keyboard::S:
			menu.moverCursor(false);
			break;

		case Keyboard::Enter:
			cambiadoEstado = true;
			estado = menu.OpcionElegida() + 2;
			if (estado == 4)
				opciones.Actualizar();
			break;
		}
		menu.Actualizar();
		break;
	case 2: //Historia

		break;
	case 3: //Duelos

		break;
	case 4: //Opciones
		switch (evento.key.code) {
		case Keyboard::Up:
			opciones.moverCursor(true);
			break;

		case Keyboard::Down:
			opciones.moverCursor(false);
			break;

		case Keyboard::Enter:
			cambiadoEstado = true;
			opciones.Enter();
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		case Keyboard::Right:
			cambiadoEstado = true;
			opciones.Enter();
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		case Keyboard::Left:
			cambiadoEstado = true;
			opciones.Izquierda();
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		}
		opciones.Actualizar();
		break;
	}

}

void Flujo::drawTransicion(RenderWindow& window) {

	if (cambiadoEstado) {
		transicion.draw(window);
		cambiadoEstado = false;
	}

}

void Flujo::draw(RenderWindow& window) {
	switch (estado) {
	case 0:
		inicio.draw(window);
		break;

	case 1:
		menu.draw(window);
		//drawTransicion(window);
		break;

	case 2:
		//Historia
		drawTransicion(window);
		break;
	case 3:
		//Duelo
		drawTransicion(window);
		break;

	case 4:
		opciones.draw(window);
		//drawTransicion(window);
		break;
	default:
		exit(0);
		break;
	
	
	}

}


#endif