#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "EventManager.h"

using namespace sf;
using namespace std;

View getLetterboxView(View view, int windowWidth, int windowHeight) {

    float windowRatio = windowWidth / (float)windowHeight;
    float viewRatio = view.getSize().x / (float)view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

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
    Color pink = Color(245, 10, 237, 255);
    Color blue = Color(165, 231, 255);
    a.loadFromFile("resources/Sprites/Varios/Menus.png");
    a.createMaskFromColor(pink);
    a.createMaskFromColor(blue);
    b.loadFromFile("resources/Sprites/Varios/Bios.png");
    b.createMaskFromColor(pink);

    Texture textures[10];
    textures[0].loadFromImage(a);
    textures[1].loadFromImage(b);

    Text version;
    version.setFont(font);
    version.setFillColor(Color::White);
    version.setString("Beta v0.1");
    version.setCharacterSize(25);
    version.setPosition(Vector2f(30.0, height_window - 45.0));

    EventManager EventManager(textures, font, clock);

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
        window.draw(version);

        window.display();
    }

    return 0;

		

}
