
#include "TransitionManager.h"

TransitionManager::TransitionManager() {

	for (int i = 0; i < NUM_SQUARES; i++) {
		backg[i].setFillColor(Color::Black);
	}

}

void TransitionManager::draw(RenderWindow& window) {

	for (int i = 0; i < NUM_SQUARES; i++) {
		backg[i].setSize(Vector2f(window.getSize().x, window.getSize().y / NUM_SQUARES));
		backg[i].setScale(1.01f, 1.01f);
		backg[i].setPosition(0, i * backg[i].getSize().y);
	}

	float resta = 2;

	while (backg[NUM_SQUARES - 1].getSize().y > resta) {

		for (int e = 0; e < NUM_SQUARES; e++) {

			backg[e].setSize(Vector2f(backg[e].getSize().x, backg[e].getSize().y - resta));
			window.draw(backg[e]);

		}

		window.display();

	}

}
