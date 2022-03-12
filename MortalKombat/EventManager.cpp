
#include "EventManager.h"

EventManager::EventManager(Texture texturas[], Font fuente) : StartManager(&texturas[0]), MenuManager(&texturas[0], fuente), OptionsManager(&texturas[0], fuente), PlayerSelector(&texturas[0]) {

	estado = 0;
	personaje1 = 0;
	cambiadoEstado = false;

	//musica[0].openFromFile("audio/soundtrack.ogg");

	//musica[0].play();
	//musica[0].setLoop(true);

}

void EventManager::setClock(Clock clock) {

	this->clock = clock;

}

void EventManager::Actualizar(Event evento) {

	switch (estado) {
	case 0: //Pantalla inicial
		cambiadoEstado = true;
		estado = 1;
		StartManager.~StartManager();
		MenuManager.Actualizar();
		break;
	case 1: //MenuManager
		switch (evento.key.code) {
		case Keyboard::Up:
			MenuManager.moverCursor(true);
			break;

		case Keyboard::Down:
			MenuManager.moverCursor(false);
			break;

		case Keyboard::Enter:
			cambiadoEstado = true;
			estado = MenuManager.OpcionElegida() + 2;
			if (estado == 4)
				OptionsManager.Actualizar();
			break;
		}
		MenuManager.Actualizar();
		break;
	case 2: //PlayerSelectorHistoria
		switch (evento.key.code) {
		case Keyboard::Up:
			PlayerSelector.MoverCursor(0,1);
			break;
		case Keyboard::Down:
			PlayerSelector.MoverCursor(0, -1);
			break;
		case Keyboard::Right:
			PlayerSelector.MoverCursor(1, 0);
			break;
		case Keyboard::Left:
			PlayerSelector.MoverCursor(-1, 0);
			break;
		case Keyboard::Enter:
			personaje1 = PlayerSelector.OpcionElegida();
			estado = 5;
			break;
		}
		break;
	case 3: //PlayerSelectorDuelo

		break;
	case 4: //OptionsManager
		switch (evento.key.code) {
		case Keyboard::Up:
			OptionsManager.moverCursor(true);
			break;

		case Keyboard::Down:
			OptionsManager.moverCursor(false);
			break;

		case Keyboard::Enter:
			cambiadoEstado = true;
			OptionsManager.Enter(musica[0]);
			if (OptionsManager.OpcionElegida() == 4) {
				estado = 1;
				MenuManager.Actualizar();
			}
			break;
		case Keyboard::Right:
			cambiadoEstado = true;
			OptionsManager.Enter(musica[0]);
			if (OptionsManager.OpcionElegida() == 4) {
				estado = 1;
				MenuManager.Actualizar();
			}
			break;
		case Keyboard::Left:
			cambiadoEstado = true;
			OptionsManager.Izquierda(musica[0]);
			if (OptionsManager.OpcionElegida() == 4) {
				estado = 1;
				MenuManager.Actualizar();
			}
			break;
		}
		OptionsManager.Actualizar();
		break;
	case 5: //Torre
	
		break;
	case 6: //Batalla

		break;
	}

}

void EventManager::drawTransitionManager(RenderWindow& window) {

	if (cambiadoEstado) {
		TransitionManager.draw(window);
		cambiadoEstado = false;
	}

}

void EventManager::draw(RenderWindow& window) {
	switch (estado) {
	case 0:
		StartManager.draw(window, clock.getElapsedTime().asSeconds());
		break;

	case 1:
		MenuManager.draw(window);
		//drawTransitionManager(window);
		break;

	case 2:
		PlayerSelector.Draw(window);
		//drawTransitionManager(window);
		break;
	case 3:
		//PlayerSelectorDuelo
		drawTransitionManager(window);
		break;

	case 4:
		OptionsManager.draw(window);
		//drawTransitionManager(window);
		break;
	default:
		exit(0);
		break;


	}

}

