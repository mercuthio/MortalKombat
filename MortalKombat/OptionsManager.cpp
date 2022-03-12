
#include "OptionsManager.h"
#include "MenuManager.h"

OptionsManager::OptionsManager(Texture* textura, Font font_) {

	font = font_;
	opcionElegida = 0;
	musica = 3;
	efectos = 3;
	velocidad = 1;
	dificultad = false;

	for (int i = 0; i < MAXIMO_MUSICA; i++) {
		musi[i].setSize(Vector2f(15, TAMANIO_LETRA));
	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {
		efec[i].setSize(Vector2f(15, TAMANIO_LETRA));
	}

	for (int i = 0; i <= NUMERO_OPCIONES; i++) {
		text[i].setFont(font);
		text[i].setFillColor(Color::Black);
		text[i].setCharacterSize(TAMANIO_LETRA);
		text[i].setOutlineColor(Color::Green);
		text[i].setOutlineThickness(2.0f);
	}

	text[0].setString("MUSICA");
	text[1].setString("EFECTOS");
	text[2].setString("VELOCIDAD");
	text[3].setString("DIFICULTAD");
	text[4].setString("SALIR");

	veloc.setFont(font);
	veloc.setFillColor(Color::Green);
	veloc.setCharacterSize(TAMANIO_LETRA);

	dific.setFont(font);
	dific.setFillColor(Color::Green);
	dific.setCharacterSize(TAMANIO_LETRA);

	uvRect.width = 390;
	uvRect.height = 250;
	uvRect.left = 1440;
	uvRect.top = 885;

	fondo.setPosition(0, 0);
	fondo.setTextureRect(uvRect);
	fondo.setTexture(textura);

}

void OptionsManager::Actualizar() {

	text[opcionElegida].setFillColor(Color::Green);
	text[opcionElegida].setOutlineColor(Color::Black);

	for (int i = 0; i <= NUMERO_OPCIONES; i++) {
		if (i != opcionElegida && text[i].getFillColor() == Color::Green) {
			text[i].setFillColor(Color::Black);
			text[i].setOutlineColor(Color::Green);
		}
	}

	for (int i = 0; i < MAXIMO_MUSICA; i++) {

		if (i <= musica) {
			musi[i].setFillColor(Color::Green);
		}
		else {
			musi[i].setFillColor(Color::Black);
		}

	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {

		if (i <= efectos) {
			efec[i].setFillColor(Color::Green);
		}
		else {
			efec[i].setFillColor(Color::Black);
		}

	}

	switch (velocidad) {
	case 0:
		veloc.setString("LENTA");
		break;
	case 1:
		veloc.setString("NORMAL");
		break;

	case 2:
		veloc.setString("RAPIDA");
		break;
	}

	if (dificultad) {
		dific.setString("DIFICIL");
	}
	else {
		dific.setString("NORMAL");
	}

}

void OptionsManager::Enter(Music& music) {

	switch (opcionElegida) {
	case 0: //MUSICA
		if (musica + 1 < MAXIMO_MUSICA) {
			musica++;
		}
		music.setVolume((musica + 1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (efectos + 1 < MAXIMO_EFECTOS) {
			efectos++;
		}
		break;
	case 2: //VELOCIDAD
		if (velocidad + 1 < MAXIMO_VELOCIDAD) {
			velocidad++;
		}
		break;
	case 3: //DIFICULTAD
		dificultad = !dificultad;
		break;
	}

}

void OptionsManager::Izquierda(Music& music) {

	switch (opcionElegida) {
	case 0: //MUSICA
		if (musica - 1 >= -1) {
			musica--;
		}
		music.setVolume((musica + 1) * 20.0f);
		break;
	case 1: //EFECTOS
		if (efectos - 1 >= -1) {
			efectos--;
		}
		break;
	case 2: //VELOCIDAD
		if (velocidad - 1>= 0) {
			velocidad--;
		}
		break;
	case 3: //DIFICULTAD
		dificultad = !dificultad;
		break;
	}

}

int OptionsManager::OpcionElegida() {

	return opcionElegida;

}

void OptionsManager::draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

	for (int i = 0; i < NUMERO_OPCIONES - 1; i++) {
		text[i].setPosition(Vector2f(window.getSize().x / 10, window.getSize().y / 10 + TAMANIO_LETRA * (i * 1.3)));
		window.draw(text[i]);
	}

	for (int i = 0; i < MAXIMO_MUSICA; i++) {
		musi[i].setPosition(Vector2f(window.getSize().x / 1.6 + (i * (TAMANIO_LETRA / 2)), window.getSize().y / 10));
		window.draw(musi[i]);
	}

	for (int i = 0; i < MAXIMO_EFECTOS; i++) {
		efec[i].setPosition(Vector2f(window.getSize().x / 1.6 + (i * (TAMANIO_LETRA / 2)), window.getSize().y / 10 + TAMANIO_LETRA * 1.5));
		window.draw(efec[i]);
	}

	veloc.setPosition(Vector2f(window.getSize().x / 1.6, window.getSize().y / 10 + TAMANIO_LETRA * (2 * 1.3)));
	window.draw(veloc);

	dific.setPosition(Vector2f(window.getSize().x / 1.6, window.getSize().y / 10 + TAMANIO_LETRA * (3 * 1.3)));
	window.draw(dific);

	text[NUMERO_OPCIONES - 1].setPosition(Vector2f(window.getSize().x / 10, window.getSize().y / 1.2 - (TAMANIO_LETRA + 5)));
	window.draw(text[NUMERO_OPCIONES - 1]);

}

void OptionsManager::moverCursor(bool arriba) {

	if (arriba) {
		opcionElegida--;
		if (opcionElegida < 0) {
			opcionElegida = NUMERO_OPCIONES - 1;
		}
	}
	else if (!arriba) {
		opcionElegida++;
		if (opcionElegida == NUMERO_OPCIONES) {
			opcionElegida = 0;
		}
	}

}
