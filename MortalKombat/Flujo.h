#ifndef	FLUJO_H
#define FLUJO_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Inicio.h"
#include "Menu.h"
#include "Transicion.h"

using namespace sf;
using namespace std;

class Flujo {

public:
	Flujo(Texture[], Font);
	~Flujo() = default;

	void Actualizar(Event);
	void draw(RenderWindow&);

private:

	int estado;	//0 = Inicio, 1 = Menu, 2 = Historia, 3 = Duelo, 4 = Opciones, 5 = Salir
	Menu menu;
	Inicio inicio;
	Transicion transicion;

};

Flujo::Flujo(Texture texturas[], Font fuente) : inicio(&texturas[0]), menu(&texturas[1], fuente) {

	estado = 0;

}

void Flujo::Actualizar(Event evento) {

	if (estado == 0) {
		estado = 1;
		inicio.~Inicio();
	}
	else if (estado == 1 && evento.key.code == Keyboard::Up) {
		menu.moverCursor(true);
	}
	else if (estado == 1 && evento.key.code == Keyboard::Down) {
		menu.moverCursor(false);
	}
	else if (estado == 1 && evento.key.code == Keyboard::Enter) {
		estado = menu.OpcionElegida() + 2;
	}

	menu.Actualizar();

}

void Flujo::draw(RenderWindow& window) {
	switch (estado) {
	case 0:
		inicio.draw(window);
		break;

	case 1:
		menu.draw(window);
		transicion.draw(window);
		break;

	case 2:
		transicion.draw(window);
		//Historia
		break;
	case 3:
		transicion.draw(window);
		//Duelo
		break;

	case 4:
		transicion.draw(window);
		//Opciones
		break;
	default:
		//Salir
		break;
	
	
	}

}


#endif