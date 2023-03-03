#ifndef SFML_PONG_VISIBLE_OBJECT_H
#define SFML_PONG_VISIBLE_OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>


class visible_object {
public:
    visible_object(std::string textureFilename);
    virtual ~visible_object();
    virtual void  handleInput(sf::Event *event) {};
    virtual void update(float timeElapsed) = 0;
    virtual void draw(sf::RenderWindow *window);
    virtual void collideWith(visible_object *target) {};
    virtual void move(float x, float y);
    virtual void setPosition(float x, float y);
    virtual sf::Vector2<float> getPosition();
    virtual float getTop();
    virtual float getBottom();
    virtual float getLeft();
    virtual float getRight();
    virtual sf::Rect<float> getBoundingRect();

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _isLoaded;

};


#endif //SFML_PONG_VISIBLE_OBJECT_H
