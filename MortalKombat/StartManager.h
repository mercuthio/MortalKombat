#ifndef StartManager_H
#define StartManager_H

#include "SFML/Graphics.hpp"
#include "GlobalVars.h"

using namespace sf;

const int NUM_BIOS = 7;
const int NUM_FRAMES[NUM_BIOS] = { 17,21,20,18,19,16,12 };
const int ENDIND_LINE_FRAME[NUM_BIOS] = { 8,10,10,9,9,8,6 };

class StartManager {

public:
	StartManager(Texture*, Texture*);
	~StartManager() = default;

	bool draw(RenderWindow&, float);	//Devuelve true si ha terminado de mostrar todo
	void updateFrame();

private:

	int actual_frame = 0;
	int character = 0;
	float seconds_aux = 0.0;

	IntRect uvRect_backg = IntRect();
	IntRect uvRect_icon = IntRect();
	IntRect uvRect_name = IntRect();
	IntRect uvRect_text = IntRect();
	RectangleShape icon = RectangleShape();
	RectangleShape bio_backg = RectangleShape();
	RectangleShape menu_backg = RectangleShape();
	RectangleShape name = RectangleShape();
	RectangleShape text = RectangleShape();

};

#endif