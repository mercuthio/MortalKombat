
#include "PlayerSelector.h"
#include <iostream>
using namespace std;

PlayerSelector::PlayerSelector(Texture* texture_, bool twoPlayers_) {

	texture = texture_;
	Restart();

	twoPlayers = twoPlayers_;

}

void PlayerSelector::LoadTextures() {

	Vector2f size_backg = Vector2f(width_window, height_window);
	Vector2f size_frame = Vector2f(151, 227);
	Vector2f size_icon = Vector2f(151, 227);

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

	//Iconos personajes 1 - 7
	uvRect.width = 59.0f;
	uvRect.height = 74.0f;
	uvRect.left = 904;
	uvRect.top = 409;
	rect.setSize(size_icon);

	Color Gray = Color(60, 70, 75, 255);

	for (int i = 0; i < NUMBER_CHARACTERS; i++) {

		switch (i) {
		case 0:
			uvRect.left = 904;
			rect.setPosition(87.0f, 136.0f);
			rect.setFillColor(Gray);
			break;
		case 1:
			uvRect.left = 904 + 64;
			rect.setPosition((width_window / 5.97) + 87, 136);
			rect.setFillColor(Gray);
			break;
		case 2:
			uvRect.left = 904 + 64 * 2;
			rect.setPosition((width_window / 5.97) + 87, (width_window / 4.13) + 136);
			rect.setFillColor(Gray);
			break;
		case 3:
			uvRect.left = 904 + 64 * 3;
			rect.setPosition((width_window / 5.97) * 2 + 87, (width_window / 4.13) + 136);
			rect.setFillColor(Color::White);
			break;
		case 4:
			uvRect.left = 904 + 64 * 4;
			rect.setPosition((width_window / 5.97) * 3 + 87, (width_window / 4.13) + 136);
			rect.setFillColor(Color::White);
			break;
		case 5:
			uvRect.left = 904 + 64 * 5;
			rect.setPosition((width_window / 5.97) * 3 + 87, 136);
			rect.setFillColor(Gray);
			break;
		case 6:
			uvRect.left = 904 + 64 * 6;
			rect.setPosition((width_window / 5.97) * 4 + 87, 136);
			rect.setFillColor(Color::White);
			break;
		}
		rect.setTextureRect(uvRect);
		Objects.push_back(rect);
	}
	rect.setFillColor(Color::White);

	//Marcos cursor 8 y 9
	uvRect.width = 67.0f;
	uvRect.height = 82.0f;
	uvRect.left = 904;
	uvRect.top = 571;
	rect.setSize(size_frame);

	rect.setTextureRect(uvRect);
	rect.setPosition(87.0f, 136.0f);
	Objects.push_back(rect);

	if (twoPlayers) {

		uvRect.left = 1051;
		rect.setTextureRect(uvRect);
		rect.setPosition(87.0f, 136.0f);
		Objects.push_back(rect);

	}

}

void PlayerSelector::Restart() {

	Objects.clear();
	LoadTextures();

	choosen1 = false;
	choosen2 = false;

	x = 0;
	y = 0;								
	x2 = 0;
	y2 = 0;

	clock = 0;
	clock_choosen1 = 0;
	clock_choosen2 = 0;
	frame_choosen1 = 0;
	frame_choosen2 = 0;

}

