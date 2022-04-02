#include "Warrior_Shrine.h"

void Warrior_Shrine::loadTextures() {
	sizeVector = 4;
	texture->loadFromFile("resources/Sprites/Escenarios/Warrior_Shrine.png");

	float rectWidth = 1281.0f;
	float rectHeight = 347.0f;

	float aspectRelation = (height_window+100)/rectHeight;

	float offset_left = (rectWidth * aspectRelation - width_window) / 2;
	float offset_top = 55;

	Vector2f sizeBackground = Vector2f(rectWidth * aspectRelation, height_window+100);

	initPlayer1 = Vector2<float>(-50, 200);
	initPlayer2 = Vector2<float>(550, 200);

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
	uvRect.top = 8.0f;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas montañas 1
	uvRect.top = 8.0 + (rectHeight+8.0)*1;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas arboles 2
	uvRect.top = 8.0 + (rectHeight + 8.0) * 2;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Esculturas 3
	uvRect.top = 8.0 + (rectHeight + 8.0) * 3;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);
}