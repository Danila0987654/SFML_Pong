#ifndef SFML_PONG_MENU_STATE_H
#define SFML_PONG_MENU_STATE_H

#include <iostream>

#include "game_state.h"
#include "../pang.h"

class MenuState : public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;

private:
    sf::Texture _playTexture;
    sf::Sprite _playSprite;
    sf::Texture _exitTexture;
    sf::Sprite _exitSprite;
};

#endif //SFML_PONG_MENU_STATE_H
