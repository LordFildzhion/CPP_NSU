#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(float x, float y);

    void move(float dy);

    sf::CircleShape getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setRadius(float radius);

    float getRadius();

    void setRandomRadius();

    void setType(size_t type);

    void setRandomAsteroid();

    size_t getType();

    void setRandomType();

    void setTexture(sf::Texture &texture);

private:
    sf::CircleShape shape;
    size_t type;
    sf::Texture texture;
};

Asteroid::Asteroid(float x, float y) : shape(20.0f) {
    shape.setPosition({x, y});
    type = 1;
}

void Asteroid::move(float dy) {
    shape.move({0, dy});
}

sf::CircleShape Asteroid::getShape() {
    return shape;
}

const sf::CircleShape& Asteroid::getShape() const {
    return shape;
}

sf::Vector2f Asteroid::getPosition() {
    return shape.getPosition();
}

void Asteroid::setPosition(float x, float y) {
    shape.setPosition({x, y});
}

void Asteroid::setRadius(float radius) {
    shape.setRadius(radius);
}

float Asteroid::getRadius() {
    return shape.getRadius();
}

void Asteroid::setRandomRadius() {
    shape.setRadius(rand() % 20 + 10);
}

void Asteroid::setType(size_t type) {
    this->type = type;
}

void Asteroid::setRandomAsteroid() {
    setRandomRadius();
    setRandomType();
}

size_t Asteroid::getType() {
    return type;
}

void Asteroid::setRandomType() {
    type = rand() % 3 + 1;
}

void Asteroid::setTexture(sf::Texture &texture) {
    this->texture = texture;
    shape.setTexture(&texture);
}

#endif // ASTEROID_HPP
