#include "SFML/Graphics.hpp"
#include <iostream>
#include "Flujo.h"

using namespace sf;
using namespace std;

int ANCHO_PANTALLA = 800;
int ALTO_PANTALLA = 600;

int RATIO_ANCHO = 4;
int RATIO_ALTO = 3;


int main() {

    RenderWindow window(VideoMode(ANCHO_PANTALLA, ALTO_PANTALLA), "Mortal Kombat 1");

    Clock reloj;
    Event event;
    
    Font fuente;
    fuente.loadFromFile("Recursos/Fuente/mortalKombat1.ttf");

    Texture texturas[10];
    texturas[0].loadFromFile("Recursos/Imagenes/Menus/Inicio.png");
    texturas[1].loadFromFile("Recursos/Imagenes/Menus/Menu.png");

    Flujo flujo(texturas, fuente);

    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyReleased) {
                flujo.Actualizar(event);
            }

        }

        window.clear();
        flujo.draw(window);
        window.display();
    }

    return 0;

		

}
