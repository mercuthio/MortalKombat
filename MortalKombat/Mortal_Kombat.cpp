#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "EventManager.h"
#include "Character.h"
#include "Goro.h"
#include "LiuKang.h"
#include "Animation.h"
#include <chrono>
#include <thread>

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
    Event event;
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(60);
    
    //Character goro = CreateGoro();
    Character liu = CreateLiuKang();

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyReleased) {
                //EventManager.Actualizar(event);
            }

        }
        //goro.Update(0.05f);
        liu.Update(0.05f);
        window.clear();
        //goro.debugDraw(window);
        liu.debugDraw(window);
        window.display();
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
