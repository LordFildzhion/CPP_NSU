#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

class Ship {
public:
    Ship(float x = 400, float y = 500, size_t type = 1);

    void move(float dx);

    sf::CircleShape getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setTexture(sf::Texture &texture);

    void setType(size_t type);

    size_t getType();

    void setRandomType();

private:
    sf::CircleShape shape;
    size_t type;
    sf::Texture texture;
};

Ship::Ship(float x, float y, size_t type) : shape(50.0f, 8) {
    shape.setPosition({x, y});
    type = 1;
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

void Ship::setRandomType() {
    type = rand() % 2 + 1;
}

#endif // SHIP_HPP
