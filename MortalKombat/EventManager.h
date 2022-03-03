#ifndef	EventManager_H
#define EventManager_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "StartManager.h"
#include "MenuManager.h"
#include "TransitionManager.h"
#include "OptionsManager.h"
#include "PlayerSelector.h"

using namespace sf;
using namespace std;

const int NUMERO_CANCIONES = 10;

class EventManager {

public:
	EventManager(Texture[], Font);
	~EventManager() = default;

	void Actualizar(Event);
	void draw(RenderWindow&);
	void setClock(Clock);
	void drawPlayerSelectorChoose(RenderWindow&);

private:

	void drawTransitionManager(RenderWindow& window);

	int estado;	//0 = StartManager, 1 = MenuManager, 2 = PlayerSelectorHistoria, 3 = PlayerSelectorDuelo, 4 = OptionsManager, 5 = Torre, 6 = Batalla
	int personaje1;
	bool cambiadoEstado;
	MenuManager MenuManager;
	Music musica[NUMERO_CANCIONES];
	StartManager StartManager;
	OptionsManager OptionsManager;
	TransitionManager TransitionManager;
	Clock clock;
	PlayerSelector PlayerSelector;

};

#endif