void PlayerSelector::Update() {

	Objects[8].setPosition((width_window / 5.97) * x + 87, (width_window / 4.13) * y + 136);

	if (twoPlayers)	Objects[9].setPosition((width_window / 5.97) * x2 + 87, (width_window / 4.13) * y2 + 136);
	
	IntRect uvRect;
	IntRect uvRect2;

	clock++;
	if (choosen1) clock_choosen1++;
	if (choosen2) clock_choosen2++;

	if (clock == 10) {
		
		clock = 0;
		flash = !flash;

		uvRect = Objects[8].getTextureRect();
		if (twoPlayers) uvRect2 = Objects[9].getTextureRect();

		if (flash) {
			if (twoPlayers) uvRect2.left = 1123;
			uvRect.left = 976;
		}
		else {
			if (twoPlayers) uvRect2.left = 1051;
			uvRect.left = 904;
		}

		Objects[8].setTextureRect(uvRect);
		if (twoPlayers) Objects[9].setTextureRect(uvRect2);
		
	}

	if (choosen1 && frame_choosen1 <= 8 && clock_choosen1 == 5) {

		int character = ChoosenOption_int(true);
		clock_choosen1 = 0;

		if (frame_choosen1 == 8) Objects[character + 1].setFillColor(Color::Blue);
		if (frame_choosen1 < 8 && (frame_choosen1 % 2) == 0) Objects[character + 1].setFillColor(Color::White);
		if (frame_choosen1 < 8 && (frame_choosen1 % 2) == 1) Objects[character + 1].setFillColor(Color::Transparent);

		frame_choosen1++;

	}

	if (choosen2 && frame_choosen2 <= 8 && clock_choosen2 == 5) {

		int character = ChoosenOption_int(false);
		clock_choosen2 = 0;

		if (frame_choosen2 == 8) Objects[character + 1].setFillColor(Color::Blue);
		if (frame_choosen2 < 8 && (frame_choosen2 % 2) == 0) Objects[character + 1].setFillColor(Color::White);
		if (frame_choosen2 < 8 && (frame_choosen2 % 2) == 1) Objects[character + 1].setFillColor(Color::Transparent);

		frame_choosen2++;

	}
	
}

bool PlayerSelector::AnimationFinished() {

	return ( !twoPlayers && frame_choosen1 == 9 ) || ( twoPlayers && frame_choosen1 == 9 && frame_choosen2 == 9 );

}

void PlayerSelector::MoveCursor(int x_, int y_, bool player1) {

	if (!choosen1 && player1 && x == 1 && y == 0 && x_ == 1 ) {
		x = 3;
		music.moveSelector();
	}
	else if (!choosen1 && player1&& x == 3 && y == 0 && x_ == -1) {
		x = 1;
		music.moveSelector();
	}
	else if (!choosen2 && !player1 && x2 == 1 && y2 == 0 && x_ == 1) {
		x2 = 3;
		music.moveSelector();
	}
	else if (!choosen2 && !player1 && x2 == 3 && y2 == 0 && x_ == -1) {
		x2 = 1;
		music.moveSelector();
	}
	else {
		if (player1 && !choosen1 && CHARACTERS[y + y_][x + x_] == 1) {
			x += x_;
			y += y_;
			music.moveSelector();
		}
		else if (!player1 && !choosen2 && CHARACTERS[y2 + y_][x2 + x_] == 1) {
			x2 += x_;
			y2 += y_;
			music.moveSelector();
		}
	}

}

int PlayerSelector::ChoosenOption_int(bool player1) {

	int charac = 0;
	if (!player1 && ((x2 == 4 && y2 == 0) || (x2 == 2 && y2 == 1) || (x2 == 3 && y2 == 1)) ) {
		choosen2 = true;

		if (y2 == 0 && x2 < 2) {
			charac = x2;
		}
		else if (y2 == 0) {
			charac = x2 + 2;
		}
		else {
			charac = x2 + 1;
		}

		return  (CharacterType)charac;
	}

	if ((x == 4 && y == 0) || (x == 2 && y == 1) || (x == 3 && y == 1)) {
		choosen1 = true;
		if (y == 0 && x < 2) {
			charac = x;
		}
		else if (y == 0) {
			charac = x + 2;
		}
		else {
			charac = x + 1;
		}
		return (CharacterType)charac;
	}

}

CharacterType PlayerSelector::ChoosenOption(bool player1) {

	return (CharacterType)ChoosenOption_int(player1);

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
