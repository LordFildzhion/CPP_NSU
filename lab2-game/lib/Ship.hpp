#ifndef SHIP_HPP
#define SHIP_HPP

#include <utility>

#include <SFML/Graphics.hpp>

namespace ShipValues {
    const float DEFAULT_SHIP_RADIUS = 50.0f;
    const size_t DEFAULT_SHIP_ANGLEs = 8;
}

class Ship {
 public:
    explicit Ship(float x = 400, float y = 500, size_t type = 1);

    void move(float dx);

    sf::CircleShape getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setTexture(sf::Texture &texture);

    void setType(size_t type);

    size_t getType();

    void setRandomType(size_t typeCount);

 private:
    sf::CircleShape shape;
    size_t type;
};

Ship::Ship(float x, float y, size_t type) : shape(50.0f, 8) {
    shape.setPosition({x, y});
    this->type = type;
}

void Ship::move(float dx) {
    shape.move({dx, 0});
}

sf::CircleShape Ship::getShape() {
    return shape;
}

const sf::CircleShape& Ship::getShape() const {
    return shape;
}

sf::Vector2f Ship::getPosition() {
    return shape.getPosition();
}

void Ship::setPosition(float x, float y) {
    shape.setPosition({x, y});
}

void Ship::setTexture(sf::Texture &texture) {
    shape.setTexture(&texture);
}

void Ship::setType(size_t type) {
    this->type = type;
}

size_t Ship::getType() {
    return type;
}

void Ship::setRandomType(size_t typeCount) {
    type = rand() % typeCount + 1;
}

#endif  // SHIP_HPP
