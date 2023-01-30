#ifndef SFML_PONG_GAME_STATE_H
#define SFML_PONG_GAME_STATE_H

#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual ~GameState();
    virtual void init() = 0;
    virtual void handleInput(sf::Event *event) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //SFML_PONG_GAME_STATE_H
