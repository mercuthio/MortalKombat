#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "EventManager.h"

using namespace sf;
using namespace std;

const int NUMBER_TRACKS = 191;

const float ASPECT_RATIO = 4.0 / 3.0;

Color pink = Color(245, 10, 237, 255);

View getLetterboxView(View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float)windowHeight;
    float viewRatio = view.getSize().x / (float)view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

    return view;
}

int main() {

    int width_window = 800;
    int height_window = 600;

    RenderWindow window(VideoMode(width_window, height_window), "Mortal Kombat I", (sf::Style::Resize + sf::Style::Close));

    Image icon;
    icon.loadFromFile("resources/Imagenes/Menus/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    View view;
    view.setSize(width_window, height_window);
    view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
    view = getLetterboxView(view, width_window, height_window);

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

            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyReleased)
                EventManager.Update(event);
            if (event.type == sf::Event::Resized)
                view = getLetterboxView(view, event.size.width, event.size.height);

        }

        window.clear();

        window.setView(view);
        EventManager.draw(window);

        window.display();
    }

    return 0;

		

}
