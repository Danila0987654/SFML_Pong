#ifndef SFML_PONG_PLAYING_STATE_H
#define SFML_PONG_PLAYING_STATE_H
#include <iostream>

#include "game_state.h"

class PlayingState : public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
private:
    sf::Texture _player1Texture;
    sf::Sprite _player1Sprite;
    float _playerSpeed = 80.0f;
    enum Direction {DIRECTION_NONE, DIRECTION_UP, DIRECTION_DOWN};
    Direction _playerDirection = DIRECTION_NONE;
};

#endif //SFML_PONG_PLAYING_STATE_H
