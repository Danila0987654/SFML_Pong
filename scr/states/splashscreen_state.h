#ifndef SFML_PONG_SPLASHSCREEN_STATE_H
#define SFML_PONG_SPLASHSCREEN_STATE_H

#include <iostream>

#include "game_state.h"

#include "../pang.h"

class SplashscreenState : public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow * window) override;

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif //SFML_PONG_SPLASHSCREEN_STATE_H
