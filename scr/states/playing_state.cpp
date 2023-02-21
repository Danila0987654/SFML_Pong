#include "playing_state.h"

void PlayingState::init() {
    if (!_player1Texture.loadFromFile("../assets/paddle.png")) {
        std::cout << "Error while loading assets" << "\n";
        return;
    }
    _player1Sprite.setTexture(_player1Texture);
    _player1Sprite.setScale(0.5, 0.5);
    _player1Sprite.setPosition(100, 100);
}
void PlayingState::handleInput(sf::Event *event) {
}
void PlayingState::update(float timeElapsed) {}
void PlayingState::draw(sf::RenderWindow *window) {
    window->draw(_player1Sprite);
}
