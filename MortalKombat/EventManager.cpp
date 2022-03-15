
#include "EventManager.h"

EventManager::EventManager(Texture textures[], Font font) : StartManager(&textures[0], &textures[1]), MenuManager(&textures[0], font), OptionsManager(&textures[0], font), PlayerSelector_hist(&textures[0], false), PlayerSelector_duel(&textures[0], true), HistoryManager(&textures[0]) {

	state = 0;
	character1 = 0;
	changedEstate = false;

	//music[0].openFromFile("audio/soundtrack.ogg");

	//music[0].play();
	//music[0].setLoop(true);

}

void EventManager::setClock(Clock clock) {

	this->clock = clock;

}

void EventManager::Update(Event event) {

	switch (state) {
	case 0: //Pantalla inicial
		changedEstate = true;
		state = 1;
		StartManager.~StartManager();
		MenuManager.Update();
		break;
	case 1: //MenuManager
		switch (event.key.code) {
		case Keyboard::Up:
			MenuManager.MoveCursor(true);
			break;

		case Keyboard::Down:
			MenuManager.MoveCursor(false);
			break;

		case Keyboard::Enter:
			changedEstate = true;
			state = MenuManager.ChoosenOption() + 2;
			if (state == 4)
				OptionsManager.Update();
			break;
		}
		MenuManager.Update();
		break;
	case 2: //PlayerSelectorHistoria
		switch (event.key.code) {
		case Keyboard::W:
			PlayerSelector_hist.MoveCursor(0,-1, true);
			break;
		case Keyboard::S:
			PlayerSelector_hist.MoveCursor(0, 1, true);
			break;
		case Keyboard::D:
			PlayerSelector_hist.MoveCursor(1, 0, true);
			break;
		case Keyboard::A:
			PlayerSelector_hist.MoveCursor(-1, 0, true);
			break;
		case Keyboard::Enter:
			character1 = PlayerSelector_hist.ChoosenOption(true);
			changedEstate = true;
			state = 5;
			break;
		case Keyboard::Escape:
			state = 1;
			break;
		}
		PlayerSelector_hist.Update();
		MenuManager.Update();
		break;
	case 3: //PlayerSelectorDuelo
		switch (event.key.code) {
		case Keyboard::W:
			PlayerSelector_duel.MoveCursor(0, -1, true);
			break;
		case Keyboard::S:
			PlayerSelector_duel.MoveCursor(0, 1, true);
			break;
		case Keyboard::D:
			PlayerSelector_duel.MoveCursor(1, 0, true);
			break;
		case Keyboard::A:
			PlayerSelector_duel.MoveCursor(-1, 0, true);
			break;
		case Keyboard::Enter:
			character1 = PlayerSelector_duel.ChoosenOption(true);
			if (PlayerSelector_duel.Choosen()) {
				changedEstate = true;
				state = 5;
			}
			break;
		case Keyboard::Up:
			PlayerSelector_duel.MoveCursor(0, -1, false);
			break;
		case Keyboard::Down:
			PlayerSelector_duel.MoveCursor(0, 1, false);
			break;
		case Keyboard::Right:
			PlayerSelector_duel.MoveCursor(1, 0, false);
			break;
		case Keyboard::Left:
			PlayerSelector_duel.MoveCursor(-1, 0, false);
			break;
		case Keyboard::Space:
			personaje2 = PlayerSelector_duel.ChoosenOption(false);
			if (PlayerSelector_duel.Choosen()) {
				changedEstate = true;
				state = 5;
			}
			break;
		case Keyboard::Escape:
			state = 1;
			break;
		}
		PlayerSelector_duel.Update();
		MenuManager.Update();
		break;
	case 4: //OptionsManager
		switch (event.key.code) {
		case Keyboard::Up:
			OptionsManager.MoveCursor(true);
			break;

		case Keyboard::Down:
			OptionsManager.MoveCursor(false);
			break;

		case Keyboard::Enter:
			changedEstate = true;
			OptionsManager.Enter(music[0]);
			if (OptionsManager.ChoosenOption() == 4) {
				state = 1;
				MenuManager.Update();
			}
			break;
		case Keyboard::Right:
			changedEstate = true;
			OptionsManager.Enter(music[0]);
			if (OptionsManager.ChoosenOption() == 4) {
				state = 1;
				MenuManager.Update();
			}
			break;
		case Keyboard::Left:
			changedEstate = true;
			OptionsManager.Izquierda(music[0]);
			if (OptionsManager.ChoosenOption() == 4) {
				state = 1;
				MenuManager.Update();
			}
			break;
		case Keyboard::Escape:
			state = 1;
			break;
		}
		OptionsManager.Update();
		break;
	case 5: //Hisstoria
		
		break;
	case 6: //Batalla

		break;
	}

}

void EventManager::drawPlayerSelectorChoose(RenderWindow& window) {

	PlayerSelector_duel.DrawChoosen(window, false);
	PlayerSelector_duel.DrawChoosen(window, true);
	changedEstate = false;

}

void EventManager::drawTransitionManager(RenderWindow& window) {

	if (changedEstate) {
		TransitionManager.draw(window);
		changedEstate = false;
	}

}

void EventManager::draw(RenderWindow& window) {
	switch (state) {
	case 0:
		if (StartManager.draw(window, clock.getElapsedTime().asSeconds())) { //Si true, terminada intro
			changedEstate = true;
			state = 1;
			StartManager.~StartManager();
			MenuManager.Update();
		};
		break;

	case 1:
		MenuManager.draw(window);
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
		break;
	case 5:
		drawPlayerSelectorChoose(window);
		//HistoryManager.Draw(window);
		break;
	default:
		exit(0);
		break;

	}

}

