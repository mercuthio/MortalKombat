#include "The_Pit.h"

void The_Pit::loadTextures() {
	sizeVector = 2;
	texture->loadFromFile("resources/Sprites/Escenarios/The_Pit.png");

	float rectWidth = 1146.0f;
	float rectHeight = 272.0f;

	float aspectRelation = (height_window + 20) / rectHeight;

	float offset_left = (rectWidth * aspectRelation - width_window) / 2;
	float offset_top = 0;

	playerInitPos1 = Vector2f(offset_left + 30, aspectRelation * height_window / 2);

	Vector2f sizeBackground = Vector2f(rectWidth * aspectRelation, height_window + 20);

	IntRect uvRect;
	RectangleShape tile;
	uvRect.width = rectWidth;
	uvRect.height = rectHeight;

	tile.setTexture(texture);
	tile.setSize(sizeBackground);
	tile.setPosition(-offset_left, -offset_top);
	tile.setScale(1.0f, 1.0f);

	//Fondo con luna 0
	uvRect.left = 8.0f;
	uvRect.top = 152.0f;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Fondo pasarela 4
	rectWidth = 1147.0f;
	rectHeight = 1000.0f;

	sizeBackground = Vector2f(rectWidth * aspectRelation, rectHeight*aspectRelation);

	uvRect.left = 8.0f;
	uvRect.top = 432.0f;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);



}