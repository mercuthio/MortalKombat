
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

	frame.setSize(Vector2f(151,227));
	frame.setPosition(87, 136);
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

		frame2.setSize(Vector2f(151, 227));
		frame2.setPosition(87, 136);
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

	backg.setSize(Vector2f(width_window, height_window));

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		switch (i) {
		case 0:
			uvRect_chara.left = 904;
			icons[i].setPosition(87, 136);
			break;
		case 1:
			uvRect_chara.left = 904 + 64;
			icons[i].setPosition((width_window / 5.97) + 87, 136);
			break;
		case 2:
			uvRect_chara.left = 904 + 64 * 2;
			icons[i].setPosition((width_window / 5.97) + 87, (width_window / 4.13) + 136);
			break;
		case 3:
			uvRect_chara.left = 904 + 64 * 3;
			icons[i].setPosition((width_window / 5.97) * 2 + 87, (width_window / 4.13) + 136);
			break;
		case 4:
			uvRect_chara.left = 904 + 64 * 4;
			icons[i].setPosition((width_window / 5.97) * 3 + 87, (width_window / 4.13) + 136);
			break;
		case 5:
			uvRect_chara.left = 904 + 64 * 5;
			icons[i].setPosition((width_window / 5.97) * 3 + 87, 136);
			break;
		case 6:
			uvRect_chara.left = 904 + 64 * 6;
			icons[i].setPosition((width_window / 5.97) * 4 + 87, 136);
			break;
		}
		icons[i].setTextureRect(uvRect_chara);
		icons[i].setSize(Vector2f(151, 227));
	}

}

void PlayerSelector::Restart() {

	choosen1 = false;
	choosen2 = false;

	x = 0;
	y = 0;								
	x2 = 0;
	y2 = 0;

	time = 0;

}

void PlayerSelector::Update() {

	frame.setPosition((width_window / 5.97) * x + 87, (width_window / 4.13) * y + 136);

	if (twoPlayers)
		frame2.setPosition((width_window / 5.97) * x2 + 87, (width_window / 4.13) * y2 + 136);

}

void PlayerSelector::MoveCursor(int x_, int y_, bool player1) {

	if (player1 && x == 1 && y == 0 && x_ == 1 ) {
		x = 3;
	}
	else if (player1&& x == 3 && y == 0 && x_ == -1) {
		x = 1;
	}
	else if (!player1 && x2 == 1 && y2 == 0 && x_ == 1) {
		x2 = 3;
	}
	else if (!player1 && x2 == 3 && y2 == 0 && x_ == -1) {
		x2 = 1;
	}
	else {
		if (player1 && !choosen1 && CHARACTERS[y + y_][x + x_] == 1) {

			x += x_;
			y += y_;
		}
		else if (!player1 && !choosen2 && CHARACTERS[y2 + y_][x2 + x_] == 1) {
			x2 += x_;
			y2 += y_;
		}
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
			while (clock.getElapsedTime().asSeconds() < 1.0f) {}

	}

}

character PlayerSelector::ChoosenOption(bool player1) {

	if (!player1) {
		choosen2 = true;
		return (character) (x2 + (MAX_X * y2));
	}
	choosen1 = true;
	return (character) (x + (MAX_X * y));

}

//Solo es llamada en el caso de dos personajes
bool PlayerSelector::Choosen() {

	return choosen1 && choosen2;
	
}


void PlayerSelector::Draw(RenderWindow& window, float seconds) {

	window.draw(backg);
	
	for (int i = 0; i < NUMBER_CHARACTERS; i++) {
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

	window.draw(frame);

	if (twoPlayers) {
		window.draw(frame2);
	}

}
