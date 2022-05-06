#include "Goros_Lair.h"

void Goros_Lair::loadTextures() {
	sizeVector = 9;
	texture->loadFromFile("resources/Sprites/Escenarios/Goros_Lair.png");

	float rectWidth = 1173.0f;
	float rectHeight = 297.0f;

	float aspectRelation = (height_window + 100) / rectHeight;

	float offset_left = (rectWidth * aspectRelation - width_window) / 2;
	float offset_top = 55;

	Vector2f sizeBackground = Vector2f(rectWidth * aspectRelation, height_window + 100);

	initPlayer1 = Vector2<float>(-50, 200);
	initPlayer2 = Vector2<float>(400, 200);

	screenLeftLimit = -180;
	screenRightLimit = 580;
	screenFloorLimit = 200;

	screenLeftHardLimit = -800;
	screenRightHardLimit = 800;

	IntRect uvRect;
	RectangleShape tile;
	uvRect.width = rectWidth;
	uvRect.height = rectHeight;

	tile.setTexture(texture);
	tile.setSize(sizeBackground);
	tile.setPosition(-offset_left, -offset_top);
	tile.setScale(1.0f, 1.0f);

	//Fondo con ojos 0
	uvRect.left = 9.0f;
	uvRect.top = 9.0f;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas 1
	uvRect.top = 8.0 + (rectHeight + 8.0) * 1;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas 2
	uvRect.top = 8.0 + (rectHeight + 8.0) * 2;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas 3
	uvRect.top = 8.0 + (rectHeight + 8.0) * 3;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas columnas 4
	uvRect.top = 8.0 + (rectHeight + 8.0) * 4;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas 5
	uvRect.top = 8.0 + (rectHeight + 8.0) * 5;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas calavera 6
	uvRect.top = 8.0 + (rectHeight + 8.0) * 6;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas delante 7
	uvRect.top = 8.0 + (rectHeight + 8.0) * 7;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

	//Piezas delante 8
	uvRect.top = 8.0 + (rectHeight + 8.0) * 8;
	tile.setTextureRect(uvRect);
	backgroundVector.push_back(tile);

}