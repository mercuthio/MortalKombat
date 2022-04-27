#include "Throne_Room.h"

void Throne_Room::loadTextures() {
	sizeVector = 4;
	texture->loadFromFile("resources/Sprites/Escenarios/Throne_Room.png");

	float rectWidth = 1384.0f;
	float rectHeight = 280.0f;

	float aspectRelation = (height_window + 20) / rectHeight;

	float offset_left = (rectWidth * aspectRelation - width_window) / 2;
	float offset_top = 0;

	Vector2f sizeBackground = Vector2f(rectWidth * aspectRelation, height_window + 20);

	initPlayer1 = Vector2<float>(-50, 200);
	initPlayer2 = Vector2<float>(400, 200);

	screenLeftLimit = -180;
	screenRightLimit = 580;
	screenFloorLimit = 200;

	screenLeftHardLimit = -1500;
	screenRightHardLimit = 1500;

	IntRect uvRect;
	RectangleShape tile;
	uvRect.width = rectWidth;
	uvRect.height = rectHeight;

	tile.setTexture(texture);
	tile.setSize(sizeBackground);
	tile.setPosition(-offset_left, -offset_top);
	tile.setScale(1.0f, 1.0f);

	//Fondo con montañas 0
	uvRect.left = 8.0f;
	uvRect.top = 8.0f;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas fondo 1
	uvRect.top = 8.0 + (rectHeight + 8.0) * 1;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas trono 2
	uvRect.top = 8.0 + (rectHeight + 8.0) * 2;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Columnas 3
	uvRect.top = 8.0 + (rectHeight + 8.0) * 3;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Alfombra 3
	uvRect.top = 8.0 + (rectHeight + 8.0) * 4;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Suelo final 4
	uvRect.top = 8.0 + (rectHeight + 8.0) * 4;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);
}