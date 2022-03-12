
#include "PlayerSelector.h"
#include <iostream>
using namespace std;
PlayerSelector::PlayerSelector(Texture* texture, bool dosJugadores_) {

	x = 0;
	y = 0;
	parpadeo = false;
	elegido1 = false;
	dosJugadores = dosJugadores_;

	uvRect_backg.width = 400;
	uvRect_backg.height = 254;
	uvRect_backg.left = 486;
	uvRect_backg.top = 393;

	fondo.setPosition(0, 0);
	fondo.setTextureRect(uvRect_backg);
	fondo.setTexture(texture);

	uvRect_frame.width = 67;
	uvRect_frame.height = 82;
	uvRect_frame.left = 904;
	uvRect_frame.top = 571;

	marco.setPosition(marco.getSize().x * x + 56, marco.getSize().y * y + 99);
	marco.setTextureRect(uvRect_frame);
	marco.setTexture(texture);

	if (dosJugadores) {

		elegido2 = false;

		x2 = 0;
		y2 = 0;

		uvRect_frame2.width = 67;
		uvRect_frame2.height = 82;
		uvRect_frame2.left = 1051;
		uvRect_frame2.top = 571;

		marco2.setPosition(marco2.getSize().x * x2 + 56, marco2.getSize().y * y2 + 99);
		marco2.setTextureRect(uvRect_frame2);
		marco2.setTexture(texture);

	}

	uvRect_chara.width = 59;
	uvRect_chara.height = 74;
	uvRect_chara.left = 904;
	uvRect_chara.top = 409;

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		icons[i].setTextureRect(uvRect_chara);
		icons[i].setTexture(texture);

	}

}

void PlayerSelector::Actualizar() {

	marco.setPosition(marco.getSize().x * x + 56, marco.getSize().y * y + 99);

	if (dosJugadores)
		marco2.setPosition(marco2.getSize().x * x2 + 56, marco2.getSize().y * y2 + 99);

}

void PlayerSelector::MoverCursor(int x_, int y_, bool jugador1) {

	if (jugador1 && !elegido1 && PERSONAJES[y + y_][x + x_] == 1) {
		x += x_;
		y += y_;
	}
	else if (!jugador1 && !elegido2 && PERSONAJES[y2 + y_][x2 + x_] == 1) {
		x2 += x_;
		y2 += y_;
	}

}

void PlayerSelector::DrawChoosen(RenderWindow& window, bool jugador1) {
	int character = 0;

	if (jugador1) {
		elegido1 = true;
		if (y == 0) { //Primera fila
			character = x;
		}
		else { //Segunda fila
			character = x + 2;
		}
	}
	else {
		elegido2 = true;
		if (y2 == 0) { //Primera fila
			character = x2;
		}
		else { //Segunda fila
			character = x2 + 2;
		}
	}

	Clock clock;
	float time = 0;
	int frames = 0;

	//Animacion de seleccion del personaje
	while (frames < 3){

		if (clock.getElapsedTime().asSeconds() - time > 0.1f) {
			icons[character].setFillColor(Color::White);
			window.draw(icons[character]);
			frames++;
			time = clock.getElapsedTime().asSeconds();
		}

	}

	uvRect_chara.top += 77;
	icons[character].setTextureRect(uvRect_chara); //uvRect_frame
	window.draw(icons[character]);
	if ((dosJugadores && elegido1 && elegido2) || (!dosJugadores))
		while (clock.getElapsedTime().asSeconds() < 2.0f){}

}

int PlayerSelector::OpcionElegida(bool jugador1) {

	if (!jugador1) {
		elegido2 = true;
		return x2 + (MAXIMO_X * y2);
	}
	elegido1 = true;
	return x + (MAXIMO_X * y);

}

//Solo es llamada en el caso de dos personajes
bool PlayerSelector::Elegidos() {

	return elegido1 && elegido2;
	
}


void PlayerSelector::Draw(RenderWindow& window, float segundos) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		switch (i) {
		case 0:
			uvRect_chara.left = 904;
			icons[i].setPosition(56, 99);
			break;
		case 1:
			uvRect_chara.left = 904 + 64;
			icons[i].setPosition(marco.getSize().x + 56, 99);
			break;
		case 2:
			uvRect_chara.left = 904 + 64*2;
			icons[i].setPosition(marco.getSize().x + 56, marco.getSize().y + 99);
			break;
		case 3:
			uvRect_chara.left = 904 + 64*3;
			icons[i].setPosition(marco.getSize().x*2 + 56, marco.getSize().y + 99);
			break;
		case 4:
			uvRect_chara.left = 904 + 64*4;
			icons[i].setPosition(marco.getSize().x*3 + 56, marco.getSize().y + 99);
			break;
		case 5:
			uvRect_chara.left = 904 + 64*5;
			icons[i].setPosition(marco.getSize().x*3 + 56, 99);
			break;
		case 6:
			uvRect_chara.left = 904 + 64*6;
			icons[i].setPosition(marco.getSize().x*4 + 56, 99);
			break;
		}
		icons[i].setTextureRect(uvRect_chara);
		icons[i].setSize(Vector2f(135, 190));
		window.draw(icons[i]);

	}

	if (segundos - tiempo >= 0.1f) {
		parpadeo = !parpadeo;
		if (parpadeo) {
			uvRect_frame.left += 72;
			if (dosJugadores)
				uvRect_frame2.left += 72;

		}
		else {
			uvRect_frame.left -= 72;
			if (dosJugadores)
				uvRect_frame2.left -= 72;
		}
		marco.setTextureRect(uvRect_frame);
		if (dosJugadores)
			marco2.setTextureRect(uvRect_frame2);
		tiempo = segundos;


	}
	marco.setSize(Vector2f(135, 190));
	window.draw(marco);

	if (dosJugadores) {
		marco2.setSize(Vector2f(135, 190));
		window.draw(marco2);
	}

}
