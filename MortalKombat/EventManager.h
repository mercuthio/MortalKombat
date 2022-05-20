#ifndef	EventManager_H
#define EventManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "StartManager.h"
#include "MenuManager.h"
#include "OptionsManager.h"
#include "PlayerSelector.h"
#include "HistoryManager.h"
#include "BattleManager.h"
#include "MusicManager.h"
#include "DeadManager.h"
#include "FinishManager.h"
#include "ControlsManager.h"

#include <chrono>
#include <thread>
#include <time.h>

using namespace sf;
using namespace std;

class EventManager {

public:
	EventManager(Texture[], Font, Clock);
	~EventManager() = default;

	void Update(Event);									//Actualiza el menu actual dada una tecla pulsada
	void draw(RenderWindow&);							//Dibuja el menu actual

private:

	void drawTransitionManager(RenderWindow& window);	//Dibuja la transicion entre pantallas

	int state = 0;											//0 = StartManager, 1 = MenuManager, 2 = PlayerSelectorHistoria, 3 = PlayerSelectorDuelo, 4 = OptionsManager, 5 = Torre, 6 = Batalla
	bool changedEstate = false;									//True cuando se va a cambiar el estado en el siguiente frame, false en cualquier otro momento

	CharacterType character1;							//Personaje elegido por el jugador 1
	CharacterType character2;							//Personaje elegido por el jugador 2

	background stage;
	MenuManager MenuManager;							//Objeto del menu principal
	StartManager StartManager;						//Objeto de las pantallas iniciales
	OptionsManager OptionsManager;						//Objeto del menu de opciones
	Clock clock = Clock();										//Reloj para gestionar actualizacion de animaciones
	PlayerSelector PlayerSelector_hist;					//Objeto de selector de personajes de historia
	PlayerSelector PlayerSelector_duel;					//Objeto de selector de personajes de duelo
	HistoryManager HistoryManager;
	BattleManager BattleManager;
	DeadManager DeadManager;
	FinishManager FinishManager;
	ControlsManager ControlsManager;

	RectangleShape loading_screen = RectangleShape();
	Texture* texture = new Texture();

};

#endif