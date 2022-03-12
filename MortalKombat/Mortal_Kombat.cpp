#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "EventManager.h"

using namespace sf;
using namespace std;

const int NUMBER_TRACKS = 191;

int WIDTH_WINDOW = 800;
int HEIGHT_WINDOW = 600;

int RATIO_WIDTH = 4;
int RATIO_HEIGHT = 3;

Color pink = Color(245, 10, 237, 255);

int main() {

    RenderWindow window(VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Mortal Kombat I");

    Clock clock;
    Event event;
    
    Font font;
    font.loadFromFile("resources/Fuente/mortalKombat1.ttf");

    Image a, b;
    a.loadFromFile("resources/Sprites/Varios/Menus.png");
    a.createMaskFromColor(pink);
    b.loadFromFile("resources/Sprites/Varios/Bios.png");
    b.createMaskFromColor(pink);

    Texture textures[10];
    textures[0].loadFromImage(a);
    textures[1].loadFromImage(b);

    EventManager EventManager(textures, font);
    EventManager.setClock(clock);

    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyReleased) {
                EventManager.Update(event);
            }

        }

        window.clear();
        EventManager.draw(window);
        window.display();
    }

    return 0;

		

}
