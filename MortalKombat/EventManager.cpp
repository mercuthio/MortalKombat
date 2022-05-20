#include "EventManager.h"

MusicManager music = MusicManager();

EventManager::EventManager(Texture textures[], Font font, Clock clock) : BattleManager(&textures[0], &textures[3], font, clock), StartManager(&textures[0], &textures[1]),
MenuManager(&textures[0], font), OptionsManager(&textures[0], font), PlayerSelector_hist(&textures[0], false),
PlayerSelector_duel(&textures[0], true), HistoryManager(&textures[0],0), DeadManager(&textures[0]), FinishManager(&textures[2]), ControlsManager(&textures[0],font) {

	this->clock = clock;

	state = -1;
	changedEstate = false;
}

void EventManager::Update(Event event) {

	switch (state) {
	case -1: //Cargando
		break;
	case 0: //Pantalla inicial
		changedEstate = true;
		state = 1;

		music.skipIntro();
		music.mainTheme();

		StartManager.~StartManager();
		MenuManager.Update();

		break;

	case 1: //MenuManager

		switch (event.key.code) {
		case Keyboard::W:
			music.moveMain();
			MenuManager.MoveCursor(true);
			break;

		case Keyboard::S:
			music.moveMain();
			MenuManager.MoveCursor(false);
			break;

		case Keyboard::Enter:

			changedEstate = true;
			state = MenuManager.ChoosenOption() + 2;

			if (state == 2) { character1 = (CharacterType)0; character2 = (CharacterType)0; PlayerSelector_hist.Restart(); music.selectorTheme(); }
			if (state == 3) { character1 = (CharacterType)0; character2 = (CharacterType)0; PlayerSelector_duel.Restart(); music.selectorTheme(); }
			if (state == 4) OptionsManager.Update();
			if (state == 5) exit(0);

			break;

		}

		MenuManager.Update();
		break;

	case 2: //PlayerSelectorHistoria

		switch (event.key.code) {
		case Keyboard::W:
			PlayerSelector_hist.MoveCursor(0, -1, true);
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
			if (!PlayerSelector_hist.choosen1) {
				character1 = PlayerSelector_hist.ChoosenOption(true);

				switch (character1)
				{
				case CAGE:
					music.JhonnyCage();
					break;
				case LIU_KANG:
					music.LiuKang();
					break;
				case SCORPION:
					music.Scorpion();
					break;
				case SONYA:
					music.SonyaBlade();
					break;
				}

				stage = (background)(rand() % 5);
				BattleManager.RestartCombat(character1, character2, stage, false);
				BattleManager.Restart();

				HistoryManager.Restart(character1);

				changedEstate = true;
			}
			break;

		case Keyboard::Escape:
			music.mainTheme();
			state = 1;
			break;

		case Keyboard::BackSpace:

			music.mainTheme();
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

		case Keyboard::Space:

			if (!PlayerSelector_duel.choosen1) {

				character1 = PlayerSelector_duel.ChoosenOption(true);

				switch (character1)
				{
				case CAGE:
					music.JhonnyCage();
					break;
				case LIU_KANG:
					music.LiuKang();
					break;
				case SCORPION:
					music.Scorpion();
					break;
				case SONYA:
					music.SonyaBlade();
					break;
				}

				if (PlayerSelector_duel.Choosen()) {

					changedEstate = true;

					stage = (background)(rand() % 5);
					BattleManager.RestartCombat(character1, character2, stage, true);
					BattleManager.Restart();

				}
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

		case Keyboard::Enter:

			if (!PlayerSelector_duel.choosen2) {
				character2 = PlayerSelector_duel.ChoosenOption(false);
				switch (character2)
				{
				case CAGE:
					music.JhonnyCage();
					break;
				case LIU_KANG:
					music.LiuKang();
					break;
				case SCORPION:
					music.Scorpion();
					break;
				case SONYA:
					music.SonyaBlade();
					break;
				}

				if (PlayerSelector_duel.Choosen()) {

					changedEstate = true;

					stage = (background)(rand() % 5);
					BattleManager.RestartCombat(character1, character2, stage, true);
					BattleManager.Restart();
				}
			}
			break;

		case Keyboard::Escape:
			music.mainTheme();
			state = 1;
			break;

		case Keyboard::BackSpace:

			music.mainTheme();
			state = 1;
			break;
		}

		PlayerSelector_duel.Update();
		MenuManager.Update();
		break;
	case 4: //OptionsManager

		switch (event.key.code) {
		case Keyboard::W:
			OptionsManager.MoveCursor(true);
			break;

		case Keyboard::S:
			OptionsManager.MoveCursor(false);
			break;

		case Keyboard::Enter:

			changedEstate = true;
			if (OptionsManager.Enter()) {
				changedEstate = true;
				state = 10;
				ControlsManager.Update();
			}
			break;

		case Keyboard::D:

			changedEstate = true;
			OptionsManager.Right();
			break;

		case Keyboard::A:

			changedEstate = true;
			OptionsManager.Izquierda();
			break;

		case Keyboard::Escape:

			music.skipIntro();
			state = 1;
			break;
		case Keyboard:: BackSpace:

			music.skipIntro();
			state = 1;
			break;
		}
		OptionsManager.Update();
		break;

	case 5: //Historia

		if (event.key.code == Keyboard::Escape) {
			state = 1;
			music.mainTheme();
		}

	case 6: //Batalla historia

		if (event.key.code == Keyboard::Escape) {
			music.moveMain();
			if (BattleManager.paused) {
				state = 1;
				music.mainTheme();
			}
			else {
				BattleManager.Pause();
			}
		}
		else if (BattleManager.paused) {
			BattleManager.Pause();
		}
		BattleManager.Update(event);
		break;

	case 7: //Batalla duelo

		if (event.key.code == Keyboard::Escape) {
			music.moveMain();
			if (BattleManager.paused) {
				state = 1;
				music.mainTheme();
			}
			else {
				BattleManager.Pause();
			}
		}
		else if (BattleManager.paused) {
			BattleManager.Pause();
		}
		BattleManager.Update(event);
		break;
	case 10: //Controles

		switch (event.key.code) {
		case Keyboard::D:
			ControlsManager.Right();
			break;
		case Keyboard::Enter:
			ControlsManager.Enter();
			break;
		case Keyboard::A:
			ControlsManager.Izquierda();
			break;
		case Keyboard::S:
			ControlsManager.MoveCursor(false);
			break;
		case Keyboard::W:
			ControlsManager.MoveCursor(true);
			break;
		case Keyboard::Escape:
			state = 4;
			break;
		case Keyboard::BackSpace:
			state = 4;
			break;
		default:
			ControlsManager.changeKey(event.key.code);
			break;
		}
		ControlsManager.Update();
		break;
	}

}

void EventManager::draw(RenderWindow& window) {

	int ganador_partida;

	switch (state) {
	case -1: //Cargando
		if (clock.getElapsedTime().asSeconds() - loadingTime > 0) {
			state = 0;
		}
		break;
	case 0:	//Intro

		if (StartManager.draw(window, clock.getElapsedTime().asSeconds() - loadingTime)) { //Si terminada intro

			changedEstate = true;
			state = 1;

			music.skipIntro();
			music.mainTheme();

			StartManager.~StartManager();
			MenuManager.Update();

		};
		break;
	case 1: //Menu principal

		MenuManager.Update();
		MenuManager.draw(window);
		break;

	case 2: //Selector de personaje en historia

		PlayerSelector_hist.Update();
		PlayerSelector_hist.Draw(window, clock.getElapsedTime().asSeconds());

		if (PlayerSelector_hist.AnimationFinished()) {
			state = 5;
			music.historyTheme();

		}
		break;

	case 3:	//Selector de personajes en duelo

		PlayerSelector_duel.Update();
		PlayerSelector_duel.Draw(window, clock.getElapsedTime().asSeconds());

		if (PlayerSelector_duel.AnimationFinished()) {
			state = 7;
			stage = (background)(rand() % 5);
			BattleManager.RestartCombat(character1, character2, stage, true);
			BattleManager.Restart();
		}
		break;

	case 4:	//Pantalla opcines

		OptionsManager.draw(window);
		break;

	case 5:	//Cinematica historia
		HistoryManager.Update();
		if (HistoryManager.Draw(window, clock.getElapsedTime().asSeconds())) {

			state = 6;
			character2 = (CharacterType)HistoryManager.getOpponent();
			stage = (background)(rand() % 5);
			BattleManager.RestartCombat(character1, character2, stage, false);
			BattleManager.Restart();
		}
		break;

	case 6:	//Batalla historia

		BattleManager.Update();
		BattleManager.draw(window);

		ganador_partida = BattleManager.isfinished();
		if (ganador_partida == 1) {					//Ha ganado el jugador
			if (HistoryManager.NextCombat()) {		//Si modo historia completado
				FinishManager.Restart(character1);
				music.victoryTheme();
				state = 8;							//Estado cinematica final
			}
			else {
				music.historyTheme();
				HistoryManager.RestartVariables();
				state = 5;							//Si terminada partida se va a la cinematica de la historia
			}
		}
		else if (ganador_partida == 2) {			//Ha ganado la IA
			DeadManager.Restart();
			music.defeatTheme();
			state = 9;
		}

		break;

	case 7: //Batalla duelo

		BattleManager.Update();
		BattleManager.draw(window);
		if (BattleManager.isfinished() != 0) {
			PlayerSelector_duel.Restart();
			music.mainTheme();
			state = 1;	//Si terminada partida se va al selector de personajes
		} 
		
		break;

	case 8: //Cinematica final

		FinishManager.Update();
		if (FinishManager.Draw(window)) {
			music.mainTheme(); 
			state = 1;		//Si terminada cinematica final vamos al menu
		}
		break;

	case 9:	//Pantalla de muerte

		DeadManager.Update();
		if (DeadManager.Draw(window)) {
			music.mainTheme();
			state = 1;		//Si terminada pantalla de muerte vamos al menu
		}
		break;

	case 10://Controles

		ControlsManager.draw(window);
		break;

	default:

		exit(0);
		break;

	}

}