
#include "Selector.h"

Selector::Selector(Texture* fondo_, Texture* marco_) {

	x = 0;
	y = 0;
	parpadeo = false;

	fondo.setTexture(fondo_);
	marco.setTexture(marco_);
	marco.setSize(Vector2f(100, 100));
}

void Selector::Actualizar() {

	//parpadeo = !parpadeo;

}

void Selector::MoverCursor(int x_, int y_) {

	if (PERSONAJES[y + y_][x + x_]) {
		x += x_;
		y += y_;
	}

}

int Selector::OpcionElegida() {

	return x + (MAXIMO_X * y);

}

void Selector::Draw(RenderWindow& window) {

	fondo.setSize(Vector2f(float(window.getSize().x), float(window.getSize().y)));
	window.draw(fondo);

	marco.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	window.draw(marco);


}
