#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(sf::Texture &texture, float x, float y);

    void move(float dy);

    sf::CircleShape getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    void setTexture(sf::Texture &texture);

    void setScatter(size_t scatter);

    size_t getScatter();

private:
    sf::CircleShape shape;
    int8_t scatter;
};

Bullet::Bullet(sf::Texture &texture, float x, float y) : shape(10.0f, 5) {
    scatter = (rand() % 10) - (rand() % 10);

    shape.setPosition({x + scatter, y});
    shape.setTexture(&texture);
}

void Bullet::move(float dy) {
    shape.move({0, dy});
}

sf::CircleShape Bullet::getShape() {
    return shape;
}

const sf::CircleShape& Bullet::getShape() const {
    return shape;
}

sf::Vector2f Bullet::getPosition() {
    return shape.getPosition();
}

void Bullet::setPosition(float x, float y) {
    shape.setPosition({x, y});
}

void Bullet::setTexture(sf::Texture &texture) {
    shape.setTexture(&texture);
}

void Bullet::setScatter(size_t scatter) {
    this->scatter = scatter;
    shape.setPosition({shape.getPosition().x + scatter, shape.getPosition().y});
}

size_t Bullet::getScatter() {
    return scatter;
}

#endif // BULLET_HPP
