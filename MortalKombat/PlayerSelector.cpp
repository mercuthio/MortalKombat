
#include "PlayerSelector.h"

PlayerSelector::PlayerSelector(Texture* fondo_) {

	x = 0;
	y = 0;
	parpadeo = false;

	fondo.setTexture(fondo_);
	marco.setSize(Vector2f(100, 100));
}

void PlayerSelector::Actualizar() {

	//parpadeo = !parpadeo;

}

void PlayerSelector::MoverCursor(int x_, int y_) {

	if (PERSONAJES[y + y_][x + x_]) {
		x += x_;
		y += y_;
	}

}

int PlayerSelector::OpcionElegida() {

	return x + (MAXIMO_X * y);

}

void PlayerSelector::Draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);


}
