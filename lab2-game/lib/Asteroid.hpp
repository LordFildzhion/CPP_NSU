#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <utility>

namespace AsteroidValues {
    const size_t MAX_RADIUS = 20;
    const size_t MIN_RADIUS = 10;
    const size_t MAX_ANGLE_COUNT = 10;
    const size_t MIN_ANGLE_COUNT = 6;
}

#include <SFML/Graphics.hpp>

class Asteroid {
 public:
    Asteroid(float x, float y);

    explicit Asteroid(const sf::Vector2f &position);

    void move(float dy);

    sf::CircleShape& getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void setRadius(float radius);

    float getRadius();

    void setRandomRadius();

    void setType(int8_t type);

    void setRandomAsteroid(size_t typesCount);

    int8_t getType();

    void setRandomType(size_t typesCount);

    void setTexture(const sf::Texture &texture);

 private:
    sf::CircleShape shape;
    size_t type;
};

Asteroid::Asteroid(float x, float y) : shape(AsteroidValues::MAX_RADIUS, rand() % (AsteroidValues::MAX_ANGLE_COUNT - AsteroidValues::MIN_ANGLE_COUNT + 1) + AsteroidValues::MIN_ANGLE_COUNT) {
    shape.setPosition({x, y});
    type = 1;
}

Asteroid::Asteroid(const sf::Vector2f &position) : shape(AsteroidValues::MAX_RADIUS, rand() % (AsteroidValues::MAX_ANGLE_COUNT - AsteroidValues::MIN_ANGLE_COUNT + 1) + AsteroidValues::MIN_ANGLE_COUNT) {
    shape.setPosition(position);
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

void Asteroid::setPosition(const sf::Vector2f &position) {
    shape.setPosition(position);
}

void Asteroid::setRadius(float radius) {
    shape.setRadius(radius);
}

float Asteroid::getRadius() {
    return shape.getRadius();
}

void Asteroid::setRandomRadius() {
    shape.setRadius(rand() % AsteroidValues::MAX_RADIUS + AsteroidValues::MIN_RADIUS);
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

void Asteroid::setTexture(const sf::Texture &texture) {
    shape.setTexture(&texture);
}


#endif  // ASTEROID_HPP
