#ifndef SFML_PONG_SPLASHSCREEN_STATE_H
#define SFML_PONG_SPLASHSCREEN_STATE_H

#include "game_state.h"

class SplashscreenState : public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow * window) override;
};

#endif //SFML_PONG_SPLASHSCREEN_STATE_H
