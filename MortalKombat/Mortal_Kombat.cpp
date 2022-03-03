#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "EventManager.h"

using namespace sf;
using namespace std;

const int NUMBER_TRACKS = 191;

int ANCHO_PANTALLA = 800;
int ALTO_PANTALLA = 600;

int RATIO_ANCHO = 4;
int RATIO_ALTO = 3;

Color pink = Color(245, 10, 237, 255);

int main() {

    RenderWindow window(VideoMode(ANCHO_PANTALLA, ALTO_PANTALLA), "Mortal Kombat I");

    Clock clock;
    Event event;
    
    Font fuente;
    fuente.loadFromFile("resources/Fuente/mortalKombat1.ttf");

    Image a;
    a.loadFromFile("resources/Sprites/Varios/Menus.png");
    a.createMaskFromColor(pink);

    Texture texturas[10];
    texturas[0].loadFromImage(a);

    EventManager EventManager(texturas, fuente);
    EventManager.setClock(clock);

    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyReleased) {
                EventManager.Actualizar(event);
            }

        }

        window.clear();
        EventManager.draw(window);
        window.display();
    }

    return 0;

		

}
