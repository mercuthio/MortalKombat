
#include "Flujo.h"

Flujo::Flujo(Texture texturas[], Font fuente) : inicio(&texturas[0]), menu(&texturas[1], fuente), opciones(&texturas[2], fuente), selector(&texturas[3],&texturas[4]) {

	estado = 0;
	personaje1 = 0;
	cambiadoEstado = false;

	musica[0].openFromFile("audio/soundtrack.ogg");

	musica[0].play();
	musica[0].setLoop(true);

}

void Flujo::setClock(Clock clock) {

	this->clock = clock;

}

void Flujo::Actualizar(Event evento) {

	switch (estado) {
	case 0: //Pantalla inicial
		cambiadoEstado = true;
		estado = 1;
		inicio.~Inicio();
		menu.Actualizar();
		break;
	case 1: //Menu
		switch (evento.key.code) {
		case Keyboard::Up:
			menu.moverCursor(true);
			break;

		case Keyboard::Down:
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
	case 2: //SelectorHistoria
		switch (evento.key.code) {
		case Keyboard::Up:
			selector.MoverCursor(0,1);
			break;
		case Keyboard::Down:
			selector.MoverCursor(0, -1);
			break;
		case Keyboard::Right:
			selector.MoverCursor(1, 0);
			break;
		case Keyboard::Left:
			selector.MoverCursor(-1, 0);
			break;
		case Keyboard::Enter:
			personaje1 = selector.OpcionElegida();
			estado = 5;
			break;
		}
		break;
	case 3: //SelectorDuelo

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
			opciones.Enter(musica[0]);
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		case Keyboard::Right:
			cambiadoEstado = true;
			opciones.Enter(musica[0]);
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		case Keyboard::Left:
			cambiadoEstado = true;
			opciones.Izquierda(musica[0]);
			if (opciones.OpcionElegida() == 4) {
				estado = 1;
				menu.Actualizar();
			}
			break;
		}
		opciones.Actualizar();
		break;
	case 5: //Torre
	
		break;
	case 6: //Batalla

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
		selector.Draw(window);
		//drawTransicion(window);
		break;
	case 3:
		//SelectorDuelo
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

