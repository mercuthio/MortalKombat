
#include "PlayerSelector.h"
#include <iostream>
using namespace std;
PlayerSelector::PlayerSelector(Texture* texture, bool twoPlayers_) {

	x = 0;
	y = 0;
	flash = false;
	choosen1 = false;
	twoPlayers = twoPlayers_;

	Vector2f size_backg = Vector2f(width_window, height_window);
	Vector2f size_frame = Vector2f(151, 227);
	Vector2f size_icon = Vector2f(26, 31);

	IntRect uvRect;
	RectangleShape rect;

	rect.setTexture(texture);
	rect.setScale(1.0f, 1.0f);

	//Fondo 0
	uvRect.width = 400.0f;
	uvRect.height = 254.0f;
	uvRect.left = 486;
	uvRect.top = 393;
	rect.setSize(size_backg);

	rect.setTextureRect(uvRect);
	rect.setPosition(0.0f, 0.0f);
	Objects.push_back(rect);

	//Marcos cursor 1 y 2
	uvRect.width = 67.0f;
	uvRect.height = 82.0f;
	uvRect.left = 904;
	uvRect.top = 571;
	rect.setSize(size_frame);

	rect.setTextureRect(uvRect);
	rect.setPosition(87.0f, 136.0f);
	Objects.push_back(rect);

	if (twoPlayers) {

		choosen2 = false;
		x2 = 0;
		y2 = 0;

		uvRect.left = 904;
		rect.setTextureRect(uvRect);
		rect.setPosition(87.0f, 136.0f);
		Objects.push_back(rect);

	}

	//Iconos personajes 3 - 10
	uvRect.width = 59.0f;
	uvRect.height = 74.0f;
	uvRect.left = 904;
	uvRect.top = 409;
	rect.setSize(size_icon);

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		switch (i) {
		case 0:
			uvRect.left = 904;
			rect.setPosition(87.0f, 136.0f);
			break;
		case 1:
			uvRect.left = 904 + 64;
			rect.setPosition((width_window / 5.97) + 87, 136);
			break;
		case 2:
			uvRect.left = 904 + 64 * 2;
			rect.setPosition((width_window / 5.97) + 87, (width_window / 4.13) + 136);
			break;
		case 3:
			uvRect.left = 904 + 64 * 3;
			rect.setPosition((width_window / 5.97) * 2 + 87, (width_window / 4.13) + 136);
			break;
		case 4:
			uvRect.left = 904 + 64 * 4;
			rect.setPosition((width_window / 5.97) * 3 + 87, (width_window / 4.13) + 136);
			break;
		case 5:
			uvRect.left = 904 + 64 * 5;
			rect.setPosition((width_window / 5.97) * 3 + 87, 136);
			break;
		case 6:
			uvRect.left = 904 + 64 * 6;
			rect.setPosition((width_window / 5.97) * 4 + 87, 136);
			break;
		}
		rect.setTextureRect(uvRect);
		Objects.push_back(rect);
	}

}

void PlayerSelector::Restart() {

	choosen1 = false;
	choosen2 = false;

	x = 0;
	y = 0;								
	x2 = 0;
	y2 = 0;

	clock = 0;

}

void PlayerSelector::Update() {

	Objects[1].setPosition((width_window / 5.97) * x + 87, (width_window / 4.13) * y + 136);

	if (twoPlayers)
		Objects[2].setPosition((width_window / 5.97) * x2 + 87, (width_window / 4.13) * y2 + 136);

	IntRect uvRect;
	clock++;

	if (clock == 10) {
		
		clock = 0;
		flash = !flash;

		uvRect = Objects[1].getTextureRect();

		if (flash) {
			uvRect.left += 72;
		}
		else {
			uvRect.left -= 72;
		}

		Objects[1].setTextureRect(uvRect);
		if (twoPlayers) Objects[2].setTextureRect(uvRect);

	}

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
				Objects[3 + character].setFillColor(Color::Black);
				window.draw(Objects[3 + character]);
				Objects[3 + character].setFillColor(Color::White);
				window.draw(Objects[3 + character]);
				frames++;
				time = clock.getElapsedTime().asSeconds();
			}

		}

		while (clock.getElapsedTime().asSeconds() - time < 3.0f) {}
		/*
		uvRect_chara.top += 77;
		icons[character].setTextureRect(uvRect_chara); //uvRect_frame
		window.draw(icons[character]);
		if ((twoPlayers && choosen1 && choosen2) || (!twoPlayers))
			while (clock.getElapsedTime().asSeconds() < 1.0f) {}
		*/
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

	for (RectangleShape object : Objects) {
		window.draw(object);
	}

}
