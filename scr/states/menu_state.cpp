#include "menu_state.h"

void MenuState::init() {
    if (!_playTexture.loadFromFile("../assets/play-btn.png") ||
    !_exitTexture.loadFromFile("../assets/exit-btn.png")) {
        std::cout << "Error while loading assets" << "\n";
        return;
    }

    _playSprite.setTexture(_playTexture);
    _exitSprite.setTexture(_exitTexture);
    _playSprite.setPosition(260,150);
    _exitSprite.setPosition(260,200);
}
void MenuState::handleInput(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        int x = event->mouseButton.x;
        int y = event->mouseButton.y;
        if (_playSprite.getGlobalBounds().contains(x, y)) {
            Pang::setState(Pang::Playing);
        } else if (_exitSprite.getGlobalBounds().contains(x, y)) {
            Pang::setState(Pang::Exiting);
        }
    }
}
void MenuState::update(float timeElapsed) {}
void MenuState::draw(sf::RenderWindow *window) {
    window->draw(_playSprite);
    window->draw(_exitSprite);
}