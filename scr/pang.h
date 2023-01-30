#ifndef SFML_PONG_PANG_H
#define SFML_PONG_PANG_H

#include <SFML/Graphics.hpp>

class Pang {
public:
    const static int SCREEN_WIDTH = 500;
    const static int SCREEN_HEIGHT = 400;
    static void start();
    static void gameLoop();

private:
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SFML_PONG_PANG_H
