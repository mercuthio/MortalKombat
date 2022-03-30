
#include "StartManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

StartManager::StartManager(Texture* menus, Texture* bios) {

	srand(time(0));
	character = rand() % 8;
	actual_frame = 0;
	seconds_aux = 3.0f;

	uvRect_backg.width = 390;
	uvRect_backg.height = 250;
	uvRect_backg.left = 1890;
	uvRect_backg.top = 1551;

	menu_backg.setPosition(0, 0);
	menu_backg.setTextureRect(uvRect_backg);
	menu_backg.setTexture(menus);

	bio_backg.setPosition(0, 0);
	bio_backg.setTextureRect(uvRect_backg);
	bio_backg.setTexture(bios);

	switch (character) {
	case(0):
		uvRect_name.top = 8;
		uvRect_text.left = 8;
		uvRect_text.top = 1770;
		uvRect_icon.top = 32;
		break;
	case(1):
		uvRect_name.top = 218;
		uvRect_text.left = 305;
		uvRect_text.top = 1770;
		uvRect_icon.top = 244;
		break;
	case(2):
		uvRect_name.top = 430;
		uvRect_text.left = 602;
		uvRect_text.top = 1770;
		uvRect_icon.top = 456;
		break;
	case(3):
		uvRect_name.top = 640;
		uvRect_text.left = 8;
		uvRect_text.top = 1862;
		uvRect_icon.top = 664;
		break;
	case(4):
		uvRect_name.top = 848;
		uvRect_text.left = 305;
		uvRect_text.top = 1862;
		uvRect_icon.top = 872;
		break;
	case(5):
		uvRect_name.top = 1056;
		uvRect_text.left = 602;
		uvRect_text.top = 1862;
		uvRect_icon.top = 1080;
		break;
	case(6):
		uvRect_name.top = 1264;
		uvRect_text.left = 8;
		uvRect_text.top = 1954;
		uvRect_icon.top = 1288;
		break;
	}

	uvRect_icon.width = 108;
	uvRect_icon.height = 82;
	uvRect_icon.left = 10;

	uvRect_name.width = 133;
	uvRect_name.height = 18;
	uvRect_name.left = 8;

	uvRect_text.width = 289;
	uvRect_text.height = 84;

	icon.setTextureRect(uvRect_icon);
	icon.setTexture(bios);

	name.setTextureRect(uvRect_name);
	name.setTexture(bios);

	text.setTextureRect(uvRect_text);
	text.setTexture(bios);

	bio_backg.setSize(Vector2f(width_window, height_window));
	menu_backg.setSize(Vector2f(width_window, height_window));

	icon.setSize(Vector2f(width_window / 3.7, height_window / 3.1));
	text.setSize(Vector2f(width_window / 1.4, height_window / 2.8));
	name.setSize(Vector2f(width_window / 2.8, height_window / 10));

}

//Script de la intro
bool StartManager::draw(RenderWindow& window, float seconds) {


	if (seconds > 25.0f) {		//Pantalla goro con texto
		uvRect_backg.left = 3586;
		menu_backg.setTextureRect(uvRect_backg);
		window.draw(menu_backg);
	}
	else if (seconds > 22.0f) { //Pantalla goro sin texto
		uvRect_backg.left = 3162;
		menu_backg.setTextureRect(uvRect_backg);
		window.draw(menu_backg);
	}
	else if (seconds > 20.0f) { //Pantalla goro lives
		menu_backg.setFillColor(Color::White);
		uvRect_backg.left = 2738;
		uvRect_backg.top = 1551;
		menu_backg.setTextureRect(uvRect_backg);
		window.draw(menu_backg);
	}
	else if (seconds > 19.0) { //Fondo negro
		menu_backg.setFillColor(Color::Black);
		window.draw(menu_backg);
	}
	else if (seconds > 8.0f) {	//Biografia del personaje
		
		if (seconds - seconds_aux > 0.1f) {
			seconds_aux = seconds;
			updateFrame();
		}

		name.setOrigin(name.getSize().x / 2, name.getSize().y / 2);
		name.setPosition(Vector2f(float(width_window / 2), float(height_window / 7)));

		icon.setOrigin(name.getSize().x / 2, name.getSize().y / 2);
		icon.setPosition(Vector2f(float(width_window / 1.8), float(height_window / 3.3)));

		text.setOrigin(name.getSize().x / 2, name.getSize().y / 2);
		text.setPosition(Vector2f(float(width_window / 3), float(height_window / 1.5)));

		uvRect_backg.left = 12;
		uvRect_backg.top = 1504;

		bio_backg.setTextureRect(uvRect_backg);
		icon.setTextureRect(uvRect_icon);
		window.draw(bio_backg);
		window.draw(name);
		window.draw(icon);
		window.draw(text);

	}
	else if (seconds > 4.0f) { //Pantalla inicial roja
		uvRect_backg.left = 2320;
		menu_backg.setTextureRect(uvRect_backg);
		window.draw(menu_backg);
	}
	else {
		window.draw(menu_backg);
	}

	if (seconds > 40.0f) {
		return true;
	}
	return false;

}

//Actuailza el frame del sprite mostrado en el icono de la biografia
void StartManager::updateFrame() {
	if (actual_frame < NUM_FRAMES[character]) {
		actual_frame++;

		if (actual_frame == ENDIND_LINE_FRAME[character] + 1) {
			uvRect_icon.top += 82 + 4;
			uvRect_icon.left = 10;
		}
		else {
			uvRect_icon.left += 108 + 4;
		}
	
	}

}

