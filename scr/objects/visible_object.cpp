#include "visible_object.h"

visible_object::visible_object(std::string textureFilename) {
    if (!_texture.loadFromFile(textureFilename)) {
        std::cout << "Error while loading assets" << "\n";
        return;
    }
    _isLoaded = true;
    _sprite.setTexture(_texture);
}

visible_object::~visible_object() {}

void visible_object::draw(sf::RenderWindow *window) {
    if (!_isLoaded) return;
    window->draw(_sprite);
}

void visible_object::move(float x, float y) {
    if (!_isLoaded) return;
    _sprite.move(x, y);
}

void visible_object::setPosition(float x, float y) {
    if (!_isLoaded) return;
    _sprite.setPosition(x, y);
}

sf::Vector2<float> visible_object::getPosition() {
    return _sprite.getPosition();
}

float visible_object::getTop() {
    sf::Rect<float> boundingRect = getBoundingRect();
    return boundingRect.top;
}

float visible_object::getBottom() {
    sf::Rect<float> boundingRect = getBoundingRect();
    return boundingRect.left;
}

float visible_object::getLeft() {
    sf::Rect<float> boundingRect = getBoundingRect();
    return boundingRect.left;
}

float visible_object::getRight() {
    sf::Rect<float> boundingRect = getBoundingRect();
    return boundingRect.left + boundingRect.width;
}