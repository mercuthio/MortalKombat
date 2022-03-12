#ifndef StartManager_H
#define StartManager_H

#include "SFML/Graphics.hpp"

using namespace sf;

const int NUM_BIOS = 7;
const int NUM_FRAMES[NUM_BIOS] = { 17,21,20,18,19,16,12 };
const int ENDIND_LINE_FRAME[NUM_BIOS] = { 8,10,10,9,9,8,6 };

class StartManager {

public:
	StartManager(Texture*, Texture*);
	~StartManager() = default;

	bool draw(RenderWindow&, float);	//Devuelve true si ha terminado de mostrar todo
	void actualizarFrame();

private:

	int actual_frame;
	int personaje;
	float seconds_aux;

	IntRect uvRect_fondo;
	IntRect uvRect_icono;
	IntRect uvRect_nombre;
	IntRect uvRect_texto;
	RectangleShape icono;
	RectangleShape fondo_bios;
	RectangleShape fondo_menus;
	RectangleShape nombre;
	RectangleShape texto;

};

#endif