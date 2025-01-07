#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

class Ship {
public:
    Ship(float x = 400, float y = 500) : shape(50.0f, 8) {
        shape.setPosition({x, y});
        type = 1;
    }

    void move(float dx) {
        shape.move({dx, 0});
    }

    sf::CircleShape getShape() {
        return shape;
    }

    const sf::CircleShape& getShape() const {
        return shape;
    }

    sf::Vector2f getPosition() {
        return shape.getPosition();
    }

    void setPosition(float x, float y) {
        shape.setPosition({x, y});
    }

    void setTexture(sf::Texture &texture) {
        shape.setTexture(&texture);
    }

    void setType(size_t type) {
        this->type = type;
    }

    size_t getType() {
        return type;
    }

    void setRandomType() {
        type = rand() % 2 + 1;
    }

private:
    sf::CircleShape shape;
    size_t type;
    sf::Texture texture;
};

#endif // SHIP_HPP
