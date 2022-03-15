
#include "PlayerSelector.h"
#include <iostream>
using namespace std;
PlayerSelector::PlayerSelector(Texture* texture, bool twoPlayers_) {

	x = 0;
	y = 0;
	flash = false;
	choosen1 = false;
	twoPlayers = twoPlayers_;

	uvRect_backg.width = 400;
	uvRect_backg.height = 254;
	uvRect_backg.left = 486;
	uvRect_backg.top = 393;

	backg.setPosition(0, 0);
	backg.setTextureRect(uvRect_backg);
	backg.setTexture(texture);

	uvRect_frame.width = 67;
	uvRect_frame.height = 82;
	uvRect_frame.left = 904;
	uvRect_frame.top = 571;

	frame.setPosition(frame.getSize().x * x + 56, frame.getSize().y * y + 99);
	frame.setTextureRect(uvRect_frame);
	frame.setTexture(texture);

	if (twoPlayers) {

		choosen2 = false;

		x2 = 0;
		y2 = 0;

		uvRect_frame2.width = 67;
		uvRect_frame2.height = 82;
		uvRect_frame2.left = 1051;
		uvRect_frame2.top = 571;

		frame2.setPosition(frame2.getSize().x * x2 + 56, frame2.getSize().y * y2 + 99);
		frame2.setTextureRect(uvRect_frame2);
		frame2.setTexture(texture);

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

void PlayerSelector::Update() {

	frame.setPosition(frame.getSize().x * x + 56, frame.getSize().y * y + 99);

	if (twoPlayers)
		frame2.setPosition(frame2.getSize().x * x2 + 56, frame2.getSize().y * y2 + 99);

}

void PlayerSelector::MoveCursor(int x_, int y_, bool player1) {

	if (player1 && !choosen1 && CHARACTERS[y + y_][x + x_] == 1) {
		x += x_;
		y += y_;
	}
	else if (!player1 && !choosen2 && CHARACTERS[y2 + y_][x2 + x_] == 1) {
		x2 += x_;
		y2 += y_;
	}

}

void PlayerSelector::DrawChoosen(RenderWindow& window, bool player1) {
	int character = 0;

	if (!(!player1 && !twoPlayers)) {

		if (player1) {
			choosen1 = true;
			if (y == 0) { //Primera fila
				character = x;
			}
			else { //Segunda fila
				character = x + 2;
			}
		}
		else {
			choosen2 = true;
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
		while (frames < 3) {

			if (clock.getElapsedTime().asSeconds() - time > 0.1f) {
				icons[character].setFillColor(Color::Black);
				window.draw(icons[character]);
				icons[character].setFillColor(Color::White);
				window.draw(icons[character]);
				frames++;
				time = clock.getElapsedTime().asSeconds();
			}

		}

		while (clock.getElapsedTime().asSeconds() - time < 3.0f) {}

		uvRect_chara.top += 77;
		icons[character].setTextureRect(uvRect_chara); //uvRect_frame
		window.draw(icons[character]);
		if ((twoPlayers && choosen1 && choosen2) || (!twoPlayers))
			while (clock.getElapsedTime().asSeconds() < 2.0f) {}
		cout << "hasta luego " << endl;
	}

}

int PlayerSelector::ChoosenOption(bool player1) {

	if (!player1) {
		choosen2 = true;
		return x2 + (MAX_X * y2);
	}
	choosen1 = true;
	return x + (MAX_X * y);

}

//Solo es llamada en el caso de dos personajes
bool PlayerSelector::Choosen() {

	return choosen1 && choosen2;
	
}


void PlayerSelector::Draw(RenderWindow& window, float seconds) {

	backg.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(backg);

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		switch (i) {
		case 0:
			uvRect_chara.left = 904;
			icons[i].setPosition(56, 99);
			break;
		case 1:
			uvRect_chara.left = 904 + 64;
			icons[i].setPosition(frame.getSize().x + 56, 99);
			break;
		case 2:
			uvRect_chara.left = 904 + 64*2;
			icons[i].setPosition(frame.getSize().x + 56, frame.getSize().y + 99);
			break;
		case 3:
			uvRect_chara.left = 904 + 64*3;
			icons[i].setPosition(frame.getSize().x*2 + 56, frame.getSize().y + 99);
			break;
		case 4:
			uvRect_chara.left = 904 + 64*4;
			icons[i].setPosition(frame.getSize().x*3 + 56, frame.getSize().y + 99);
			break;
		case 5:
			uvRect_chara.left = 904 + 64*5;
			icons[i].setPosition(frame.getSize().x*3 + 56, 99);
			break;
		case 6:
			uvRect_chara.left = 904 + 64*6;
			icons[i].setPosition(frame.getSize().x*4 + 56, 99);
			break;
		}
		icons[i].setTextureRect(uvRect_chara);
		icons[i].setSize(Vector2f(135, 190));
		window.draw(icons[i]);

	}

	if (seconds - time >= 0.1f) {
		flash = !flash;
		if (flash) {
			uvRect_frame.left += 72;
			if (twoPlayers)
				uvRect_frame2.left += 72;

		}
		else {
			uvRect_frame.left -= 72;
			if (twoPlayers)
				uvRect_frame2.left -= 72;
		}
		frame.setTextureRect(uvRect_frame);
		if (twoPlayers)
			frame2.setTextureRect(uvRect_frame2);
		time = seconds;


	}
	frame.setSize(Vector2f(135, 190));
	window.draw(frame);

	if (twoPlayers) {
		frame2.setSize(Vector2f(135, 190));
		window.draw(frame2);
	}

}
