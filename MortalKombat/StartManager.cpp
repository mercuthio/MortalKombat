
#include "StartManager.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

StartManager::StartManager(Texture* menus, Texture* bios) {

	srand(time(NULL));
	personaje = rand() % 8;
	actual_frame = 0;
	seconds_aux = 3.0f;

	uvRect_fondo.width = 390;
	uvRect_fondo.height = 250;
	uvRect_fondo.left = 1890;
	uvRect_fondo.top = 1551;

	fondo_menus.setPosition(0, 0);
	fondo_menus.setTextureRect(uvRect_fondo);
	fondo_menus.setTexture(menus);

	fondo_bios.setPosition(0, 0);
	fondo_bios.setTextureRect(uvRect_fondo); //no necesario
	fondo_bios.setTexture(bios);

	switch (personaje) {
	case(0):
		uvRect_nombre.top = 8;
		uvRect_texto.left = 8;
		uvRect_texto.top = 1770;
		uvRect_icono.top = 32;
		break;
	case(1):
		uvRect_nombre.top = 218;
		uvRect_texto.left = 305;
		uvRect_texto.top = 1770;
		uvRect_icono.top = 244;
		break;
	case(2):
		uvRect_nombre.top = 430;
		uvRect_texto.left = 602;
		uvRect_texto.top = 1770;
		uvRect_icono.top = 456;
		break;
	case(3):
		uvRect_nombre.top = 640;
		uvRect_texto.left = 8;
		uvRect_texto.top = 1862;
		uvRect_icono.top = 664;
		break;
	case(4):
		uvRect_nombre.top = 848;
		uvRect_texto.left = 305;
		uvRect_texto.top = 1862;
		uvRect_icono.top = 872;
		break;
	case(5):
		uvRect_nombre.top = 1056;
		uvRect_texto.left = 602;
		uvRect_texto.top = 1862;
		uvRect_icono.top = 1080;
		break;
	case(6):
		uvRect_nombre.top = 1264;
		uvRect_texto.left = 8;
		uvRect_texto.top = 1954;
		uvRect_icono.top = 1288;
		break;
	}

	uvRect_icono.width = 108;
	uvRect_icono.height = 82;
	uvRect_icono.left = 10;

	uvRect_nombre.width = 133;
	uvRect_nombre.height = 18;
	uvRect_nombre.left = 8;

	uvRect_texto.width = 289;
	uvRect_texto.height = 84;

	icono.setTextureRect(uvRect_icono);
	icono.setTexture(bios);

	nombre.setTextureRect(uvRect_nombre);
	nombre.setTexture(bios);

	texto.setTextureRect(uvRect_texto);
	texto.setTexture(bios);

}

bool StartManager::draw(RenderWindow& window, float segundos) {

	fondo_bios.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	fondo_menus.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));

	icono.setSize(Vector2f(float(window.getSize().x / 3.7), float(window.getSize().y / 3.1)));
	texto.setSize(Vector2f(float(window.getSize().x / 1.4), float(window.getSize().y / 2.8)));
	nombre.setSize(Vector2f(float(window.getSize().x / 2.8), float(window.getSize().y / 10)));

	if (segundos > 25.0f) {		//Pantalla goro con texto
		uvRect_fondo.left = 3586;
		fondo_menus.setTextureRect(uvRect_fondo);
		window.draw(fondo_menus);
	}
	else if (segundos > 22.0f) { //Pantalla goro sin texto
		uvRect_fondo.left = 3162;
		fondo_menus.setTextureRect(uvRect_fondo);
		window.draw(fondo_menus);
	}
	else if (segundos > 20.0f) { //Pantalla goro lives
		fondo_menus.setFillColor(Color::White);
		uvRect_fondo.left = 2738;
		uvRect_fondo.top = 1551;
		fondo_menus.setTextureRect(uvRect_fondo);
		window.draw(fondo_menus);
	}
	else if (segundos > 19.0) { //Fondo negro
		fondo_menus.setFillColor(Color::Black);
		window.draw(fondo_menus);
	}
	else if (segundos > 8.0f) {	//Se empieza a mostrar la biografia del personaje
		
		if (segundos - seconds_aux > 0.1f) {
			seconds_aux = segundos;
			actualizarFrame();
		}

		nombre.setOrigin(nombre.getSize().x / 2, nombre.getSize().y / 2);
		nombre.setPosition(Vector2f(float(window.getSize().x / 2), float(window.getSize().y / 7)));

		icono.setOrigin(nombre.getSize().x / 2, nombre.getSize().y / 2);
		icono.setPosition(Vector2f(float(window.getSize().x / 1.8), float(window.getSize().y / 3.3)));

		texto.setOrigin(nombre.getSize().x / 2, nombre.getSize().y / 2);
		texto.setPosition(Vector2f(float(window.getSize().x / 3), float(window.getSize().y / 1.5)));

		uvRect_fondo.left = 12;
		uvRect_fondo.top = 1504;

		fondo_bios.setTextureRect(uvRect_fondo);
		icono.setTextureRect(uvRect_icono);
		window.draw(fondo_bios);
		window.draw(nombre);
		window.draw(icono);
		window.draw(texto);

	}
	else if (segundos > 2.0f) { //Pantalla inicial roja
		uvRect_fondo.left = 2320;
		fondo_menus.setTextureRect(uvRect_fondo);
		window.draw(fondo_menus);
	}
	else {
		window.draw(fondo_menus);
	}

	if (segundos > 40.0f) {
		return true;
	}
	return false;

}

void StartManager::actualizarFrame() {
	if (actual_frame < NUM_FRAMES[personaje]) {
		actual_frame++;

		if (actual_frame == ENDIND_LINE_FRAME[personaje] + 1) {
			uvRect_icono.top += 82 + 4;
			uvRect_icono.left = 10;
		}
		else {
			uvRect_icono.left += 108 + 4;
		}
	
	}

}

