#ifndef ASTEROID_HPP
#define ASTEROID_HPP

namespace AsteroidValues {
    size_t ASTEROID_MAX_RADIUS = 20;
    size_t ASTEROID_MIN_RADIUS = 10;    

}

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(float x, float y);

    void move(float dy);

    sf::CircleShape& getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setRadius(float radius);

    float getRadius();

    void setRandomRadius();

    void setType(int8_t type);

    void setRandomAsteroid(size_t typesCount);

    int8_t getType();

    void setRandomType(size_t typesCount);

    void setTexture(sf::Texture &texture);

private:
    sf::CircleShape shape;
    size_t type;
};

Asteroid::Asteroid(float x, float y) : shape(AsteroidValues::ASTEROID_MAX_RADIUS, 8) {
    shape.setPosition({x, y});
    type = 1;
}

void Asteroid::move(float dy) {
    shape.move({0, dy});
}

sf::CircleShape& Asteroid::getShape() {
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
    shape.setRadius(rand() % AsteroidValues::ASTEROID_MAX_RADIUS + AsteroidValues::ASTEROID_MIN_RADIUS);
}

void Asteroid::setType(int8_t type) {
    this->type = type;
}

void Asteroid::setRandomAsteroid(size_t typesCount) {
    setRandomRadius();
    setRandomType(typesCount);
}

int8_t Asteroid::getType() {
    return type;
}

void Asteroid::setRandomType(size_t typesCount) {
    type = rand() % typesCount + 1;
}

void Asteroid::setTexture(sf::Texture &texture) {
    shape.setTexture(&texture);
}

#endif // ASTEROID_HPP
