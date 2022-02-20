#ifndef	FLUJO_H
#define FLUJO_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Inicio.h"
#include "Menu.h"
#include "Transicion.h"
#include "Opciones.h"
#include "Selector.h"

using namespace sf;
using namespace std;

const int NUMERO_CANCIONES = 10;

class Flujo {

public:
	Flujo(Texture[], Font);
	~Flujo() = default;

	void Actualizar(Event);
	void draw(RenderWindow&);
	void setClock(Clock);

private:

	void drawTransicion(RenderWindow& window);

	int estado;	//0 = Inicio, 1 = Menu, 2 = SelectorHistoria, 3 = SelectorDuelo, 4 = Opciones, 5 = Torre, 6 = Batalla
	int personaje1;
	bool cambiadoEstado;
	Menu menu;
	Music musica[NUMERO_CANCIONES];
	Inicio inicio;
	Opciones opciones;
	Transicion transicion;
	Clock clock;
	Selector selector;

};

#endif