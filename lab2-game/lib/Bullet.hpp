#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(sf::Texture &texture, float x, float y) : shape(10.0f, 5) {
        scatter = (rand() % 5) - (rand() % 5);

        shape.setPosition({x + scatter, y});
        shape.setTexture(&texture);
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

    void setTexture(sf::Texture &texture) {
        shape.setTexture(&texture);
    }

    void setScatter(size_t scatter) {
        this->scatter = scatter;
        shape.setPosition({shape.getPosition().x + scatter, shape.getPosition().y});
    }

    size_t getScatter() {
        return scatter;
    }

private:
    sf::CircleShape shape;
    int8_t scatter;
};

#endif // BULLET_HPP