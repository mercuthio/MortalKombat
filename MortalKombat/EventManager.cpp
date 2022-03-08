
#include "EventManager.h"

EventManager::EventManager(Texture texturas[], Font fuente) : StartManager(&texturas[0]), MenuManager(&texturas[0], fuente), OptionsManager(&texturas[0], fuente), PlayerSelector_hist(&texturas[0], false), PlayerSelector_duel(&texturas[0], true) {

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
		case Keyboard::W:
			PlayerSelector_hist.MoverCursor(0,-1, true);
			break;
		case Keyboard::S:
			PlayerSelector_hist.MoverCursor(0, 1, true);
			break;
		case Keyboard::D:
			PlayerSelector_hist.MoverCursor(1, 0, true);
			break;
		case Keyboard::A:
			PlayerSelector_hist.MoverCursor(-1, 0, true);
			break;
		case Keyboard::E:
			personaje1 = PlayerSelector_hist.OpcionElegida(true);
			cambiadoEstado = true;
			estado = 5;
			break;
		case Keyboard::Escape:
			estado = 1;
			break;
		}
		PlayerSelector_hist.Actualizar();
		MenuManager.Actualizar();
		break;
	case 3: //PlayerSelectorDuelo
		switch (evento.key.code) {
		case Keyboard::W:
			PlayerSelector_duel.MoverCursor(0, -1, true);
			break;
		case Keyboard::S:
			PlayerSelector_duel.MoverCursor(0, 1, true);
			break;
		case Keyboard::D:
			PlayerSelector_duel.MoverCursor(1, 0, true);
			break;
		case Keyboard::A:
			PlayerSelector_duel.MoverCursor(-1, 0, true);
			break;
		case Keyboard::Enter:
			personaje1 = PlayerSelector_duel.OpcionElegida(true);
			if (PlayerSelector_duel.Elegidos()) {
				cambiadoEstado = true;
				estado = 5;
			}
			break;
		case Keyboard::Up:
			PlayerSelector_duel.MoverCursor(0, -1, false);
			break;
		case Keyboard::Down:
			PlayerSelector_duel.MoverCursor(0, 1, false);
			break;
		case Keyboard::Right:
			PlayerSelector_duel.MoverCursor(1, 0, false);
			break;
		case Keyboard::Left:
			PlayerSelector_duel.MoverCursor(-1, 0, false);
			break;
		case Keyboard::Space:
			personaje2 = PlayerSelector_duel.OpcionElegida(false);
			if (PlayerSelector_duel.Elegidos()) {
				cambiadoEstado = true;
				estado = 5;
			}
			break;
		}
		PlayerSelector_duel.Actualizar();
		MenuManager.Actualizar();
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

void EventManager::drawPlayerSelectorChoose(RenderWindow& window) {

	if (cambiadoEstado && estado == 2) {
		PlayerSelector_hist.DrawChoosen(window, true);
		cambiadoEstado = false;
	}
	else if (cambiadoEstado && estado == 3) {
		PlayerSelector_duel.DrawChoosen(window, false);
		PlayerSelector_duel.DrawChoosen(window, true);
		cambiadoEstado = false;
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
		PlayerSelector_hist.Draw(window, clock.getElapsedTime().asSeconds());
		//drawTransitionManager(window);
		break;
	case 3:
		PlayerSelector_duel.Draw(window, clock.getElapsedTime().asSeconds());
		//drawTransitionManager(window);
		break;

	case 4:
		OptionsManager.draw(window);
		//drawTransitionManager(window);
		break;
	case 5:
		drawPlayerSelectorChoose(window);
		//drawTower(window);
		break;
	default:
		exit(0);
		break;


	}

}

