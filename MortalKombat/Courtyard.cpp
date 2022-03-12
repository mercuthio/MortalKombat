#include "Courtyard.h"

void Courtyard::loadTextures() {

	sizeVector = 8;

	float rectWidth = 1037.0f;
	float rectHeight = 281.0f;

	Vector2f sizeBackground = Vector2f(rectWidth, rectHeight);

	RectangleShape aux;
	IntRect auxShape;

	aux.setFillColor(Color::Cyan);
	aux.setSize(sizeBackground);
	auxShape.height = rectHeight;
	auxShape.width = rectWidth;

	backgroundVector[0] = aux;

}