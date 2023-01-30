#ifndef SFML_PONG_PANG_H
#define SFML_PONG_PANG_H

#include <SFML/Graphics.hpp>
#include "states/game_state.h"
#include "states/splashscreen_state.h"
#include "states/menu_state.h"
#include "states/playing_state.h"

class Pang {
public:
    const static int SCREEN_WIDTH = 500;
    const static int SCREEN_HEIGHT = 400;

    enum State {Uninitialized, Splashscreen, Menu, Playing, Exiting};

    static void start();
    static void gameLoop();
    static void setState(State s);

private:
    static State _state;

    static std::map<State, GameState*> _stateInstances;
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};


#endif //SFML_PONG_PANG_H
