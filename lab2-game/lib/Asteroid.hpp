#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <SFML/Graphics.hpp>

class Asteroid {
public:
    Asteroid(float x, float y) : shape(20.0f) {
        shape.setPosition({x, y});
        speed = 2.0f;
        type = 1;
    }

    void move(float dy) {
        shape.move({0, dy});
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

    void setSpeed(float speed) {
        this->speed = speed;
    }

    float getSpeed() {
        return speed;
    }

    void setRadius(float radius) {
        shape.setRadius(radius);
    }

    float getRadius() {
        return shape.getRadius();
    }

    void setRandomSpeed() {
        speed = rand() % 5 + 1;
    }

    void setRandomRadius() {
        shape.setRadius(rand() % 20 + 10);
    }

    void setType(size_t type) {
        this->type = type;
    }

    size_t getType() {
        return type;
    }

    void setRandomType() {
        type = rand() % 3 + 1;
    }

    void setTexture(sf::Texture &texture) {
        this->texture = texture;
        shape.setTexture(&texture);
    }

private:
    sf::CircleShape shape;
    float speed;
    size_t type;
    sf::Texture texture;
};

#endif // ASTEROID_HPP