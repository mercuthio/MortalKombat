
#include "PlayerSelector.h"
#include <iostream>
using namespace std;
PlayerSelector::PlayerSelector(Texture* texture) {

	x = 0;
	y = 0;
	parpadeo = false;

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

}

void PlayerSelector::MoverCursor(int x_, int y_) {

	if (PERSONAJES[y + y_][x + x_] == 1) {
		x += x_;
		y += y_;
	}

}

void PlayerSelector::DrawChoosen(RenderWindow& window) {
	int character = 0;

	if (y == 0) { //Primera fila
		character = x;
	}
	else { //Segunda fila
		character = x + 2;
	}	

	Clock clock;
	float time = 0;
	int frames = 0;

	while (frames < 3){

		if (clock.getElapsedTime().asSeconds() - time > 0.1f) {
			icons[character].setFillColor(Color::White);
			window.draw(icons[character]);
			frames++;
			time = clock.getElapsedTime().asSeconds();
		}

	}

	uvRect_chara.top += 77;
	icons[character].setTextureRect(uvRect_frame);
	window.draw(icons[character]);
	while (clock.getElapsedTime().asSeconds() < 2.0f){}

}

int PlayerSelector::OpcionElegida() {

	return x + (MAXIMO_X * y);

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
		}
		else {
			uvRect_frame.left -= 72;
		}
		marco.setTextureRect(uvRect_frame);
		tiempo = segundos;
	}
	marco.setSize(Vector2f(135, 190));
	window.draw(marco);

}
