#include "playing_state.h"

void PlayingState::init() {
    if (!_fieldTexture.loadFromFile("../assets/field.png")) {
        std::cout << "Error while loading assets" << "\n";
        return;
    }
    _fieldSprite.setTexture(_fieldTexture);
    _fieldSprite.setScale(0.35, 0.4);
    _fieldSprite.setPosition(80, 40);


    if (!_player1Texture.loadFromFile("../assets/paddle.png")) {
        std::cout << "Error while loading assets" << "\n";
        return;
    }
    _player1Sprite.setTexture(_player1Texture);
    _player1Sprite.setScale(0.5, 0.5);
    _player1Sprite.setPosition(100, 100);
}
void PlayingState::handleInput(sf::Event *event) {
    if (event->type == sf::Event::KeyReleased) {
        _playerDirection = DIRECTION_NONE;
    } else if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Up) {
            _playerDirection = DIRECTION_UP;
        } else if (event->key.code == sf::Keyboard::Down) {
            _playerDirection = DIRECTION_DOWN;
        }
    }
}
void PlayingState::update(float timeElapsed) {
    float velocity = 0.0f;
    if (_playerDirection == DIRECTION_UP) {
        velocity = _playerSpeed * -1;
    } else if (_playerDirection == DIRECTION_DOWN) {
        velocity = _playerSpeed;
    }
    _player1Sprite.move(0, velocity * timeElapsed);

    sf::Rect<float> fieldBound = _fieldSprite.getGlobalBounds();
    sf::Vector2<float> player1Position = _player1Sprite.getPosition();

    if (player1Position.y < fieldBound.top + 10) {
        _player1Sprite.setPosition(player1Position.x, fieldBound.top + 10);
    } else if (player1Position.y + _player1Sprite.getTexture()->getSize().y > fieldBound.top + fieldBound.height + 90) {
        _player1Sprite.setPosition(player1Position.x, fieldBound.top + fieldBound.height -
        _player1Sprite.getTexture()->getSize().y + 90);
    }
}
void PlayingState::draw(sf::RenderWindow *window) {
    window->draw(_fieldSprite);
    window->draw(_player1Sprite);
}
